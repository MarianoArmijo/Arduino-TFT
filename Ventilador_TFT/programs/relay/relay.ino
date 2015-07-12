// Relay
// Programa para encender o/y apagar un relay.
  
int ch1 = 11; // asigno una variable int indicando el puerto por el que se conecta el servo

void setup() 
{ 
  pinMode(ch1, OUTPUT);
} 
 
void loop() 
{ 

  digitalWrite(ch1, HIGH);
} 
