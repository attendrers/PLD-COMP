
#include <string>
#include "CodeGenVisitor.h"
using namespace std;

// Adds a place for var in the current position (-4%rbp) --> (-8 %rbp)
// And moves it 
string allocateTmpVar(int type,FunctionData * f,string leftVar){
    f->decrementLastVarPosition(type);
    int lastVarPosition = f->getLastVarPosition();
    string place = string(to_string(lastVarPosition)+"(%rbp)");
    cout<<"\tmovl    "<<leftVar<<", "<<lastVarPosition<<"(%rbp)\n";
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


// antlrcpp::Any CodeGenVisitor::visitMinus(ifccParser::MinusContext *context)
// {
//     string tmp0 = (string)visit(context->expr(0));
//     string tmp1 = (string)visit(context->expr(1));
//     assemblerText += "        movl    " + tmp0 + ", %edx\n";
//     assemblerText += "        movl    " + tmp1 + ", %eax\n";
//     assemblerText += "        subl	%edx, %eax\n";
//     // i++;
//     // return string("#tmp"+to_string(i));
//     return string("%eax");
// };

// antlrcpp::Any CodeGenVisitor::visitMuldiv(ifccParser::MuldivContext *context)
// {
//     string tmp0 = (string)visit(context->expr(0));
//     string tmp1 = (string)visit(context->expr(1));
//     char op = context->OP()->getText()[0];
//     if (op == '*')
//     {
//         assemblerText += "        movl    " + tmp0 + ", %edx\n";
//         assemblerText += "        movl    " + tmp1 + ", %eax\n";
//         assemblerText += "        imul	%edx, %eax\n";
//     }
//     else
//     {
//         assemblerText += "        movl    " + tmp0 + ", %eax\n";
//         assemblerText += "        cltd\n";
//         // %edx is used by the cltd command so we're gonna use %ebx instead it's a 32bits register just like %eax and %edx
//         assemblerText += "        movl    " + tmp1 + ", %ebx\n";
//         assemblerText += "        idivl	%ebx \n";
//     }
//     // i++;
//     // return string("#tmp"+to_string(i));
//     return string("%eax");
// }

// antlrcpp::Any CodeGenVisitor::visitCONST(ifccParser::CONSTContext *context)
// {
//     // i++;
//     // return string("#tmp"+to_string(i));
//     return string("$" + context->CONST()->getText());
// }

// antlrcpp::Any CodeGenVisitor::visitPlus(ifccParser::PlusContext *context)
// {
//     string tmp0 = (string)visit(context->expr(0));
//     string tmp1 = (string)visit(context->expr(1));
//     assemblerText += "        movl    " + tmp0 + ", %edx\n";
//     assemblerText += "        movl    " + tmp1 + ", %eax\n";
//     assemblerText += "        addl	%edx, %eax\n";
//     // i++;
//     // return string("#tmp"+to_string(i));
//     return string("%eax");
// }
// antlrcpp::Any CodeGenVisitor::visitOp_or(ifccParser::Op_orContext *context) override
// {
//     string tmp0 = (string)visit(context->expr(0));
//     string tmp1 = (string)visit(context->expr(1));
//     assemblerText += "        movl    " + tmp0 + ", %edx\n";
//     assemblerText += "        movl    " + tmp1 + ", %eax\n";
//     assemblerText += "        orl	%edx, %eax\n";
//     // i++;
//     // return string("#tmp"+to_string(i));
//     return string("%eax");
// }

// antlrcpp::Any CodeGenVisitor::visitOp_and(ifccParser::Op_andContext *context) override
// {
//     string tmp0 = (string)visit(context->expr(0));
//     string tmp1 = (string)visit(context->expr(1));
//     assemblerText += "        movl    " + tmp0 + ", %edx\n";
//     assemblerText += "        movl    " + tmp1 + ", %eax\n";
//     assemblerText += "        andl	%edx, %eax\n";
//     // i++;
//     // return string("#tmp"+to_string(i));
//     return string("%eax");
// }

// antlrcpp::Any CodeGenVisitor::visitOp_xor(ifccParser::Op_xorContext *context) override
// {
//     string tmp0 = (string)visit(context->expr(0));
//     string tmp1 = (string)visit(context->expr(1));
//     assemblerText += "        movl    " + tmp0 + ", %edx\n";
//     assemblerText += "        movl    " + tmp1 + ", %eax\n";
//     assemblerText += "        xorl	%edx, %eax\n";
//     // i++;
//     // return string("#tmp"+to_string(i));
//     return string("%eax");
// }

// antlrcpp::Any CodeGenVisitor::visitOp_equal(ifccParser::Op_equalContext *context) override
// {
//     string tmp0 = (string)visit(context->expr(0));
//     string tmp1 = (string)visit(context->expr(1));
//     assemblerText += "        movl    " + tmp0 + ", %edx\n";
//     assemblerText += "        movl    " + tmp1 + ", %eax\n";
//     assemblerText += "        cmpl	%edx, %eax\n";
//     assemblerText += "        sete	%al\n";
//     assemblerText += "        movzbl	%al, %eax\n";
//     return string("%eax");
// }

// antlrcpp::Any CodeGenVisitor::visitOp_not_equal(ifccParser::Op_not_equalContext *context) override
// {
//     string tmp0 = (string)visit(context->expr(0));
//     string tmp1 = (string)visit(context->expr(1));
//     assemblerText += "        movl    " + tmp0 + ", %edx\n";
//     assemblerText += "        movl    " + tmp1 + ", %eax\n";
//     assemblerText += "        cmpl	%edx, %eax\n";
//     assemblerText += "        setne	%al\n";
//     assemblerText += "        movzbl	%al, %eax\n";
//     return string("%eax");
// }

// antlrcpp::Any CodeGenVisitor::visitOp_sup(ifccParser::Op_supContext *context) override
// {
//     string tmp0 = (string)visit(context->expr(0));
//     string tmp1 = (string)visit(context->expr(1));
//     assemblerText += "        movl    " + tmp0 + ", %edx\n";
//     assemblerText += "        movl    " + tmp1 + ", %eax\n";
//     assemblerText += "        cmpl	%edx, %eax\n";
//     assemblerText += "        setg	%al\n";
//     assemblerText += "        movzbl	%al, %eax\n";
//     return string("%eax");
// }

// antlrcpp::Any CodeGenVisitor::visitOp_inf(ifccParser::Op_infContext *context) override
// {
//     string tmp0 = (string)visit(context->expr(0));
//     string tmp1 = (string)visit(context->expr(1));
//     assemblerText += "        movl    " + tmp0 + ", %edx\n";
//     assemblerText += "        movl    " + tmp1 + ", %eax\n";
//     assemblerText += "        cmpl	%edx, %eax\n";
//     assemblerText += "        setl	%al\n";
//     assemblerText += "        movzbl	%al, %eax\n";
//     return string("%eax");
// }

// antlrcpp::Any CodeGenVisitor::visitALPHANUMERIC(ifccParser::ALPHANUMERICContext *context)
// {
//     return string(to_string(offsets[context->ALPHANUMERIC()->getText()]) + "(%rbp)");
// }

// antlrcpp::Any CodeGenVisitor::visitOp_opposite(ifccParser::Op_oppositeContext *context) override
// {
//     string tmp0 = (string)visit(context->expr());
//     assemblerText += "        movl    " + tmp0 + ", %eax\n";
//     assemblerText += "        negl	%eax\n";
//     return string("%eax");
// }

// antlrcpp::Any CodeGenVisitor::visitOp_not(ifccParser::Op_notContext *context) override
// {
//     string tmp0 = (string)visit(context->expr());
//     assemblerText += "        cmpl	$0, " + tmp0 + "\n";
//     assemblerText += "        sete	%al\n";
//     assemblerText += "        movzbl	%al, %eax\n";
//     return string("%eax");
// }
