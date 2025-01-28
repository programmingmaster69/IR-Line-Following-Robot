#define IRL 7 // IR: White - LOW, Black - 1.
#define IRR 8
#define ENR 9
#define ENL 10
#define RM1 0
#define RM2 1
#define LM1 2
#define LM2 3

void setup() {
  Serial.begin(9600);
  pinMode(IRL, INPUT);
  pinMode(IRR, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);

}

void loop() {
  while(digitalRead(IRL)==LOW && digitalRead(IRR)==LOW){
    Serial.println("IR Left: " + String(digitalRead(IRL)) + ". IR Right: " + String(digitalRead(IRR)));
    analogWrite(ENR,LOW);
    analogWrite(ENL,LOW);
  }
  while(digitalRead(IRL)==LOW && digitalRead(IRR)==HIGH){
    Serial.println("IR Left: " + String(digitalRead(IRL)) + ". IR Right: " + String(digitalRead(IRR)));
    analogWrite(ENR,127);
    analogWrite(ENL,255);
    digitalWrite(LM1,HIGH);
    digitalWrite(LM2,LOW);
    digitalWrite(RM1,HIGH);
    digitalWrite(RM2,LOW);

  }
  while(digitalRead(IRL)==HIGH && digitalRead(IRR)==LOW){
    Serial.println("IR Left: " + String(digitalRead(IRL)) + ". IR Right: " + String(digitalRead(IRR)));
    analogWrite(ENR,255);
    analogWrite(ENL,127);
    digitalWrite(LM1,HIGH);
    digitalWrite(LM2,LOW);
    digitalWrite(RM1,HIGH);
    digitalWrite(RM2,LOW);
  }
  while(digitalRead(IRL)==HIGH && digitalRead(IRR)==HIGH){
    Serial.println("IR Left: " + String(digitalRead(IRL)) + ". IR Right: " + String(digitalRead(IRR)));
    analogWrite(ENR,255);
    analogWrite(ENL,255);
    digitalWrite(LM1,HIGH);
    digitalWrite(LM2,LOW);
    digitalWrite(RM1,HIGH);
    digitalWrite(RM2,LOW);
  }

  
}
