#x = $s0
#y = $s1
#z = $s2

.text
ori $t0, $zero, 0xFFFF
sll $t0, $t0, 16  #deslocando para a esquerda, ficando 0xFFFF0000
ori $s0, $t0, 0xFFFF #x = FFFFFFFF

ori $t0, $zero, 0x493E 
sll $s1, $t0, 4 #y = 300.000

sll $t0, $s1, 2 #t0 = 4y

sub $s2, $s0, $t0 #z = x - 4y
