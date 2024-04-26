int ledVermelho = 13;
int ledAmarelo = 12;
int ledVerde = 11;
int ledAzul = 10;

void setup() {
	pinMode(ledVermelho, OUTPUT); 
  	pinMode(ledAmarelo, OUTPUT); 
  	pinMode(ledVerde, OUTPUT); 
  	pinMode(ledAzul, OUTPUT);
}
            
void loop () {
	digitalWrite(ledVermelho, HIGH);
  
  for (int i= 0; i< 3; i++){
		digitalWrite(ledAzul, HIGH);
		delay(1000);
		digitalWrite (ledAzul, LOW);
		delay(1000);
  }
	
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledVerde, HIGH);
	
  for(int i= 0; i< 4; i++){
    	digitalWrite(ledAzul, HIGH);
		delay(1000);
		digitalWrite(ledAzul, LOW);
		delay(1000);
  }
              
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, HIGH);
               
  for(int i= 0; i< 2; i++){
		digitalWrite (ledAzul, HIGH);
		delay(1000);
		digitalWrite (ledAzul, LOW);
		delay(1000);
	}
               
	digitalWrite (ledAmarelo, LOW);
}