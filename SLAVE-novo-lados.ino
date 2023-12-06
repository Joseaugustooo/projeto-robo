#include <SoftwareSerial.h>

int IN1 = 5;
int IN2 = 6;
int IN3 = 7;
int IN4 = 8;

SoftwareSerial HC05(0, 1);
char state; // comandos recebidos pelo bluetooth
char aux;

void setup() {
  HC05.begin(38400);
  Serial.begin(9600);

 pinMode(IN1, OUTPUT); //in1
 pinMode(IN2, OUTPUT); //in2
 pinMode(IN3, OUTPUT); //in3 
 pinMode(IN4, OUTPUT); //in4
}

// 0 == parado, 1 == frente, 2 == direita-frente, 3 == esquerda-frente, 4 == direita-re, 5 == esquerda-re, 6 == ré;
void freio(int INa, int INb)
{
  digitalWrite(INa, LOW);
  digitalWrite(INb, LOW);
}

void anti(int INa, int INb)
{
  digitalWrite(INa, LOW);
  digitalWrite(INb, HIGH);

}

void hora(int INa, int INb)
{

  digitalWrite(INa, HIGH);
  digitalWrite(INb, LOW);
  
}

void loop() {
  if (HC05.available() > 0)
  {
    state = HC05.read();

    // 0 == parado, 1 == frente, 2 == direita-frente, 3 == esquerda-frente, 4 == direita-re, 5 == esquerda-re, 6 == ré;
    
    for (int i = 0; i < 7; i++) if (state == i + 48) aux = state;
    Serial.println(aux);

   switch(aux)
   {
    case '0':
      freio(IN1, IN2);
      freio(IN3, IN4);
      break;

    case '1':
      anti(IN1, IN2);
      hora(IN3, IN4);
      break;

    case '2':
      freio(IN1, IN2);
      hora(IN3, IN4);
      break;

    case '3':
      anti(IN1, IN2);
      freio(IN3, IN4);
      break;

    case '4':
      hora(IN1, IN2);
      hora(IN3, IN4);
      break;

    case '5':
      anti(IN1, IN2);
      anti(IN3, IN4);
      break;

    case '6':
      hora(IN1, IN2);
      anti(IN3, IN4);
      break;
   }
  }
  
}
