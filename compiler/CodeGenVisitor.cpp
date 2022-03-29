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
	std::cout<<".globl	main\n"
		" main: \n"

		"	# prologue\n"
		"	pushq %rbp\n"
		"	movq %rsp, %rbp\n\n";

	
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
					cout<<"	movl	$"<<varValue<<", "<<(-(i+1)*4)<<"(%rbp)\n";
				}
				// Case int b = a;
				else if(current->ALPHANUMERIC().size()==2){
					string leftVar = current->ALPHANUMERIC().at(0)->getText(); 
					string rightVar= current->ALPHANUMERIC().at(1)->getText();
					vars.push_back(make_pair(leftVar,Var(rightVar)));
					offsets[leftVar] = -((i+1)*4);
					cout <<"	movl	"<<offsets[leftVar]<<"(%rbp), %eax"<<"\n";
					cout<<"		movl	%eax, "<<(-(i+1)*4)<<"(%rbp)\n";
					
				}
			}

			// Expr on right side
			else{
				string leftVar = current->ALPHANUMERIC().at(0)->getText();
				offsets[leftVar] = -((i+1)*4);
				ExprVisitor e(offsets);
				cout<<"	# Expression here\n";
				e.visit(current->expr());
				cout<<e.getAssemblerText();
				cout<<"	movl	%eax, "<<(-(i+1)*4)<<"(%rbp)\n";
			}
	
		}

		// We are in a return line
		else{
			// Case return constant ( return 10; )
			if(current->CONST()!=nullptr){
				retval = stoi(current->CONST()->getText());
				cout<<" 	movl	$"<<retval<<", %eax\n";
			}
			// Case return variable ( return a; )
			else if(current->expr()==nullptr){
				string varName = current->ALPHANUMERIC().at(0)->getText();
				cout<<"	movl	"<<offsets[varName]<<"(%rbp), %eax\n";
			}
			// Case return expression ( return a+b; )
			else{
				ExprVisitor e(offsets);
				e.visit(current->expr());
				cout<<e.getAssemblerText();
				// Final result should be in %eax so no need to do a movl to %eax
			}

		}
	}

	// int length = vars.size();
	
	// Case where we want to first initialize everything and then write assembler ( could be useful next)

	// for(int i=0; i<length; i++){
	// 	Var current = vars.at(i).second;
	// 	if(current.isSimple){
	// 		std::cout<<"	movl	$"<<current.val<<", "<<(-(i+1)*4)<<"(%rbp)\n";
	// 	}
	// 	else{
	// 		cout <<"	movl	"<<offsets[current.var]<<"(%rbp), %eax"<<"\n";
			
	// 		cout<<"	movl	%eax, "<<(-(i+1)*4)<<"(%rbp)\n";
	// 	}
	// }

		std::cout<<
		"	\n	# epilogue\n"
		"	popq %rbp\n"
		" 	ret\n";

	return 0;
}

