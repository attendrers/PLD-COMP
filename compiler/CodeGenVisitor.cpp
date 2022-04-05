#include "CodeGenVisitor.h"

#include <string>

// class Var{
// 	public:
// 		Var(string var,int type){
// 			this->var = var;
// 			this->type = type;
// 			isSimple = false;
// 		}

// 		Var(int val,int type){
// 			this->val = val;
// 			this->type = type;
// 			isSimple = true;
// 		}
// 		string var;
// 		int val;
// 		int type;//1 pour int, 0 pour char
// 		bool isSimple;


// };

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx) 
{
	// cout<<".globl	main\n"
	// 	" main: \n"

	// 	"	# prologue\n"
	// 	"	pushq %rbp\n"
	// 	"	movq %rsp, %rbp\n\n";

	cout<<".globl		main\n";
	for(auto & func : ctx->func()){
		visit(func);
		currentIndex++;
	}

    // cout<<
    // "	\n	# epilogue\n"
    // "	popq %rbp\n"
    // " 	ret\n";

	return 0;
}

antlrcpp::Any CodeGenVisitor::visitFunc(ifccParser::FuncContext *ctx){
	string funcName = ctx->funcName->getText();
	cout<<funcName<<":\n";
	cout<<".LFB"<<0<<":\n";
	cout<<"	# prologue\n"
		"	pushq %rbp\n"
		"	movq %rsp, %rbp\n\n";
	
	// funcName == "main" && cout<<"	subq	$16, %rsp\n";

	for(auto & line : ctx->line()){
		visit(line);
	}

	 cout<<
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
	unordered_map<string, int> offsets = functionDatas[currentIndex].getOffsets();
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
	unordered_map<string, int> offsets = functionDatas[currentIndex].getOffsets();
	cout<<"	movb	$"<<varValue<<", "<<offsets[varName]<<"(%rbp)\n";
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
	unordered_map<string, int> offsets = functionDatas[currentIndex].getOffsets();
	cout <<"	movl	"<<offsets[rightVar]<<"(%rbp), %eax"<<"\n";
	cout<<"	movl	%eax, "<<offsets[leftVar]<<"(%rbp)\n";

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitDeclaration_expr(ifccParser::Declaration_exprContext *ctx){
	string varName = ctx->ALPHANUMERIC()->getText();
	string place = visit(ctx->expr());

	unordered_map<string, int> offsets = functionDatas[currentIndex].getOffsets();
	// Can't movl (%rbp) into (%rbp) directly
	// Put one first in %eax then move from %eax to next one
	cout<<" 	movl	"<<place<<", %eax\n";
	cout<<" 	movl	%eax, "<<offsets[varName]<<"(%rbp)\n";
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
    string temp = ctx->CHAR_CONST()->getText();
	int retval = (int)temp.at(1);
    cout<<" 	movl	$"<<retval<<", %eax\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitReturn_variable(ifccParser::Return_variableContext *ctx) {
    // Case return variable ( return a; )
    string varName = ctx->ALPHANUMERIC()->getText();
	unordered_map<string, int> offsets = functionDatas[currentIndex].getOffsets();
	unordered_map<string, int> types = functionDatas[currentIndex].getTypes();
	string op = types[varName] == 4 ? "	movl	" : "	movsbl	";
    cout<<op<<offsets[varName]<<"(%rbp), %eax\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitReturn_expr(ifccParser::Return_exprContext *ctx) {
    string place = visit(ctx->expr());
	cout <<"	movl	"<<place<<", %eax\n";

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitFunction_call(ifccParser::Function_callContext *ctx){
    cout<<"		call	"<<ctx->funcName->getText()<<"\n";
	// Params of function
	for(auto & param : ctx->primaryexpr()){
		// cout<<param->getText()<<",";
	}
	return 0;
}




