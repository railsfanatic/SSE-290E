	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_saveStudents
	.align	4, 0x90
_saveStudents:                          ## @saveStudents
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	leaq	L_.str(%rip), %rdi
	leaq	L_.str1(%rip), %rsi
	callq	_fopen
	movq	%rax, -16(%rbp)
	cmpq	$0, -16(%rbp)
	jne	LBB0_2
## BB#1:
	leaq	L_.str2(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	$1, -4(%rbp)
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	jmp	LBB0_7
LBB0_2:
	leaq	L_.str3(%rip), %rdi
	movl	_numStudents(%rip), %esi
	movb	$0, %al
	callq	_printf
	leaq	_numStudents(%rip), %rdi
	movl	$4, %esi
                                        ## kill: RSI<def> ESI<kill>
	movl	$1, %ecx
	movl	%ecx, %edx
	movq	-16(%rbp), %rcx
	movl	%eax, -24(%rbp)         ## 4-byte Spill
	callq	_fwrite
	movl	$0, -8(%rbp)
	movq	%rax, -32(%rbp)         ## 8-byte Spill
LBB0_3:                                 ## =>This Inner Loop Header: Depth=1
	movl	-8(%rbp), %eax
	cmpl	_numStudents(%rip), %eax
	jge	LBB0_6
## BB#4:                                ##   in Loop: Header=BB0_3 Depth=1
	movl	$80, %eax
	movl	%eax, %esi
	movl	$1, %eax
	movl	%eax, %edx
	movq	_students@GOTPCREL(%rip), %rcx
	movslq	-8(%rbp), %rdi
	imulq	$80, %rdi, %rdi
	addq	%rdi, %rcx
	movq	-16(%rbp), %rdi
	movq	%rdi, -40(%rbp)         ## 8-byte Spill
	movq	%rcx, %rdi
	movq	-40(%rbp), %rcx         ## 8-byte Reload
	callq	_fwrite
	leaq	L_.str4(%rip), %rdi
	movl	-8(%rbp), %esi
	movq	%rax, -48(%rbp)         ## 8-byte Spill
	movb	$0, %al
	callq	_printf
	movl	%eax, -52(%rbp)         ## 4-byte Spill
## BB#5:                                ##   in Loop: Header=BB0_3 Depth=1
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	LBB0_3
LBB0_6:
	movq	-16(%rbp), %rdi
	callq	_fclose
	movl	$0, -4(%rbp)
	movl	%eax, -56(%rbp)         ## 4-byte Spill
LBB0_7:
	movl	-4(%rbp), %eax
	addq	$64, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_loadStudents
	.align	4, 0x90
_loadStudents:                          ## @loadStudents
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp3:
	.cfi_def_cfa_offset 16
Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp5:
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	leaq	L_.str(%rip), %rdi
	leaq	L_.str5(%rip), %rsi
	callq	_fopen
	movq	%rax, -16(%rbp)
	cmpq	$0, -16(%rbp)
	jne	LBB1_2
## BB#1:
	leaq	L_.str2(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	$1, -4(%rbp)
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	jmp	LBB1_7
LBB1_2:
	leaq	_numStudents(%rip), %rax
	movl	$4, %ecx
	movl	%ecx, %esi
	movl	$1, %ecx
	movl	%ecx, %edx
	movq	-16(%rbp), %rcx
	movq	%rax, %rdi
	callq	_fread
	leaq	L_.str6(%rip), %rdi
	movl	_numStudents(%rip), %esi
	movq	%rax, -32(%rbp)         ## 8-byte Spill
	movb	$0, %al
	callq	_printf
	movl	$0, -8(%rbp)
	movl	%eax, -36(%rbp)         ## 4-byte Spill
LBB1_3:                                 ## =>This Inner Loop Header: Depth=1
	movl	-8(%rbp), %eax
	cmpl	_numStudents(%rip), %eax
	jge	LBB1_6
## BB#4:                                ##   in Loop: Header=BB1_3 Depth=1
	movl	$80, %eax
	movl	%eax, %esi
	movl	$1, %eax
	movl	%eax, %edx
	movq	_students@GOTPCREL(%rip), %rcx
	movslq	-8(%rbp), %rdi
	imulq	$80, %rdi, %rdi
	addq	%rdi, %rcx
	movq	-16(%rbp), %rdi
	movq	%rdi, -48(%rbp)         ## 8-byte Spill
	movq	%rcx, %rdi
	movq	-48(%rbp), %rcx         ## 8-byte Reload
	callq	_fread
	leaq	L_.str4(%rip), %rdi
	movl	-8(%rbp), %esi
	movq	%rax, -56(%rbp)         ## 8-byte Spill
	movb	$0, %al
	callq	_printf
	movl	%eax, -60(%rbp)         ## 4-byte Spill
## BB#5:                                ##   in Loop: Header=BB1_3 Depth=1
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	LBB1_3
LBB1_6:
	movq	-16(%rbp), %rdi
	callq	_fclose
	movl	$0, -4(%rbp)
	movl	%eax, -64(%rbp)         ## 4-byte Spill
LBB1_7:
	movl	-4(%rbp), %eax
	addq	$64, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_stripWhitespace
	.align	4, 0x90
_stripWhitespace:                       ## @stripWhitespace
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp6:
	.cfi_def_cfa_offset 16
Ltmp7:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp8:
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movq	%rdi, -16(%rbp)
LBB2_1:                                 ## =>This Inner Loop Header: Depth=1
	xorl	%eax, %eax
	movb	%al, %cl
	movq	-16(%rbp), %rdx
	movsbl	(%rdx), %eax
	cmpl	$0, %eax
	movb	%cl, -33(%rbp)          ## 1-byte Spill
	je	LBB2_3
## BB#2:                                ##   in Loop: Header=BB2_1 Depth=1
	movq	-16(%rbp), %rax
	movsbl	(%rax), %edi
	callq	_isspace
	cmpl	$0, %eax
	setne	%cl
	movb	%cl, -33(%rbp)          ## 1-byte Spill
LBB2_3:                                 ##   in Loop: Header=BB2_1 Depth=1
	movb	-33(%rbp), %al          ## 1-byte Reload
	testb	$1, %al
	jne	LBB2_4
	jmp	LBB2_5
LBB2_4:                                 ##   in Loop: Header=BB2_1 Depth=1
	movq	-16(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -16(%rbp)
	jmp	LBB2_1
LBB2_5:
	movq	$-1, %rcx
	movq	-16(%rbp), %rdi
	movq	%rcx, -48(%rbp)         ## 8-byte Spill
	callq	_strlen
	addq	$1, %rax
	movq	%rax, -24(%rbp)
	movq	-8(%rbp), %rdi
	movq	-16(%rbp), %rsi
	movq	-24(%rbp), %rdx
	movq	-48(%rbp), %rcx         ## 8-byte Reload
	callq	___memmove_chk
	movq	-8(%rbp), %rcx
	addq	-24(%rbp), %rcx
	movq	%rcx, -32(%rbp)
	movq	%rax, -56(%rbp)         ## 8-byte Spill
LBB2_6:                                 ## =>This Inner Loop Header: Depth=1
	xorl	%eax, %eax
	movb	%al, %cl
	movq	-8(%rbp), %rdx
	cmpq	-32(%rbp), %rdx
	movb	%cl, -57(%rbp)          ## 1-byte Spill
	jae	LBB2_8
## BB#7:                                ##   in Loop: Header=BB2_6 Depth=1
	movq	-32(%rbp), %rax
	movsbl	(%rax), %edi
	callq	_isspace
	cmpl	$0, %eax
	setne	%cl
	movb	%cl, -57(%rbp)          ## 1-byte Spill
LBB2_8:                                 ##   in Loop: Header=BB2_6 Depth=1
	movb	-57(%rbp), %al          ## 1-byte Reload
	testb	$1, %al
	jne	LBB2_9
	jmp	LBB2_10
LBB2_9:                                 ##   in Loop: Header=BB2_6 Depth=1
	movq	-32(%rbp), %rax
	addq	$-1, %rax
	movq	%rax, -32(%rbp)
	jmp	LBB2_6
LBB2_10:
	movq	-32(%rbp), %rax
	movb	$0, (%rax)
	addq	$64, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_inputString
	.align	4, 0x90
_inputString:                           ## @inputString
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp9:
	.cfi_def_cfa_offset 16
Ltmp10:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp11:
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdi
	callq	_malloc
	leaq	L_.str7(%rip), %rdi
	movq	%rax, -24(%rbp)
	movl	$0, -28(%rbp)
	movb	$0, -29(%rbp)
	movq	-8(%rbp), %rsi
	movb	$0, %al
	callq	_printf
	movq	___stdinp@GOTPCREL(%rip), %rsi
	movq	-24(%rbp), %rdi
	movq	-16(%rbp), %rcx
	movl	%ecx, %edx
	movq	(%rsi), %rcx
	movl	%edx, %esi
	movq	%rcx, %rdx
	movl	%eax, -36(%rbp)         ## 4-byte Spill
	callq	_fgets
	movl	$0, -28(%rbp)
	movq	%rax, -48(%rbp)         ## 8-byte Spill
LBB3_1:                                 ## =>This Inner Loop Header: Depth=1
	movslq	-28(%rbp), %rax
	cmpq	-16(%rbp), %rax
	jae	LBB3_6
## BB#2:                                ##   in Loop: Header=BB3_1 Depth=1
	movslq	-28(%rbp), %rax
	movq	-24(%rbp), %rcx
	movsbl	(%rcx,%rax), %edx
	cmpl	$10, %edx
	jne	LBB3_4
## BB#3:                                ##   in Loop: Header=BB3_1 Depth=1
	movslq	-28(%rbp), %rax
	movq	-24(%rbp), %rcx
	movb	$0, (%rcx,%rax)
	movb	$1, -29(%rbp)
LBB3_4:                                 ##   in Loop: Header=BB3_1 Depth=1
	jmp	LBB3_5
LBB3_5:                                 ##   in Loop: Header=BB3_1 Depth=1
	movl	-28(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -28(%rbp)
	jmp	LBB3_1
LBB3_6:
	movsbl	-29(%rbp), %eax
	cmpl	$0, %eax
	jne	LBB3_13
## BB#7:
	jmp	LBB3_8
LBB3_8:                                 ## =>This Inner Loop Header: Depth=1
	callq	_getchar
	xorl	%ecx, %ecx
	movb	%cl, %dl
	movb	%al, %sil
	movb	%sil, -29(%rbp)
	movsbl	%sil, %eax
	cmpl	$10, %eax
	movb	%dl, -49(%rbp)          ## 1-byte Spill
	je	LBB3_10
## BB#9:                                ##   in Loop: Header=BB3_8 Depth=1
	movsbl	-29(%rbp), %eax
	cmpl	$0, %eax
	setne	%cl
	movb	%cl, -49(%rbp)          ## 1-byte Spill
LBB3_10:                                ##   in Loop: Header=BB3_8 Depth=1
	movb	-49(%rbp), %al          ## 1-byte Reload
	testb	$1, %al
	jne	LBB3_11
	jmp	LBB3_12
LBB3_11:                                ##   in Loop: Header=BB3_8 Depth=1
	jmp	LBB3_8
LBB3_12:
	jmp	LBB3_13
LBB3_13:
	movq	-24(%rbp), %rdi
	callq	_stripWhitespace
	movq	-24(%rbp), %rax
	addq	$64, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_inputDate
	.align	4, 0x90
_inputDate:                             ## @inputDate
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp12:
	.cfi_def_cfa_offset 16
Ltmp13:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp14:
	.cfi_def_cfa_register %rbp
	subq	$144, %rsp
	xorl	%esi, %esi
	movl	$56, %eax
	movl	%eax, %edx
	leaq	-112(%rbp), %rcx
	movq	___stack_chk_guard@GOTPCREL(%rip), %r8
	movq	(%r8), %r8
	movq	%r8, -8(%rbp)
	movq	%rdi, -40(%rbp)
	movl	$0, -44(%rbp)
	movl	$0, -48(%rbp)
	movl	$0, -52(%rbp)
	movq	%rcx, %rdi
	callq	_memset
LBB4_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	$10, %eax
	movl	%eax, %esi
	leaq	-18(%rbp), %rdi
	movq	-40(%rbp), %rcx
	movq	%rdi, -120(%rbp)        ## 8-byte Spill
	movq	%rcx, %rdi
	callq	_inputString
	movl	$10, %edx
                                        ## kill: RDX<def> EDX<kill>
	movq	-120(%rbp), %rdi        ## 8-byte Reload
	movq	%rax, %rsi
	callq	___strcpy_chk
	leaq	-18(%rbp), %rdi
	leaq	L_.str8(%rip), %rsi
	movq	%rax, -128(%rbp)        ## 8-byte Spill
	callq	_strcmp
	cmpl	$0, %eax
	jne	LBB4_3
## BB#2:
	leaq	-112(%rbp), %rdi
	callq	_mktime
	movq	%rax, -32(%rbp)
	jmp	LBB4_18
LBB4_3:                                 ##   in Loop: Header=BB4_1 Depth=1
	leaq	L_.str9(%rip), %rsi
	leaq	-44(%rbp), %rdx
	leaq	-48(%rbp), %rcx
	leaq	-52(%rbp), %r8
	leaq	-18(%rbp), %rdi
	movb	$0, %al
	callq	_sscanf
	cmpl	$100, -52(%rbp)
	movl	%eax, -132(%rbp)        ## 4-byte Spill
	jge	LBB4_6
## BB#4:                                ##   in Loop: Header=BB4_1 Depth=1
	cmpl	$30, -52(%rbp)
	jl	LBB4_6
## BB#5:                                ##   in Loop: Header=BB4_1 Depth=1
	movl	-52(%rbp), %eax
	addl	$1900, %eax             ## imm = 0x76C
	movl	%eax, -52(%rbp)
LBB4_6:                                 ##   in Loop: Header=BB4_1 Depth=1
	cmpl	$30, -52(%rbp)
	jge	LBB4_8
## BB#7:                                ##   in Loop: Header=BB4_1 Depth=1
	movl	-52(%rbp), %eax
	addl	$2000, %eax             ## imm = 0x7D0
	movl	%eax, -52(%rbp)
LBB4_8:                                 ##   in Loop: Header=BB4_1 Depth=1
	jmp	LBB4_9
LBB4_9:                                 ##   in Loop: Header=BB4_1 Depth=1
	movb	$1, %al
	cmpl	$1, -44(%rbp)
	movb	%al, -133(%rbp)         ## 1-byte Spill
	jl	LBB4_16
## BB#10:                               ##   in Loop: Header=BB4_1 Depth=1
	movb	$1, %al
	cmpl	$12, -44(%rbp)
	movb	%al, -133(%rbp)         ## 1-byte Spill
	jg	LBB4_16
## BB#11:                               ##   in Loop: Header=BB4_1 Depth=1
	movb	$1, %al
	cmpl	$1, -48(%rbp)
	movb	%al, -133(%rbp)         ## 1-byte Spill
	jl	LBB4_16
## BB#12:                               ##   in Loop: Header=BB4_1 Depth=1
	movb	$1, %al
	cmpl	$31, -48(%rbp)
	movb	%al, -133(%rbp)         ## 1-byte Spill
	jg	LBB4_16
## BB#13:                               ##   in Loop: Header=BB4_1 Depth=1
	movb	$1, %al
	cmpl	$1900, -52(%rbp)        ## imm = 0x76C
	movb	%al, -134(%rbp)         ## 1-byte Spill
	jl	LBB4_15
## BB#14:                               ##   in Loop: Header=BB4_1 Depth=1
	cmpl	$2100, -52(%rbp)        ## imm = 0x834
	setg	%al
	movb	%al, -134(%rbp)         ## 1-byte Spill
LBB4_15:                                ##   in Loop: Header=BB4_1 Depth=1
	movb	-134(%rbp), %al         ## 1-byte Reload
	movb	%al, -133(%rbp)         ## 1-byte Spill
LBB4_16:                                ##   in Loop: Header=BB4_1 Depth=1
	movb	-133(%rbp), %al         ## 1-byte Reload
	testb	$1, %al
	jne	LBB4_1
## BB#17:
	leaq	-112(%rbp), %rdi
	movl	-44(%rbp), %eax
	subl	$1, %eax
	movl	%eax, -96(%rbp)
	movl	-48(%rbp), %eax
	movl	%eax, -100(%rbp)
	movl	-52(%rbp), %eax
	subl	$1900, %eax             ## imm = 0x76C
	movl	%eax, -92(%rbp)
	callq	_mktime
	movq	%rax, -32(%rbp)
LBB4_18:
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	-32(%rbp), %rcx
	movq	(%rax), %rax
	cmpq	-8(%rbp), %rax
	movq	%rcx, -144(%rbp)        ## 8-byte Spill
	jne	LBB4_20
## BB#19:                               ## %SP_return
	movq	-144(%rbp), %rax        ## 8-byte Reload
	addq	$144, %rsp
	popq	%rbp
	retq
LBB4_20:                                ## %CallStackCheckFailBlk
	callq	___stack_chk_fail
	.cfi_endproc

	.globl	_inputInteger
	.align	4, 0x90
_inputInteger:                          ## @inputInteger
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp15:
	.cfi_def_cfa_offset 16
Ltmp16:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp17:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$10, %eax
	movl	%eax, %esi
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	_inputString
	movq	%rax, %rdi
	callq	_atoi
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_confirm
	.align	4, 0x90
_confirm:                               ## @confirm
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp18:
	.cfi_def_cfa_offset 16
Ltmp19:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp20:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$2, %eax
	movl	%eax, %esi
	movq	%rdi, -16(%rbp)
	movq	-16(%rbp), %rdi
	callq	_inputString
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rdi
	leaq	L_.str10(%rip), %rsi
	callq	_strcmp
	cmpl	$0, %eax
	je	LBB6_2
## BB#1:
	movq	-24(%rbp), %rdi
	leaq	L_.str11(%rip), %rsi
	callq	_strcmp
	cmpl	$0, %eax
	jne	LBB6_3
LBB6_2:
	movl	$1, -4(%rbp)
	jmp	LBB6_4
LBB6_3:
	movl	$0, -4(%rbp)
LBB6_4:
	movl	-4(%rbp), %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_addStudents
	.align	4, 0x90
_addStudents:                           ## @addStudents
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp21:
	.cfi_def_cfa_offset 16
Ltmp22:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp23:
	.cfi_def_cfa_register %rbp
	subq	$192, %rsp
	leaq	L_.str12(%rip), %rdi
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movb	$0, %al
	callq	_printf
	movl	%eax, -108(%rbp)        ## 4-byte Spill
LBB7_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB7_2 Depth 2
	jmp	LBB7_2
LBB7_2:                                 ##   Parent Loop BB7_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	leaq	L_.str13(%rip), %rdi
	movl	_numStudents(%rip), %eax
	addl	$1, %eax
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	leaq	L_.str14(%rip), %rdi
	movl	$32, %esi
                                        ## kill: RSI<def> ESI<kill>
	leaq	-48(%rbp), %rcx
	movl	%eax, -112(%rbp)        ## 4-byte Spill
	movq	%rcx, -120(%rbp)        ## 8-byte Spill
	callq	_inputString
	movl	$32, %edx
                                        ## kill: RDX<def> EDX<kill>
	movq	-120(%rbp), %rdi        ## 8-byte Reload
	movq	%rax, %rsi
	callq	___strcpy_chk
	leaq	-48(%rbp), %rdi
	leaq	L_.str8(%rip), %rsi
	movq	%rax, -128(%rbp)        ## 8-byte Spill
	callq	_strcmp
	cmpl	$0, %eax
	jne	LBB7_4
## BB#3:
	jmp	LBB7_10
LBB7_4:                                 ##   in Loop: Header=BB7_2 Depth=2
	leaq	L_.str15(%rip), %rdi
	movl	$32, %eax
	movl	%eax, %esi
	leaq	-80(%rbp), %rcx
	movq	%rcx, -136(%rbp)        ## 8-byte Spill
	callq	_inputString
	movl	$32, %edx
                                        ## kill: RDX<def> EDX<kill>
	movq	-136(%rbp), %rdi        ## 8-byte Reload
	movq	%rax, %rsi
	callq	___strcpy_chk
	leaq	-80(%rbp), %rdi
	leaq	L_.str8(%rip), %rsi
	movq	%rax, -144(%rbp)        ## 8-byte Spill
	callq	_strcmp
	cmpl	$0, %eax
	jne	LBB7_6
## BB#5:
	jmp	LBB7_10
LBB7_6:                                 ##   in Loop: Header=BB7_2 Depth=2
	leaq	L_.str16(%rip), %rdi
	callq	_inputInteger
	leaq	L_.str17(%rip), %rdi
	movl	%eax, -84(%rbp)
	callq	_inputDate
	leaq	-96(%rbp), %rdi
	leaq	-80(%rbp), %rdx
	leaq	-48(%rbp), %rsi
	movq	%rax, -96(%rbp)
	movl	-84(%rbp), %ecx
	movq	%rsi, -152(%rbp)        ## 8-byte Spill
	movl	%ecx, -156(%rbp)        ## 4-byte Spill
	movq	%rdx, -168(%rbp)        ## 8-byte Spill
	callq	_ctime
	leaq	L_.str18(%rip), %rdi
	movq	-152(%rbp), %rsi        ## 8-byte Reload
	movq	-168(%rbp), %rdx        ## 8-byte Reload
	movl	-156(%rbp), %ecx        ## 4-byte Reload
	movq	%rax, %r8
	movb	$0, %al
	callq	_printf
	movl	%eax, -172(%rbp)        ## 4-byte Spill
## BB#7:                                ##   in Loop: Header=BB7_2 Depth=2
	leaq	L_.str19(%rip), %rdi
	callq	_confirm
	cmpl	$0, %eax
	setne	%cl
	xorb	$1, %cl
	testb	$1, %cl
	jne	LBB7_2
## BB#8:                                ##   in Loop: Header=BB7_1 Depth=1
	movq	$-1, %rdx
	leaq	-48(%rbp), %rsi
	movq	_students@GOTPCREL(%rip), %rax
	movslq	_numStudents(%rip), %rcx
	imulq	$80, %rcx, %rcx
	addq	%rcx, %rax
	movq	%rax, -104(%rbp)
	movq	-104(%rbp), %rdi
	callq	___strcpy_chk
	movq	$-1, %rdx
	leaq	-80(%rbp), %rsi
	movq	-104(%rbp), %rcx
	addq	$32, %rcx
	movq	%rcx, %rdi
	movq	%rax, -184(%rbp)        ## 8-byte Spill
	callq	___strcpy_chk
	movl	-84(%rbp), %r8d
	movq	-104(%rbp), %rcx
	movl	%r8d, 64(%rcx)
	movq	-96(%rbp), %rcx
	movq	-104(%rbp), %rdx
	movq	%rcx, 72(%rdx)
	movl	_numStudents(%rip), %r8d
	addl	$1, %r8d
	movl	%r8d, _numStudents(%rip)
	movq	%rax, -192(%rbp)        ## 8-byte Spill
## BB#9:                                ##   in Loop: Header=BB7_1 Depth=1
	leaq	L_.str20(%rip), %rdi
	callq	_confirm
	cmpl	$0, %eax
	jne	LBB7_1
LBB7_10:
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	cmpq	-8(%rbp), %rax
	jne	LBB7_12
## BB#11:                               ## %SP_return
	addq	$192, %rsp
	popq	%rbp
	retq
LBB7_12:                                ## %CallStackCheckFailBlk
	callq	___stack_chk_fail
	.cfi_endproc

	.globl	_formatDate
	.align	4, 0x90
_formatDate:                            ## @formatDate
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp24:
	.cfi_def_cfa_offset 16
Ltmp25:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp26:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$10, %eax
	movl	%eax, %ecx
	movq	%rdi, -8(%rbp)
	movq	%rcx, %rdi
	callq	_malloc
	leaq	-8(%rbp), %rdi
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, -24(%rbp)         ## 8-byte Spill
	callq	_localtime
	movl	$10, %edx
	movl	%edx, %esi
	leaq	L_.str21(%rip), %rdx
	movq	-24(%rbp), %rdi         ## 8-byte Reload
	movq	%rax, %rcx
	callq	_strftime
	movq	-16(%rbp), %rcx
	movq	%rax, -32(%rbp)         ## 8-byte Spill
	movq	%rcx, %rax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_printStudent
	.align	4, 0x90
_printStudent:                          ## @printStudent
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp27:
	.cfi_def_cfa_offset 16
Ltmp28:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp29:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	leaq	L_.str22(%rip), %rax
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	addq	$32, %rdi
	movq	-8(%rbp), %rdx
	movq	%rdi, -16(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	movq	-16(%rbp), %rsi         ## 8-byte Reload
	movb	$0, %al
	callq	_printf
	movq	-8(%rbp), %rdx
	movq	72(%rdx), %rdi
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	callq	_formatDate
	leaq	L_.str23(%rip), %rdi
	movq	%rax, %rsi
	movb	$0, %al
	callq	_printf
	leaq	L_.str24(%rip), %rdi
	movq	-8(%rbp), %rdx
	movl	64(%rdx), %esi
	movl	%eax, -24(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_formatName
	.align	4, 0x90
_formatName:                            ## @formatName
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp30:
	.cfi_def_cfa_offset 16
Ltmp31:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp32:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movl	$66, %eax
	movl	%eax, %ecx
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	%edx, -20(%rbp)
	movq	%rcx, %rdi
	callq	_malloc
	movq	%rax, -32(%rbp)
	cmpl	$0, -20(%rbp)
	je	LBB10_2
## BB#1:
	xorl	%esi, %esi
	leaq	L_.str25(%rip), %rcx
	movq	$-1, %rdx
	movq	-32(%rbp), %rdi
	movq	-16(%rbp), %r8
	movq	-8(%rbp), %r9
	movb	$0, %al
	callq	___sprintf_chk
	movl	%eax, -36(%rbp)         ## 4-byte Spill
	jmp	LBB10_3
LBB10_2:
	xorl	%esi, %esi
	leaq	L_.str26(%rip), %rcx
	movq	$-1, %rdx
	movq	-32(%rbp), %rdi
	movq	-8(%rbp), %r8
	movq	-16(%rbp), %r9
	movb	$0, %al
	callq	___sprintf_chk
	movl	%eax, -40(%rbp)         ## 4-byte Spill
LBB10_3:
	movq	-32(%rbp), %rax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_editStudent
	.align	4, 0x90
_editStudent:                           ## @editStudent
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp33:
	.cfi_def_cfa_offset 16
Ltmp34:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp35:
	.cfi_def_cfa_register %rbp
	subq	$240, %rsp
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movq	%rdi, -88(%rbp)
	movq	$0, -104(%rbp)
	movq	$0, -112(%rbp)
LBB11_1:                                ## =>This Inner Loop Header: Depth=1
	leaq	L_.str27(%rip), %rdi
	movl	_numStudents(%rip), %eax
	addl	$1, %eax
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	leaq	L_.str28(%rip), %rdi
	movq	-88(%rbp), %rsi
	movl	%eax, -116(%rbp)        ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str8(%rip), %rdi
	movl	$32, %ecx
	movl	%ecx, %esi
	leaq	-48(%rbp), %rdx
	movl	%eax, -120(%rbp)        ## 4-byte Spill
	movq	%rdx, -128(%rbp)        ## 8-byte Spill
	callq	_inputString
	movl	$32, %ecx
	movl	%ecx, %edx
	movq	-128(%rbp), %rdi        ## 8-byte Reload
	movq	%rax, %rsi
	callq	___strcpy_chk
	leaq	-48(%rbp), %rdi
	leaq	L_.str8(%rip), %rsi
	movq	%rax, -136(%rbp)        ## 8-byte Spill
	callq	_strcmp
	cmpl	$0, %eax
	jne	LBB11_3
## BB#2:                                ##   in Loop: Header=BB11_1 Depth=1
	movl	$32, %eax
	movl	%eax, %edx
	leaq	-48(%rbp), %rdi
	movq	-88(%rbp), %rsi
	callq	___strcpy_chk
	movq	%rax, -144(%rbp)        ## 8-byte Spill
LBB11_3:                                ##   in Loop: Header=BB11_1 Depth=1
	leaq	L_.str29(%rip), %rdi
	movq	-88(%rbp), %rax
	addq	$32, %rax
	movq	%rax, %rsi
	movb	$0, %al
	callq	_printf
	leaq	L_.str8(%rip), %rdi
	movl	$32, %ecx
	movl	%ecx, %esi
	leaq	-80(%rbp), %rdx
	movl	%eax, -148(%rbp)        ## 4-byte Spill
	movq	%rdx, -160(%rbp)        ## 8-byte Spill
	callq	_inputString
	movl	$32, %ecx
	movl	%ecx, %edx
	movq	-160(%rbp), %rdi        ## 8-byte Reload
	movq	%rax, %rsi
	callq	___strcpy_chk
	leaq	-80(%rbp), %rdi
	leaq	L_.str8(%rip), %rsi
	movq	%rax, -168(%rbp)        ## 8-byte Spill
	callq	_strcmp
	cmpl	$0, %eax
	jne	LBB11_5
## BB#4:                                ##   in Loop: Header=BB11_1 Depth=1
	movl	$32, %eax
	movl	%eax, %edx
	leaq	-80(%rbp), %rdi
	movq	-88(%rbp), %rcx
	addq	$32, %rcx
	movq	%rcx, %rsi
	callq	___strcpy_chk
	movq	%rax, -176(%rbp)        ## 8-byte Spill
LBB11_5:                                ##   in Loop: Header=BB11_1 Depth=1
	leaq	L_.str30(%rip), %rdi
	movq	-88(%rbp), %rax
	movl	64(%rax), %esi
	movb	$0, %al
	callq	_printf
	leaq	L_.str8(%rip), %rdi
	movl	%eax, -180(%rbp)        ## 4-byte Spill
	callq	_inputInteger
	movl	%eax, -92(%rbp)
	cmpl	$0, -92(%rbp)
	jne	LBB11_7
## BB#6:                                ##   in Loop: Header=BB11_1 Depth=1
	movq	-88(%rbp), %rax
	movl	64(%rax), %ecx
	movl	%ecx, -92(%rbp)
LBB11_7:                                ##   in Loop: Header=BB11_1 Depth=1
	movq	-88(%rbp), %rax
	movq	72(%rax), %rdi
	callq	_formatDate
	leaq	L_.str31(%rip), %rdi
	movq	%rax, %rsi
	movb	$0, %al
	callq	_printf
	leaq	L_.str8(%rip), %rdi
	movl	%eax, -184(%rbp)        ## 4-byte Spill
	callq	_inputDate
	movq	%rax, -104(%rbp)
	movq	-104(%rbp), %rdi
	movq	-112(%rbp), %rsi
	callq	_difftime
	xorps	%xmm1, %xmm1
	ucomisd	%xmm1, %xmm0
	jne	LBB11_9
	jp	LBB11_9
## BB#8:                                ##   in Loop: Header=BB11_1 Depth=1
	movq	-88(%rbp), %rax
	movq	72(%rax), %rax
	movq	%rax, -104(%rbp)
LBB11_9:                                ##   in Loop: Header=BB11_1 Depth=1
	leaq	-104(%rbp), %rdi
	leaq	-80(%rbp), %rdx
	leaq	-48(%rbp), %rsi
	movl	-92(%rbp), %ecx
	movl	%ecx, -188(%rbp)        ## 4-byte Spill
	movq	%rdx, -200(%rbp)        ## 8-byte Spill
	movq	%rsi, -208(%rbp)        ## 8-byte Spill
	callq	_ctime
	leaq	L_.str18(%rip), %rdi
	movq	-208(%rbp), %rsi        ## 8-byte Reload
	movq	-200(%rbp), %rdx        ## 8-byte Reload
	movl	-188(%rbp), %ecx        ## 4-byte Reload
	movq	%rax, %r8
	movb	$0, %al
	callq	_printf
	movl	%eax, -212(%rbp)        ## 4-byte Spill
## BB#10:                               ##   in Loop: Header=BB11_1 Depth=1
	leaq	L_.str32(%rip), %rdi
	callq	_confirm
	cmpl	$0, %eax
	setne	%cl
	xorb	$1, %cl
	testb	$1, %cl
	jne	LBB11_1
## BB#11:
	movq	$-1, %rdx
	leaq	-48(%rbp), %rsi
	movq	-88(%rbp), %rdi
	callq	___strcpy_chk
	movq	$-1, %rdx
	leaq	-80(%rbp), %rsi
	movq	-88(%rbp), %rdi
	addq	$32, %rdi
	movq	%rax, -224(%rbp)        ## 8-byte Spill
	callq	___strcpy_chk
	movq	___stack_chk_guard@GOTPCREL(%rip), %rdx
	movl	-92(%rbp), %ecx
	movq	-88(%rbp), %rsi
	movl	%ecx, 64(%rsi)
	movq	-104(%rbp), %rsi
	movq	-88(%rbp), %rdi
	movq	%rsi, 72(%rdi)
	movq	(%rdx), %rdx
	cmpq	-8(%rbp), %rdx
	movq	%rax, -232(%rbp)        ## 8-byte Spill
	jne	LBB11_13
## BB#12:                               ## %SP_return
	addq	$240, %rsp
	popq	%rbp
	retq
LBB11_13:                               ## %CallStackCheckFailBlk
	callq	___stack_chk_fail
	.cfi_endproc

	.globl	_listStudents
	.align	4, 0x90
_listStudents:                          ## @listStudents
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp36:
	.cfi_def_cfa_offset 16
Ltmp37:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp38:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	leaq	L_.str33(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str34(%rip), %rdi
	movl	%eax, -16(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	movl	$0, -12(%rbp)
	movl	%eax, -20(%rbp)         ## 4-byte Spill
LBB12_1:                                ## =>This Inner Loop Header: Depth=1
	movl	-12(%rbp), %eax
	cmpl	_numStudents(%rip), %eax
	jge	LBB12_4
## BB#2:                                ##   in Loop: Header=BB12_1 Depth=1
	movl	$1, %edx
	movq	_students@GOTPCREL(%rip), %rax
	movslq	-12(%rbp), %rcx
	imulq	$80, %rcx, %rcx
	addq	%rcx, %rax
	movq	%rax, -8(%rbp)
	movl	-12(%rbp), %esi
	addl	$1, %esi
	movq	-8(%rbp), %rdi
	movq	-8(%rbp), %rax
	addq	$32, %rax
	movl	%esi, -24(%rbp)         ## 4-byte Spill
	movq	%rax, %rsi
	callq	_formatName
	movq	-8(%rbp), %rcx
	movq	72(%rcx), %rdi
	movq	%rax, -32(%rbp)         ## 8-byte Spill
	callq	_formatDate
	leaq	L_.str35(%rip), %rdi
	movq	-8(%rbp), %rcx
	movl	64(%rcx), %r8d
	movl	-24(%rbp), %esi         ## 4-byte Reload
	movq	-32(%rbp), %rdx         ## 8-byte Reload
	movq	%rax, %rcx
	movb	$0, %al
	callq	_printf
	movl	%eax, -36(%rbp)         ## 4-byte Spill
## BB#3:                                ##   in Loop: Header=BB12_1 Depth=1
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -12(%rbp)
	jmp	LBB12_1
LBB12_4:
	leaq	L_.str36(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str37(%rip), %rdi
	movl	%eax, -40(%rbp)         ## 4-byte Spill
	callq	_inputInteger
	movl	%eax, -12(%rbp)
	cmpl	$1, -12(%rbp)
	jl	LBB12_6
## BB#5:
	movl	-12(%rbp), %eax
	cmpl	_numStudents(%rip), %eax
	jle	LBB12_7
LBB12_6:
	jmp	LBB12_8
LBB12_7:
	movq	_students@GOTPCREL(%rip), %rax
	movl	-12(%rbp), %ecx
	subl	$1, %ecx
	movslq	%ecx, %rdx
	imulq	$80, %rdx, %rdx
	addq	%rdx, %rax
	movq	%rax, %rdi
	callq	_editStudent
LBB12_8:
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_sortStudents
	.align	4, 0x90
_sortStudents:                          ## @sortStudents
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp39:
	.cfi_def_cfa_offset 16
Ltmp40:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp41:
	.cfi_def_cfa_register %rbp
	subq	$176, %rsp
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	$0, -96(%rbp)
	movl	$0, -100(%rbp)
	movl	$0, -104(%rbp)
	cmpl	$2, _numStudents(%rip)
	jge	LBB13_2
## BB#1:
	jmp	LBB13_25
LBB13_2:
	leaq	L_.str38(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str8(%rip), %rdi
	movl	$2, %ecx
	movl	%ecx, %esi
	movl	%eax, -124(%rbp)        ## 4-byte Spill
	callq	_inputString
	movsbl	(%rax), %edi
	callq	_toupper
	movb	%al, %dl
	movb	%dl, -89(%rbp)
LBB13_3:                                ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB13_5 Depth 2
	cmpl	$0, -100(%rbp)
	setne	%al
	xorb	$1, %al
	testb	$1, %al
	jne	LBB13_4
	jmp	LBB13_25
LBB13_4:                                ##   in Loop: Header=BB13_3 Depth=1
	movl	$1, -100(%rbp)
	movl	$0, -96(%rbp)
LBB13_5:                                ##   Parent Loop BB13_3 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movl	-96(%rbp), %eax
	movl	_numStudents(%rip), %ecx
	subl	$1, %ecx
	cmpl	%ecx, %eax
	jge	LBB13_24
## BB#6:                                ##   in Loop: Header=BB13_5 Depth=2
	movl	$0, -104(%rbp)
	movsbl	-89(%rbp), %eax
	addl	$-67, %eax
	movl	%eax, %ecx
	subl	$9, %eax
	movq	%rcx, -136(%rbp)        ## 8-byte Spill
	movl	%eax, -140(%rbp)        ## 4-byte Spill
	ja	LBB13_15
## BB#28:                               ##   in Loop: Header=BB13_5 Depth=2
	leaq	LJTI13_0(%rip), %rax
	movq	-136(%rbp), %rcx        ## 8-byte Reload
	movslq	(%rax,%rcx,4), %rdx
	addq	%rax, %rdx
	jmpq	*%rdx
LBB13_7:                                ##   in Loop: Header=BB13_5 Depth=2
	movb	$1, %al
	movq	_students@GOTPCREL(%rip), %rcx
	movl	-96(%rbp), %edx
	addl	$1, %edx
	movslq	%edx, %rsi
	imulq	$80, %rsi, %rsi
	movq	%rcx, %rdi
	addq	%rsi, %rdi
	movslq	-96(%rbp), %rsi
	imulq	$80, %rsi, %rsi
	addq	%rsi, %rcx
	movq	%rcx, %rsi
	movb	%al, -141(%rbp)         ## 1-byte Spill
	callq	_strcmp
	cmpl	$0, %eax
	movb	-141(%rbp), %r8b        ## 1-byte Reload
	movb	%r8b, -142(%rbp)        ## 1-byte Spill
	jl	LBB13_11
## BB#8:                                ##   in Loop: Header=BB13_5 Depth=2
	xorl	%eax, %eax
	movb	%al, %cl
	movq	_students@GOTPCREL(%rip), %rdx
	movl	-96(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rsi
	imulq	$80, %rsi, %rsi
	movq	%rdx, %rdi
	addq	%rsi, %rdi
	movslq	-96(%rbp), %rsi
	imulq	$80, %rsi, %rsi
	addq	%rsi, %rdx
	movq	%rdx, %rsi
	movb	%cl, -143(%rbp)         ## 1-byte Spill
	callq	_strcmp
	cmpl	$0, %eax
	movb	-143(%rbp), %cl         ## 1-byte Reload
	movb	%cl, -144(%rbp)         ## 1-byte Spill
	jne	LBB13_10
## BB#9:                                ##   in Loop: Header=BB13_5 Depth=2
	movq	_students@GOTPCREL(%rip), %rax
	movl	-96(%rbp), %ecx
	addl	$1, %ecx
	movslq	%ecx, %rdx
	imulq	$80, %rdx, %rdx
	movq	%rax, %rsi
	addq	%rdx, %rsi
	addq	$32, %rsi
	movslq	-96(%rbp), %rdx
	imulq	$80, %rdx, %rdx
	addq	%rdx, %rax
	addq	$32, %rax
	movq	%rsi, %rdi
	movq	%rax, %rsi
	callq	_strcmp
	cmpl	$0, %eax
	setl	%r8b
	movb	%r8b, -144(%rbp)        ## 1-byte Spill
LBB13_10:                               ##   in Loop: Header=BB13_5 Depth=2
	movb	-144(%rbp), %al         ## 1-byte Reload
	movb	%al, -142(%rbp)         ## 1-byte Spill
LBB13_11:                               ##   in Loop: Header=BB13_5 Depth=2
	movb	-142(%rbp), %al         ## 1-byte Reload
	andb	$1, %al
	movzbl	%al, %ecx
	movl	%ecx, -104(%rbp)
	jmp	LBB13_20
LBB13_12:                               ##   in Loop: Header=BB13_5 Depth=2
	movq	_students@GOTPCREL(%rip), %rax
	movslq	-96(%rbp), %rcx
	imulq	$80, %rcx, %rcx
	movq	%rax, %rdx
	addq	%rcx, %rdx
	movq	72(%rdx), %rcx
	movq	%rcx, -112(%rbp)
	movl	-96(%rbp), %esi
	addl	$1, %esi
	movslq	%esi, %rcx
	imulq	$80, %rcx, %rcx
	addq	%rcx, %rax
	movq	72(%rax), %rax
	movq	%rax, -120(%rbp)
	movq	-112(%rbp), %rdi
	movq	-120(%rbp), %rsi
	callq	_difftime
	cvttsd2si	%xmm0, %r8d
	movl	%r8d, -104(%rbp)
	jmp	LBB13_20
LBB13_13:                               ##   in Loop: Header=BB13_5 Depth=2
	movq	_students@GOTPCREL(%rip), %rax
	movslq	-96(%rbp), %rcx
	imulq	$80, %rcx, %rcx
	movq	%rax, %rdx
	addq	%rcx, %rdx
	movl	64(%rdx), %esi
	movl	-96(%rbp), %edi
	addl	$1, %edi
	movslq	%edi, %rcx
	imulq	$80, %rcx, %rcx
	addq	%rcx, %rax
	cmpl	64(%rax), %esi
	setg	%r8b
	andb	$1, %r8b
	movzbl	%r8b, %esi
	movl	%esi, -104(%rbp)
	jmp	LBB13_20
LBB13_14:                               ##   in Loop: Header=BB13_5 Depth=2
	jmp	LBB13_15
LBB13_15:                               ##   in Loop: Header=BB13_5 Depth=2
	movb	$1, %al
	movq	_students@GOTPCREL(%rip), %rcx
	movl	-96(%rbp), %edx
	addl	$1, %edx
	movslq	%edx, %rsi
	imulq	$80, %rsi, %rsi
	movq	%rcx, %rdi
	addq	%rsi, %rdi
	addq	$32, %rdi
	movslq	-96(%rbp), %rsi
	imulq	$80, %rsi, %rsi
	addq	%rsi, %rcx
	addq	$32, %rcx
	movq	%rcx, %rsi
	movb	%al, -145(%rbp)         ## 1-byte Spill
	callq	_strcmp
	cmpl	$0, %eax
	movb	-145(%rbp), %r8b        ## 1-byte Reload
	movb	%r8b, -146(%rbp)        ## 1-byte Spill
	jl	LBB13_19
## BB#16:                               ##   in Loop: Header=BB13_5 Depth=2
	xorl	%eax, %eax
	movb	%al, %cl
	movq	_students@GOTPCREL(%rip), %rdx
	movl	-96(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rsi
	imulq	$80, %rsi, %rsi
	movq	%rdx, %rdi
	addq	%rsi, %rdi
	addq	$32, %rdi
	movslq	-96(%rbp), %rsi
	imulq	$80, %rsi, %rsi
	addq	%rsi, %rdx
	addq	$32, %rdx
	movq	%rdx, %rsi
	movb	%cl, -147(%rbp)         ## 1-byte Spill
	callq	_strcmp
	cmpl	$0, %eax
	movb	-147(%rbp), %cl         ## 1-byte Reload
	movb	%cl, -148(%rbp)         ## 1-byte Spill
	jne	LBB13_18
## BB#17:                               ##   in Loop: Header=BB13_5 Depth=2
	movq	_students@GOTPCREL(%rip), %rax
	movl	-96(%rbp), %ecx
	addl	$1, %ecx
	movslq	%ecx, %rdx
	imulq	$80, %rdx, %rdx
	movq	%rax, %rsi
	addq	%rdx, %rsi
	movslq	-96(%rbp), %rdx
	imulq	$80, %rdx, %rdx
	addq	%rdx, %rax
	movq	%rsi, %rdi
	movq	%rax, %rsi
	callq	_strcmp
	cmpl	$0, %eax
	setl	%r8b
	movb	%r8b, -148(%rbp)        ## 1-byte Spill
LBB13_18:                               ##   in Loop: Header=BB13_5 Depth=2
	movb	-148(%rbp), %al         ## 1-byte Reload
	movb	%al, -146(%rbp)         ## 1-byte Spill
LBB13_19:                               ##   in Loop: Header=BB13_5 Depth=2
	movb	-146(%rbp), %al         ## 1-byte Reload
	andb	$1, %al
	movzbl	%al, %ecx
	movl	%ecx, -104(%rbp)
LBB13_20:                               ##   in Loop: Header=BB13_5 Depth=2
	cmpl	$0, -104(%rbp)
	je	LBB13_22
## BB#21:                               ##   in Loop: Header=BB13_5 Depth=2
	movl	$80, %eax
	movl	%eax, %ecx
	leaq	-88(%rbp), %rdx
	movq	_students@GOTPCREL(%rip), %rsi
	movslq	-96(%rbp), %rdi
	imulq	$80, %rdi, %rdi
	movq	%rsi, %r8
	addq	%rdi, %r8
	movq	%rdx, %rdi
	movq	%rsi, -160(%rbp)        ## 8-byte Spill
	movq	%r8, %rsi
	movq	%rdx, -168(%rbp)        ## 8-byte Spill
	movq	%rcx, %rdx
	movq	%rcx, -176(%rbp)        ## 8-byte Spill
	callq	_memcpy
	movslq	-96(%rbp), %rcx
	imulq	$80, %rcx, %rcx
	movq	-160(%rbp), %rdx        ## 8-byte Reload
	addq	%rcx, %rdx
	movl	-96(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rcx
	imulq	$80, %rcx, %rcx
	movq	-160(%rbp), %rsi        ## 8-byte Reload
	addq	%rcx, %rsi
	movq	%rdx, %rdi
	movq	-176(%rbp), %rdx        ## 8-byte Reload
	callq	_memcpy
	movl	-96(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rcx
	imulq	$80, %rcx, %rcx
	movq	-160(%rbp), %rdx        ## 8-byte Reload
	addq	%rcx, %rdx
	movq	-168(%rbp), %rcx        ## 8-byte Reload
	movq	%rdx, %rdi
	movq	%rcx, %rsi
	movq	-176(%rbp), %rdx        ## 8-byte Reload
	callq	_memcpy
	movl	$0, -100(%rbp)
LBB13_22:                               ##   in Loop: Header=BB13_5 Depth=2
	jmp	LBB13_23
LBB13_23:                               ##   in Loop: Header=BB13_5 Depth=2
	movl	-96(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -96(%rbp)
	jmp	LBB13_5
LBB13_24:                               ##   in Loop: Header=BB13_3 Depth=1
	jmp	LBB13_3
LBB13_25:
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	cmpq	-8(%rbp), %rax
	jne	LBB13_27
## BB#26:                               ## %SP_return
	addq	$176, %rsp
	popq	%rbp
	retq
LBB13_27:                               ## %CallStackCheckFailBlk
	callq	___stack_chk_fail
	.cfi_endproc
	.align	2, 0x90
L13_0_set_13 = LBB13_13-LJTI13_0
L13_0_set_15 = LBB13_15-LJTI13_0
L13_0_set_12 = LBB13_12-LJTI13_0
L13_0_set_7 = LBB13_7-LJTI13_0
L13_0_set_14 = LBB13_14-LJTI13_0
LJTI13_0:
	.long	L13_0_set_13
	.long	L13_0_set_15
	.long	L13_0_set_12
	.long	L13_0_set_7
	.long	L13_0_set_15
	.long	L13_0_set_15
	.long	L13_0_set_15
	.long	L13_0_set_15
	.long	L13_0_set_15
	.long	L13_0_set_14

	.globl	_downcase
	.align	4, 0x90
_downcase:                              ## @downcase
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp42:
	.cfi_def_cfa_offset 16
Ltmp43:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp44:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	_strlen
	shlq	$0, %rax
	movq	%rax, %rdi
	callq	_malloc
	movq	%rax, -16(%rbp)
	movq	-8(%rbp), %rdi
	callq	_strdup
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, -24(%rbp)
LBB14_1:                                ## =>This Inner Loop Header: Depth=1
	movq	-16(%rbp), %rax
	cmpb	$0, (%rax)
	je	LBB14_4
## BB#2:                                ##   in Loop: Header=BB14_1 Depth=1
	movq	-16(%rbp), %rax
	movsbl	(%rax), %edi
	callq	_tolower
	movb	%al, %cl
	movq	-16(%rbp), %rdx
	movb	%cl, (%rdx)
## BB#3:                                ##   in Loop: Header=BB14_1 Depth=1
	movq	-16(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -16(%rbp)
	jmp	LBB14_1
LBB14_4:
	movq	-24(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_findStudent
	.align	4, 0x90
_findStudent:                           ## @findStudent
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp45:
	.cfi_def_cfa_offset 16
Ltmp46:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp47:
	.cfi_def_cfa_register %rbp
	subq	$480, %rsp              ## imm = 0x1E0
	leaq	L_.str39(%rip), %rdi
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	$0, -420(%rbp)
	movl	$0, -444(%rbp)
	movl	$0, -448(%rbp)
	movb	$0, %al
	callq	_printf
	movl	%eax, -452(%rbp)        ## 4-byte Spill
LBB15_1:                                ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB15_2 Depth 2
                                        ##     Child Loop BB15_10 Depth 2
	leaq	L_.str40(%rip), %rdi
	movl	$32, %eax
	movl	%eax, %esi
	movl	$0, -444(%rbp)
	callq	_inputString
	movq	%rax, %rdi
	callq	_downcase
	leaq	L_.str41(%rip), %rdi
	movq	%rax, -432(%rbp)
	movb	$0, %al
	callq	_printf
	movl	$0, -420(%rbp)
	movl	%eax, -456(%rbp)        ## 4-byte Spill
LBB15_2:                                ##   Parent Loop BB15_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movl	-420(%rbp), %eax
	cmpl	_numStudents(%rip), %eax
	jge	LBB15_7
## BB#3:                                ##   in Loop: Header=BB15_2 Depth=2
	movq	_students@GOTPCREL(%rip), %rax
	movslq	-420(%rbp), %rcx
	imulq	$80, %rcx, %rcx
	addq	%rcx, %rax
	addq	$32, %rax
	movq	%rax, %rdi
	callq	_downcase
	movq	%rax, -440(%rbp)
	movq	-440(%rbp), %rdi
	movq	-432(%rbp), %rsi
	callq	_strstr
	cmpq	$0, %rax
	je	LBB15_5
## BB#4:                                ##   in Loop: Header=BB15_2 Depth=2
	movl	-420(%rbp), %eax
	movslq	-444(%rbp), %rcx
	movl	%eax, -416(%rbp,%rcx,4)
	movl	-444(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -444(%rbp)
LBB15_5:                                ##   in Loop: Header=BB15_2 Depth=2
	jmp	LBB15_6
LBB15_6:                                ##   in Loop: Header=BB15_2 Depth=2
	movl	-420(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -420(%rbp)
	jmp	LBB15_2
LBB15_7:                                ##   in Loop: Header=BB15_1 Depth=1
	cmpl	$0, -444(%rbp)
	jne	LBB15_9
## BB#8:                                ##   in Loop: Header=BB15_1 Depth=1
	leaq	L_.str42(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -460(%rbp)        ## 4-byte Spill
	jmp	LBB15_14
LBB15_9:                                ##   in Loop: Header=BB15_1 Depth=1
	leaq	L_.str43(%rip), %rdi
	movl	-444(%rbp), %esi
	movb	$0, %al
	callq	_printf
	movl	$0, -420(%rbp)
	movl	%eax, -464(%rbp)        ## 4-byte Spill
LBB15_10:                               ##   Parent Loop BB15_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movl	-420(%rbp), %eax
	cmpl	-444(%rbp), %eax
	jge	LBB15_13
## BB#11:                               ##   in Loop: Header=BB15_10 Depth=2
	movq	_students@GOTPCREL(%rip), %rax
	movslq	-420(%rbp), %rcx
	movslq	-416(%rbp,%rcx,4), %rcx
	imulq	$80, %rcx, %rcx
	addq	%rcx, %rax
	movq	%rax, %rdi
	callq	_printStudent
	leaq	L_.str36(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -468(%rbp)        ## 4-byte Spill
## BB#12:                               ##   in Loop: Header=BB15_10 Depth=2
	movl	-420(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -420(%rbp)
	jmp	LBB15_10
LBB15_13:                               ##   in Loop: Header=BB15_1 Depth=1
	jmp	LBB15_14
LBB15_14:                               ##   in Loop: Header=BB15_1 Depth=1
	jmp	LBB15_15
LBB15_15:                               ##   in Loop: Header=BB15_1 Depth=1
	leaq	L_.str44(%rip), %rdi
	callq	_confirm
	cmpl	$0, %eax
	jne	LBB15_1
## BB#16:
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	cmpq	-8(%rbp), %rax
	jne	LBB15_18
## BB#17:                               ## %SP_return
	addq	$480, %rsp              ## imm = 0x1E0
	popq	%rbp
	retq
LBB15_18:                               ## %CallStackCheckFailBlk
	callq	___stack_chk_fail
	.cfi_endproc

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp48:
	.cfi_def_cfa_offset 16
Ltmp49:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp50:
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	movl	$0, -4(%rbp)
	movl	$0, -8(%rbp)
LBB16_1:                                ## =>This Inner Loop Header: Depth=1
	movl	_numStudents(%rip), %esi
	leaq	L_.str45(%rip), %rdi
	xorl	%eax, %eax
	movb	%al, %cl
	movb	%cl, %al
	movb	%cl, -9(%rbp)           ## 1-byte Spill
	callq	_printf
	leaq	L_.str46(%rip), %rdi
	movl	%eax, -16(%rbp)         ## 4-byte Spill
	callq	_inputInteger
	movl	%eax, -8(%rbp)
	leaq	L_.str36(%rip), %rdi
	movb	-9(%rbp), %al           ## 1-byte Reload
	callq	_printf
	movl	-8(%rbp), %esi
	decl	%esi
	movl	%esi, %edi
	subl	$5, %esi
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	movq	%rdi, -32(%rbp)         ## 8-byte Spill
	movl	%esi, -36(%rbp)         ## 4-byte Spill
	ja	LBB16_16
## BB#22:                               ##   in Loop: Header=BB16_1 Depth=1
	leaq	LJTI16_0(%rip), %rax
	movq	-32(%rbp), %rcx         ## 8-byte Reload
	movslq	(%rax,%rcx,4), %rdx
	addq	%rax, %rdx
	jmpq	*%rdx
LBB16_2:                                ##   in Loop: Header=BB16_1 Depth=1
	callq	_addStudents
	jmp	LBB16_19
LBB16_3:                                ##   in Loop: Header=BB16_1 Depth=1
	callq	_findStudent
	jmp	LBB16_19
LBB16_4:                                ##   in Loop: Header=BB16_1 Depth=1
	callq	_listStudents
	jmp	LBB16_19
LBB16_5:                                ##   in Loop: Header=BB16_1 Depth=1
	callq	_sortStudents
	jmp	LBB16_19
LBB16_6:                                ##   in Loop: Header=BB16_1 Depth=1
	cmpl	$0, _numStudents(%rip)
	je	LBB16_8
## BB#7:                                ##   in Loop: Header=BB16_1 Depth=1
	leaq	L_.str47(%rip), %rdi
	callq	_confirm
	cmpl	$0, %eax
	je	LBB16_9
LBB16_8:                                ##   in Loop: Header=BB16_1 Depth=1
	callq	_loadStudents
	movl	%eax, -40(%rbp)         ## 4-byte Spill
LBB16_9:                                ##   in Loop: Header=BB16_1 Depth=1
	jmp	LBB16_19
LBB16_10:                               ##   in Loop: Header=BB16_1 Depth=1
	cmpl	$0, _numStudents(%rip)
	jne	LBB16_12
## BB#11:                               ##   in Loop: Header=BB16_1 Depth=1
	leaq	L_.str48(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -44(%rbp)         ## 4-byte Spill
	jmp	LBB16_15
LBB16_12:                               ##   in Loop: Header=BB16_1 Depth=1
	leaq	L_.str49(%rip), %rdi
	callq	_confirm
	cmpl	$0, %eax
	je	LBB16_14
## BB#13:                               ##   in Loop: Header=BB16_1 Depth=1
	callq	_saveStudents
	movl	%eax, -48(%rbp)         ## 4-byte Spill
LBB16_14:                               ##   in Loop: Header=BB16_1 Depth=1
	jmp	LBB16_15
LBB16_15:                               ##   in Loop: Header=BB16_1 Depth=1
	jmp	LBB16_19
LBB16_16:                               ##   in Loop: Header=BB16_1 Depth=1
	leaq	L_.str50(%rip), %rdi
	callq	_confirm
	cmpl	$0, %eax
	je	LBB16_18
## BB#17:
	leaq	L_.str51(%rip), %rdi
	movb	$0, %al
	callq	_printf
	xorl	%edi, %edi
	movl	%eax, -52(%rbp)         ## 4-byte Spill
	callq	_exit
LBB16_18:                               ##   in Loop: Header=BB16_1 Depth=1
	jmp	LBB16_19
LBB16_19:                               ##   in Loop: Header=BB16_1 Depth=1
	jmp	LBB16_20
LBB16_20:                               ##   in Loop: Header=BB16_1 Depth=1
	movb	$1, %al
	testb	$1, %al
	jne	LBB16_1
	jmp	LBB16_21
LBB16_21:
	xorl	%eax, %eax
	addq	$64, %rsp
	popq	%rbp
	retq
	.cfi_endproc
	.align	2, 0x90
L16_0_set_2 = LBB16_2-LJTI16_0
L16_0_set_3 = LBB16_3-LJTI16_0
L16_0_set_4 = LBB16_4-LJTI16_0
L16_0_set_5 = LBB16_5-LJTI16_0
L16_0_set_6 = LBB16_6-LJTI16_0
L16_0_set_10 = LBB16_10-LJTI16_0
LJTI16_0:
	.long	L16_0_set_2
	.long	L16_0_set_3
	.long	L16_0_set_4
	.long	L16_0_set_5
	.long	L16_0_set_6
	.long	L16_0_set_10

	.globl	_numStudents            ## @numStudents
.zerofill __DATA,__common,_numStudents,4,2
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"students.dat"

L_.str1:                                ## @.str1
	.asciz	"wb"

L_.str2:                                ## @.str2
	.asciz	"Unable to open file!\n"

L_.str3:                                ## @.str3
	.asciz	"Saving %d students ...\t"

	.comm	_students,8000,4        ## @students
L_.str4:                                ## @.str4
	.asciz	"%d  "

L_.str5:                                ## @.str5
	.asciz	"rb"

L_.str6:                                ## @.str6
	.asciz	"\nLoading %d students ...\t"

L_.str7:                                ## @.str7
	.asciz	"%s"

L_.str8:                                ## @.str8
	.space	1

L_.str9:                                ## @.str9
	.asciz	"%d/%d/%d"

L_.str10:                               ## @.str10
	.asciz	"y"

L_.str11:                               ## @.str11
	.asciz	"Y"

L_.str12:                               ## @.str12
	.asciz	"Add Students\n============\n\nStart entering students. Leave first name blank to stop.\n\n"

L_.str13:                               ## @.str13
	.asciz	"Student #%d\n"

L_.str14:                               ## @.str14
	.asciz	"First name: "

L_.str15:                               ## @.str15
	.asciz	"Last name: "

L_.str16:                               ## @.str16
	.asciz	"Completed credits: "

L_.str17:                               ## @.str17
	.asciz	"Enrollment date (mm/dd/yyyy): "

L_.str18:                               ## @.str18
	.asciz	"\nFirst name: %s\nLast name: %s\nCompleted credits: %d\nEnrollment date: %s\n"

L_.str19:                               ## @.str19
	.asciz	"Info correct (y/n) ?"

L_.str20:                               ## @.str20
	.asciz	"Add another student (y/n) ?"

L_.str21:                               ## @.str21
	.asciz	"%m/%d/%Y"

L_.str22:                               ## @.str22
	.asciz	"%s, %s\n"

L_.str23:                               ## @.str23
	.asciz	"Date enrolled: %s\n"

L_.str24:                               ## @.str24
	.asciz	"Completed credits: %d\n"

L_.str25:                               ## @.str25
	.asciz	"%s, %s"

L_.str26:                               ## @.str26
	.asciz	"%s %s"

L_.str27:                               ## @.str27
	.asciz	"\nEditing Student #%d\n"

L_.str28:                               ## @.str28
	.asciz	"First name: [%s] "

L_.str29:                               ## @.str29
	.asciz	"Last name: [%s] "

L_.str30:                               ## @.str30
	.asciz	"Completed credits: [%d] "

L_.str31:                               ## @.str31
	.asciz	"Enrollment date (mm/dd/yyyy): [%s] "

L_.str32:                               ## @.str32
	.asciz	"\nInfo correct (y/n) ?"

L_.str33:                               ## @.str33
	.asciz	"ALL STUDENTS\n\n"

L_.str34:                               ## @.str34
	.asciz	"  #  Student Name\t\t\tEnrolled    Credits\n===  ============\t\t\t==========  =======\n"

L_.str35:                               ## @.str35
	.asciz	"%3d  %-34.34s %10s  %7d\n"

L_.str36:                               ## @.str36
	.asciz	"\n"

L_.str37:                               ## @.str37
	.asciz	"Enter # to edit, Enter to return to menu. "

L_.str38:                               ## @.str38
	.asciz	"Sort by:\tL) Last Name\n\t\tF) First Name\n\t\tE) Enrollment Date\n\t\tC) Completed Credits ? "

L_.str39:                               ## @.str39
	.asciz	"FIND STUDENT BY LAST NAME\n\n"

L_.str40:                               ## @.str40
	.asciz	"Last name? "

L_.str41:                               ## @.str41
	.asciz	"\n\nSearching ... "

L_.str42:                               ## @.str42
	.asciz	"No matches found.\n"

L_.str43:                               ## @.str43
	.asciz	"Found %d students:\n\n"

L_.str44:                               ## @.str44
	.asciz	"Find another (y/n) ? "

L_.str45:                               ## @.str45
	.asciz	"\n\nWelcome to STUDENTS!\n===================\n\nThere are currently %d students in memory.\n\n1.  Add New Student(s)\n\n2.  Find Student by Last Name\n\n3.  List All Students\n\n4.  Sort Database\n\n5.  Load Students File (./students.dat)\n\n6.  Save Students File (./students.dat)\n\n7.  Quit\n\n"

L_.str46:                               ## @.str46
	.asciz	"Choice: "

L_.str47:                               ## @.str47
	.asciz	"Overwrite memory with students from file (y/n) ? "

L_.str48:                               ## @.str48
	.asciz	"There are no students to save yet!\n"

L_.str49:                               ## @.str49
	.asciz	"Overwrite the file (y/n) ? "

L_.str50:                               ## @.str50
	.asciz	"Are you sure you want to quit (y/n) ? "

L_.str51:                               ## @.str51
	.asciz	"\nGoodbye!\n"


.subsections_via_symbols
