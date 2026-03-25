# Source Backup Samples

## Overview
This category focuses on `.sourcebackupconfig`, which collects the files required to rebuild a sketch into a zip archive and embeds that archive as `sourcebackup_embed.h` / `sourcebackup_embed.cpp`. The resulting binary can emit a Base64 backup over Serial, which is useful when you need to inspect or restore the source bundle that produced a deployed firmware image.

## Requirements
- Arduino CLI 0.35 or newer on PATH
- An ESP32 Dev Module compatible board connected over a USB data cable
- ESP32 Arduino core `esp32:esp32` (3.3.7)

## Build & Upload
```
arduino-cli compile --profile esp32_dev 03_source-backup/<sketch-folder>
arduino-cli upload --profile esp32_dev --port <port> 03_source-backup/<sketch-folder>
```
Replace `<sketch-folder>` with the directory you want to test. `01_boot-print` and `02_gpio-low-print` are currently available. Keep the Serial Monitor at 115200 baud.

## Notes
- The `include` and `exclude` patterns in `.sourcebackupconfig` define which project files become part of the archive and which generated outputs stay out.
- Compilation regenerates `sourcebackup_embed.h` and `sourcebackup_embed.cpp`, embedding both the zip payload and a manifest into program memory.
- The generated helpers expose a restore URL and Base64 output routines so you can copy the backup from Serial into the restore page at `https://tanakamasayuki.github.io/arduino-cli-helper/sourcebackup.html`.

## References
- [Arduino CLI Documentation](https://arduino.github.io/arduino-cli/latest/)
- [ESP32 Arduino Core](https://github.com/espressif/arduino-esp32)
- [Source Backup Restore](https://tanakamasayuki.github.io/arduino-cli-helper/sourcebackup.html)
