#include "CodeGenVisitor.h"

#include <string>

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
	cout<<".LFB"<<currentIndex<<":\n";
	cout<<"	# prologue\n"
		"	pushq %rbp\n"
		"	movq %rsp, %rbp\n\n";

	// A function that's gonna be called with params (need to put the params/variables in registers)
	if(funcName!="main" && ctx->ALPHANUMERIC().size()>1){
		string registers_string[] = {"%edi","%esi","%edx","%ecx","%r8d","%r9d","r10d","r11d","r12d","r13d","r14d","r15d"};
		vector<string> registers (registers_string, registers_string+(sizeof(registers_string)/sizeof(string)));
		FunctionData * functionData = functionDatas[currentIndex];

		// Get from registers and put the params into %rbp registers to become variables in the program function ( starting at -100(%rbp))
		int currentOffset = -100;
		for(int i=1; i<ctx->ALPHANUMERIC().size() && (i-1)<registers.size(); i++){
			
			string paramName = ctx->ALPHANUMERIC().at(i)->getText();
			functionData->addToOffset(paramName,currentOffset);
			string rightPos = string(to_string(currentOffset)+"(%rbp)");
			cout<<" 	movl	"<<registers.at(i-1)<<", "<<rightPos<<"\n";
			currentOffset-=4;
		}
	}
	
	for(auto & line : ctx->line()){
		visit(line);
		if(fin==true)
		{
			fin=false;
			break;
		}
	}

	 cout<<
    "	\n	# epilogue\n"
    "	popq %rbp\n"
    " 	ret\n";
	return 0;
}

antlrcpp::Any CodeGenVisitor::visitBloc(ifccParser::BlocContext *ctx)
{
	for(auto & line : ctx->line()){
		visit(line);
		if(fin==true)
		{
			fin=false;
			break;
		}
	}
	return 0;
}

// Declarations

antlrcpp::Any CodeGenVisitor::visitDeclaration_intconst(ifccParser::Declaration_intconstContext *ctx){
	// Case int a = 5 ; 
	string varName = ctx->ALPHANUMERIC()->getText();
	int varValue=0;
	if(ctx->INT_CONST()) varValue = stoi(ctx->INT_CONST()->getText());

	unordered_map<string, int> offsets = functionDatas[currentIndex]->getOffsets();
	cout<<"	movl	$"<<varValue<<", "<<offsets[varName]<<"(%rbp)\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitDeclaration_charconst(ifccParser::Declaration_charconstContext *ctx){
	// Case char a = '5' ; 
	string varName = ctx->ALPHANUMERIC()->getText();
	string temp = ctx->CHAR_CONST()->getText();
	int varValue = (int)temp.at(1);

	unordered_map<string, int> offsets = functionDatas[currentIndex]->getOffsets();
	cout<<"	movb	$"<<varValue<<", "<<offsets[varName]<<"(%rbp)\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitDeclaration_variable(ifccParser::Declaration_variableContext *ctx){
	// Case int b = a;
	string leftVar = ctx->ALPHANUMERIC().at(0)->getText(); 
	string rightVar= ctx->ALPHANUMERIC().at(1)->getText();
	unordered_map<string, int> offsets = functionDatas[currentIndex]->getOffsets();
	cout <<"	movl	"<<offsets[rightVar]<<"(%rbp), %eax"<<"\n";
	cout<<"	movl	%eax, "<<offsets[leftVar]<<"(%rbp)\n";

    return 0;
}

antlrcpp::Any CodeGenVisitor::visitDeclaration_expr(ifccParser::Declaration_exprContext *ctx){
	string varName = ctx->ALPHANUMERIC()->getText();
	string place = visit(ctx->expr());

	unordered_map<string, int> offsets = functionDatas[currentIndex]->getOffsets();
	// Can't movl (%rbp) into (%rbp) directly
	// Put one first in %eax then move from %eax to next one
	cout<<" 	movl	"<<place<<", %eax\n";
	cout<<" 	movl	%eax, "<<offsets[varName]<<"(%rbp)\n";
    return 0;
}

// Affectations

antlrcpp::Any CodeGenVisitor::visitAffectation_intconst(ifccParser::Affectation_intconstContext *ctx){
	string varName = ctx->ALPHANUMERIC()->getText();
	int varValue = stoi(ctx->INT_CONST()->getText());

	unordered_map<string, int> offsets = functionDatas[currentIndex]->getOffsets();
	cout<<"	movl	$"<<varValue<<", "<<offsets[varName]<<"(%rbp)\n";
	return 0;
}

