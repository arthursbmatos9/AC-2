#x = $s0
#y = $s1
#vet[0] = $s2
#i = $s3
.text
.globl main
main:
	lui $s2, 0x1001
	sll $t0, $s3, 2 #t0 = 4i
	add $t1, $t0, $s2 #t1 = end base + 4i
	lw $s0, 0 ($t1)
	add $a0, $zero, $s0
	add $a1, $zero, $s0
	addi $sp, $sp, -4
	sw $t1, 4 ($sp)
	jal soma
	lw $t1, 4 ($sp)
	addi $sp, $sp, 4
	add $s1, $zero, $v0
	sw $s1, 4 ($t1)

fim: 
	addi $v0, $zero, 10
	syscall

soma:
	addi $sp, $sp, -4
	sw $s0, 4 ($sp)
	add $s0, $a0, $a1
	add $v0, $zero, $s0
	lw $s0, 4 ($sp)
	addi $sp, $sp, 4
	jr $ra