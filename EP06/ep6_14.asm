#t0 = primeira posicao da memoria
#s0 = numero
#t1 = bit de verificacao de par ou impar (0 = par, 1 = impar)

.text
lui $t0, 0x1001 #endereco da primeira posicao da memoria
lw $s0, 0 ($t0) #carregando numero

andi $t1, $s0, 1 #faz um ANDi com o valor e o numero 1, se der 0 é par, se der 1, é impar
bne $t1, $zero, impar #se for par, vai atribuir 0 a t1, se for impar, vai atribuir 1 a t1
sw $t1, 4 ($t0)
j fim

impar:
   sw $t1, 4 ($t0)
   
fim:

.data
A: .word 2023