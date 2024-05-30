#y =   x^4 + x^3 -2x^2    se x for par 
#      x^5 – x^3  + 1     se x for impar 
      
#Os valores de x devem ser lidos da primeira posição livre da memória e o valor de y deverá ser 
#escrito na segunda posição livre. 

.text
lui $t0, 0x1001     #primeira posicao da memoria
lw $s0, 0 ($t0)     #pegando x

andi $t1, $s0, 1    #verifica se eh par ou impar (se $t1 = 1, impar; se $t1 = 0, par)
beq $t1, $zero, par #se for par vai para o label par, caso impar, seguir as proximas linhas

impar:
	mult $s0, $s0 #x^2
	mflo $t2      
	mult $t2, $s0 
	mflo $t2      #x^3
	mult $t2, $s0 #x^4
	mflo $t3      
	mult $t3, $s0 
	mflo $t3      #x^5

	ori $t4, $zero, 1 #colocando 1 em um registrador para poder somar com o numero 1
	sub $t3, $t3, $t2  #t3 = x^5 – x^3
	add $t5, $t3, $t4  #t5 = x^5 – x^3  + 1
		
	j fim
	
par:
	mult $s0, $s0 
	mflo $t2      #x^2
	mult $t2, $s0 
	mflo $t3      #x^3
	mult $t3, $s0 
	mflo $t4      #x^4
	
	
	ori $t5, $zero, 2   #colocando 2 em um registrador para poder multiplicar por pelo numero 2
	mult $t2, $t5       #t2 = 2x^2
	mflo $t2
	add $t4, $t4, $t3   #t4 = x^4 + x^3
	sub $t5, $t4, $t3   #t5 = x^4 + x^3 - 2x^2
	
fim:
	sw $t5, 4 ($t0)     #guardando o resultado na memoria
	
.data
x: .word 3
