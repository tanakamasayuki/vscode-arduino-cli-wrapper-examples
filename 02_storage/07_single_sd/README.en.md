# Single SD Asset

## Overview
This sketch reads a PNG from a microSD card and draws it on the LCD. It repeatedly attempts to mount the card over SPI, reporting progress on the serial console until the media is detected.

## Requirements
- Arduino CLI 0.35 or newer
- M5Stack Core (Basic) or M5Stack AtomS3 with a formatted microSD card
- ESP32 Arduino core `esp32:esp32` (3.3.2)
- Libraries `M5Unified` 0.2.10 and `M5GFX` 0.2.16

## Build & Upload
```
arduino-cli compile --profile m5stack_core 02_storage/07_single_sd
arduino-cli upload --profile m5stack_core --port <port> 02_storage/07_single_sd
```
Select `m5stack_atoms3` when deploying to AtomS3 hardware.

## Notes
- Copy the files from `copy_to_sd/` onto the root of the microSD card before powering the board.
- The sketch calls `SD.begin(GPIO_NUM_4, SPI, 25000000)`; ensure your wiring uses GPIO 4 for chip select or adjust the argument to match your hardware.
- While the card is absent the loop prints `SD Wait...` every 500 ms at 115200 baud, giving you an immediate status indicator.

## References
- [ESP32 SD API](https://docs.espressif.com/projects/arduino-esp32/en/latest/api/filesystem.html#sd)
- [M5Unified Library](https://github.com/m5stack/M5Unified)
- [Arduino CLI Documentation](https://arduino.github.io/arduino-cli/latest/)
