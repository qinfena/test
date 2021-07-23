	.type fgoto. @function
fgoto:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$48, %rsp
	movl	%edi, -36(%rbp)
	movl	$0, -4(%rbp)
	movq	$0, -16(%rbp)
.L_AGAIN:
	cmpq	$0, -16(%rbp)
	je 	.L_ELSE
	movq 	-16(%rbp), %rax
	movl 	(%rax), %edx
	movq 	-24(%rbp), %rax
	cmpq 	-16(%rbp), %rax
	jne	.L_YES
	movl 	$.L_STR_EQ, %eax
	jmp 	.L_NO
.L_YES:
	movl 	$.L_STR_NE, %eax
.L_NO:
	movl 	-4(%rbp), %esi
	movl  	%edx, %ecx
	movq 	%rax, %rdx
	movl 	$.L_STR_FRMT, %edi
	movl 	$0, %eax
	call 	printf
.L_ELSE:
	movq 	-16(%rbp), %rax
	movq 	%rax, -24(%rbp)
	movl 	-4(%rbp), %eax
	movl 	%eax, -28(%rbp)
	leaq 	-28(%rbp), %rax
	movq 	%rax, -16(%rbp)
	addl 	$1, -4(%rbp)
	movl 	-4(%rbp), %eax
	cmpl 	-36(%rbp), %eax
	jbe 	.L_AGAIN
	leave
	ret
