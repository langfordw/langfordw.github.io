const byte dir1 = 8;
const byte pwm1 = 9;
const byte dir2 = 19;
const byte pwm2 = 10;
const byte dir3 = 12;
const byte pwm3 = 11;
const byte dir4 = 0;
const byte pwm4 = 3;

int val = 0;
int val2 = 0;
unsigned long t = 0;
float w = 0.3;//0.21;//0.42;
float w2 = 0.0005;
int del = 500;
float x = 0;
float y = 0;
unsigned long tick = 0;
float phi_n = 0;
float deltaPhi = 6; //2 (0.4 --> 2.14Hz, 2 --> 10Hz,  4 --> 20Hz) 6 should be ~30Hz
float inc = 0.0001;
boolean atPeak = false;
int sgn = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(dir1, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(dir3, OUTPUT);
  pinMode(pwm3, OUTPUT);
  pinMode(dir4, OUTPUT);
  pinMode(pwm4, OUTPUT);
  
//  while(!Serial);
  Serial.println("started");
//  analogWrite(pwm,255);
//  digitalWrite(dir, HIGH);
//  analogWrite(pwm2,255);
//  digitalWrite(dir2, HIGH);
//  tStart = millis();
}

void loop() {
  t = millis();

//  deltaPhi += inc;
//  if (deltaPhi >= 1 || deltaPhi <= 0.1) {
//    inc = -inc;
//  }

  phi_n += deltaPhi;
  val = 255*sin(2*PI*phi_n/255);
//  val = 0;
  
  if (val >= 254 && !atPeak) {
    
    atPeak = true;
  }
  if (atPeak && val < 127) {
    atPeak = false;
    tick++;
  }
    if (tick%50 > 25) {
      sgn = -1;
    } else  {
      sgn = 1;
    }
  val2 = 255*sin(2*PI*phi_n/255 + sgn*PI/2);
//  val2 = 255;
  
//  if (tick%50 > 25) {
//    val2 = 255*sin(2*PI*phi_n/255 + sgn*PI/2);
////    val2 = 255*cos(0.075*t + 0.065/w2*sin(w2*t)+PI/2.);
//  } else {
//    val2 = 255*sin(2*PI*phi_n/255 + sgn*PI/2);
////    val2 = 255*cos(0.075*t + 0.065/w2*sin(w2*t)-PI/2.);
//  }

  
  Serial.print(tick);
  Serial.print(", ");
  Serial.print(val);
  Serial.print(", ");
  Serial.println(val2);

  if (val < 0) {
    digitalWrite(dir1,LOW);
    digitalWrite(dir3,LOW);
  } else {
    digitalWrite(dir1,HIGH);
    digitalWrite(dir3,HIGH);
  }
  analogWrite(pwm1,abs(val));
  analogWrite(pwm3,abs(val));

  if (val2 < 0) {
    digitalWrite(dir2,LOW);
    digitalWrite(dir4,LOW);
  } else {
    digitalWrite(dir2,HIGH);
    digitalWrite(dir4,HIGH);
  }
  analogWrite(pwm2,abs(val2));
  analogWrite(pwm4,abs(val2));

//if (val < 0) {
//    digitalWrite(dir1,LOW);
//    digitalWrite(dir4,HIGH);
//  } else {
//    digitalWrite(dir1,HIGH);
//    digitalWrite(dir4,LOW);
//  }
//  analogWrite(pwm1,abs(val));
//  analogWrite(pwm4,abs(val));
//
//  if (val2 < 0) {
//    digitalWrite(dir2,LOW);
//    digitalWrite(dir3,LOW);
//  } else {
//    digitalWrite(dir2,HIGH);
//    digitalWrite(dir3,HIGH);
//  }
//  analogWrite(pwm2,abs(val2));
//  analogWrite(pwm3,abs(val2));
}
