# Wiring Notes - Grocery Checkout System

## Pin Connections

### HC-SR04 Ultrasonic Sensor
- **TRIG** → Arduino Pin D2
- **ECHO** → Arduino Pin D3  
- **VCC** → 5V
- **GND** → GND

### WS2812B LED Panel(s)
- **DIN** → Arduino Pin D6 (through 330-470Ω resistor)
- **5V** → External 5V power supply (NOT Arduino 5V)
- **GND** → Common ground with Arduino

### Active Buzzer
- **+** → Arduino Pin D9
- **-** → GND

## Power Considerations

### Critical Power Setup
- Use a dedicated 5V high-current power supply for LED panels
- **DO NOT** power LEDs from Arduino 5V pin
- Connect common ground between power supply and Arduino
- Each 16×16 panel can draw up to 15A at full brightness white

### Power Protection
- Add large electrolytic capacitor (1000µF, 6.3V+) across LED 5V and GND near each panel
- Place capacitor close to the LED panel input
- For multiple panels, inject power at both ends of the strip

### Current Limiting
- Keep `MAX_BRIGHTNESS` at 60 or lower in config.h
- Monitor for brownouts/resets during operation
- If instability occurs, reduce brightness further

## Wiring Best Practices

### Data Signal Integrity  
- Use 330-470Ω series resistor on WS2812 DATA line near panel
- Keep data wire as short as possible
- Use twisted pair or shielded cable for longer runs

### Sensor Placement
- Mount ultrasonic sensor away from direct LED panel heat
- Angle sensor slightly to avoid reflections from checkout surface
- Ensure clear line of sight to detection area
- Keep sensor steady to avoid false triggers

### Mechanical Considerations
- Secure all connections with heat shrink tubing
- Use strain relief on power connections
- Mount components in enclosure to protect from handling
- Label all connections for troubleshooting

## Testing Checklist

### Power-On Sequence
1. Connect external 5V supply to LEDs (Arduino unpowered)
2. Verify LED power supply voltage (4.8-5.2V)
3. Connect Arduino USB power
4. Upload and test each component individually

### Component Testing Order
1. **LED Test**: Upload `test/test_led.ino` - verify colors and no flickering
2. **Buzzer Test**: Upload `test/test_buzzer.ino` - confirm audible beep
3. **Sensor Test**: Upload `test/test_ultrasonic.ino` - check distance readings
4. **Integration Test**: Upload main `firmware.ino` - full system test

### Troubleshooting

#### LED Issues
- **No LEDs**: Check power supply, ground connections
- **Wrong colors**: Verify GRB vs RGB in code, check data pin
- **Flickering**: Check power supply capacity, reduce brightness

#### Sensor Issues  
- **No readings**: Check TRIG/ECHO pin connections
- **Inconsistent readings**: Check for reflective surfaces, mounting stability
- **False triggers**: Adjust `SCAN_THRESHOLD_CM`, check for vibrations

#### System Resets
- **Random resets**: Usually power supply issues, reduce LED brightness
- **Immediate reset**: Check for short circuits, verify pin assignments

## Library Requirements

Install these libraries through Arduino IDE Library Manager:
- **FastLED** (WS2812B control)
- **NewPing** (HC-SR04 ultrasonic sensor)
- **Arduino_LED_Matrix** (optional - UNO R4 built-in display)

## Recommended Hardware

### Power Supply
- 5V 10A+ switching power supply for two 16×16 panels
- Barrel jack or terminal block connections
- Overcurrent protection recommended

### Wire Gauge
- 18 AWG minimum for LED power connections
- 22-24 AWG for data/signal connections  
- Use appropriately rated wire for current loads