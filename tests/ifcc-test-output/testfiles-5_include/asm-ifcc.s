.globl	main
 main: 
	# prologue
	pushq %rbp
	movq %rsp, %rbp
 	movl	$0, %eax
	#epilogue
	popq %rbp
 	ret
