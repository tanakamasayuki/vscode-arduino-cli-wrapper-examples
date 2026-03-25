# Hidden Source Backup

## Overview
This sketch embeds Source Backup into the firmware image but does not reference it from the sketch code. Because it never calls helpers such as `sourcebackup::writeArchiveBase64WithInfoTo()`, you cannot retrieve the backup directly from the board over Serial while the firmware is running.

## Requirements
- Arduino CLI 0.35 or newer
- An ESP32 Dev Module compatible board
- ESP32 Arduino core `esp32:esp32` (3.3.7)
- `esptool.py` if you want to read flash back from hardware

## Build & Upload
```
arduino-cli compile --profile esp32_dev 03_source-backup/03_none-print
arduino-cli upload --profile esp32_dev --port <port> 03_source-backup/03_none-print
```
This sketch does not print the Source Backup payload on boot. It only reports that the backup is embedded.

## Notes
- The Source Backup payload still lives inside `sourcebackup_embed.cpp`, so it remains in the firmware image even though the runtime code never references it.
- To extract it from real hardware, read the flash image first. Example:
```bash
esptool.py -p /dev/ttyUSB0 read-flash 0x00000 0x400000 flash.bin
```
- Upload the resulting `flash.bin` to the extraction page at `https://tanakamasayuki.github.io/arduino-cli-helper/sourcebackup.html` to detect the embedded Source Backup and download the ZIP archive.
- Since the sketch does not read the backup itself, obtaining the firmware image is the required first step for analysis.

## References
- [Arduino CLI Documentation](https://arduino.github.io/arduino-cli/latest/)
- [ESP32 Arduino Core](https://github.com/espressif/arduino-esp32)
- [Source Backup Restore](https://tanakamasayuki.github.io/arduino-cli-helper/sourcebackup.html)
- [esptool](https://github.com/espressif/esptool)
