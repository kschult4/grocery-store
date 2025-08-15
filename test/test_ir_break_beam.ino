#define PIN_IR_BEAM 2
#define DEBOUNCE_MS 50

static unsigned long lastBeamBreakMs = 0;
static bool lastBeamState = HIGH;
static bool beamBroken = false;

void setup() {
  Serial.begin(115200);
  pinMode(PIN_IR_BEAM, INPUT_PULLUP);
  Serial.println("IR Break Beam Sensor Test Starting...");
  Serial.println("Break the beam to test detection");
}

void loop() {
  bool currentState = digitalRead(PIN_IR_BEAM);
  unsigned long now = millis();
  
  // Debounce the input
  if (currentState != lastBeamState && (now - lastBeamBreakMs) > DEBOUNCE_MS) {
    lastBeamState = currentState;
    lastBeamBreakMs = now;
    
    if (currentState == LOW && !beamBroken) {
      // Beam broken (item detected)
      beamBroken = true;
      Serial.println("*** BEAM BROKEN - ITEM DETECTED ***");
    }
    else if (currentState == HIGH && beamBroken) {
      // Beam restored (item passed through)
      beamBroken = false;
      Serial.println("Beam restored - item passed");
    }
  }
  
  // Show current state every 2 seconds
  static unsigned long lastPrintMs = 0;
  if (now - lastPrintMs > 2000) {
    lastPrintMs = now;
    Serial.print("Beam state: ");
    Serial.print(currentState == HIGH ? "CLEAR" : "BROKEN");
    Serial.print(" (Pin reading: ");
    Serial.print(currentState);
    Serial.println(")");
  }
  
  delay(10);
}