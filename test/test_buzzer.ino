#define PIN_BUZZER 9

void setup() {
  pinMode(PIN_BUZZER, OUTPUT);
  Serial.begin(115200);
  Serial.println("Buzzer Test Starting...");
}

void loop() {
  Serial.println("Beep!");
  digitalWrite(PIN_BUZZER, HIGH);
  delay(120);
  digitalWrite(PIN_BUZZER, LOW);
  delay(1000);
}