#x = $s0
#y = $s1
#z = $s2

.text
ori $s0, $zero, 3 #x = 3
ori $s1, $zero, 4 #y = 4

sll $t0, $s0, 4 #t0 = 16x
sub $t0, $t0, $s0 #t0 = 15x

sll $t1, $s1, 6 #t1 = 64y
sll $t2, $s1, 1 #t2 = 2y
add $t2, $t1, $s1 #t2 = 3y
add $t2, $t1, $t2 #y = 64y + 3y

add $t1, $t0, $t2 #t1 = 15x + 67y
sll $s2, $t1, 2 #z = ( 15*x + 67*y)*4