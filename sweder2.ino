#include <IRremote.h>
int ReceptorIR = 2;
int led = 3;
int led1 = 4;
int led2 = 5;
int led3 = 6;

IRrecv irrecv(ReceptorIR);
decode_results Codigo;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(led, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}
void loop()
{
  if (irrecv.decode(&Codigo))
  {
    Serial.print("0x"); //macro para ver código de tecla por comunicación serial
    Serial.println(Codigo.value, HEX); //
    switch (Codigo.value)
    {
      case 0xFFA22D: //al presionar la primera tecla:
        if (digitalRead(led)) //si el led se encuentra prendido
          digitalWrite(led, LOW);
        else //por el contrario, si led esta apagado, se prende
          digitalWrite(led, HIGH);
        break;

      case 0xFFA23D: //al presionar la primera tecla:
        if (digitalRead(led1)) //si el led se encuentra prendido
          digitalWrite(led1, LOW);
        else //por el contrario, si led esta apagado, se prende
          digitalWrite(led1, HIGH);
        break;

      case 0xFFA24D: //al presionar la primera tecla:
        if (digitalRead(led2)) //si el led se encuentra prendido
          digitalWrite(led2, LOW);
        else //por el contrario, si led esta apagado, se prende
          digitalWrite(led2, HIGH);
        break;

      case 0xFFA25D: //al presionar la primera tecla:
        if (digitalRead(led3)) //si el led se encuentra prendido
          digitalWrite(led3, LOW);
        else //por el contrario, si led esta apagado, se prende
          digitalWrite(led3, HIGH);
        break;


      case 0xFFA26D: //al presionar la tecla todos encienden:
        if (digitalRead(led));
        (digitalRead(led1));
        (digitalRead(led2));
        (digitalRead(led3));//si el led se encuentra prendido
        digitalWrite(led, HIGH);
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        break;

      case 0xFFA27D: //al presionar la tecla todos apagan:
        if (digitalRead(led));
        (digitalRead(led1));
        (digitalRead(led2));
        (digitalRead(led3));//si el led se encuentra prendido
        digitalWrite(led, LOW);
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        break;


    }
    irrecv.resume();
  }
delay (200);
}
