.globl	main
 main: 
	# prologue
	pushq %rbp
	movq %rsp, %rbp

	# Expression here
        movl    $5, %edx
        movl    $10, %eax
        imul	%edx, %eax
	movl	%eax, -4(%rbp)
	# Expression here
        movl    $42, %eax
        cltd
        movl    $3, %ebx
        idivl	%ebx 
	movl	%eax, -8(%rbp)
	# Expression here
        movl    -4(%rbp), %edx
        movl    -8(%rbp), %eax
        subl	%edx, %eax
	movl	%eax, -12(%rbp)
	# Expression here
        movl    -4(%rbp), %eax
        cltd
        movl    -8(%rbp), %ebx
        idivl	%ebx 
	movl	%eax, -16(%rbp)
	# Expression here
        movl    $45, %edx
        movl    -16(%rbp), %eax
        subl	%edx, %eax
	movl	%eax, -20(%rbp)
	# Expression here
        movl    $2, %edx
        movl    -16(%rbp), %eax
        imul	%edx, %eax
        movl    %eax, %edx
        movl    -20(%rbp), %eax
        addl	%edx, %eax
        movl    %eax, %edx
        movl    -4(%rbp), %eax
        subl	%edx, %eax
	movl	%eax, -24(%rbp)
	movl	-16(%rbp), %eax
	
	# epilogue
	popq %rbp
 	ret
