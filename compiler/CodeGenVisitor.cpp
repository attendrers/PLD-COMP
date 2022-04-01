#include "CodeGenVisitor.h"

#include <string>

class Var{
	public:
		Var(string var,int type){
			this->var = var;
			this->type = type;
			isSimple = false;
		}

		Var(int val,int type){
			this->val = val;
			this->type = type;
			isSimple = true;
		}
		string var;
		int val;
		int type;//1 pour int, 0 pour char
		bool isSimple;


};

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx) 
{
	std::cout<<".globl	main\n"
		" main: \n"

		"	# prologue\n"
		"	pushq %rbp\n"
		"	movq %rsp, %rbp\n\n";

	
	// vector<pair<string,Var>> vars;
	for(auto & line : ctx->line()){
		visit(line);
	}

    std::cout<<
    "	\n	# epilogue\n"
    "	popq %rbp\n"
    " 	ret\n";

	return 0;
}

antlrcpp::Any CodeGenVisitor::visitDeclaration_intconst(ifccParser::Declaration_intconstContext *ctx){
	// Case int a = 5 ; 
	string varName = ctx->ALPHANUMERIC()->getText();
	int varValue = stoi(ctx->INT_CONST()->getText());
	// vars.push_back(make_pair(varName,Var(varValue,1)));
	// offsets[varName] = -((i+1)*4);
    // i++;
	cout<<"	movl	$"<<varValue<<", "<<offsets[varName]<<"(%rbp)\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitDeclaration_charconst(ifccParser::Declaration_charconstContext *ctx){
	// Case char a = '5' ; 
	string varName = ctx->ALPHANUMERIC()->getText();
	string temp = ctx->CHAR_CONST()->getText();
	int varValue = (int)temp.at(1);
	// // vars.push_back(make_pair(varName,Var(varValue,0)));
	// offsets[varName] = -(i+1);
    // i++;
	cout<<"	movl	$"<<varValue<<", "<<offsets[varName]<<"(%rbp)\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitDeclaration_variable(ifccParser::Declaration_variableContext *ctx){
	// Case int b = a;
	string leftVar = ctx->ALPHANUMERIC().at(0)->getText(); 
	string rightVar= ctx->ALPHANUMERIC().at(1)->getText();
	// int type=(ctx->TYPE()->getText()=="int")?1:0;
	// // vars.push_back(make_pair(leftVar,Var(rightVar,type)));
	// if(type==1) offsets[leftVar] = -((i+1)*4);
	// else offsets[leftVar] = -(i+1);
    // i++;
	cout <<"	movl	"<<offsets[rightVar]<<"(%rbp), %eax"<<"\n";
	cout<<"	movl	%eax, "<<offsets[leftVar]<<"(%rbp)\n";

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitDeclaration_expr(ifccParser::Declaration_exprContext *ctx){
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitReturn(ifccParser::ReturnContext *ctx){
	// We are in a return line
    visit(ctx->return_global());
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitReturn_intconst(ifccParser::Return_intconstContext *ctx) {
    // Case return constant ( return 10; )
    int retval = stoi(ctx->INT_CONST()->getText());
    cout<<" 	movl	$"<<retval<<", %eax\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitReturn_charconst(ifccParser::Return_charconstContext *ctx) {
    // Case return constant ( return 10; )
    int retval = stoi(ctx->CHAR_CONST()->getText());
    cout<<" 	movl	$"<<retval<<", %eax\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitReturn_variable(ifccParser::Return_variableContext *ctx) {
    // Case return variable ( return a; )
    string varName = ctx->ALPHANUMERIC()->getText();
    cout<<"	movl	"<<offsets[varName]<<"(%rbp), %eax\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitReturn_expr(ifccParser::Return_exprContext *ctx) {
    // Case return expression ( return a+b; )
    // ExprVisitor e(offsets);
    // e.visit(current->expr());
    // cout<<e.getAssemblerText();
    // Final result should be in %eax so no need to do a movl to %eax

    return 0;
}





