#$s0 = x; $s1 = z; $s2 = y; $t0 = endereco da primeira posicao de memoria
.text
lui $t0, 0x1001

lw $s0, 0 ($t0)
sll $t1, $s0, 7   #t1 = 128x
sub $s0, $t1, $s0 #x = 127x

lw $s1, 4 ($t0)
sll $t1, $s1, 6   #t1 = 64z
add $s1, $t1, $s1 #z = 65z

sub $t1, $s0, $s1      #t1 = 127x - 65z
ori $t2, $zero, 0x0001 #t2 = 1
add $s2, $t1, $t2      #z = 127x – 65z + 1

sw $s2, 8 ($t0)    #salvando na memoria o valor de Y atualizado

.data 
x: .word 5 
z: .word 7 
y: .word 0   