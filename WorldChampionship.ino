

int testPin = 10;
float tt, aa = 12345.8;
long loops = 100000;

#include <Servo.h>


#if defined(ARDUINO_ARCH_AVR)
#define LED  13
#define servoPin 3
#define starttPin 5
#define testPin 2
#define boardName "Arduino"

#else

#if defined(ARDUINO_ARCH_ESP8266)
//#include <Esp.h>
#define LED  4
#define servoPin 3
#define starttPin 5
#define testPin D2
#define boardName "ESP8266"

#else
#define LED  7
#define servoPin 3
#define starttPin 5
#define testPin 2
#define boardName "MKR1000"

#endif
#endif



Servo myservo;  // create servo object to control a servo

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("START");

  pinMode(LED, OUTPUT);
  pinMode(starttPin, INPUT_PULLUP);
  digitalWrite(LED, LOW);
  myservo.attach(servoPin);  // attaches the servo on pin 9 to the s
//  Serial.println(ESP.getFlashChipSize());
//  int zz = ESP.getFlashChipSpeed();


/* 
Serial.println(D1);
Serial.println(D2);
Serial.println(D3);
Serial.println(D4);
Serial.println(D5);
Serial.println(D6);
Serial.println(D7);
  */
}

void loop() {
  
  // ---------- Wait for the start button
  Serial.println("Prep");
    Serial.println(LED);
//  while (digitalRead(starttPin)) delay(1);
  Serial.println("Load");
//  while (!digitalRead(starttPin)) delay(1);
  Serial.println(boardName);
  long start = millis();
  digitalWrite(LED, HIGH);
  myservo.write(0);
  
  //----------- R A C E
  for (long i = 0; i < loops; i++) {

    tt = 5000.0 * aa / i;
   /* pinMode(testPin, OUTPUT);
    digitalWrite(testPin, LOW);
    digitalWrite(testPin, HIGH);

    pinMode(testPin, INPUT);
    digitalRead(testPin);
    digitalRead(testPin);
    if (digitalRead(testPin)) {
      int tt = 150 * 1234;
    } else
    {
      tt = 554 % 12;
    }
    */
  }

  //----------- Raise the flag
  digitalWrite(LED, LOW);
  myservo.write(70);
  Serial.println(millis() - start);
  Serial.println("Finish");
}
