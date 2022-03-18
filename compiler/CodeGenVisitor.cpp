#include "CodeGenVisitor.h"
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
	for(int i=0; i<ctx->line().size(); i++){
		ifccParser::LineContext * current = ctx->line().at(i);
		// We are in a declaration line
		if(current->RETURN()==nullptr){
			// Case int a = 5 ; 
			if(current->ALPHANUMERIC().size()==1){
				string varName = current->ALPHANUMERIC().at(0)->getText();
				int varValue = stoi(current->CONST()->getText());
				vars.push_back(make_pair(varName,Var(varValue)));
			}
			// Case int b = a;
			else{
				string leftVar = current->ALPHANUMERIC().at(1)->getText(); 
				string rightVar= current->ALPHANUMERIC().at(0)->getText();
				vars.push_back(make_pair(rightVar,Var(leftVar)));
				
			}
			
	
		}

		// We are in a return line
		else{
			retval = stoi(current->CONST()->getText());
		}
	}

	int length = vars.size();
	unordered_map <string,int> offsets;
	for(int i=0; i<length; i++){
		// cout<<vars.at(i).first<<" "<<(i-length)*4<<endl;
		offsets[vars.at(i).first] = (i-length)*4;
	}
	std::cout<<".globl	main\n"
		" main: \n"

		"	# prologue\n"
		"	pushq %rbp\n"
		"	movq %rsp, %rbp\n";
	for(int i=0; i<length; i++){
		Var current = vars.at(i).second;
		if(current.isSimple){
			std::cout<<"	movl	$"<<current.val<<", "<<(i-length)*4<<"(%rbp)\n";
		}
		else{
			cout <<"	movl	"<<offsets[current.var]<<"(%rbp), %eax"<<"\n";
			
			cout<<"	movl	%eax, "<<(i-length)*4<<"(%rbp)\n";
		}
	}

		std::cout<<

		" 	movl	$"<<retval<<", %eax\n"

		"	#epilogue\n"
		"	popq %rbp\n"
		" 	ret\n";

	return 0;
}

