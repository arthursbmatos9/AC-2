int ledF3 = 13;
int ledF2 = 12;
int ledF1 = 11;
int ledF0 = 10;
String x, y, OPCode;
int fCompleto;

char codigo[500];
String memoria[100];
int posicao, pc, qtdTotal;

void setup() {
  Serial.begin(9600);
  pinMode(ledF3, OUTPUT);
  pinMode(ledF2, OUTPUT);
  pinMode(ledF1, OUTPUT);
  pinMode(ledF0, OUTPUT);
  
  //iniciando a memoria com "z"
  for(int i=0; i< 100; i++){
  	memoria[i] = "z";
  }
  
  //iniciando variaveis que serao utilizadas na hora de imprimir
  posicao = 4;
  pc = 4;
  fCompleto = 0;
  qtdTotal = 0;
  x = "0";
  y = "0";
}




void loop() {
  if (Serial.available() > 0) {
    String entrada = Serial.readStringUntil('Z'); //le a entrada ate encontrar o sinalizador de final (Z)
    extrairStrings(entrada); //separa a entrada e salva na memoria as instrucoes
    posicao = 4;
  }
  
  if(qtdTotal >= 1 && posicao == 4){ 
   	mostraMemoria2();
    Serial.print("\n");
  }
  
  delay(2000);
  
  while(memoria[pc].equals("z") == false){ //pc comeca em 4 na primeira rodada do while
    //faz a leitura
    x = memoria[pc][0];
    y = memoria[pc][1];
    OPCode = memoria[pc][2];
  
    //se x for uma letra, transformar para decimal
    if(x.equals("A"))
        x = "10";
    else if(x.equals("B"))
        x = "11";
    else if(x.equals("C"))
        x = "12";
    else if(x.equals("D"))
        x = "13";
    else if(x.equals("E"))
        x = "14";
    else if(x.equals("F"))
        x = "15";
  
    //se y for uma letra, transformar para decimal
    if(y.equals("A"))
        y = "10";
    else if(y.equals("B"))
        y = "11";
    else if(y.equals("C"))
        y = "12";
    else if(y.equals("D"))
        y = "13";
    else if(y.equals("E"))
        y = "14";
    else if(y.equals("F"))
        y = "15";
 
    // identifica qual operacao a ser realizada
    if (OPCode.equals("0"))
        fCompleto = op0(x.toInt(), y.toInt());
    else if (OPCode.equals("1"))
        fCompleto = op1(x.toInt(), y.toInt());
    else if (OPCode.equals("2"))
        fCompleto = op2(x.toInt(), y.toInt());
    else if (OPCode.equals("3"))
        fCompleto = op3(x.toInt(), y.toInt());
    else if (OPCode.equals("4"))
        fCompleto = op4(x.toInt(), y.toInt());
    else if (OPCode.equals("5"))
        fCompleto = op5(x.toInt(), y.toInt());
    else if (OPCode.equals("6"))
        fCompleto = op6(x.toInt(), y.toInt());
    else if (OPCode.equals("7"))
        fCompleto = op7(x.toInt(), y.toInt());
    else if (OPCode.equals("8"))
        fCompleto = op8(x.toInt(), y.toInt());
    else if (OPCode.equals("9"))
        fCompleto = op9(x.toInt(), y.toInt());
    else if (OPCode.equals("A"))
        fCompleto = opA(x.toInt(), y.toInt());
    else if (OPCode.equals("B"))
        fCompleto = opB(x.toInt(), y.toInt());
    else if (OPCode.equals("C"))
        fCompleto = opC(x.toInt(), y.toInt());
    else if (OPCode.equals("D"))
        fCompleto = opD(x.toInt(), y.toInt());
    else if (OPCode.equals("E"))
        fCompleto = opE(x.toInt(), y.toInt());
    else if (OPCode.equals("F"))
        fCompleto = opF(x.toInt(), y.toInt());  
    
    mostraMemoria();
    acenderLeds(fCompleto);

    delay(2000);

    //apaga todos os leds para poder executar proxima instrucao
    digitalWrite(ledF3, LOW);
    digitalWrite(ledF2, LOW);
    digitalWrite(ledF1, LOW);
    digitalWrite(ledF0, LOW);

    delay(2000);
   	
    Serial.print("\n");
  } //fim do for
}

