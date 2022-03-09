	.text
	.abicalls
	.option	pic0
	.section	.mdebug.abi32,"",@progbits
	.nan	legacy
	.file	"o32_cc_byval.ll"
	.section	.rodata.cst4,"aM",@progbits,4
	.p2align	2               # -- Begin function f1
$CPI0_0:
	.4byte	1101004800              # float 20
$CPI0_1:
	.4byte	1101529088              # float 21
	.text
	.globl	f1
	.p2align	2
	.type	f1,@function
	.set	nomicromips
	.set	nomips16
	.ent	f1
f1:                                     # @f1
	.frame	$sp,56,$ra
	.mask 	0x80030000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	.set	noat
# %bb.0:                                # %entry
	addiu	$sp, $sp, -56
	sw	$ra, 52($sp)            # 4-byte Folded Spill
	sw	$17, 48($sp)            # 4-byte Folded Spill
	sw	$16, 44($sp)            # 4-byte Folded Spill
	lui	$16, %hi(f1.s1)
	addiu	$17, $16, %lo(f1.s1)
	lw	$1, 12($17)
	lw	$2, 16($17)
	lw	$3, 20($17)
	lw	$4, 24($17)
	lw	$5, 28($17)
	sw	$5, 36($sp)
	sw	$4, 32($sp)
	sw	$3, 28($sp)
	sw	$2, 24($sp)
	sw	$1, 20($sp)
	lw	$1, 8($17)
	sw	$1, 16($sp)
	lw	$6, %lo(f1.s1)($16)
	lw	$7, 4($17)
	lui	$1, %hi($CPI0_0)
	lwc1	$f12, %lo($CPI0_0)($1)
	jal	callee1
	nop
	lui	$1, %hi(f1.s2)
	addiu	$2, $1, %lo(f1.s2)
	lw	$7, 12($2)
	lw	$6, 8($2)
	lw	$5, 4($2)
	lw	$4, %lo(f1.s2)($1)
	jal	callee2
	nop
	addiu	$1, $zero, 11
	lui	$2, %hi($CPI0_1)
	lwc1	$f12, %lo($CPI0_1)($2)
	sb	$1, 40($sp)
	lw	$1, 12($17)
	lw	$2, 16($17)
	lw	$3, 20($17)
	lw	$4, 24($17)
	lw	$5, 28($17)
	sw	$5, 36($sp)
	sw	$4, 32($sp)
	sw	$3, 28($sp)
	sw	$2, 24($sp)
	sw	$1, 20($sp)
	lw	$1, 8($17)
	sw	$1, 16($sp)
	lw	$7, 4($17)
	lw	$6, %lo(f1.s1)($16)
	lbu	$1, 40($sp)
	jal	callee3
	sll	$5, $1, 24
	lw	$16, 44($sp)            # 4-byte Folded Reload
	lw	$17, 48($sp)            # 4-byte Folded Reload
	lw	$ra, 52($sp)            # 4-byte Folded Reload
	jr	$ra
	addiu	$sp, $sp, 56
	.set	at
	.set	macro
	.set	reorder
	.end	f1
$func_end0:
	.size	f1, ($func_end0)-f1
                                        # -- End function
	.type	f1.s1,@object           # @f1.s1
	.section	.rodata.cst32,"aM",@progbits,32
	.p2align	3
f1.s1:
	.byte	1                       # 0x1
	.space	1
	.2byte	2                       # 0x2
	.4byte	3                       # 0x3
	.8byte	4                       # 0x4
	.8byte	4617315517961601024     # double 5
	.4byte	6                       # 0x6
	.space	4
	.size	f1.s1, 32

	.type	f1.s2,@object           # @f1.s2
	.section	.rodata.cst16,"aM",@progbits,16
	.p2align	2
f1.s2:
	.4byte	7                       # 0x7
	.4byte	8                       # 0x8
	.4byte	9                       # 0x9
	.4byte	10                      # 0xa
	.size	f1.s2, 16


	.section	".note.GNU-stack","",@progbits
	.text
