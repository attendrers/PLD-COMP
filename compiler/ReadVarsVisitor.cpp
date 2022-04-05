#include "ReadVarsVisitor.h"

antlrcpp::Any ReadVarsVisitor::visitProg(ifccParser::ProgContext *ctx){
    for(auto & func : ctx->func()){
        FunctionData * fcData = new FunctionData();
        functionDatas.push_back(fcData);
		visit(func);
        
        currentIndex++;
	}
    for(int i=0; i<functionDatas.size();i++){
        FunctionData * currentF = functionDatas[i];
        vector<string> vars = currentF->getVars();
        unordered_map<string, int> types = currentF->getTypes();
        int lastVarPosition = currentF->getLastVarPosition();


        int length  = vars.size();
        int current = lastVarPosition;
        for(string & var : vars){
            currentF->addToOffset(var,current);
            current+= types[var];
        }
    }

    for ( auto it : vars)
    {
        if(!(find(used_vars.begin(), used_vars.end(), it) != used_vars.end()))
        {
            not_used.push_back(it);
        }
    }

    if (not_used.size() != 0)
    {
        cout << "#Warning : (" << not_used.size() << ") not used" << endl;
    }

    return 0;
};

antlrcpp::Any ReadVarsVisitor::visitFunc(ifccParser::FuncContext *ctx){
	for(auto & line : ctx->line()){
		visit(line);
	}

	return 0;
}

antlrcpp::Any ReadVarsVisitor::visitDeclaration_intconst(ifccParser::Declaration_intconstContext *ctx) {
    FunctionData * currentF = functionDatas[currentIndex];


    string varName = ctx->ALPHANUMERIC()->getText();
    currentF->addToVars(varName);

    int type=(ctx->TYPE()->getText()=="int")?4:1;
    currentF->addToTypes(varName,type);    

    // cout<<"type: "<<functionDatas[currentIndex]->getTypes().at(varName)<<" vs: "<<types[varName]<<endl;
    currentF->decrementLastVarPosition(type);

    return 0;
};

antlrcpp::Any ReadVarsVisitor::visitDeclaration_charconst(ifccParser::Declaration_charconstContext *ctx) {
    FunctionData * currentF = functionDatas[currentIndex];

    string varName = ctx->ALPHANUMERIC()->getText();
    currentF->addToVars(varName);
    int type=(ctx->TYPE()->getText()=="int")?4:1;
    currentF->addToTypes(varName,type); 
    currentF->decrementLastVarPosition(type);

    return 0;
};

antlrcpp::Any ReadVarsVisitor::visitDeclaration_variable(ifccParser::Declaration_variableContext *ctx) {
    FunctionData * currentF = functionDatas[currentIndex];
    unordered_map<string, int> types = functionDatas[currentIndex]->getTypes();

    string leftVar = ctx->ALPHANUMERIC().at(0)->getText();
    string rightVar= ctx->ALPHANUMERIC().at(1)->getText();
    
    if(types[rightVar]==0){
        throw out_of_range("Undeclared variable: ("+rightVar+") at variable declaration of: ("+leftVar+")");
    }
    currentF->addToVars(leftVar);
    used_vars.push_back(rightVar);

    int type=(ctx->TYPE()->getText()=="int")?4:1;
    currentF->addToTypes(leftVar,type); 
    currentF->decrementLastVarPosition(type);

    return 0;
};

antlrcpp::Any ReadVarsVisitor::visitDeclaration_expr(ifccParser::Declaration_exprContext *ctx) {
    FunctionData * currentF = functionDatas[currentIndex];

    string varName = ctx->ALPHANUMERIC()->getText();
    currentF->addToVars(varName);

    int type=(ctx->TYPE()->getText()=="int")?4:1;
    currentF->addToTypes(varName,type); 
    currentF->decrementLastVarPosition(type);
    return 0;
};

antlrcpp::Any ReadVarsVisitor::visitReturn_variable(ifccParser::Return_variableContext *ctx) {

    unordered_map<string, int> types = functionDatas[currentIndex]->getTypes();
    string varName = ctx->ALPHANUMERIC()->getText();

    if(types[varName]==0){
        throw out_of_range("Undeclared variable: ("+varName+") at final return");
    }

    used_vars.push_back(varName);

    return 0;
    
};

antlrcpp::Any ReadVarsVisitor::visitDeclaration_function_call(ifccParser::Declaration_function_callContext *ctx){
	FunctionData * currentF = functionDatas[currentIndex];

    string varName = ctx->ALPHANUMERIC()->getText();
    currentF->addToVars(varName);


    int type=(ctx->TYPE()->getText()=="int")?4:1;
    currentF->addToTypes(varName,type); 
    currentF->decrementLastVarPosition(type);
	return 0;
}

antlrcpp::Any ReadVarsVisitor::visitVariable(ifccParser::VariableContext *ctx){
    string varName = ctx->ALPHANUMERIC()->getText();
    used_vars.push_back(varName);
}

// unordered_map <string,int> ReadVarsVisitor::getOffsets(){
//     return offsets;
// };

// int ReadVarsVisitor::getLastVarPosition(){
//     return lastVarPosition;
// }

// unordered_map <string,int> ReadVarsVisitor::getTypes(){
//     return types;
// };