antlrcpp::Any CodeGenVisitor::visitAffectation_charconst(ifccParser::Affectation_charconstContext *ctx){
	string varName = ctx->ALPHANUMERIC()->getText();
	string temp = ctx->CHAR_CONST()->getText();
	int varValue = (int)temp.at(1);

	unordered_map<string, int> offsets = functionDatas[currentIndex]->getOffsets();
	cout<<"	movb	$"<<varValue<<", "<<offsets[varName]<<"(%rbp)\n";
	return 0;
}

antlrcpp::Any CodeGenVisitor::visitAffectation_variable(ifccParser::Affectation_variableContext *ctx){
	string leftVar = ctx->ALPHANUMERIC().at(0)->getText(); 
	string rightVar= ctx->ALPHANUMERIC().at(1)->getText();
	unordered_map<string, int> offsets = functionDatas[currentIndex]->getOffsets();
	cout <<"	movl	"<<offsets[rightVar]<<"(%rbp), %eax"<<"\n";
	cout<<"	movl	%eax, "<<offsets[leftVar]<<"(%rbp)\n";
	return 0;
}

antlrcpp::Any CodeGenVisitor::visitAffectation_expr(ifccParser::Affectation_exprContext *ctx){

	unordered_map<string, int> offsets = functionDatas[currentIndex]->getOffsets();
	
	string place = visit(ctx->expr());
	string varName = ctx->ALPHANUMERIC()->getText();
	// Can't movl (%rbp) into (%rbp) directly
	// Put one first in %eax then move from %eax to next one
	cout<<" 	movl	"<<place<<", %eax\n";
	cout<<" 	movl	%eax, "<<offsets[varName]<<"(%rbp)\n";
	return 0;
}

antlrcpp::Any CodeGenVisitor::visitAffectation_function_call(ifccParser::Affectation_function_callContext *ctx){
	visit(ctx->func_call());
	string varName = ctx->ALPHANUMERIC()->getText();
	unordered_map<string, int> offsets = functionDatas[currentIndex]->getOffsets();
	cout<<"	movl	%eax, "<<offsets[varName]<<"(%rbp)\n";
	return 0;
}

