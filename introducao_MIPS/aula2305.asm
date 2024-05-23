.text
.globl main
main:
  ori $s0, $zero, 5 #s0 = 5
  ori $s1, $zero, 2 #s1 = 2
  mult $s0, $s1     #faz a mutiplicacao, salvando no LO ou HI
  mflo $s2          #busca do LO, salvando em $s2
  
  div $s0, $s1    #faz a divisao, salvando a parte inteira em LO e o resto da divisao em HI
  mflo $s3        #busca do LO, salvando em $s3
  mfhi $s4        #busca do HI, salvando em $s4