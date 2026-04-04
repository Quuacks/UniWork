	.file	"main.c"
	.text
	.globl	fillArray
	.def	fillArray;	.scl	2;	.type	32;	.endef
	.seh_proc	fillArray
fillArray:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L2
.L3:
	call	rand
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,4), %rcx
	movq	16(%rbp), %rdx
	leaq	(%rcx,%rdx), %r8
	movslq	%eax, %rdx
	imulq	$1374389535, %rdx, %rdx
	shrq	$32, %rdx
	sarl	$5, %edx
	movl	%eax, %ecx
	sarl	$31, %ecx
	subl	%ecx, %edx
	imull	$100, %edx, %ecx
	subl	%ecx, %eax
	movl	%eax, %edx
	movl	%edx, (%r8)
	addl	$1, -4(%rbp)
.L2:
	movl	-4(%rbp), %eax
	cmpl	24(%rbp), %eax
	jl	.L3
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "%d \0"
	.text
	.globl	printArray
	.def	printArray;	.scl	2;	.type	32;	.endef
	.seh_proc	printArray
printArray:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L5
.L6:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	leaq	.LC0(%rip), %rcx
	movl	%eax, %edx
	call	printf
	addl	$1, -4(%rbp)
.L5:
	movl	-4(%rbp), %eax
	cmpl	24(%rbp), %eax
	jl	.L6
	movl	$10, %ecx
	call	putchar
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	compareArrays
	.def	compareArrays;	.scl	2;	.type	32;	.endef
	.seh_proc	compareArrays
