# Single SPIFFS Asset

## Overview
This sketch loads a PNG file from the ESP32 SPIFFS partition and draws it to the LCD. It highlights how to bundle binary resources in the `data/` directory and flash them with the Arduino CLI Wrapper before running the program.

## Requirements
- Arduino CLI 0.35 or newer
- M5Stack Core (Basic) or M5Stack AtomS3
- ESP32 Arduino core `esp32:esp32` (3.3.2)
- Libraries `M5Unified` 0.2.10 and `M5GFX` 0.2.16

## Build & Upload
```
arduino-cli compile --profile m5stack_core 02_storage/05_single_spiffs
arduino-cli upload --profile m5stack_core --port <port> 02_storage/05_single_spiffs
```
Run the same commands with `--profile m5stack_atoms3` for AtomS3 hardware.

## Notes
- Before uploading the sketch, execute **Arduino CLI Wrapper: Upload Data** so that the contents of `data/` are written to SPIFFS; the sketch prints `Run Upload Data!` if the mount fails.
- `M5.Lcd.drawPngFile(SPIFFS, "/1.png", x, y)` reads the file each frame, so you can swap assets without recompiling.

## References
- [SPIFFS on ESP32](https://docs.espressif.com/projects/arduino-esp32/en/latest/api/filesystem.html#spiffs)
- [M5Unified Library](https://github.com/m5stack/M5Unified)
- [Arduino CLI Documentation](https://arduino.github.io/arduino-cli/latest/)
