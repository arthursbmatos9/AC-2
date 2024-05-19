		     #colocando 0x12345678 no registrador $8
ori $8, $zero, 0x1234
sll $8, $8, 16
ori $8, $8, 0x5678

srl $9, $8, 24       #colocando 0x12 no registrador $9

sll $10, $8, 8       #colocando 0x34 no registrador $10
srl $10, $10, 24

andi $11, $8, 0xFF00 #colocando 0x56 no registrador $10
srl $11, $11, 8

andi $12, $8, 0x00FF #colocando 0x78 no registrador $10

