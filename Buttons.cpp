// New pins and constants (add at top)
#define BTN1_PIN   32   // 100.3 MHz
#define BTN2_PIN   33   // 96.6 MHz
#define BTN3_PIN   25   // 106.8 MHz

const float PRESET[3] = {100.3, 96.6, 106.8};
unsigned long lastDebounceTime[3] = {0, 0, 0};
const unsigned long DEBOUNCE_DELAY = 60;

// In setup() - add this:
pinMode(BTN1_PIN, INPUT_PULLUP);
pinMode(BTN2_PIN, INPUT_PULLUP);
pinMode(BTN3_PIN, INPUT_PULLUP);

// New function added:
void checkPresetButton(int index, int pin, float presetFreq, const char* num) {
  if (digitalRead(pin) == LOW) {
    if (millis() - lastDebounceTime[index] > DEBOUNCE_DELAY) {
      currentFreq = presetFreq;
      updateDisplay();
      Serial.printf("PRESET %s activated → %.1f MHz\n", num, presetFreq);
      lastDebounceTime[index] = millis();
      delay(150);
    }
  }
}

// In loop() - add button checking:
checkPresetButton(0, BTN1_PIN, PRESET[0], "1");
checkPresetButton(1, BTN2_PIN, PRESET[1], "2");
checkPresetButton(2, BTN3_PIN, PRESET[2], "3");
