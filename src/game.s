	.file	"game.c"
	.text
	.globl	Board
	.bss
	.align 32
	.type	Board, @object
	.size	Board, 42
Board:
	.zero	42
	.globl	DiscsPerIndex
	.align 16
	.type	DiscsPerIndex, @object
	.size	DiscsPerIndex, 28
DiscsPerIndex:
	.zero	28
	.globl	playerA
	.data
	.type	playerA, @object
	.size	playerA, 1
playerA:
	.byte	65
	.globl	playerB
	.type	playerB, @object
	.size	playerB, 1
playerB:
	.byte	66
	.globl	currentPlayer
	.type	currentPlayer, @object
	.size	currentPlayer, 1
currentPlayer:
	.byte	65
	.section	.rodata
	.align 8
.LC0:
	.string	"Welcome to Connect Four!\nPlayer A: "
.LC1:
	.string	" %c"
.LC2:
	.string	"Player B: "
	.align 8
.LC3:
	.string	"Player B cannot be the same as Player A.\nEnter again: "
	.text
	.globl	InitializeGame
	.type	InitializeGame, @function
InitializeGame:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	playerA(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movzbl	playerA(%rip), %eax
	movsbl	%al, %eax
	movl	%eax, %edi
	call	toupper@PLT
	movb	%al, playerA(%rip)
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	playerB(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movzbl	playerB(%rip), %eax
	movsbl	%al, %eax
	movl	%eax, %edi
	call	toupper@PLT
	movb	%al, playerB(%rip)
	jmp	.L2
.L3:
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	playerB(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movzbl	playerB(%rip), %eax
	movsbl	%al, %eax
	movl	%eax, %edi
	call	toupper@PLT
	movb	%al, playerB(%rip)
.L2:
	movzbl	playerA(%rip), %edx
	movzbl	playerB(%rip), %eax
	cmpb	%al, %dl
	je	.L3
	movzbl	playerA(%rip), %eax
	movb	%al, currentPlayer(%rip)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	initializeBoard
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	Display
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	InitializeGame, .-InitializeGame
	.globl	initializeBoard
	.type	initializeBoard, @function
initializeBoard:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L5
.L8:
	movl	$0, -4(%rbp)
	jmp	.L6
.L7:
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$3, %rax
	subq	%rdx, %rax
	movq	%rax, %rcx
	movq	-24(%rbp), %rax
	leaq	(%rcx,%rax), %rdx
	movl	-4(%rbp), %eax
	cltq
	movb	$46, (%rdx,%rax)
	addl	$1, -4(%rbp)
.L6:
	cmpl	$6, -4(%rbp)
	jle	.L7
	addl	$1, -8(%rbp)
.L5:
	cmpl	$5, -8(%rbp)
	jle	.L8
	nop
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	initializeBoard, .-initializeBoard
	.section	.rodata
.LC4:
	.string	"%c "
.LC5:
	.string	"1 2 3 4 5 6 7"
	.text
	.globl	Display
	.type	Display, @function
Display:
.LFB8:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L10
.L13:
	movl	$0, -4(%rbp)
	jmp	.L11
.L12:
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$3, %rax
	subq	%rdx, %rax
	movq	%rax, %rcx
	movq	-24(%rbp), %rax
	leaq	(%rcx,%rax), %rdx
	movl	-4(%rbp), %eax
	cltq
	movzbl	(%rdx,%rax), %eax
	movsbl	%al, %eax
	movl	%eax, %esi
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -4(%rbp)
.L11:
	cmpl	$6, -4(%rbp)
	jle	.L12
	movl	$10, %edi
	call	putchar@PLT
	addl	$1, -8(%rbp)
.L10:
	cmpl	$5, -8(%rbp)
	jle	.L13
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	Display, .-Display
	.globl	MakeMove
	.type	MakeMove, @function
MakeMove:
.LFB9:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	addl	$1, -28(%rbp)
	cmpl	$0, -28(%rbp)
	jle	.L15
	cmpl	$7, -28(%rbp)
	jle	.L16
.L15:
	movl	$-1, %eax
	jmp	.L17
.L16:
	movl	-28(%rbp), %eax
	subl	$1, %eax
	movl	%eax, -8(%rbp)
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	DiscsPerIndex(%rip), %rax
	movl	(%rdx,%rax), %eax
	cmpl	$5, %eax
	jle	.L18
	movl	$-2, %eax
	jmp	.L17
.L18:
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	DiscsPerIndex(%rip), %rax
	movl	(%rdx,%rax), %eax
	movl	$5, %edx
	subl	%eax, %edx
	movl	%edx, -4(%rbp)
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$3, %rax
	subq	%rdx, %rax
	movq	%rax, %rcx
	movq	-24(%rbp), %rax
	addq	%rax, %rcx
	movzbl	currentPlayer(%rip), %edx
	movl	-8(%rbp), %eax
	cltq
	movb	%dl, (%rcx,%rax)
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	DiscsPerIndex(%rip), %rax
	movl	(%rdx,%rax), %eax
	leal	1(%rax), %ecx
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	DiscsPerIndex(%rip), %rax
	movl	%ecx, (%rdx,%rax)
	movl	$0, %eax
.L17:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	MakeMove, .-MakeMove
	.globl	CheckWin
	.type	CheckWin, @function
CheckWin:
.LFB10:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -40(%rbp)
	movl	%esi, %eax
	movb	%al, -44(%rbp)
	movl	$0, -32(%rbp)
	jmp	.L20
.L25:
	movl	$0, -28(%rbp)
	jmp	.L21
.L24:
	movl	-32(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$3, %rax
	subq	%rdx, %rax
	movq	%rax, %rcx
	movq	-40(%rbp), %rax
	leaq	(%rcx,%rax), %rdx
	movl	-28(%rbp), %eax
	cltq
	movzbl	(%rdx,%rax), %eax
	cmpb	%al, -44(%rbp)
	jne	.L22
	movl	-32(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$3, %rax
	subq	%rdx, %rax
	movq	%rax, %rcx
	movq	-40(%rbp), %rax
	leaq	(%rcx,%rax), %rdx
	movl	-28(%rbp), %eax
	addl	$1, %eax
	cltq
	movzbl	(%rdx,%rax), %eax
	cmpb	%al, -44(%rbp)
	jne	.L22
	movl	-32(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$3, %rax
	subq	%rdx, %rax
	movq	%rax, %rcx
	movq	-40(%rbp), %rax
	leaq	(%rcx,%rax), %rdx
	movl	-28(%rbp), %eax
	addl	$2, %eax
	cltq
	movzbl	(%rdx,%rax), %eax
	cmpb	%al, -44(%rbp)
	jne	.L22
	movl	-32(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$3, %rax
	subq	%rdx, %rax
	movq	%rax, %rcx
	movq	-40(%rbp), %rax
	leaq	(%rcx,%rax), %rdx
	movl	-28(%rbp), %eax
	addl	$3, %eax
	cltq
	movzbl	(%rdx,%rax), %eax
	cmpb	%al, -44(%rbp)
	jne	.L22
	movl	$1, %eax
	jmp	.L23
.L22:
	addl	$1, -28(%rbp)
.L21:
	cmpl	$3, -28(%rbp)
	jle	.L24
	addl	$1, -32(%rbp)
.L20:
	cmpl	$5, -32(%rbp)
	jle	.L25
	movl	$0, -24(%rbp)
	jmp	.L26
.L30:
	movl	$0, -20(%rbp)
	jmp	.L27
.L29:
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$3, %rax
	subq	%rdx, %rax
	movq	%rax, %rcx
	movq	-40(%rbp), %rax
	leaq	(%rcx,%rax), %rdx
	movl	-24(%rbp), %eax
	cltq
	movzbl	(%rdx,%rax), %eax
	cmpb	%al, -44(%rbp)
	jne	.L28
	movl	-20(%rbp), %eax
	cltq
	leaq	1(%rax), %rdx
	movq	%rdx, %rax
	salq	$3, %rax
	subq	%rdx, %rax
	movq	%rax, %rcx
	movq	-40(%rbp), %rax
	leaq	(%rcx,%rax), %rdx
	movl	-24(%rbp), %eax
	cltq
	movzbl	(%rdx,%rax), %eax
	cmpb	%al, -44(%rbp)
	jne	.L28
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$3, %rax
	subq	%rdx, %rax
	leaq	14(%rax), %rdx
	movq	-40(%rbp), %rax
	addq	%rax, %rdx
	movl	-24(%rbp), %eax
	cltq
	movzbl	(%rdx,%rax), %eax
	cmpb	%al, -44(%rbp)
	jne	.L28
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$3, %rax
	subq	%rdx, %rax
	leaq	21(%rax), %rdx
	movq	-40(%rbp), %rax
	addq	%rax, %rdx
	movl	-24(%rbp), %eax
	cltq
	movzbl	(%rdx,%rax), %eax
	cmpb	%al, -44(%rbp)
	jne	.L28
	movl	$1, %eax
	jmp	.L23
.L28:
	addl	$1, -20(%rbp)
.L27:
	cmpl	$2, -20(%rbp)
	jle	.L29
	addl	$1, -24(%rbp)
.L26:
	cmpl	$6, -24(%rbp)
	jle	.L30
	movl	$0, -16(%rbp)
	jmp	.L31
.L35:
	movl	$0, -12(%rbp)
	jmp	.L32
.L34:
	movl	-16(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$3, %rax
	subq	%rdx, %rax
	movq	%rax, %rcx
	movq	-40(%rbp), %rax
	leaq	(%rcx,%rax), %rdx
	movl	-12(%rbp), %eax
	cltq
	movzbl	(%rdx,%rax), %eax
	cmpb	%al, -44(%rbp)
	jne	.L33
	movl	-16(%rbp), %eax
	cltq
	leaq	1(%rax), %rdx
	movq	%rdx, %rax
	salq	$3, %rax
	subq	%rdx, %rax
	movq	%rax, %rcx
	movq	-40(%rbp), %rax
	leaq	(%rcx,%rax), %rdx
	movl	-12(%rbp), %eax
	addl	$1, %eax
	cltq
	movzbl	(%rdx,%rax), %eax
	cmpb	%al, -44(%rbp)
	jne	.L33
	movl	-16(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$3, %rax
	subq	%rdx, %rax
	leaq	14(%rax), %rdx
	movq	-40(%rbp), %rax
	addq	%rax, %rdx
	movl	-12(%rbp), %eax
	addl	$2, %eax
	cltq
	movzbl	(%rdx,%rax), %eax
	cmpb	%al, -44(%rbp)
	jne	.L33
	movl	-16(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$3, %rax
	subq	%rdx, %rax
	leaq	21(%rax), %rdx
	movq	-40(%rbp), %rax
	addq	%rax, %rdx
	movl	-12(%rbp), %eax
	addl	$3, %eax
	cltq
	movzbl	(%rdx,%rax), %eax
	cmpb	%al, -44(%rbp)
	jne	.L33
	movl	$1, %eax
	jmp	.L23
.L33:
	addl	$1, -12(%rbp)
.L32:
	cmpl	$3, -12(%rbp)
	jle	.L34
	addl	$1, -16(%rbp)
.L31:
	cmpl	$2, -16(%rbp)
	jle	.L35
	movl	$0, -8(%rbp)
	jmp	.L36
.L40:
	movl	$3, -4(%rbp)
	jmp	.L37
.L39:
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$3, %rax
	subq	%rdx, %rax
	movq	%rax, %rcx
	movq	-40(%rbp), %rax
	leaq	(%rcx,%rax), %rdx
	movl	-4(%rbp), %eax
	cltq
	movzbl	(%rdx,%rax), %eax
	cmpb	%al, -44(%rbp)
	jne	.L38
	movl	-8(%rbp), %eax
	cltq
	leaq	1(%rax), %rdx
	movq	%rdx, %rax
	salq	$3, %rax
	subq	%rdx, %rax
	movq	%rax, %rcx
	movq	-40(%rbp), %rax
	leaq	(%rcx,%rax), %rdx
	movl	-4(%rbp), %eax
	subl	$1, %eax
	cltq
	movzbl	(%rdx,%rax), %eax
	cmpb	%al, -44(%rbp)
	jne	.L38
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$3, %rax
	subq	%rdx, %rax
	leaq	14(%rax), %rdx
	movq	-40(%rbp), %rax
	addq	%rax, %rdx
	movl	-4(%rbp), %eax
	subl	$2, %eax
	cltq
	movzbl	(%rdx,%rax), %eax
	cmpb	%al, -44(%rbp)
	jne	.L38
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$3, %rax
	subq	%rdx, %rax
	leaq	21(%rax), %rdx
	movq	-40(%rbp), %rax
	addq	%rax, %rdx
	movl	-4(%rbp), %eax
	subl	$3, %eax
	cltq
	movzbl	(%rdx,%rax), %eax
	cmpb	%al, -44(%rbp)
	jne	.L38
	movl	$1, %eax
	jmp	.L23
.L38:
	addl	$1, -4(%rbp)
.L37:
	cmpl	$6, -4(%rbp)
	jle	.L39
	addl	$1, -8(%rbp)
.L36:
	cmpl	$2, -8(%rbp)
	jle	.L40
	movl	$0, %eax
.L23:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	CheckWin, .-CheckWin
	.globl	FullBoard
	.type	FullBoard, @function
FullBoard:
.LFB11:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L42
.L45:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	DiscsPerIndex(%rip), %rax
	movl	(%rdx,%rax), %eax
	cmpl	$5, %eax
	jg	.L43
	movl	$0, %eax
	jmp	.L44
.L43:
	addl	$1, -4(%rbp)
.L42:
	cmpl	$6, -4(%rbp)
	jle	.L45
	movl	$1, %eax
.L44:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	FullBoard, .-FullBoard
	.globl	SwitchPlayer
	.type	SwitchPlayer, @function
SwitchPlayer:
.LFB12:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movl	%esi, %ecx
	movl	%edx, %eax
	movl	%ecx, %edx
	movb	%dl, -12(%rbp)
	movb	%al, -16(%rbp)
	movq	-8(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	%al, -12(%rbp)
	jne	.L47
	movq	-8(%rbp), %rax
	movzbl	-16(%rbp), %edx
	movb	%dl, (%rax)
	jmp	.L49
.L47:
	movq	-8(%rbp), %rax
	movzbl	-12(%rbp), %edx
	movb	%dl, (%rax)
.L49:
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	SwitchPlayer, .-SwitchPlayer
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
