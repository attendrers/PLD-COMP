.globl	main
 main: 
	# prologue
	pushq %rbp
	movq %rsp, %rbp

	movl	$5, -4(%rbp)
	movl	$0, -8(%rbp)
	movl	$10, -12(%rbp)
	movl	$20, -16(%rbp)
	movl	$4, -20(%rbp)
	movl	-24(%rbp), %eax
		movl	%eax, -24(%rbp)
	movl	-28(%rbp), %eax
		movl	%eax, -28(%rbp)
	movl	-32(%rbp), %eax
		movl	%eax, -32(%rbp)
 	movl	$30, %eax
	
	# epilogue
	popq %rbp
 	ret
