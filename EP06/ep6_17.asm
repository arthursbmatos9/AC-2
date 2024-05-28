#$s0 = x; $s1 = y; $t2 = k

.text
lui $t0, 0x1001 ##endereco da primeira posicao da memoria
lw $s0, 0 ($t0) #s0 = x
lw $s1, 4 ($t0) #s1 = y
ori $t1, $zero, 0 #contador de somas realizadas
ori $t2, $zero, 0 #resultado temporario da soma (no final, K)

loop:
	beq $t1, $s1, fim  #so termina quando o contador for igual a qtd de multiplicacoes necessarias
	add $t2, $t2, $s0  
	addi $t1, $t1, 1   #incrementa contador
	j loop

fim:
	sw $t2, 8 ($t0) #guardando K na memoria
	
.data
x: .word 20
y: .word 10