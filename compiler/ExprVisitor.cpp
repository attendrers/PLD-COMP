
#include <string>
#include "CodeGenVisitor.h"
using namespace std;

antlrcpp::Any CodeGenVisitor::visitPar(ifccParser::ParContext *context)
{
    return visit(context->expr());
};

antlrcpp::Any CodeGenVisitor::visitPrExpr(ifccParser::PrExprContext *ctx){
    return visit(ctx->primaryexpr());
};

antlrcpp::Any CodeGenVisitor::visitOp_infsup(ifccParser::Op_infsupContext *ctx){

};

antlrcpp::Any CodeGenVisitor::visitOp_equalornot(ifccParser::Op_equalornotContext *ctx){

};

antlrcpp::Any CodeGenVisitor::visitOp_not(ifccParser::Op_notContext *ctx){

};

antlrcpp::Any CodeGenVisitor::visitOp_opposite(ifccParser::Op_oppositeContext *ctx){

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
        cout<<" cltd\n";
        cout<<"\t idivl   "<<tmp1;
    }

    lastVarPosition-=4;
    string place = string(to_string(lastVarPosition)+"(%rbp)");
    cout<<"\tmovl    %eax, "<<lastVarPosition<<"(%rbp)\n";
    // Return the place of stored result
    return place;

    // Both operations put result in %eax, put it into new variable
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
    lastVarPosition-=4;
    string place = string(to_string(lastVarPosition)+"(%rbp)");
    cout<<"\tmovl    %eax, "<<lastVarPosition<<"(%rbp)\n";
    // Return the place of stored result
    return place;
};

antlrcpp::Any CodeGenVisitor::visitOp_bit(ifccParser::Op_bitContext *ctx){

};

// primaryexpr
antlrcpp::Any CodeGenVisitor::visitChar(ifccParser::CharContext *ctx){

};

antlrcpp::Any CodeGenVisitor::visitVariable(ifccParser::VariableContext *ctx){
    return string(to_string(offsets[ctx->ALPHANUMERIC()->getText()]) + "(%rbp)");
};

antlrcpp::Any CodeGenVisitor::visitInt(ifccParser::IntContext *ctx){
    // Store the const into a tmp register
    lastVarPosition-=4;
    int val = stoi(ctx->INT_CONST()->getText());
    string place = string(to_string(lastVarPosition)+"(%rbp)");
    cout<<"\tmovl    $"<<val<<", "<<lastVarPosition<<"(%rbp)\n";
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
int main(){
    int a = 5;
    int b = 2;
    int c = 1;
    int delta = b*b - 4*a*c;
    return delta;
}
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
