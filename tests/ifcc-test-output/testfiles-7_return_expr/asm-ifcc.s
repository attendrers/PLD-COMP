.globl	main
 main: 
	# prologue
	pushq %rbp
	movq %rsp, %rbp

	movl	$5, -4(%rbp)
	movl	$10, -8(%rbp)
        movl    -4(%rbp), %edx
        movl    -8(%rbp), %eax
        addl	%edx, %eax
	
	# epilogue
	popq %rbp
 	ret
