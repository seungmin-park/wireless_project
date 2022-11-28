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
  while(Serial.available() > 0){
    turnOffAll();
    delay(1000);
    turnOnAll();
    delay(1000);
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
