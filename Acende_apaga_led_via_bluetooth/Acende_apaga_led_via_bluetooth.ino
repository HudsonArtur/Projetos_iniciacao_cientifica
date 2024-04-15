#define LED_PIN 9 //Pino conectado ao led.
#include "SoftwareSerial.h"

SoftwareSerial bluetooth(2, 3); // TX, RX (Bluetooth).

void setup() {
  bluetooth.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}
void loop() {

  if (bluetooth.available() > 0) {//Verifique se há novos bytes oriundos do bluetooth. 
    byte dado = bluetooth.read();
    if (dado == '1') {//Ative o led se a mensagem for um caracter '1'.
      digitalWrite(LED_PIN, HIGH);
    }
    if (dado == '0') {//Desative o led se a mensagem for um caracter '0'.
      digitalWrite(LED_PIN, LOW);
    }
  }

  bluetooth.println(millis());//Envie o retorno da funçao millis().
  delay(1000);
}