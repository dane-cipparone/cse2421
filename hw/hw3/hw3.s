.file		"hw3.s"		#optional directive
.section	.rodata		#required directives for rodata
.LC0:
	.string	"Please enter an integer on the next line, followed by enter:\n"
.LC1:
	.string	"%i"
.LC2:
	.string	"The value of x after adding 5 is: %i\n"

.data				#required for file-scope data: read-write program data
				#ofd static storage class
x:
	.quad 0

.globl main			#required directive for every function
	.type	main, @function	#required directive

.text				#required directive
main:
	pushq	%rbp
	movq	%rsp, %rbp
	movq	$.LC0, %rdi
	movq	$0, %rax
	call	printf
	movq	$x, %rsi
	movq	$.LC1, %rdi
	movq	$0, %rax
	call	scanf
	addq	$5, x
	movq	x, %rsi
	movq	$.LC2, %rdi
	movq	$0, %rax
	call	printf
	movq	$0, %rax
	leave
	ret
	.size	main, .-main