void extrairStrings(String entrada) {
  String temp = ""; //string temporaria que servira para salvar na memoria

  //le a string caracter por caracter
  for (int i = 0; i < entrada.length(); i++) { 
    //se for diferente de espaco, ainda faz parte da instrucao
    if (entrada[i] != ' ')
      temp += entrada[i];
    
    //se encontrar um espaco vazio, manda pra memoria o que foi encontrado
    else { 
      if (temp != "") {
        memoria[posicao++] = temp;
        qtdTotal++;
      } 
      
      //reseta o temp para ler a proxima instrucao
      temp = "";
    }
  }
}

void mostraMemoria2(){
  //printando a posicao e os valores de W, X e Y
  	Serial.print("| ");
	Serial.print(pc);
	Serial.print(" | ");
    Serial.print(converter(fCompleto));
	Serial.print(" | ");
    Serial.print(converter(x));
	Serial.print(" | ");
    Serial.print(converter(y));
	Serial.print(" | ");
  
    //mostrando a memoria de programa
    while(memoria[posicao].equals("z") == false){
	   Serial.print(memoria[posicao++]);
       Serial.print(" | ");
     }
}

void mostraMemoria(){
  	//printando a posicao e os valores de W, X e Y
  	Serial.print("| ");
	Serial.print(++pc); //incrementa o PC antes de usar
	Serial.print(" | ");
    Serial.print(converter(fCompleto));
	Serial.print(" | ");
    Serial.print(converter(x));
	Serial.print(" | ");
    Serial.print(converter(y));
	Serial.print(" | ");
  
  	//voltando posicao para o inicio da memoria para printa-la
  	posicao = 4;
  
    //mostrando a memoria de programa
    while(memoria[posicao].equals("z") == false){
	   Serial.print(memoria[posicao++]);
       Serial.print(" | ");
     }
}

String converter(int f) { 
  if (f == 0 || f == -16) { 
    return "0"; 
  } else if (f == 1 || f == -15) {
    return "1"; 
  } else if (f == 2 || f == -14) {
    return "2";
  } else if (f == 3 || f == -13) {
    return "3";
  } else if (f == 4 || f == -12) {
    return "4";
  } else if (f == 5 || f == -11) {
    return "5";
  } else if (f == 6 || f == -10) {
    return "6";
  } else if (f == 7 || f == -9) {
    return "7";
  } else if (f == 8 || f == -8) {
    return "8";
  } else if (f == 9 || f == -7) {
    return "9";
  } else if (f == 10 || f == -6) {
    return "A";
  } else if (f == 11 || f == -5) {
    return "B";
  } else if (f == 12 || f == -4) {
    return "C";
  } else if (f == 13 || f == -3) {
    return "D";
  } else if (f == 14 || f == -2) {
    return "E";
  } else if (f == 15 || f == -1) {
    return "F";
  }
}

String converter(String f) { 
  if (f.equals("10")) {
    return "A";
  } else if (f.equals("11")) {
    return "B";
  } else if (f.equals("12")) {
    return "C";
  } else if (f.equals("13")) {
    return "D";
  } else if (f.equals("14")) {
    return "E";
  } else if (f.equals("15")) {
    return "F";
  } else {
    return f;
  }
}

