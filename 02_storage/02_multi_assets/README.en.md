# Multiple Embedded Assets

## Overview
This sketch embeds four PNG files and selects one at random each frame before drawing it to the LCD. The example demonstrates how the Arduino CLI Wrapper generates a single header that exposes multiple asset pointers for quick switching between sprites stored in flash.

## Requirements
- Arduino CLI 0.35 or newer
- M5Stack Core (Basic) or M5Stack AtomS3
- ESP32 Arduino core `esp32:esp32` (3.3.2)
- Libraries `M5Unified` 0.2.10 and `M5GFX` 0.2.16

## Build & Upload
```
arduino-cli compile --profile m5stack_core 02_storage/02_multi_assets
arduino-cli upload --profile m5stack_core --port <port> 02_storage/02_multi_assets
```
Use the `m5stack_atoms3` profile when running on AtomS3 hardware.

## Notes
- The generated `assets_embed.h` exposes matching pointer/length arrays for each PNG; refresh it with **Arduino CLI Wrapper: Embed Assets** whenever the files under `assets/` change (compilation also regenerates the header automatically).
- Serial output prints the index and coordinates of every drawn image so you can confirm which sprite is on screen.
- If you need deterministic animation, seed the RNG with `randomSeed()` during setup.

## References
- [M5Unified Library](https://github.com/m5stack/M5Unified)
- [M5GFX Library](https://github.com/m5stack/M5GFX)
- [Arduino CLI Documentation](https://arduino.github.io/arduino-cli/latest/)