compareArrays:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movl	%r8d, 32(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L8
.L11:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	movq	24(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	je	.L9
	movl	$0, %eax
	jmp	.L10
.L9:
	addl	$1, -4(%rbp)
.L8:
	movl	-4(%rbp), %eax
	cmpl	32(%rbp), %eax
	jl	.L11
	movl	$1, %eax
.L10:
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC1:
	.ascii "Memory alocation failed \0"
.LC2:
	.ascii "Array m1:\0"
.LC3:
	.ascii "Array m2:\0"
.LC4:
	.ascii "Array m3:\0"
.LC5:
	.ascii "Array saved to file\0"
.LC6:
	.ascii "Failed SaveToFile\0"
	.align 8
.LC7:
	.ascii "Failed to load array from file\0"
.LC8:
	.ascii "All good\0"
.LC9:
	.ascii "something's wrong\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$208, %rsp
	.seh_stackalloc	208
	.seh_endprologue
	call	__main
	movl	$0, %ecx
	call	_time64
	movl	%eax, %ecx
	call	srand
	movl	$10, -4(%rbp)
	movabsq	$7955998168388756852, %rax
	movl	$0, %edx
	movq	%rax, -80(%rbp)
	movq	%rdx, -72(%rbp)
	movq	$0, -64(%rbp)
	movq	$0, -56(%rbp)
	movq	$0, -48(%rbp)
	movq	$0, -40(%rbp)
	movq	$0, -32(%rbp)
	movq	$0, -24(%rbp)
	movabsq	$8675433107503477871, %rax
	movabsq	$474214444660, %rdx
	movq	%rax, -144(%rbp)
	movq	%rdx, -136(%rbp)
	movq	$0, -128(%rbp)
	movq	$0, -120(%rbp)
	movq	$0, -112(%rbp)
	movq	$0, -104(%rbp)
	movq	$0, -96(%rbp)
	movq	$0, -88(%rbp)
	movl	-4(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rcx
	call	malloc
	movq	%rax, -152(%rbp)
	movl	-4(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rcx
	call	malloc
	movq	%rax, -160(%rbp)
	movl	-4(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rcx
	call	malloc
	movq	%rax, -168(%rbp)
	movq	-152(%rbp), %rax
	testq	%rax, %rax
	je	.L13
	movq	-160(%rbp), %rax
	testq	%rax, %rax
	je	.L13
	movq	-168(%rbp), %rax
	testq	%rax, %rax
	jne	.L14
.L13:
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	$-1, %eax
	jmp	.L27
.L14:
	movq	-152(%rbp), %rax
	movl	-4(%rbp), %edx
	movq	%rax, %rcx
	call	fillArray
	movq	-160(%rbp), %rax
	movl	-4(%rbp), %edx
	movq	%rax, %rcx
	call	fillArray
	movq	-168(%rbp), %rax
	movl	-4(%rbp), %edx
	movq	%rax, %rcx
	call	fillArray
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	puts
	movq	-152(%rbp), %rax
	movl	-4(%rbp), %edx
	movq	%rax, %rcx
	call	printArray
	leaq	.LC3(%rip), %rax
	movq	%rax, %rcx
	call	puts
	movq	-160(%rbp), %rax
	movl	-4(%rbp), %edx
	movq	%rax, %rcx
	call	printArray
	leaq	.LC4(%rip), %rax
	movq	%rax, %rcx
	call	puts
	movq	-168(%rbp), %rax
	movl	-4(%rbp), %edx
	movq	%rax, %rcx
	call	printArray
	movq	-152(%rbp), %rdx
	movl	-4(%rbp), %ecx
	leaq	-80(%rbp), %rax
	movl	%ecx, %r8d
	movq	%rax, %rcx
	call	saveToFile
	testl	%eax, %eax
	jne	.L16
	leaq	.LC5(%rip), %rax
	movq	%rax, %rcx
	call	puts
	movq	-168(%rbp), %rdx
	movl	-4(%rbp), %ecx
	leaq	-80(%rbp), %rax
	movl	%ecx, %r8d
	movq	%rax, %rcx
	call	saveToFile
	testl	%eax, %eax
	jne	.L18
	jmp	.L28
.L16:
	leaq	.LC6(%rip), %rax
	movq	%rax, %rcx
	call	puts
	movl	$-1, %eax
	jmp	.L27
.L28:
	leaq	.LC5(%rip), %rax
	movq	%rax, %rcx
	call	puts
	movl	$0, -172(%rbp)
	leaq	-172(%rbp), %rcx
	leaq	-152(%rbp), %rdx
	leaq	-80(%rbp), %rax
	movq	%rcx, %r8
	movq	%rax, %rcx
	call	loadFromFile
	testl	%eax, %eax
	je	.L20
	jmp	.L29
.L18:
	leaq	.LC6(%rip), %rax
	movq	%rax, %rcx
	call	puts
	movl	$-1, %eax
	jmp	.L27
.L29:
	leaq	.LC7(%rip), %rax
	movq	%rax, %rcx
	call	puts
	movl	$-1, %eax
	jmp	.L27
.L20:
	movq	-160(%rbp), %rdx
	movl	-4(%rbp), %ecx
	leaq	-144(%rbp), %rax
	movl	%ecx, %r8d
	movq	%rax, %rcx
	call	saveToFile
	testl	%eax, %eax
	jne	.L21
	leaq	.LC5(%rip), %rax
	movq	%rax, %rcx
	call	puts
	leaq	-172(%rbp), %rcx
	leaq	-168(%rbp), %rdx
	leaq	-80(%rbp), %rax
	movq	%rcx, %r8
	movq	%rax, %rcx
	call	loadFromFile
	testl	%eax, %eax
	je	.L23
	jmp	.L30
.L21:
	leaq	.LC6(%rip), %rax
	movq	%rax, %rcx
	call	puts
	movl	$-1, %eax
	jmp	.L27
.L30:
	leaq	.LC7(%rip), %rax
	movq	%rax, %rcx
	call	puts
	movl	$-1, %eax
	jmp	.L27
.L23:
	leaq	-172(%rbp), %rcx
	leaq	-160(%rbp), %rdx
	leaq	-144(%rbp), %rax
	movq	%rcx, %r8
	movq	%rax, %rcx
	call	loadFromFile
	testl	%eax, %eax
	je	.L24
	leaq	.LC7(%rip), %rax
	movq	%rax, %rcx
	call	puts
	movl	$-1, %eax
	jmp	.L27
.L24:
	movq	.refptr.saveCount(%rip), %rax
	movl	(%rax), %eax
	cmpl	$3, %eax
	jne	.L25
	movq	.refptr.loadCount(%rip), %rax
	movl	(%rax), %eax
	cmpl	$3, %eax
	jne	.L25
	leaq	.LC8(%rip), %rax
	movq	%rax, %rcx
	call	puts
	jmp	.L26
.L25:
	leaq	.LC9(%rip), %rax
	movq	%rax, %rcx
	call	puts
.L26:
	movq	-152(%rbp), %rax
	movq	%rax, %rcx
	call	free
	movq	-160(%rbp), %rax
	movq	%rax, %rcx
	call	free
	movl	$-1, %eax
.L27:
	addq	$208, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (MinGW-W64 x86_64-ucrt-posix-seh, built by Brecht Sanders, r1) 15.2.0"
	.def	rand;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	putchar;	.scl	2;	.type	32;	.endef
	.def	srand;	.scl	2;	.type	32;	.endef
	.def	malloc;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	saveToFile;	.scl	2;	.type	32;	.endef
	.def	loadFromFile;	.scl	2;	.type	32;	.endef
	.def	free;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr.loadCount, "dr"
	.p2align	3, 0
	.globl	.refptr.loadCount
	.linkonce	discard
.refptr.loadCount:
	.quad	loadCount
	.section	.rdata$.refptr.saveCount, "dr"
	.p2align	3, 0
	.globl	.refptr.saveCount
	.linkonce	discard
.refptr.saveCount:
	.quad	saveCount
