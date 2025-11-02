	.file	"main.c"
	.text
	.section	.rodata
	.align 8
.LC0:
	.string	"Player %c, choose a column (1-7): "
.LC1:
	.string	"%d"
.LC2:
	.string	"Invalid column."
	.align 8
.LC3:
	.string	"Column %d is full. Try another.\n"
.LC4:
	.string	"It is a draw!"
.LC5:
	.string	"Player %c wins!\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	Board(%rip), %rax
	movq	%rax, %rdi
	call	InitializeGame@PLT
.L10:
	movzbl	currentPlayer(%rip), %eax
	movsbl	%al, %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-16(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %esi
	leaq	Board(%rip), %rax
	movq	%rax, %rdi
	call	MakeMove@PLT
	movl	%eax, -12(%rbp)
	cmpl	$-1, -12(%rbp)
	jne	.L2
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	jmp	.L8
.L2:
	cmpl	$-2, -12(%rbp)
	jne	.L4
	movl	-16(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L8
.L4:
	leaq	Board(%rip), %rax
	movq	%rax, %rdi
	call	Display@PLT
	leaq	Board(%rip), %rax
	movq	%rax, %rdi
	call	FullBoard@PLT
	testl	%eax, %eax
	je	.L5
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	jmp	.L6
.L5:
	movzbl	currentPlayer(%rip), %eax
	movsbl	%al, %eax
	movl	%eax, %esi
	leaq	Board(%rip), %rax
	movq	%rax, %rdi
	call	CheckWin@PLT
	testl	%eax, %eax
	je	.L7
	movzbl	currentPlayer(%rip), %eax
	movsbl	%al, %eax
	movl	%eax, %esi
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L6
.L7:
	movzbl	playerB(%rip), %eax
	movsbl	%al, %edx
	movzbl	playerA(%rip), %eax
	movsbl	%al, %eax
	movl	%eax, %esi
	leaq	currentPlayer(%rip), %rax
	movq	%rax, %rdi
	call	SwitchPlayer@PLT
	jmp	.L10
.L6:
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L11
	jmp	.L12
.L8:
	jmp	.L10
.L12:
	call	__stack_chk_fail@PLT
.L11:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
