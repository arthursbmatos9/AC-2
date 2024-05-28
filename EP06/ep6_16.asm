#$s0 = x; $s1 = y; $s2 = z

.text
ori $s0, $zero, 0x186A
sll $s0, $s0, 8           #s0 = 1.600.000
ori $s1, $zero, 0x1388
sll $s1, $s1, 4           #s1 = 80.000
ori $s2, $zero, 0x61A8
sll $s2, $s2, 4           #s2 = 400.000

div $s0, $s2   #x/z
mflo $t0       #pega resultado e salva em t0
mult $t0, $s1  #(x/z) * y
mflo $t0       #pega resultado e salva em t0

.data
