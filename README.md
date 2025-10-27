# Arduino CLI Wrapper Samples

[日本語はこちら](README.ja.md)

## Overview
This repository hosts bilingual samples for the VS Code extension “Arduino CLI Wrapper.” Each category demonstrates a different workflow for managing assets, building sketches, and uploading binaries without leaving the editor. Every sketch ships with English and Japanese documentation so teams can share the same setup across locales.

## Requirements
- Arduino CLI 0.35 or newer available on `PATH`
- VS Code with the Arduino CLI Wrapper extension
- Supported boards and USB data cables noted in each sketch README
- Internet access to install board cores and libraries on first use

## Build & Upload
```
arduino-cli core update-index
arduino-cli core install <vendor>:<architecture>
arduino-cli lib update-index
arduino-cli compile --profile <profile-name> <category>/<sketch>
arduino-cli upload --profile <profile-name> --port <port> <category>/<sketch>
```
Replace `<profile-name>` with one of the profiles defined in the corresponding `sketch.yaml`. Profiles install required cores, add package index URLs, and list libraries such as `M5Unified` and `M5GFX`. Serial monitors should open at 115200 baud unless a README specifies otherwise.

## Categories
- [`01_getting-started`](01_getting-started/README.en.md): Introductory serial examples, including multi-board profiles.
- [`02_storage`](02_storage/README.en.md): Asset handling patterns for embedded images, sprites, SPIFFS, LittleFS, and microSD.

## Notes
- Whenever you edit files inside an `assets/` directory, run **Arduino CLI Wrapper: Embed Assets** (or build the sketch) to refresh the generated `assets_embed.h`.
- File-system based samples provide `data/` or `copy_to_sd/` folders—populate them with binary assets before uploading or copying to removable media.
- Follow each sketch README for board-specific wiring, upload commands, and troubleshooting logs.

## References
- [Arduino CLI Documentation](https://arduino.github.io/arduino-cli/latest/)
- [Arduino Language Reference](https://www.arduino.cc/reference/en/)
- [M5Unified](https://github.com/m5stack/M5Unified)
- [M5GFX](https://github.com/m5stack/M5GFX)
