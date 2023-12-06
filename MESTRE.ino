// portas do joystick
#define joyX A0
#define joyY A1

// input do joystick
int xValue = 0;
int yValue = 0;

/* Biblioteca */
#include <SoftwareSerial.h>

/* Comunicação Serial */
SoftwareSerial HC05(8, 7); /* Simula TX e RX nas portas 8 e 7 */

void setup() {
  HC05.begin(38400);
  Serial.begin(9600);
}
 
void loop() {
  xValue = analogRead(joyX);
  yValue = analogRead(joyY);

  // 0 == parado, 1 == frente, 2 == direita-frente, 3 == esquerda-frente, 4 == direita-re, 5 == esquerda-re, 6 == ré;
  
  if (yValue > 561 && xValue >= 461 && xValue <= 561){ // frente
      HC05.println('1');
      Serial.println('1');
  }

  else if (yValue > 461 && xValue < 461){ // direita-frente
      HC05.println('2');
      Serial.println('2');
  }
      
  else if (yValue > 461 && xValue > 561){ // esquerda-frente
      HC05.println('3');
      Serial.println('3');
  }

  else if (yValue < 461 && xValue < 461){ // direita-ré
      HC05.println('4');
      Serial.println('4');
  }
      
  else if (yValue < 461 && xValue > 561){ // esquerda-ré
      HC05.println('5');
      Serial.println('5');
  }
      
  else if (yValue < 461 && xValue >= 461 && xValue <= 561){ // ré
      HC05.println('6');
      Serial.println('6');
  }

  
      
  else{
    HC05.println('0');
    Serial.println('0');
  }//parado
  
  
  HC05.flush();
}
