#a = $s0
#b = $s1
#c = $s2
#d = $s3
#x = $s4
#y = $s5

.text
ori $s0, $zero, 2 #a =2;
ori $s1, $zero, 3 #b =3;
ori $s2, $zero, 4 #c =4;
ori $s3, $zero, 5 #d =5;

add $t0, $s0, $s1 #(a+b)
add $t1, $s2, $s3 #(c+d)
sub $s4, $t0, $t1 #x = (a+b) - (c+d)

sub $t0, $s0, $s1 #a-b
add $s5, $t0, $s4 #y = a – b + x;

sub $s1, $s4, $s5 #b = x – y;