void acenderLeds(int f) { //acende os LEDS de acordo com o valor
  if (f == 0) {
    digitalWrite(ledF3, LOW);
    digitalWrite(ledF2, LOW);
    digitalWrite(ledF1, LOW);
    digitalWrite(ledF0, LOW);
  } else if (f == 1 || f == -15) {
    digitalWrite(ledF3, LOW);
    digitalWrite(ledF2, LOW);
    digitalWrite(ledF1, LOW);
    digitalWrite(ledF0, HIGH);
  } else if (f == 2 || f == -14) {
    digitalWrite(ledF3, LOW);
    digitalWrite(ledF2, LOW);
    digitalWrite(ledF1, HIGH);
    digitalWrite(ledF0, LOW);
  } else if (f == 3 || f == -13) {
    digitalWrite(ledF3, LOW);
    digitalWrite(ledF2, LOW);
    digitalWrite(ledF1, HIGH);
    digitalWrite(ledF0, HIGH);
  } else if (f == 4 || f == -12) {
    digitalWrite(ledF3, LOW);
    digitalWrite(ledF2, HIGH);
    digitalWrite(ledF1, LOW);
    digitalWrite(ledF0, LOW);
  } else if (f == 5 || f == -11) {
    digitalWrite(ledF3, LOW);
    digitalWrite(ledF2, HIGH);
    digitalWrite(ledF1, LOW);
    digitalWrite(ledF0, HIGH);
  } else if (f == 6 || f == -10) {
    digitalWrite(ledF3, LOW);
    digitalWrite(ledF2, HIGH);
    digitalWrite(ledF1, HIGH);
    digitalWrite(ledF0, LOW);
  } else if (f == 7 || f == -9) {
    digitalWrite(ledF3, LOW);
    digitalWrite(ledF2, HIGH);
    digitalWrite(ledF1, HIGH);
    digitalWrite(ledF0, HIGH);
  } else if (f == 8 || f == -8) {
    digitalWrite(ledF3, HIGH);
    digitalWrite(ledF2, LOW);
    digitalWrite(ledF1, LOW);
    digitalWrite(ledF0, LOW);
  } else if (f == 9 || f == -7) {
    digitalWrite(ledF3, HIGH);
    digitalWrite(ledF2, LOW);
    digitalWrite(ledF1, LOW);
    digitalWrite(ledF0, HIGH);
  } else if (f == 10 || f == -6) {
    digitalWrite(ledF3, HIGH);
    digitalWrite(ledF2, LOW);
    digitalWrite(ledF1, HIGH);
    digitalWrite(ledF0, LOW);
  } else if (f == 11 || f == -5) {
    digitalWrite(ledF3, HIGH);
    digitalWrite(ledF2, LOW);
    digitalWrite(ledF1, HIGH);
    digitalWrite(ledF0, HIGH);
  } else if (f == 12 || f == -4) {
    digitalWrite(ledF3, HIGH);
    digitalWrite(ledF2, HIGH);
    digitalWrite(ledF1, LOW);
    digitalWrite(ledF0, LOW);
  } else if (f == 13 || f == -3) {
    digitalWrite(ledF3, HIGH);
    digitalWrite(ledF2, HIGH);
    digitalWrite(ledF1, LOW);
    digitalWrite(ledF0, HIGH);
  } else if (f == 14 || f == -2) {
    digitalWrite(ledF3, HIGH);
    digitalWrite(ledF2, HIGH);
    digitalWrite(ledF1, HIGH);
    digitalWrite(ledF0, LOW);
  } else if (f == 15 || f == -1) {
    digitalWrite(ledF3, HIGH);
    digitalWrite(ledF2, HIGH);
    digitalWrite(ledF1, HIGH);
    digitalWrite(ledF0, HIGH);
  }
}

//conjunto de operacoes a serem realizadas
int op0(int x, int y) {
  return ~y;
}

int op1(int x, int y) {
  return ~(~x & y);
}

int op2(int x, int y) {
  return ~x & y;
}

int op3(int x, int y) {
  return 0x0;
}

int op4(int x, int y) {
  return ~(x & y);
}

int op5(int x, int y) {
  return ~x;
}

int op6(int x, int y) {
  return x ^ y;
}

int op7(int x, int y) {
  return x & ~y;
}

int op8(int x, int y) {
  return ~x | ~y;
}

int op9(int x, int y) {
  return ~x ^ ~y;
}

int opA(int x, int y) {
  return y;
}

int opB(int x, int y) {
  return x & y;
}

int opC(int x, int y) {
  return 0x1;
}

int opD(int x, int y) {
  return x | ~y;
}

int opE(int x, int y) {
  return x | y;
}

int opF(int x, int y) {
  return x;
}