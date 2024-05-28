#$s0 = x; $s1 = y

.text
lui $t0, 0x1001 #endereco da primeira posicao da memoria
lw $s0, 0 ($t0) #s0 = x
lw $s1, 4 ($t0) #s1 = y
ori $t1, $zero, 1 #resultado temporario da exponenciacao (no final, K)
ori $t3, $zero, 0 #contador do expoente

loop1:
	beq $s1, $t3, fim
	ori $t2, $zero, 0 #produto parcial
	ori $t4, $zero, 0 #contador de somas (multiplicacoes)
		
	loop2:
		beq $t4, $t1, incExpo  #so termina quando o contador for igual a qtd de somas necessarias
		add $t2, $t2, $s0      #produto parcial
		addi $t4, $t4, 1       #incrementa contador
		j loop2
		
incExpo:
	ori $t1, $zero, 0 #volta o resultado temporario para 0
	add $t1, $t1, $t2 #produto passa a ser o resultado da multiplicacao do loop2
	addi $t3, $t3, 1 #incrementa contador do expoente
	j loop1
	

fim:
	sw $t1, 8 ($t0) #guardando K na memoria
	
.data
x: .word 2
y: .word 3