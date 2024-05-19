#x1 = $s0; x2 = $s1; x3 = $s2; x4 = $s3; soma = $s4
#endereco inicial = A[0] = $t0 = 0x10010000

.text
lui $t0, 0x1001 #salvando o endereco do primeiro endereco da memoria

lw $s0, 0, ($t0) #pegando valor de x1
lw $s1, 4 ($t0)  #pegando valor de x2
lw $s2, 8 ($t0)  #pegando valor de x3
lw $s3, 12 ($t0) #pegando valor de x4

add $t1, $s0, $s1
add $t1, $t1, $s2
add $s4, $t1, $s3 #salvando no registrador $s4 o valor da soma

sw $s4, 16 ($t0) #salvando na memoria o valor de 'soma', que esta em $s4

.data
x1: .word 15 
x2: .word 25 
x3: .word 13 
x4: .word 17 
soma: .word -1 