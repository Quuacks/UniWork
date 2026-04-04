	.file	"file.c"
	.text
	.globl	saveCount
	.bss
	.align 4
saveCount:
	.space 4
	.globl	loadCount
	.align 4
loadCount:
	.space 4
	.section .rdata,"dr"
.LC0:
	.ascii "rb\0"
.LC1:
	.ascii "Failed to open file\0"
.LC2:
	.ascii "LoadFromFile array size <= 0\0"
.LC3:
	.ascii "Memory alocation failed\0"
.LC4:
	.ascii "Failed to read array\0"
	.text
	.globl	loadFromFile
	.def	loadFromFile;	.scl	2;	.type	32;	.endef
	.seh_proc	loadFromFile
loadFromFile:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	%r8, 32(%rbp)
	leaq	.LC0(%rip), %rdx
	movq	16(%rbp), %rax
	movq	%rax, %rcx
	call	fopen
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L2
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	$-1, %eax
	jmp	.L3
.L2:
	movq	-8(%rbp), %rdx
	movq	32(%rbp), %rax
	movq	%rdx, %r9
	movl	$1, %r8d
	movl	$4, %edx
	movq	%rax, %rcx
	call	fread
	cmpq	$1, %rax
	je	.L4
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	movl	$-1, %eax
	jmp	.L3
.L4:
	movq	32(%rbp), %rax
	movl	(%rax), %eax
	testl	%eax, %eax
	jg	.L5
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	$-1, %eax
	jmp	.L3
.L5:
	movq	32(%rbp), %rax
	movl	(%rax), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rcx
	call	malloc
	movq	%rax, %rdx
	movq	24(%rbp), %rax
	movq	%rdx, (%rax)
	movq	24(%rbp), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	jne	.L6
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	leaq	.LC3(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	$-1, %eax
	jmp	.L3
.L6:
	movq	32(%rbp), %rax
	movl	(%rax), %eax
	movslq	%eax, %rdx
	movq	24(%rbp), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rcx
	movq	%rcx, %r9
	movq	%rdx, %r8
	movl	$4, %edx
	movq	%rax, %rcx
	call	fread
	movq	%rax, %rdx
	movq	32(%rbp), %rax
	movl	(%rax), %eax
	cltq
	cmpq	%rax, %rdx
	je	.L7
	movq	24(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rcx
	call	free
	movq	24(%rbp), %rax
	movq	$0, (%rax)
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	leaq	.LC4(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	$-1, %eax
	jmp	.L3
.L7:
	movl	loadCount(%rip), %eax
	addl	$1, %eax
	movl	%eax, loadCount(%rip)
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	movl	$0, %eax
.L3:
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC5:
	.ascii "wb\0"
.LC6:
	.ascii "Error writing array size\0"
.LC7:
	.ascii "Failled writing array\0"
	.text
	.globl	saveToFile
	.def	saveToFile;	.scl	2;	.type	32;	.endef
	.seh_proc	saveToFile
saveToFile:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movl	%r8d, 32(%rbp)
	leaq	.LC5(%rip), %rdx
	movq	16(%rbp), %rax
	movq	%rax, %rcx
	call	fopen
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L9
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	$-1, %eax
	jmp	.L10
.L9:
	movq	-8(%rbp), %rdx
	leaq	32(%rbp), %rax
	movq	%rdx, %r9
	movl	$1, %r8d
	movl	$4, %edx
	movq	%rax, %rcx
	call	fwrite
	cmpq	$1, %rax
	je	.L11
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	leaq	.LC6(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	$-1, %eax
	jmp	.L10
.L11:
	movl	32(%rbp), %eax
	movslq	%eax, %rdx
	movq	-8(%rbp), %rcx
	movq	24(%rbp), %rax
	movq	%rcx, %r9
	movq	%rdx, %r8
	movl	$4, %edx
	movq	%rax, %rcx
	call	fwrite
	movq	%rax, %rdx
	movl	32(%rbp), %eax
	cltq
	cmpq	%rax, %rdx
	je	.L12
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	leaq	.LC7(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	$-1, %eax
	jmp	.L10
.L12:
	movl	saveCount(%rip), %eax
	addl	$1, %eax
	movl	%eax, saveCount(%rip)
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	movl	$0, %eax
.L10:
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (MinGW-W64 x86_64-ucrt-posix-seh, built by Brecht Sanders, r1) 15.2.0"
	.def	fopen;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	fread;	.scl	2;	.type	32;	.endef
	.def	fclose;	.scl	2;	.type	32;	.endef
	.def	malloc;	.scl	2;	.type	32;	.endef
	.def	free;	.scl	2;	.type	32;	.endef
	.def	fwrite;	.scl	2;	.type	32;	.endef
