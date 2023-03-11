#include <Servo.h> //Die Servobibliothek wird aufgerufen. Sie wird benötigt, damit die Ansteuerung des Servos vereinfacht wird.
#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
Servo servo1; 
Servo servo2; 

int bewegung = 11; //Das Wort „bewegung“ steht jetzt für den Wert 7.
int bewegungsstatus = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Serial initialized");
  pinMode(bewegung, INPUT);
  servo1.attach(8);
  servo2.attach(6);

  servo1.write(0);
  servo2.write(0);
  mySwitch.enableReceive(0);  // Empfänger ist an Interrupt-Pin "0" - Das ist am UNO der Pin2

}

void loop() {

  bewegungsstatus=digitalRead(bewegung);

  if (bewegungsstatus == HIGH) {
      Serial.println(bewegungsstatus);
      servo1.write(100);
      servo2.write(100);
      delay(1000);
      servo1.write(0);
      servo2.write(0);
      delay(10000);
  }

  if (mySwitch.available()) // Wenn ein Code Empfangen wird...
  {
    int value = mySwitch.getReceivedValue(); // Empfangene Daten werden unter der Variable "value" gespeichert.
  
    if (value == 0) // Wenn die Empfangenen Daten "0" sind, wird "Unbekannter Code" angezeigt.
    {
      Serial.println("Unbekannter Code");
    } 
    
    else // Wenn der Empfangene Code brauchbar ist, wird er hier an den Serial Monitor gesendet.
    {
      Serial.print("Empfangen: ");
      Serial.println( mySwitch.getReceivedValue() );
      servo1.write(90);
      servo2.write(90);
      delay(1000);
    }
    servo1.write(0);
    servo2.write(0);

    mySwitch.resetAvailable(); // Hier wird der Empfänger "resettet"
  }

  

}
