//https://app.cirkitdesigner.com/project/b979b83e-8428-44e3-8f87-d71818c6e427

#define TRIG_PIN 3
#define ECHO_PIN 4
#define BUZZER_PIN 8
#define RED_LED_PIN 13
#define GREEN_LED_PIN 11

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  long duration;
  int distance;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);

  distance = duration * 0.034 / 2;

  if (distance == 0) {
    distance = 999; 
  }

  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 20) {
    digitalWrite(BUZZER_PIN, HIGH); 
    digitalWrite(RED_LED_PIN, LOW);  
    digitalWrite(GREEN_LED_PIN, HIGH); 
    Serial.println("สถานะ: ตรวจพบวัตถุ! (อันตราย)");
  } 
  else {
    digitalWrite(BUZZER_PIN, LOW);  
    digitalWrite(RED_LED_PIN, HIGH);  
    digitalWrite(GREEN_LED_PIN, LOW);
    Serial.println("สถานะ: ปกติ");
  }

  delay(200);
}
