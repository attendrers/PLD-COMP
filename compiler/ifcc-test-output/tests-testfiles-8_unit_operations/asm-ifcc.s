.globl	main
 main: 
	# prologue
	pushq %rbp
	movq %rsp, %rbp

	movl	$5, -4(%rbp)
	movl	$10, -8(%rbp)
	movl	$0, -12(%rbp)
	# Expression here
        movl    -4(%rbp), %eax
        negl	%eax
        movl    %eax, %edx
        movl    -8(%rbp), %eax
        addl	%edx, %eax
	movl	%eax, -16(%rbp)
	# Expression here
        cmpl	$0, -12(%rbp)
        sete	%al
        movzbl	%al, %eax
        movl    %eax, %edx
        movl    -8(%rbp), %eax
        addl	%edx, %eax
	movl	%eax, -20(%rbp)
	# Expression here
        movl    -16(%rbp), %edx
        movl    -20(%rbp), %eax
        addl	%edx, %eax
	movl	%eax, -24(%rbp)
	movl	-24(%rbp), %eax
	
	# epilogue
	popq %rbp
 	ret
