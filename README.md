# Grocery Checkout Simulator

Arduino UNO R4 WiFi project that simulates a grocery store checkout scanner with colorful LED animations and sound feedback.

## Features

- **Object Detection**: HC-SR04 ultrasonic sensor detects items within 10cm
- **Visual Feedback**: Colorful animations on 16×16 WS2812B LED panels
- **Audio Feedback**: Beep sound on item detection
- **Modular Design**: Easy to add new animations and features
- **Cooldown System**: Prevents spam triggering (1 second lockout)

## Hardware Requirements

- Arduino UNO R4 WiFi
- HC-SR04 Ultrasonic Sensor
- 16×16 WS2812B LED Panel(s)
- Active Buzzer
- 5V High-Current Power Supply (10A+ for dual panels)
- 330-470Ω Resistor
- 1000µF Electrolytic Capacitor
- Jumper wires and breadboard/PCB

## Library Dependencies

Install via Arduino IDE Library Manager:
- `FastLED`
- `NewPing`

## Quick Start

1. **Hardware Setup**: Follow wiring diagram in `wiring/wiring-notes.md`
2. **VS Code Setup**: Install Arduino extension, open project folder
3. **Test Components**: Upload test sketches from `test/` folder individually
4. **Upload Main Code**: Flash `firmware/firmware.ino` to your Arduino
5. **Adjust Settings**: Modify `firmware/config.h` for your setup

## Project Structure

```
grocery-checkout/
├── firmware/
│   ├── firmware.ino          # Main sketch
│   ├── config.h              # Pin definitions & constants
│   ├── animations/           # LED animation modules
│   ├── sensors/              # Sensor interface code
│   ├── sound/                # Audio control
│   └── display/              # LED panel control
├── test/                     # Component test sketches
├── wiring/                   # Wiring documentation
└── .vscode/                  # VS Code configuration
```

## Configuration

Key settings in `firmware/config.h`:
- `SCAN_THRESHOLD_CM`: Detection distance (default: 10cm)
- `MAX_BRIGHTNESS`: LED brightness 0-255 (default: 60)
- `SCAN_COOLDOWN_MS`: Trigger lockout time (default: 1000ms)

## Safety Notes

- **Never power LEDs from Arduino 5V pin** - use external supply
- Keep LED brightness conservative to prevent power issues
- Use proper gauge wire for power connections
- Add capacitors near LED panels for stable power

## Troubleshooting

- **LEDs don't light**: Check external power supply and ground connections
- **Random resets**: Reduce LED brightness, check power supply capacity  
- **Sensor not working**: Verify TRIG/ECHO pin connections
- **No sound**: Check buzzer polarity and pin connection

## Future Enhancements

- DFPlayer Mini for realistic checkout sounds
- Multiple sensor zones
- Item counter on UNO R4's built-in 12×8 LED matrix
- Wi-Fi connectivity and web interface
- Settings storage in EEPROM