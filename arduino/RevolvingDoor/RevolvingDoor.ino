#define LED_R 5
#define LED_Y 4
#define LED_G 3
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_Y, OUTPUT);
  pinMode(LED_G, OUTPUT);
}
 
void loop() {
  // digitalWrite(LED_R, HIGH);
  if(Serial.available()){
    char isDetectChair = Serial.read();
    if(isDetectChair == 'p'){
      digitalWrite(LED_R, HIGH);
      digitalWrite(LED_G, LOW);
      digitalWrite(LED_Y, LOW);
    }
    else if(isDetectChair == 'n'){
      digitalWrite(LED_Y, HIGH);
      digitalWrite(LED_R, LOW);
      digitalWrite(LED_G, LOW);
    }
    else if(isDetectChair == 'c'){
      digitalWrite(LED_G, HIGH);
      digitalWrite(LED_R, LOW);
      digitalWrite(LED_Y, LOW);
      delay(3000);
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
