# Serial Hello World

## Overview
This sketch set provides three board-specific "Hello World" projects that print to the Serial Monitor at 115200 baud. Each directory is dedicated to one supported board so you can focus on a single toolchain when learning Arduino CLI.

## Requirements
- Arduino CLI 0.35 or newer
- One of the supported boards and a matching USB data cable
  - Arduino Uno R3
  - ESP32 Dev Module
  - M5Atom

## Build & Upload
Example for Arduino Uno R3:
```
arduino-cli compile getting-started/serial-hello-world/serial-hello-world-uno
arduino-cli upload --port <port> getting-started/serial-hello-world/serial-hello-world-uno
```
Use the same commands with `serial-hello-world-esp32-dev` or `serial-hello-world-m5stack-atom` to target the ESP32-based boards. Replace `<port>` with the serial device path detected on your machine, and open the Serial Monitor at 115200 baud.

## Notes
- Each directory exposes a single profile in its `sketch.yaml`, so you do not need to pass `--profile`.
- If you want to manage several boards from one project, see `getting-started/serial-hello-world-multi-board/` for a profile-based variant.
- The loop prints once per second to make it easy to confirm timing stability.

## References
- [Arduino Uno R3 Board Package](https://docs.arduino.cc/hardware/uno-rev3)
- [ESP32 Arduino Core](https://github.com/espressif/arduino-esp32)
- [M5Stack Getting Started](https://docs.m5stack.com/en/start)

