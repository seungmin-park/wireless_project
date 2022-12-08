#define LED_R 5
#define LED_Y 4
#define LED_G 3
#define MOTOR_RUN 10 // 모터 우측 방향(IN1)
#define MOTOR_STOP 9 //모터 좌측 방향(IN2)
 
void setup() {
  Serial.begin(9600);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_Y, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(MOTOR_RUN, OUTPUT);
  pinMode(MOTOR_STOP, OUTPUT);
}
 
void loop() {
  if(Serial.available()){
    char isDetectChair = Serial.read();
    
    if (isDetectChair == 'c' || isDetectChair == 'w') {
      detectTarget();
      
    } else if(isDetectChair == 'a') {
      detectAdult();
      
    } else if (isDetectChair == 'e') {
      turnOff();
      
    } else if (isDetectChair == 'n') {
      detectNone();
      
    }
  }
}
 
void turnOffAll() {
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_Y, LOW);
  digitalWrite(LED_G, LOW);
}
 
void turnOnAll() {
  digitalWrite(LED_R, HIGH);
  digitalWrite(LED_Y, HIGH);
  digitalWrite(LED_G, HIGH);
}

// Wheelchair, Child detect
void detectTarget() {
  // led control
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_Y, HIGH);
  digitalWrite(LED_G, LOW);
  
  // motor control
  analogWrite(MOTOR_RUN, 63); // 0~255 63 -> 25% speed
  analogWrite(MOTOR_STOP, 0);

  delay(2000); // wheelchair delay
}

// Adult detect
void detectAdult() {
  // led control
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_Y, LOW);
  digitalWrite(LED_G, HIGH);
  
  // motor control
  analogWrite(MOTOR_RUN, 127); // 0~255 127 -> 50% speed
  analogWrite(MOTOR_STOP, 0);
}

// None detect
void detectNone() {
  // led control
  digitalWrite(LED_R, HIGH);
  digitalWrite(LED_Y, LOW);
  digitalWrite(LED_G, LOW);
  
  // motor control
  analogWrite(MOTOR_RUN, 0); // 0~255 0 -> 0% speed
  analogWrite(MOTOR_STOP, 0);
}

void turnOff() {
  // led control
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_Y, LOW);
  digitalWrite(LED_G, LOW);

  // motor control
  analogWrite(MOTOR_RUN, 0);
  analogWrite(MOTOR_STOP, 0);
}
