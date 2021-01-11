
#include "SR04.h"
#include <Servo.h>
#define TRIG_PIN 12
#define ECHO_PIN 11
#define RED_PIN 7
#define GREEN_PIN 4
#define BUZZ_PIN 8
long int data;

SoftwareSerial blue(2,3);
Servo myservo;
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;

void setup() {

   delay(500);
   pinMode(RED_PIN, OUTPUT);
   pinMode(GREEN_PIN, OUTPUT);
   pinMode(BUZZ_PIN, OUTPUT);
   myservo.attach(9);
   Serial.begin(9600);
 blue.begin(9600);
}

void loop() {
 a=sr04.Distance();
   delay(500);
   if(a < 40) { //Alarm triggered
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(BUZZ_PIN, HIGH);
     myservo.write(180);  
   }
}else { //Safe
   digitalWrite(RED_PIN, LOW);
   digitalWrite(GREEN_PIN, HIGH);
   digitalWrite(BUZZ_PIN, LOW);
    myservo.write(90);  
   }
}
