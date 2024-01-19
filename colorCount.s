	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 13, 1
	.globl	_red                            ## -- Begin function red
	.p2align	4, 0x90
_red:                                   ## @red
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_printf
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_green                          ## -- Begin function green
	.p2align	4, 0x90
_green:                                 ## @green
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_reset                          ## -- Begin function reset
	.p2align	4, 0x90
_reset:                                 ## @reset
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	leaq	L_.str.2(%rip), %rdi
	movb	$0, %al
	callq	_printf
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_colorSwitch                    ## -- Begin function colorSwitch
	.p2align	4, 0x90
_colorSwitch:                           ## @colorSwitch
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	$2, %ecx
	cltd
	idivl	%ecx
	cmpl	$0, %edx
	jne	LBB3_2
## %bb.1:
	callq	_red
	jmp	LBB3_3
LBB3_2:
	callq	_green
LBB3_3:
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_main                           ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	leaq	L_.str.3(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.4(%rip), %rdi
	leaq	-8(%rbp), %rsi
	movb	$0, %al
	callq	_scanf
	movl	-8(%rbp), %eax
	movl	%eax, -12(%rbp)
LBB4_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$0, -12(%rbp)
	jle	LBB4_4
## %bb.2:                               ##   in Loop: Header=BB4_1 Depth=1
	movl	-12(%rbp), %edi
	callq	_colorSwitch
	movl	-12(%rbp), %esi
	leaq	L_.str.5(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	$1, %edi
	callq	_sleep
	callq	_reset
## %bb.3:                               ##   in Loop: Header=BB4_1 Depth=1
	movl	-12(%rbp), %eax
	addl	$-1, %eax
	movl	%eax, -12(%rbp)
	jmp	LBB4_1
LBB4_4:
	xorl	%eax, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"\033[1;31m"

L_.str.1:                               ## @.str.1
	.asciz	"\033[1;32m"

L_.str.2:                               ## @.str.2
	.asciz	"\033[0m"

L_.str.3:                               ## @.str.3
	.asciz	"Enter a number of seconds to countdown from: "

L_.str.4:                               ## @.str.4
	.asciz	"%d"

L_.str.5:                               ## @.str.5
	.asciz	"%d\n"

.subsections_via_symbols
