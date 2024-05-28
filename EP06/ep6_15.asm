#t0 = posicao na memoria
#t1 = soma
#t2 = 100 (condicao de parada)
#t3 = contador da posicao atual (i)
#t4 = valor a ser inserido na memoria

.text
lui $t0, 0x1001 #endereco da primeira posicao da memoria
lw $s0, 0 ($t0) #carregando numero

ori $t1, $zero, 0   #inicio da soma
ori $t2, $zero, 100 #condicao de parada do loop
ori $t3, $zero, 0   #contador da posicao atual (i)

loop:
	beq $t2, $t3, fim #condicao de parada: contador de posicao ser igual a ultima posicao do array + 1
	add $t4, $t3, $t3 #operacao
	addi $t4, $t4, 1  #operacao
	add $t1, $t1, $t4 #soma = soma + t4 (v[i])
	sw $t4, 0 ($t0)   #armazenando o valor na memoria
	addi $t0, $t0, 4  #atualizando a posicao da memoria
	addi $t3, $t3, 1  #atualizando o contador de posicoes
	j loop

fim:
	sw $t1, 0 ($t0) #escreve na memoria a soma dos valores do vetor

.data


