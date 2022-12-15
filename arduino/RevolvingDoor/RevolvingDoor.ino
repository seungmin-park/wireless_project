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
    char detectionCode = Serial.read();
    
    if (detectionCode == 'c' || detectionCode == 'w') {
      detectTarget();
      
    } else if(detectionCode == 'a') {
      detectAdult();
      
    } else if (detectionCode == 'e') {
      turnOff();
      
    } else if (detectionCode == 'n') {
      detectNone();
      
    }
  }
}

// Wheelchair, Child detect
void detectTarget() {
  // led control
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_Y, HIGH);
  digitalWrite(LED_G, LOW);
  
  // motor control
  analogWrite(MOTOR_RUN, 60); // acc
  delay(2);
  analogWrite(MOTOR_RUN, 18); // min speed
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
  analogWrite(MOTOR_RUN, 28); 
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
