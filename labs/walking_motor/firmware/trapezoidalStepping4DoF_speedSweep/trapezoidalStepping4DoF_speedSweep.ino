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
int val3 = 0;
int val4 = 0;
unsigned long t = 0;
float w = 0.3;//0.21;//0.42;
float w2 = 0.0005;
int del = 500;
float x = 0;
float y = 0;
unsigned long tick = 0;
long phi_n = 0;
int deltaPhi = 1; //2 (0.4 --> 2.14Hz, 2 --> 10Hz,  4 --> 20Hz) 6 should be ~30Hz
int layerPhaseOffset = 127;
float inc = 1;
boolean atPeak = false;
int sgn = 1;
int ntimes = 0;
long tstart = 0;
int numRamps = 0;

const int t_on1 = 68; // time on 
const int t_off1 = 67; // time off (retracted)
//const int t_on1 = 100; // time on 
//const int t_off1 = 35; // time off (retracted)
const int t_ramp1 = 30;// time to ramp from on to midpoint
const int maxVal = 255;
const int minVal = -255;
const int t1 = t_ramp1;
const int t2 = t_on1 + t_ramp1;
const int t3 = t_on1 + 3*t_ramp1;
const int t4 = t_on1 + t_off1 + 3*t_ramp1;
//const uint8_t t_per1 = 255// total period of waveform

int trapezoid(int index) {
  //index is 0 --> 255 and represents the position within one cycle of the waveform
  //  t1  t2
  //   ---
  // /     \       t5
  //t0      \    /
  //         ----
  //        t3   t4
  
  if (index < t1) {
    return (index*maxVal/float(t_ramp1));
  } else if (index < t2) {
    return maxVal;
  } else if (index < t3) {
    return (maxVal + (index-t2)*(minVal - maxVal)/float(2*t_ramp1));
  } else if (index < t4) {
    return minVal;
  } else {
    return (minVal - (index-t4)*minVal/float(t_ramp1));
  }
}

//int trapezoid(int index) {
//  //index is 0 --> 255 and represents the position within one cycle of the waveform
//  return int(maxVal*sin(2*PI*index/255));
//}

void actuate(uint8_t pwm_pin, uint8_t dir_pin, int pwm_val) {
  if (pwm_val < 0) {
    digitalWrite(dir_pin,LOW);
  } else {
    digitalWrite(dir_pin,HIGH);
  }
  analogWrite(pwm_pin,abs(pwm_val));
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(dir1, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(dir3, OUTPUT);
  pinMode(pwm3, OUTPUT);
  pinMode(dir4, OUTPUT);
  pinMode(pwm4, OUTPUT);
  
  while(!Serial);
//  Serial.println("started");
//  analogWrite(pwm,255);
//  digitalWrite(dir, HIGH);
//  analogWrite(pwm2,255);
//  digitalWrite(dir2, HIGH);
//  tStart = millis();
  tstart = millis();
}

void loop() {
  
  if (millis() - t > 1) {
    t = millis();
//    ntimes++;

    
  
  phi_n += deltaPhi;

  val = trapezoid(phi_n%255);
  
  if (val >= 254 && !atPeak) {
    
    atPeak = true;
  }
  if (atPeak && val < 127) {
    atPeak = false;
    tick++;
    ntimes++;
  }

  if (ntimes > 10) {
      deltaPhi += inc;
      ntimes = 0;
    }

  if (deltaPhi > 85 && inc > 0) {
    inc = -inc;
    numRamps++;
  } else if (deltaPhi < 2 && inc < 0) {
    inc = -inc;
    numRamps++;
  }

  if (numRamps > 2) {
    while(1) {
      actuate(pwm1,dir1,0);
      actuate(pwm2,dir2,0);
      actuate(pwm3,dir3,0);
      actuate(pwm4,dir4,0); 
    }
  }

//  if (millis()-tstart > 120000 || deltaPhi > 85) {
//    while(1) {
//      actuate(pwm1,dir1,0);
//      actuate(pwm2,dir2,0);
//      actuate(pwm3,dir3,0);
//      actuate(pwm4,dir4,0); 
//    }
//  }
//    if (tick%50 > 25) {
//      sgn = -1;
//    } else  {
//      sgn = 1;
//    }
    val2 = trapezoid((phi_n+sgn*64)%255);

  Serial.print(millis());
  Serial.print(", ");
  Serial.print(deltaPhi);
  Serial.print(", ");
  Serial.println(phi_n);
//  Serial.print(", ");
//  Serial.print(val);
//  Serial.print(", ");
//  Serial.println(val2);

  val3 = trapezoid((phi_n+sgn*layerPhaseOffset)%255);
  val4 = trapezoid((phi_n+sgn*(layerPhaseOffset+64))%255);

  val = -255;
  val2 = -255;
//  val3 = -255;
//  val4 = -255;

  actuate(pwm1,dir1,val);
  actuate(pwm2,dir2,val2);
  actuate(pwm3,dir3,val3);
  actuate(pwm4,dir4,val4);

  }
//  if (val < 0) {
//    digitalWrite(dir1,LOW);
//    digitalWrite(dir3,LOW);
//  } else {
//    digitalWrite(dir1,HIGH);
//    digitalWrite(dir3,HIGH);
//  }
//  analogWrite(pwm1,abs(val));
//  analogWrite(pwm3,abs(val));
//
//  if (val2 < 0) {
//    digitalWrite(dir2,LOW);
//    digitalWrite(dir4,LOW);
//  } else {
//    digitalWrite(dir2,HIGH);
//    digitalWrite(dir4,HIGH);
//  }
//  analogWrite(pwm2,abs(val2));
//  analogWrite(pwm4,abs(val2));

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

//  if (val < 100 && val2 < 100) {
//    digitalWrite(dir3, HIGH);
//    digitalWrite(dir4, HIGH);
//    digitalWrite(pwm3, HIGH);
//    digitalWrite(pwm4, HIGH);
//  } else {
//    digitalWrite(dir3, LOW);
//    digitalWrite(dir4, LOW);
//    digitalWrite(pwm3, HIGH);
//    digitalWrite(pwm4, HIGH);
//  }
}

