#t0 = primeira posicao da memoria
#s0 = numero
#t1 = bit de sinal (1 = negativo, 0 = positivo)

.text
lui $t0, 0x1001 #endereco da primeira posicao da memoria
lw $s0, 0 ($t0) #carregando numero

srl $t1, $s0, 31 #deslocando os bits, deixando o de sinal na primeira posicao a direita
beq $t1, $zero, positivo #se o numero for positivo, ñ fazer nada
			 #caso negativo, pegar seu modulo e substituir na memória
sub $s0, $zero, $s0
sw $s0, 0 ($t0)

positivo:
	#se ja for positivo ñ faz nada
	
	
.data
A: .word -15