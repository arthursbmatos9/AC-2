ori $8, $0, 0x01    #estado inicial
ori $8, $8, 0xFFFF  #fazendo ORI, ficando 0000FFFF
sll $8, $8, 16      #deslocando para esquerda, ficando FFFF0000
ori $8, $8, 0xFFFF  #fazendo ORI, ficando FFFFFFFF