# Anti jump logic
## Contributor: Kamaufaith 

- Fixed bug: Frequency jumping back to previous value after pressing preset buttons
- Introduced lastStablePotFreq variable to remember the physical potentiometer position
- Added strong hysteresis (0.4 MHz threshold) to prevent jitter and false updates
- Improved ADC reading with more samples (10 readings) for better stability
- Enhanced checkPresetButton() function to lock the pot position correctly when preset is selected
- Added temporary "PRESET" text feedback on the OLED display when a button is pressed
- Increased responsiveness and eliminated display flickering
- Added detailed Serial debugging messages for easier troubleshooting
