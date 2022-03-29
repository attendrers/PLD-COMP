.globl	main
 main: 
	# prologue
	pushq %rbp
	movq %rsp, %rbp

	movl	$5, -4(%rbp)
	movl	$10, -8(%rbp)
	# Expression here
        movl    -4(%rbp), %edx
        movl    -8(%rbp), %eax
        addl	%edx, %eax
	movl	%eax, -12(%rbp)
	# Expression here
        movl    -4(%rbp), %edx
        movl    $5, %eax
        addl	%edx, %eax
	movl	%eax, -16(%rbp)
	# Expression here
        movl    -4(%rbp), %edx
        movl    -8(%rbp), %eax
        addl	%edx, %eax
        movl    %eax, %edx
        movl    $10, %eax
        addl	%edx, %eax
        movl    %eax, %edx
        movl    -12(%rbp), %eax
        addl	%edx, %eax
        movl    %eax, %edx
        movl    $4, %eax
        addl	%edx, %eax
        movl    %eax, %edx
        movl    -16(%rbp), %eax
        addl	%edx, %eax
	movl	%eax, -20(%rbp)
	movl	-12(%rbp), %eax
	
	# epilogue
	popq %rbp
 	ret
