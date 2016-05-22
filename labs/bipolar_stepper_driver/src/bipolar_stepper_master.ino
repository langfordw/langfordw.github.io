/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int dir_pin = 2;
int step_pin = 4;
int led = 13;
int high = 1;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(dir_pin, OUTPUT);     
  pinMode(step_pin, OUTPUT);  
  pinMode(led, OUTPUT);  
  digitalWrite(dir_pin, HIGH);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
//  if (Serial.available()) {
//    Serial.read();

  digitalWrite(dir_pin, HIGH);
  for (int i = 0; i < 1036; i++) {
    if (high) {
      digitalWrite(led, LOW);
      digitalWrite(step_pin, LOW);
      high = 0;
    } else {
      digitalWrite(led, HIGH);
      digitalWrite(step_pin, HIGH);
      high = 1;
    }
    delayMicroseconds(1000);
  }
//  delay(50);
//  digitalWrite(dir_pin, LOW);
//  for (int i = 0; i < 1036; i++) {
//    if (high) {
//      digitalWrite(led, LOW);
//      digitalWrite(step_pin, LOW);
//      high = 0;
//    } else {
//      digitalWrite(led, HIGH);
//      digitalWrite(step_pin, HIGH);
//      high = 1;
//    }
//    delayMicroseconds(2500);
//  }
//  delay(50);
      
//  }
//  delay(100);
//  digitalWrite(dir_pin, HIGH);
//  for (int i=0; i < 1036; i++) {
//    digitalWrite(step_pin, HIGH);
//    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
//    delay(200);               // wait for a second
//    digitalWrite(step_pin, LOW);
//    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
//    delay(200);               // wait for a second
//  }
//  
//  delay(1000);
//  
//  digitalWrite(dir_pin, LOW);
//  for (int i=0; i < 1036; i++) {
//    digitalWrite(step_pin, HIGH);
//    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
//    delay(2);               // wait for a second
//    digitalWrite(step_pin, LOW);
//    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
//    delay(2);               // wait for a second
//  }
//  
//  delay(1000);

//digitalWrite(step_pin,HIGH);
//digitalWrite(dir_pin,HIGH);

//  digitalWrite(dir_pin, LOW);
//  digitalWrite(step_pin, LOW);
//  digitalWrite(led, LOW);
//  delay(1000);
//  digitalWrite(dir_pin, HIGH);
//  digitalWrite(step_pin, LOW);
//  digitalWrite(led, HIGH);
//  delay(1000);
}
