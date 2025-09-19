# Serial Hello World (Multi-Board)

## Overview
This example keeps one sketch and switches between Arduino Uno R3, ESP32 Dev Module, and M5Atom by selecting profiles defined in `sketch.yaml`. It is useful when you want to maintain a single codebase that targets multiple boards from Arduino CLI.

## Requirements
- Arduino CLI 0.35 or newer installed on PATH
- One of the supported boards and its USB data cable
- Board support packages listed in `sketch.yaml` (install them before compiling if needed)

## Build & Upload
```
arduino-cli compile --profile uno getting-started/serial-hello-world-multi-board/serial-hello-world-multi-board
arduino-cli upload --profile uno --port <port> getting-started/serial-hello-world-multi-board/serial-hello-world-multi-board
```
Replace `uno` with `esp32_dev` or `m5stack_atom` to target ESP32-based boards. Open the Serial Monitor at 115200 baud to read the output.

## Notes
- The default profile is `uno`; you can omit `--profile` when building for Arduino Uno R3.
- Each profile lists its required core and, where necessary, the package index URL.
- Pair this example with the board-specific projects in `getting-started/serial-hello-world/` to compare maintenance styles.

## References
- [Arduino CLI Documentation](https://arduino.github.io/arduino-cli/latest/)
- [Arduino Uno R3 Board Package](https://docs.arduino.cc/hardware/uno-rev3)
- [ESP32 Arduino Core](https://github.com/espressif/arduino-esp32)
- [M5Stack Getting Started](https://docs.m5stack.com/en/start)

