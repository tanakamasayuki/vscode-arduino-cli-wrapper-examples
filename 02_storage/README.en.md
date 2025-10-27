# Storage Samples

## Overview
This category showcases different ways to bundle and stream binary assets when working with M5Stack displays. The sketches cover embedded PNG/BMP data, sprite drawing, and file-system based loading so you can choose the right delivery method for your storage and performance needs.

## Requirements
- Arduino CLI 0.35 or newer on PATH
- M5Stack Core (Basic) or M5Stack AtomS3 with a USB data cable
- ESP32 Arduino core `esp32:esp32` (3.3.2) installed
- Libraries `M5Unified` 0.2.10 and `M5GFX` 0.2.16

## Build & Upload
```
arduino-cli compile --profile m5stack_core 02_storage/<sketch-folder>
arduino-cli upload --profile m5stack_core --port <port> 02_storage/<sketch-folder>
```
Replace `<sketch-folder>` with the directory name you want to test (for example `01_single_assets` or `06_single_littlefs`). Select the `m5stack_atoms3` profile when targeting AtomS3 hardware. Keep the Serial Monitor at 115200 baud.

## Notes
- Folders that contain `assets_embed.h` expect you to refresh embedded binaries with the **Arduino CLI Wrapper: Embed Assets** command (the wrapper also regenerates the header automatically when you compile) after editing files under `assets/`.
- File-system sketches rely on the VS Code command palette entry **Arduino CLI Wrapper: Upload Data** to flash the contents of `data/` before running.
- `07_single_sd/copy_to_sd/` stores files that must be copied manually onto a microSD card before inserting it into the device.
- Each `sketch.yaml` enumerates the required core version and libraries so that `arduino-cli` can resolve dependencies when the profile is selected.

## References
- [Arduino CLI Documentation](https://arduino.github.io/arduino-cli/latest/)
- [ESP32 Arduino Core](https://github.com/espressif/arduino-esp32)
- [M5Unified Library](https://github.com/m5stack/M5Unified)
- [M5GFX Library](https://github.com/m5stack/M5GFX)
