#y =   x^3 + 1    se x > 0
#      x^4 - 1     se x <= 0
      
#Os valores de  x devem ser lidos da primeira posição livre da memória e o valor de y deverá ser 
#escrito na segunda posição livre

.text
lui $t0, 0x1001     #primeira posicao da memoria
lw $s0, 0 ($t0)     #pegando x

slt $t1, $zero, $s0 #verificando se x > 0 (se $t1= 1, sim; se $t1= 0, nao)
bne $t1, $zero, maior

menorIgual:
	mult $s0, $s0 #x^2
	mflo $t2      
	mult $t2, $s0 #x^3
	mflo $t2
	mult $t2, $s0 
	mflo $t2      #x^4
	
	ori $t3, $zero, 1 #colocando 1 em um registrador para poder subtrair com o numero 1
	sub $t3, $t2, $t3 #t3 = x^4 - 1

	j fim

maior:
	mult $s0, $s0 #x^2
	mflo $t2      
	mult $t2, $s0 
	mflo $t2      #x^3
	
	ori $t3, $zero, 1 #colocando 1 em um registrador para poder somar com o numero 1
	add $t3, $t2, $t3 #t3 = x^3 + 1

fim:
	sw $t3, 4 ($t0)

.data
x: .word 2
