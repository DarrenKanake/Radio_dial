 ### What was added:

- Initialized ESP32 with SSD1306 OLED display via I2C
- Implemented potentiometer reading using ADC with averaging for noise reduction
- Created accurate frequency mapping from ADC values (0–4095) to 88.0–108.0 MHz range
- Developed the main updateDisplay() function showing:
  - Large frequency text (e.g., "100.3 MHz")
  - Moving horizontal tuning bar (visual dial)
  - Fixed 88 and 108 MHz labels
- Set up basic project structure, Serial debugging, and main loop
