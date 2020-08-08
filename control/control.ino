#include <VirtualWire.h>
const int ypin = A0;
const int xpin = A1;
const int emisor = 4;
int xPosition=0; 
int yPosition=0;
int ledtest = 13;

const int push = 2;
void setup(){
  Serial.begin(9600);
  pinMode(xpin,INPUT);
  pinMode(ypin,INPUT);
  pinMode(push,INPUT);
  pinMode(ledtest,OUTPUT);

  vw_setup(2000); //velocidad en Bits por segundo
  vw_set_tx_pin(emisor);


}

void loop(){
String str;  
    char buf[VW_MAX_MESSAGE_LEN];
  xPosition = analogRead(xpin);
  yPosition = analogRead(ypin);
  Serial.println(String(xPosition)+","+String(yPosition));
   
   // Ejemplo de envío int
   int dataInt = millis() / 1000;
    str = "i" + String(xPosition) +","+String(yPosition); /// Convertir a string
    str.toCharArray(buf,sizeof(buf)); // Convertir a char array
    vw_send((uint8_t *)buf, strlen(buf)); // Enviar array
    vw_wait_tx(); // Esperar envio
    
}