// Conditions
antlrcpp::Any CodeGenVisitor::visitComp_infsup(ifccParser::Comp_infsupContext *ctx){
    // Get places of stored left/right vars
    string tmp0 = visit(ctx->left);
    string tmp1 = visit(ctx->right);
    string  op = ctx->op->getText();
    cout<<"\tmovl    " + tmp0 + ", %eax\n";
    cout<<"\tcmpl    " + tmp1 + ", %eax\n";
    //comparaison in a expression
    if(op==">=")
    {
        cout<<"\tjl      ";
    }
    else if(op=="<=")
    {
        cout<<"\tjg      ";
    }
    else if(op==">")
    {
        cout<<"\tjle     ";
    }
    else if(op=="<")
    {
        cout<<"\tjge     ";
    }
	cout<<".L"<<blocIndex<<"\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitComp_equalornot(ifccParser::Comp_equalornotContext *ctx){
    // Get places of stored left/right vars
    string tmp0 = visit(ctx->left);
    string tmp1 = visit(ctx->right);
    string  op = ctx->op->getText();
    cout<<"\tmovl    " + tmp0 + ", %eax\n";
    cout<<"\tcmpl    " + tmp1 + ", %eax\n";
    //comparaison in a expression
    if(op=="==")
    {
        cout<<"\tjne     ";
    }
    else if(op=="!=")
    {
        cout<<"\tje      ";
    }
	cout<<".L"<<blocIndex<<"\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitComp2_infsup(ifccParser::Comp2_infsupContext *ctx){
    // Get places of stored left/right vars
    string tmp0 = visit(ctx->left);
    string tmp1 = visit(ctx->right);
    string  op = ctx->op->getText();
    cout<<"\tmovl    " + tmp0 + ", %eax\n";
    cout<<"\tcmpl    " + tmp1 + ", %eax\n";
    //comparaison in a expression
    if(op==">=")
    {
        cout<<"\tjge     ";
    }
    else if(op=="<=")
    {
        cout<<"\tjle     ";
    }
    else if(op==">")
    {
        cout<<"\tjg      ";
    }
    else if(op=="<")
    {
        cout<<"\tjl      ";
    }
	cout<<".L"<<blocIndex<<"\n";
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitComp2_equalornot(ifccParser::Comp2_equalornotContext *ctx){
    // Get places of stored left/right vars
    string tmp0 = visit(ctx->left);
    string tmp1 = visit(ctx->right);
    string  op = ctx->op->getText();
    cout<<"\tmovl    " + tmp0 + ", %eax\n";
    cout<<"\tcmpl    " + tmp1 + ", %eax\n";
    //comparaison in a expression
    if(op=="==")
    {
        cout<<"\tje      ";
    }
    else if(op=="!=")
    {
        cout<<"\tjne     ";
    }
	cout<<".L"<<blocIndex<<"\n";
    return 0;
}

// Statements

antlrcpp::Any CodeGenVisitor::visitStatement_if(ifccParser::Statement_ifContext *ctx)
{
	blocIndex++;
	visit(ctx->cond);
	visit(ctx->blocif);
	if(ctx->ELSE())
	{
		blocIndex++;
		cout<<"\tjmp    .L"<<blocIndex<<"\n";
		cout<<".L"<<blocIndex-1<<":\n";
		visit(ctx->blocelse);
		cout<<".L"<<blocIndex<<":\n";
	}
	else
	{
		cout<<".L"<<blocIndex<<":\n";
	}
	return 0;
}

antlrcpp::Any CodeGenVisitor::visitStatement_while(ifccParser::Statement_whileContext *ctx)
{
	blocIndex+=2;
	cout<<"\tjmp .L"<<blocIndex<<"\n";
	cout<<".L"<<blocIndex<<":\n";
	visit(ctx->bloc());
	cout<<".L"<<blocIndex-1<<":\n";
	visit(ctx->cond);
	return 0;
}

// Returns

antlrcpp::Any CodeGenVisitor::visitReturn_intconst(ifccParser::Return_intconstContext *ctx) {
    // Case return constant ( return 10; )
    int retval = stoi(ctx->INT_CONST()->getText());
    cout<<" 	movl	$"<<retval<<", %eax\n";
	fin=true;
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitReturn_charconst(ifccParser::Return_charconstContext *ctx) {
    // Case return constant ( return 10; )
    string temp = ctx->CHAR_CONST()->getText();
	int retval = (int)temp.at(1);
    cout<<" 	movl	$"<<retval<<", %eax\n";
	fin=true;
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitReturn_variable(ifccParser::Return_variableContext *ctx) {
    // Case return variable ( return a; )
    string varName = ctx->ALPHANUMERIC()->getText();
	unordered_map<string, int> offsets = functionDatas[currentIndex]->getOffsets();
	unordered_map<string, int> types = functionDatas[currentIndex]->getTypes();
	string op = types[varName] == 4 ? "	movl	" : "	movsbl	";
    cout<<op<<offsets[varName]<<"(%rbp), %eax\n";
	fin=true;
    return 0;
}

antlrcpp::Any CodeGenVisitor::visitReturn_expr(ifccParser::Return_exprContext *ctx) {
    string place = visit(ctx->expr());
	cout <<"	movl	"<<place<<", %eax\n";
	fin=true;
    return 0;
}

// Functions

antlrcpp::Any CodeGenVisitor::visitFunction_call(ifccParser::Function_callContext *ctx){

	// Params of function
	int numberOfParams = ctx->func_param().size();
	string registers_string[] = {"%edi","%esi","%edx","%ecx","%r8d","%r9d","r10d","r11d","r12d","r13d","r14d","r15d"};
	vector<string> registers (registers_string, registers_string+(sizeof(registers_string)/sizeof(string)));
	int numberOfRegisters = registers.size();

	for(int i =0 ; i<numberOfParams && i<numberOfRegisters ; i++){
		auto param = ctx->func_param().at(i);
		string place = visit(param);
		cout<<" 	movl	"<<place<<", "<<registers[i]<<"\n";
	}

	// Calling the function
    cout<<"\t call	"<<ctx->funcName->getText()<<"\n";
	
	return 0;
}

antlrcpp::Any CodeGenVisitor::visitDeclaration_function_call(ifccParser::Declaration_function_callContext *ctx){
	visit(ctx->func_call());
	string varName = ctx->ALPHANUMERIC()->getText();
	unordered_map<string, int> offsets = functionDatas[currentIndex]->getOffsets();
	cout<<"	movl	%eax, "<<offsets[varName]<<"(%rbp)\n";
	return 0;
}

antlrcpp::Any CodeGenVisitor::visitF_int(ifccParser::F_intContext *ctx) {
	int val = stoi(ctx->INT_CONST()->getText());
    string place = string("$"+to_string(val));
    return place;
}

antlrcpp::Any CodeGenVisitor::visitF_char(ifccParser::F_charContext *ctx) {
	string temp = ctx->CHAR_CONST()->getText();
	int val = (int)temp.at(1);
	string place = string("$"+to_string(val));
	return place;
}

antlrcpp::Any CodeGenVisitor::visitF_variable(ifccParser::F_variableContext *ctx) {
	unordered_map<string, int> offsets = functionDatas[currentIndex]->getOffsets();
    return string(to_string(offsets[ctx->ALPHANUMERIC()->getText()]) + "(%rbp)");
}
