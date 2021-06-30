	.text
	.section .mdebug.abiO32
	.previous
	.file	"asm-large-immediate.ll"
	.globl	test                            # -- Begin function test
	.p2align	1
	.type	test,@function
	.ent	test                            # @test
test:
	.cfi_startproc
	.frame	$sp,0,$lr
	.mask 	0x00000000,0
	.set	noreorder
	.set	nomacro
# %bb.0:                                # %entry
	#APP
	# result: 68719476738 
	#NO_APP
	#APP
	# result: -68719476738 
	#NO_APP
	ret	$lr
	nop
	.set	macro
	.set	reorder
	.end	test
$func_end0:
	.size	test, ($func_end0)-test
	.cfi_endproc
                                        # -- End function
	.section	".note.GNU-stack","",@progbits
