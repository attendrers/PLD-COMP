.globl	main
 main: 
	# prologue
	pushq %rbp
	movq %rsp, %rbp

 	movl	$42, %eax
	
	# epilogue
	popq %rbp
 	ret
