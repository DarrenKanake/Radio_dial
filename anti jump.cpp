// New variables (add at top)
float lastStablePotFreq = 98.0;
unsigned long presetDisplayUntil = 0;

// Updated setup
lastStablePotFreq = currentFreq;

// Updated loop
void loop() {
  // Check preset buttons first
  checkPresetButton(0, BTN1_PIN, PRESET[0], "1");
  checkPresetButton(1, BTN2_PIN, PRESET[1], "2");
  checkPresetButton(2, BTN3_PIN, PRESET[2], "3");

  // Improved potentiometer reading with more samples
  int adcSum = 0;
  for (int i = 0; i < 10; i++) {
    adcSum += analogRead(POT_PIN);
    delayMicroseconds(150);
  }
  int adcAvg = adcSum / 10;

  float potFreq = MIN_FREQ + (adcAvg * (MAX_FREQ - MIN_FREQ) / 4095.0);
  potFreq = round(potFreq * 10.0) / 10.0;

  // Only update if pot physically moved (prevents jump-back)
  if (abs(potFreq - lastStablePotFreq) >= 0.4) {
    currentFreq = potFreq;
    lastStablePotFreq = potFreq;
    updateDisplay();
    Serial.printf("Pot moved → New Freq: %.1f MHz (ADC: %d)\n", currentFreq, adcAvg);
  }

  delay(12);
}

// Improved checkPresetButton() - with critical fix
void checkPresetButton(int index, int pin, float presetFreq, const char* num) {
  if (digitalRead(pin) == LOW) {
    if (millis() - lastDebounceTime[index] > DEBOUNCE_DELAY) {
      
      // Critical fix: Lock pot position to current physical value
      int adcSum = 0;
      for (int i = 0; i < 8; i++) {
        adcSum += analogRead(POT_PIN);
        delayMicroseconds(200);
      }
      int currentADC = adcSum / 8;
      lastStablePotFreq = MIN_FREQ + (currentADC * (MAX_FREQ - MIN_FREQ) / 4095.0);
      lastStablePotFreq = round(lastStablePotFreq * 10.0) / 10.0;

      currentFreq = presetFreq;
      presetDisplayUntil = millis() + 900;

      updateDisplay();
      Serial.printf("PRESET %s activated → %.1f MHz | Pot locked at %.1f\n", num, presetFreq, lastStablePotFreq);

      lastDebounceTime[index] = millis();
      delay(180);
    }
  }
}

// Updated updateDisplay() with PRESET feedback
void updateDisplay() {
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(20, 2);
  display.println("FM RADIO DIAL");

  display.setTextSize(2);
  display.setCursor(10, 20);
  display.print(currentFreq, 1);
  display.print(" MHz");

  int barWidth = map(currentFreq * 10, MIN_FREQ*10, MAX_FREQ*10, 10, SCREEN_WIDTH-20);
  display.drawRect(10, 50, SCREEN_WIDTH-20, 9, SSD1306_WHITE);
  display.fillRect(10, 50, barWidth, 9, SSD1306_WHITE);

  display.setTextSize(1);
  display.setCursor(6, 53);
  display.print("88");
  display.setCursor(98, 53);
  display.print("108");

  if (millis() < presetDisplayUntil) {
    display.setCursor(45, 38);
    display.print("PRESET");
  }

  display.display();
}
