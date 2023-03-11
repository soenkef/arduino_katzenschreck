#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

int LEDblau=6; //Das Wort „LEDblau“ steht jetzt für den Wert 6.
int taster=7; //Das Wort „taster“ steht jetzt für den Wert 7.
int tasterstatus=0; //Das Wort „tasterstatus“ steht jetzt zunächst für den Wert 0. Später wird unter dieser Variable gespeichert, ob der Taster gedrückt ist oder nicht.


void setup() {
  Serial.begin(19200);
  Serial.println("Serial initialized");
  mySwitch.enableTransmit(10);  // Der Sender wird an Pin 10 angeschlossen
  pinMode(LEDblau, OUTPUT); //Der Pin mit der LED (Pin 6) ist jetzt ein Ausgang.
  pinMode(taster, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:
  tasterstatus=digitalRead(taster);
  
  if (tasterstatus == HIGH) { //Programmabschnitt des IF-Befehls öffnen.
    Serial.println("Button pressed");
    digitalWrite(LEDblau, HIGH);
    mySwitch.send(1234, 24); // Der 433mhz Sender versendet die Dezimalzahl „1234“
    delay(1000);
  } else {
    digitalWrite(LEDblau, LOW);
  }
//  digitalWrite(LEDblau, HIGH);
//  Serial.println("LED ein");
//  delay(3000);
//  digitalWrite(LEDblau, LOW);
//  Serial.println("LED aus");
//  delay(3000);

}
