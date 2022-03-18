#include "CodeGenVisitor.h"

antlrcpp::Any CodeGenVisitor::visitProg(ifccParser::ProgContext *ctx) 
{
	int retval = stoi(ctx->CONST()->getText());
	std::cout<<".globl	main\n"
		" main: \n"
		"   # prologue\n"
		"   pushq %rbp\n"
		"   movq %rsp, %rbp\n\n"
		"   # body\n"
		"   movl	$"<<retval<<", %eax\n\n"
		"   # epilogue\n"
		"   popq %rbp\n"
		"   ret\n";

	return 0;
}

