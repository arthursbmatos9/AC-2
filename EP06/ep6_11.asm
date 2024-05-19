#$s0 = x; $s1 = z; $s2 = y; $t0 = endereco da primeira posicao de memoria
.text
lui $t0, 0x1001

lw $s0, 0 ($t0) #pegando x
lw $s1, 4 ($t0) #pegando z

ori $t1, $zero, 0x493E 
sll $t1, $t1, 4    #salvando 300.000 em t1

sub $t2, $s0, $s1 #t2 = x - z
add $s2, $t2, $t1 #y = x – z + 300000

sw $s2, 8 ($t0) #salvando na memoria o valor de Y atualizado

.data 
x: .word 100000 
z: .word 200000 
y: .word 0 