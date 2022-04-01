#include "CodeGenVisitor.h"
#include "ExprVisitor.h"

#include <string>

class Var{
	public:
		Var(string var){
			this->var = var;
			isSimple = false;
		}

		Var(int val){
			this->val = val;
			isSimple = true;
		}
		string var;
		int val;
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

antlrcpp::Any CodeGenVisitor::visitDeclaration_const(ifccParser::Declaration_constContext *ctx){
	// Case int a = 5 ; 
	string varName = ctx->ALPHANUMERIC()->getText();
	int varValue = stoi(ctx->CONST()->getText());
	// vars.push_back(make_pair(varName,Var(varValue)));
	// offsets[varName] = -((i+1)*4);
    // i++;
	cout<<"	movl	$"<<varValue<<", "<<offsets[varName]<<"(%rbp)\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitDeclaration_variable(ifccParser::Declaration_variableContext *ctx){
	// Case int b = a;
	string leftVar = ctx->ALPHANUMERIC().at(0)->getText(); 
	string rightVar= ctx->ALPHANUMERIC().at(1)->getText();
	// vars.push_back(make_pair(leftVar,Var(rightVar)));
	// offsets[leftVar] = -((i+1)*4);
    // i++;
	cout <<"	movl	"<<offsets[leftVar]<<"(%rbp), %eax"<<"\n";
	cout<<"		movl	%eax, "<<offsets[rightVar]<<"(%rbp)\n";

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

antlrcpp::Any CodeGenVisitor::visitReturn_const(ifccParser::Return_constContext *ctx) {
    // Case return constant ( return 10; )
    int retval = stoi(ctx->CONST()->getText());
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





