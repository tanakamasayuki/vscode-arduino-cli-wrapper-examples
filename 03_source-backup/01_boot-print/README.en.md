# Boot Print Source Backup

## Overview
This sketch is a minimal example that prints the embedded Source Backup every time the board boots. Inside `setup()`, it calls `sourcebackup::writeArchiveBase64WithInfoTo(Serial)` so the Serial output includes both the restore page URL and the Base64-encoded zip archive.

## Requirements
- Arduino CLI 0.35 or newer
- An ESP32 Dev Module compatible board
- ESP32 Arduino core `esp32:esp32` (3.3.7)

## Build & Upload
```
arduino-cli compile --profile esp32_dev 03_source-backup/01_boot-print
arduino-cli upload --profile esp32_dev --port <port> 03_source-backup/01_boot-print
```
After flashing, open the Serial Monitor at 115200 baud and reset or power-cycle the board to capture the output.

## Notes
- `.sourcebackupconfig` includes the files needed to rebuild this sketch, such as `01_boot-print.ino`, `sketch.yaml`, and the configuration file itself.
- `sourcebackup_embed.h` and `sourcebackup_embed.cpp` are generated files, so rebuild the sketch whenever the config or included sources change.
- Because the sketch prints the full Base64 archive on each boot, use a serial terminal that can handle longer logs without truncating them.
- The output is wrapped with `-----BEGIN SOURCEBACKUP ZIP BASE64-----` and `-----END SOURCEBACKUP ZIP BASE64-----`, making the payload easy to copy into the restore page at `https://tanakamasayuki.github.io/arduino-cli-helper/sourcebackup.html`.

## References
- [Arduino CLI Documentation](https://arduino.github.io/arduino-cli/latest/)
- [ESP32 Arduino Core](https://github.com/espressif/arduino-esp32)
- [Source Backup Restore](https://tanakamasayuki.github.io/arduino-cli-helper/sourcebackup.html)
