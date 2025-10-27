# PNG Sprite Asset

## Overview
This sketch preloads a PNG image into an off-screen `M5Canvas` sprite and pushes the sprite to the LCD with transparency handling. It demonstrates how to mix embedded image data with sprite compositing to reduce flicker or prepare layered graphics before flushing them to the display.

## Requirements
- Arduino CLI 0.35 or newer
- M5Stack Core (Basic) or M5Stack AtomS3
- ESP32 Arduino core `esp32:esp32` (3.3.2)
- Libraries `M5Unified` 0.2.10 and `M5GFX` 0.2.16

## Build & Upload
```
arduino-cli compile --profile m5stack_core 02_storage/03_png_sprite_assets
arduino-cli upload --profile m5stack_core --port <port> 02_storage/03_png_sprite_assets
```
Select the `m5stack_atoms3` profile when running on AtomS3 hardware.

## Notes
- Sprite dimensions are configured through `sprite_width` and `sprite_height`; adjust these constants if your asset size changes.
- Regenerate `assets_embed.h` with **Arduino CLI Wrapper: Embed Assets** after modifying files under `assets/` (compilation also refreshes the header automatically).
- `sprite.pushSprite()` uses `TFT_TRANSPARENT`, allowing the PNG alpha channel to determine which pixels are written to the LCD.

## References
- [M5Unified Library](https://github.com/m5stack/M5Unified)
- [M5GFX Sprite Guide](https://github.com/m5stack/M5GFX#sprites)
- [Arduino CLI Documentation](https://arduino.github.io/arduino-cli/latest/)
