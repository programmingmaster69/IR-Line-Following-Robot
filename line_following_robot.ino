#define IRL 7 // IR: White - LOW, Black - HIGH.
#define IRR 8 // Right IR Sensor
#define ENR 9 // Right-side Motor Speeds
#define ENL 10 // Left-side Motor Speeds
#define RM1 0 // Right Motor 1
#define RM2 1 // Right Motor 2
#define LM1 2 // Left Motor 1
#define LM2 3 // Left Motor 2

void setup() {
  Serial.begin(9600); // Initializing Serial Monitor's Baud Rate.
  pinMode(IRL, INPUT); // Setting sensor pins to input mode in order to take digital values from them.
  pinMode(IRR, INPUT);
  pinMode(LM1, OUTPUT); // Setting PWM motor pins to output mode. 
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);

}

void loop() {
  while(digitalRead(IRL)==LOW && digitalRead(IRR)==LOW){ // No White Line ----> Turn all motors off.
    Serial.println("IR Left: " + String(digitalRead(IRL)) + ". IR Right: " + String(digitalRead(IRR)));
    analogWrite(ENR,LOW);
    analogWrite(ENL,LOW);
  }
  while(digitalRead(IRL)==LOW && digitalRead(IRR)==HIGH){ // The lines are to the right side of car, so it needs to turn right.
    Serial.println("IR Left: " + String(digitalRead(IRL)) + ". IR Right: " + String(digitalRead(IRR)));
    analogWrite(ENR,127);
    analogWrite(ENL,255);
    digitalWrite(LM1,HIGH);
    digitalWrite(LM2,HIGH);
    digitalWrite(RM1,LOW);
    digitalWrite(RM2,LOW);

  }
  while(digitalRead(IRL)==HIGH && digitalRead(IRR)==LOW){ // The lines are to the left side of car, so it needs to turn left.
    Serial.println("IR Left: " + String(digitalRead(IRL)) + ". IR Right: " + String(digitalRead(IRR)));
    analogWrite(ENR,255);
    analogWrite(ENL,127);
    digitalWrite(LM1,LOW);
    digitalWrite(LM2,LOW);
    digitalWrite(RM1,HIGH);
    digitalWrite(RM2,HIGH);
  }
  while(digitalRead(IRL)==HIGH && digitalRead(IRR)==HIGH){ // Car is in the middle, so turn all motors on and proceed forward.
    Serial.println("IR Left: " + String(digitalRead(IRL)) + ". IR Right: " + String(digitalRead(IRR)));
    analogWrite(ENR,255);
    analogWrite(ENL,255);
    digitalWrite(LM1,HIGH);
    digitalWrite(LM2,HIGH);
    digitalWrite(RM1,HIGH);
    digitalWrite(RM2,HIGH);
  }

  
}
