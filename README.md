# Radio_dial
 Preset Buttons & Debouncing  
*Contributor: Emmanuel kyalo  
 
*What was added:

- Added hardware support for three push buttons on GPIO32, GPIO33, and GPIO25
- Defined preset frequencies:
  - Button 1 → 100.3 MHz
  - Button 2 → 96.6 MHz
  - Button 3 → 106.8 MHz
- Implemented button debouncing using millis() to prevent false triggers
- Created checkPresetButton() function for clean and reusable button handling
- Integrated button checking into the main loop with higher priority than potentiometer input
- Added Serial output when presets are activated
