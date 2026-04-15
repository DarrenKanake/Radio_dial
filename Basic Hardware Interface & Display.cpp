#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Display settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Pins
#define POT_PIN    34

// Frequency constants
const float MIN_FREQ = 88.0;
const float MAX_FREQ = 108.0;

float currentFreq = 98.0;

void setup() {
  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 failed");
    for (;;);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  updateDisplay();
  Serial.println("FM Radio Dial - Core Version");
}

void loop() {
  // Read potentiometer with averaging
  int adcSum = 0;
  for (int i = 0; i < 8; i++) {
    adcSum += analogRead(POT_PIN);
    delayMicroseconds(200);
  }
  int adcAvg = adcSum / 8;

  float freq = MIN_FREQ + (adcAvg * (MAX_FREQ - MIN_FREQ) / 4095.0);
  freq = round(freq * 10.0) / 10.0;

  if (abs(freq - currentFreq) >= 0.1) {
    currentFreq = freq;
    updateDisplay();
  }

  delay(15);
}

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

  display.display();
}
