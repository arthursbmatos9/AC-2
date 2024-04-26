int ledVermelho = 13;
int ledAmarelo = 12;
int ledVerde = 11;
int ledAzul = 10;
int a;
int b;
int OPCode;
int resultado;

void setup() {
  	Serial.begin(9600);
	pinMode(ledVermelho, OUTPUT);
  	pinMode(ledAmarelo, OUTPUT);
  	pinMode(ledVerde, OUTPUT);
  	pinMode(ledAzul, OUTPUT);
}

void loop() {
  	
  if(Serial.available() > 0){
    a = Serial.parseInt();
  	b = Serial.parseInt();
  	OPCode = Serial.parseInt();
  }
  
  mostra(a, b);
  
  if(OPCode == 0){
    resultado = p_and(a,b);
    if(resultado == 1)
      digitalWrite(ledVerde, HIGH);
  }
  else if(OPCode == 1){
	resultado = p_or(a, b);
    if(resultado == 1)
      digitalWrite(ledVerde, HIGH);
  }
  else if(OPCode == 2){
    resultado = p_not(a);
    if(resultado == 1)
      digitalWrite(ledVerde, HIGH);
  }
  else if(OPCode == 3){
	resultado = soma(a, b);
    if(resultado == 1)
      digitalWrite(ledVerde, HIGH);
    else if(resultado == 2){
		digitalWrite(ledVerde, HIGH);
      	digitalWrite(ledAzul, HIGH);
    }
  }
      
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAzul, LOW);
  	
}

void mostra(int a, int b){
	if(a == 1)
      digitalWrite(ledVermelho, HIGH);
  	if(b == 1)
      digitalWrite(ledAmarelo, HIGH);
}
   
int p_and(int a, int b){
	return(a&b);
}

int p_or(int a, int b){
	return(a|b);
}

int p_not(int a){
	if(a == 0)return 1;
  	else return 0;
}

int soma(int a, int b){
	return(a+b);
}