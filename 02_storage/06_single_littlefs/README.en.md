# Single LittleFS Asset

## Overview
This sketch mounts the ESP32 LittleFS partition, reads a PNG file, and draws it on the LCD. Use it when you prefer LittleFS over SPIFFS—such as when you need better directory support or reliability improvements introduced in newer ESP32 cores.

## Requirements
- Arduino CLI 0.35 or newer
- M5Stack Core (Basic) or M5Stack AtomS3
- ESP32 Arduino core `esp32:esp32` (3.3.2)
- Libraries `M5Unified` 0.2.10 and `M5GFX` 0.2.16

## Build & Upload
```
arduino-cli compile --profile m5stack_core 02_storage/06_single_littlefs
arduino-cli upload --profile m5stack_core --port <port> 02_storage/06_single_littlefs
```
Switch to the `m5stack_atoms3` profile when uploading to AtomS3 hardware.

## Notes
- Populate the `data/` directory and run **Arduino CLI Wrapper: Upload Data** before flashing the sketch; the program reports `Run Upload Data!` if the mount fails.
- `LittleFS.begin()` uses the default configuration. If you change partition sizes, adjust the call accordingly.
- Drawing relies on `M5.Lcd.drawPngFile(LittleFS, "/1.png", x, y)`, so you can replace the file on the filesystem without recompiling.

## References
- [LittleFS on ESP32](https://docs.espressif.com/projects/arduino-esp32/en/latest/api/filesystem.html#littlefs)
- [M5Unified Library](https://github.com/m5stack/M5Unified)
- [Arduino CLI Documentation](https://arduino.github.io/arduino-cli/latest/)
