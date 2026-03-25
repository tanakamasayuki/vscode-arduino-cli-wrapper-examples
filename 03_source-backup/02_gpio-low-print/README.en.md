# GPIO Low Print Source Backup

## Overview
This sketch prints the embedded Source Backup only when a specific GPIO reads LOW during boot. It monitors `GPIO33` by default, so you can drive that pin LOW with an external switch or jumper while powering up or resetting the board to emit the Base64 zip backup.

## Requirements
- Arduino CLI 0.35 or newer
- An ESP32 Dev Module compatible board
- ESP32 Arduino core `esp32:esp32` (3.3.7)

## Build & Upload
```
arduino-cli compile --profile esp32_dev 03_source-backup/02_gpio-low-print
arduino-cli upload --profile esp32_dev --port <port> 03_source-backup/02_gpio-low-print
```
After flashing, open the Serial Monitor at 115200 baud. Hold `GPIO33` LOW while resetting or powering up the board to print the backup.

## Notes
- `kBackupTriggerPin` is set to `33` in `02_gpio-low-print.ino`, and you can change it to any GPIO that suits your hardware.
- Avoid bootstrapping pins such as `GPIO0` for this purpose because pulling them LOW can change the boot mode instead of allowing a normal startup.
- The input uses `INPUT_PULLUP`, so the monitored pin should stay HIGH in the idle state and be driven LOW only when you want to trigger the backup output.
- When the condition is not met, the sketch skips the Base64 payload and only prints the restore page URL.
- When Base64 is emitted, copy the range between `-----BEGIN SOURCEBACKUP ZIP BASE64-----` and `-----END SOURCEBACKUP ZIP BASE64-----` into the restore page at `https://tanakamasayuki.github.io/arduino-cli-helper/sourcebackup.html`.

## References
- [Arduino CLI Documentation](https://arduino.github.io/arduino-cli/latest/)
- [ESP32 Arduino Core](https://github.com/espressif/arduino-esp32)
- [Source Backup Restore](https://tanakamasayuki.github.io/arduino-cli-helper/sourcebackup.html)
