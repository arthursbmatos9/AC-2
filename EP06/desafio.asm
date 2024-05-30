.text
lui $t0, 0x1001  #pegando primeiro endereco de memoria e os 2 primeiros valores armazenados
lw $s0, 0 ($t0)
lw $s1, 4 ($t0)

mult $s0, $s1    #fazendo a multiplicacao
mflo $t1         #pegando o valor que esta no registrador low
sw $t1, 8 ($t0)  #guardando tal valor na 3a posicao de memoria
mfhi $t1         #pegando o valor que esta no registrador high
sw $t1, 12 ($t0) #guardando tal valor na 4a posicao de memoria

.data
x: .word -10
y: .word 10