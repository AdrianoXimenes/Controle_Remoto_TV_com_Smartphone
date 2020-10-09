#include <IRremote.h> // Biblioteca para controlar o led infravermelho   
IRsend irsend; //variável para poder enviar o código a TV


int ledIR = 3;
int estado;


void setup() {
  pinMode(ledIR , OUTPUT); // saída do infravermelho
  Serial.begin(9600);
  }

void loop() {

  if (Serial.available() > 0) {  // Vai ler e armazenar o estado do bluetooth
    estado = Serial.read();
  }

  if (estado == 'L') {               
    irsend.sendNEC(0xE0E040BF, 32);// código em infravermelho que sera enviado a tv para ligar/desligar
    Serial.print("Liga");
    delay(4000);
  }

  if (estado == 'V') {

    irsend.sendNEC(0xE0E0E01F, 32);// código em infravermelho que sera enviado a tv para aumentar o volume
    delay(40);
    Serial.println("Aumenta volume");
  }

  if (estado == 'v') {

    irsend.sendNEC(0xE0E0D02F, 32);// código em infravermelho que sera enviado a tv para diminuir o volume
    delay(40);
    Serial.println("Diminui volume");
  }

  if (estado == 'C') {

    irsend.sendNEC(0xE0E048B7, 32); // código em infravermelho que sera enviado a tv para aumentar o canal
    delay(40);
    Serial.println("Muda de canal +");
  }

  if (estado == 'c') {

    irsend.sendNEC(0xE0E008F7, 32); // código em infravermelho que sera enviado a tv para diminuir o canal
    delay(40);
    Serial.println("Muda de canal -");
  }
  
  if (estado == 'F') {

    irsend.sendNEC(0xE0E008F, 32); // código em infravermelho que sera enviado a tv para diminuir o canal
    delay(40);
    Serial.println("Muda de canal -");
  }
}
