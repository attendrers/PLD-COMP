#include "CodeGenVisitor.h"
#include "ExprVisitor.h"

#include <string>
#include <map>
#include <algorithm>

using namespace std;

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
	int retval;
	vector<pair<string,Var>> vars;
	unordered_map <string,int> offsets;
	for(int i=0; i<ctx->line().size(); i++){
		ifccParser::LineContext * current = ctx->line().at(i);
		// We are in a declaration line
		if(current->RETURN()==nullptr){
			// No expr on right side
			if(current->expr()==nullptr){
				// Case int a = 5 ; 
				if(current->ALPHANUMERIC().size()==1){
					string varName = current->ALPHANUMERIC().at(0)->getText();
					int varValue = stoi(current->CONST()->getText());
					vars.push_back(make_pair(varName,Var(varValue)));
					offsets[varName] = -((i+1)*4);
				}
				// Case int b = a;
				else if(current->ALPHANUMERIC().size()==2){
					string leftVar = current->ALPHANUMERIC().at(1)->getText(); 
					string rightVar= current->ALPHANUMERIC().at(0)->getText();
					vars.push_back(make_pair(rightVar,Var(leftVar)));
					
				}
			}

			// Expr on right side
			else{
				string leftVar = current->ALPHANUMERIC().at(0)->getText();
				
				cout<<"Expr: "<<current->expr()->getText()<<endl;
				ExprVisitor e(offsets);
				e.visit(current->expr());
				cout<<"Res: "<< e.getAssemblerText();
			}
	
		}

		// We are in a return line
		else{
			retval = stoi(current->CONST()->getText());
		}
	}

	int length = vars.size();
	std::cout<<".globl	main\n"
		" main: \n"

		"	# prologue\n"
		"	pushq %rbp\n"
		"	movq %rsp, %rbp\n";
	for(int i=0; i<length; i++){
		Var current = vars.at(i).second;
		if(current.isSimple){
			std::cout<<"	movl	$"<<current.val<<", "<<(-(i+1)*4)<<"(%rbp)\n";
		}
		else{
			cout <<"	movl	"<<offsets[current.var]<<"(%rbp), %eax"<<"\n";
			
			cout<<"	movl	%eax, "<<(-(i+1)*4)<<"(%rbp)\n";
		}
	}

		std::cout<<

		" 	movl	$"<<retval<<", %eax\n"

		"	#epilogue\n"
		"	popq %rbp\n"
		" 	ret\n";

	return 0;
}

