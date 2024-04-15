#include "SoftwareSerial.h"

SoftwareSerial bluetooth(2, 3);  // TX, RX (Bluetooth).

int aleatorio;

void setup() {
  bluetooth.begin(9600);
}

void loop() {

  aleatorio = random(0, 100);

  if (bluetooth.available() > 0) {  //Verifique se há novos bytes oriundos do bluetooth.
    byte dado = bluetooth.read();

    while(dado != '0') {  //Retorna ao aplicativo uma mensagem confirmando o sucesso da operação.
      bluetooth.println(aleatorio);

      aleatorio = random(0, 100);
      
      delay(500);

      if (bluetooth.available() < 0) {  //Verifique se há novos bytes oriundos do bluetooth.
        dado = '0';
      }else{
        dado = bluetooth.read();
      }
    }
  }
  delay(200);
}