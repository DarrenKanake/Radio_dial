# FM Radio Dial Interface

An embedded systems lab project that simulates a realistic FM radio tuner using an ESP32 microcontroller. Users can smoothly tune across the FM frequency band (88.0 – 108.0 MHz) with a potentiometer and instantly switch to preset stations using three push buttons. The current frequency is displayed on an SSD1306 OLED with a visual moving tuning bar.

## ✨ Features
- Smooth real-time frequency tuning using a potentiometer
- Instant preset station switching (3 programmable presets)
- Clear OLED display with large frequency readout and visual tuning bar
- Stable operation with noise filtering and anti-jump logic
- Debounced buttons for reliable input
- Detailed Serial debugging output

## 🎯 Preset Stations
- **Button 1**: 100.3 MHz
- **Button 2**: 96.6 MHz
- **Button 3**: 106.8 MHz

## 🛠️ Hardware Components
- **Microcontroller**: ESP32-WROOM-32E
- **Display**: 4-pin I2C SSD1306 OLED (128x64)
- **Tuning**: 10kΩ Potentiometer (connected to GPIO34)
- **Presets**: 3x Tactile Push Buttons (GPIO32, GPIO33, GPIO25)
- Power: 3.3V

## 👥 Team Contributions

### Darren Kanake – Core System & Display
- Set up ESP32 and SSD1306 OLED display via I2C
- Implemented potentiometer ADC reading with averaging
- Created smooth frequency mapping (88.0 – 108.0 MHz)
- Developed the main display function with large frequency text and moving tuning bar

### Emmanuel Kyalo – Preset Buttons & Input Control
- Added support for three push buttons with internal pull-ups
- Implemented button debouncing to prevent false triggers
- Created `checkPresetButton()` function
- Integrated preset stations (100.3, 96.6, 106.8 MHz)
- Ensured buttons take priority over potentiometer input

### Kamau Faith – Stability & Final Polish
- Fixed critical "frequency jump-back" issue after preset selection
- Added `lastStablePotFreq` and hysteresis logic for stability
- Enhanced ADC averaging and noise resistance
- Added temporary "PRESET" on-screen feedback
- Improved overall responsiveness and eliminated flickering

## 🚀 How to Use
1. Rotate the potentiometer to manually tune the frequency.
2. Press any of the three buttons to instantly jump to the corresponding preset station.
3. After selecting a preset, the frequency remains locked until you physically turn the potentiometer again.

## 📂 Project Structure
4. ## 🔧 Technologies & Concepts Demonstrated
- ADC reading and scaling with floating-point math
- Real-time embedded user interface design
- Button debouncing and input handling
- Hysteresis for stable analog input
- Noise filtering through sample averaging
- Modular code structure with clear separation of concerns

## 🧪 Lab Objectives Achieved
- Convert analog input into meaningful frequency values
- Design an interactive embedded UI with visual feedback
- Implement preset-based control systems
- Simulate a real-world radio device using embedded hardware

---

**Developed collaboratively by:**
- Darren Kanake – Core System & Display
- Emmanuel Kyalo – Preset Buttons & Input Control
- Kamau Faith– Stability & Final Polish

Made with  for Embedded Systems Lab • April 2026


