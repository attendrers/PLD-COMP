
#include <string>
#include "CodeGenVisitor.h"
using namespace std;

// Adds a place for var in the current position (-4%rbp) --> (-8 %rbp)
// And moves it 
string allocateTmpVar(int type,FunctionData * f,string leftVar){
    f->decrementLastVarPosition(type);
    int lastVarPosition = f->getLastVarPosition();
    string place = string(to_string(lastVarPosition)+"(%rbp)");
    string op = type == 4 ? "movl" : "movb";
    cout<<"\t"<<op<<"   "<<leftVar<<", "<<lastVarPosition<<"(%rbp)\n";
    return place;
}

antlrcpp::Any CodeGenVisitor::visitPar(ifccParser::ParContext *context)
{
    return visit(context->expr());
};

antlrcpp::Any CodeGenVisitor::visitPrExpr(ifccParser::PrExprContext *ctx){
    return visit(ctx->primaryexpr());
};

antlrcpp::Any CodeGenVisitor::visitOp_infsup(ifccParser::Op_infsupContext *ctx){
    // Get places of stored left/right vars
    string tmp0 = visit(ctx->left);
    string tmp1 = visit(ctx->right);
    string  op = ctx->op->getText();
    cout<<"\tmovl    " + tmp0 + ", %eax\n";
    cout<<"\tcmpl    " + tmp1 + ", %eax\n";
    //comparaison in a expression
    if(op==">=")
    {
        cout<<"\tsetge   %al\n";
    }
    else if(op=="<=")
    {
        cout<<"\tsetle   %al\n";
    }
    else if(op==">")
    {
        cout<<"\tsetg    %al\n";
    }
    else if(op=="<")
    {
        cout<<"\tsetl    %al\n";
    }
    
    cout<<"\tmovzbl  %al, %eax\n";
    string place = allocateTmpVar(4,functionDatas[currentIndex],"%eax");
    //return the result of comparaison
    return place;
};

antlrcpp::Any CodeGenVisitor::visitOp_equalornot(ifccParser::Op_equalornotContext *ctx){
    // Get places of stored left/right vars
    string tmp0 = visit(ctx->left);
    string tmp1 = visit(ctx->right);
    string  op = ctx->op->getText();
    cout<<"\tmovl    " + tmp0 + ", %eax\n";
    cout<<"\tcmpl    " + tmp1 + ", %eax\n";
    //comparaison in a expression
    if(op=="==")
    {
        cout<<"\tsete    %al\n";
    }
    else if(op=="!=")
    {
        cout<<"\tsetne   %al\n";
    }
    cout<<"\tmovzbl  %al, %eax\n";
    string place = allocateTmpVar(4,functionDatas[currentIndex],"%eax");
    //return the result of comparaison
    return place;
};

antlrcpp::Any CodeGenVisitor::visitOp_not(ifccParser::Op_notContext *ctx){
    string tmp0 = (string)visit(ctx->expr());
    cout<<"        cmpl	$0, " + tmp0 + "\n";
    cout<<"        sete	%al\n";
    cout<<"        movzbl	%al, %eax\n";
    // Put the result into a new tmp var
    string place = allocateTmpVar(4,functionDatas[currentIndex],"%eax");
    // Return the place of stored result
    return place;

};

antlrcpp::Any CodeGenVisitor::visitOp_opposite(ifccParser::Op_oppositeContext *ctx){
    string tmp0 = (string)visit(ctx->expr());
    cout<<"        movl    " + tmp0 + ", %eax\n";
    cout<<"        negl	%eax\n";
    string place = allocateTmpVar(4,functionDatas[currentIndex],"%eax");
    // Return the place of stored result
    return place;
};

antlrcpp::Any CodeGenVisitor::visitOp_muldiv(ifccParser::Op_muldivContext *ctx){
    // Get places of stored left/right vars
    string tmp0 = visit(ctx->left);
    string tmp1 = visit(ctx->right);

    if(ctx->op->getText()=="*"){
        // move right to eax
        cout<<"        movl    " + tmp1 + ", %eax\n";
        cout<<"\t imull   "<<tmp0<<", %eax\n";
    }
    else{
        // move left to eax
        cout<<"        movl    " + tmp0 + ", %eax\n";
        cout<<"\t cltd\n";
        cout<<"\t idivl   "<<tmp1<<"\n";
    }

    // Both operations put result in %eax, put it into new variable
    string place = allocateTmpVar(4,functionDatas[currentIndex],"%eax");
    // Return the place of stored result
    return place;

};

antlrcpp::Any CodeGenVisitor::visitOp_plusmoins(ifccParser::Op_plusmoinsContext *ctx){
    // Get places of stored left/right vars
    string tmp0 = visit(ctx->left);
    string tmp1 = visit(ctx->right);
    string  op = ctx->op->getText()=="+" ? "addl" : "subl";
    // Move them to %eax and %edx
    cout<<"        movl    " + tmp1 + ", %edx\n";
    cout<<"        movl    " + tmp0 + ", %eax\n";
    // Do the operation
    cout<<"\t"<<op<<"	%edx, %eax \n";

    // Put the result into a new tmp var
    string place = allocateTmpVar(4,functionDatas[currentIndex],"%eax");
    // Return the place of stored result
    return place;
};

antlrcpp::Any CodeGenVisitor::visitOp_bit(ifccParser::Op_bitContext *ctx){
    return 0;
};

// primaryexpr
antlrcpp::Any CodeGenVisitor::visitChar(ifccParser::CharContext *ctx){
    string temp = ctx->CHAR_CONST()->getText();
	int val = (int)temp.at(1);
    string place = allocateTmpVar(1,functionDatas[currentIndex],string("$"+to_string(val)));
    return 0;
};

antlrcpp::Any CodeGenVisitor::visitVariable(ifccParser::VariableContext *ctx){
    unordered_map<string, int> offsets = functionDatas[currentIndex]->getOffsets();
    return string(to_string(offsets[ctx->ALPHANUMERIC()->getText()]) + "(%rbp)");
};

antlrcpp::Any CodeGenVisitor::visitInt(ifccParser::IntContext *ctx){
    // Store the const into a tmp register
    int val = stoi(ctx->INT_CONST()->getText());
    string place = allocateTmpVar(4,functionDatas[currentIndex],string("$"+to_string(val)));
    return place;
};

antlrcpp::Any CodeGenVisitor::visitExpr_func_call(ifccParser::Expr_func_callContext *ctx){
    visit(ctx->func_call());

    // Result from function call is in %eax we move in a new temporary variable in a register
	string place = allocateTmpVar(4,functionDatas[currentIndex],"%eax");
    return place;
}