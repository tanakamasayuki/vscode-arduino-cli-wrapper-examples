# Getting Started Samples

## Overview
This category collects introductory sketches that demonstrate the minimum Arduino CLI workflow. Each example focuses on a single concept so that new users can compile, upload, and monitor serial output without additional hardware.

## Requirements
- Arduino CLI 0.35 or newer installed and available on PATH
- Supported board connected over USB when uploading
- USB cable capable of data transfer

## Build & Upload
```
arduino-cli core update-index
arduino-cli core install <vendor>:<architecture>
arduino-cli lib update-index
arduino-cli compile --profile <profile-name>
arduino-cli upload --profile <profile-name> --port <port>
```
Select the profile that matches your board (for example `uno`, `esp32_dev`, or `m5stack_atom`). Replace `<port>` with the serial device path detected on your system.

## Notes
- All sketches include bilingual documentation so that Japanese and English readers can follow identical steps.
- Code comments stay in English to match Arduino coding conventions.
- `Serial Hello World` offers both board-specific directories and a multi-board profile sample so you can compare workflows.
- Use the Serial Monitor at 115200 baud unless the sketch README states otherwise.

## References
- [Arduino CLI Documentation](https://arduino.github.io/arduino-cli/latest/)
- [Arduino Language Reference](https://www.arduino.cc/reference/en/)

