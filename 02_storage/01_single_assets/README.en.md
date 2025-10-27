# Single Embedded Asset

## Overview
This sketch embeds `assets/1.png` into program memory and renders it directly to the LCD with `M5Unified::drawPng`. Each frame selects a random position so you can observe how quickly an inline asset is blitted without touching a file system.

## Requirements
- Arduino CLI 0.35 or newer
- M5Stack Core (Basic) or M5Stack AtomS3
- ESP32 Arduino core `esp32:esp32` (3.3.2)
- Libraries `M5Unified` 0.2.10 and `M5GFX` 0.2.16

## Build & Upload
```
arduino-cli compile --profile m5stack_core 02_storage/01_single_assets
arduino-cli upload --profile m5stack_core --port <port> 02_storage/01_single_assets
```
Switch `--profile` to `m5stack_atoms3` when deploying to AtomS3 hardware.

## Notes
- Run **Arduino CLI Wrapper: Embed Assets** after updating the PNG inside `assets/` to regenerate `assets_embed.h` (the header is also refreshed automatically during compilation).
- The sketch seeds randomness via `random()` only when the draw loop runs; you can stabilise placement by replacing the calls with constants during debugging.
- Serial output prints the chosen coordinates at 115200 baud for quick verification.

## References
- [M5Unified Library](https://github.com/m5stack/M5Unified)
- [M5GFX Library](https://github.com/m5stack/M5GFX)
- [Arduino CLI Documentation](https://arduino.github.io/arduino-cli/latest/)
