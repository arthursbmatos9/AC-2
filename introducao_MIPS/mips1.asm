#x=1
#y=2
#z=x+y
#x-> $s0, y-> $s1, z->$s2


#inicio
       #obs: uma palavra seguida de ":" significa que esta marcando a linha
.text 
.globl puc #local que vai comecar o programa, no caso de existir algo antes da main
puc: 
	addi $s0, $zero, 1   #x=1
puc1: 
	addi $s1, $zero, 2   #y=2
puc2: 
	sub $s2, $s0, $s1    #z=x-y

	j puc     #j = jump (vai para a posicao)
	
	
.data 


