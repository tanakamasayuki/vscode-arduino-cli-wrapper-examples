# BMP Sprite Asset

## Overview
This sketch loads a BMP file into an `M5Canvas` sprite with `createFromBmp()` and then pushes the sprite to the LCD while treating magenta as the transparent color key. It illustrates how to reuse existing BMP artwork without converting it to PNG while still benefiting from sprite-based rendering.

## Requirements
- Arduino CLI 0.35 or newer
- M5Stack Core (Basic) or M5Stack AtomS3
- ESP32 Arduino core `esp32:esp32` (3.3.2)
- Libraries `M5Unified` 0.2.10 and `M5GFX` 0.2.16

## Build & Upload
```
arduino-cli compile --profile m5stack_core 02_storage/04_bmp_sprite_assets
arduino-cli upload --profile m5stack_core --port <port> 02_storage/04_bmp_sprite_assets
```
Use the `m5stack_atoms3` profile when targeting AtomS3 hardware.

## Notes
- `sprite.createFromBmp()` determines the canvas dimensions from the embedded BMP, so you only need to update the source file before regenerating `assets_embed.h`.
- The sketch passes `TFT_MAGENTA` to `pushSprite()` as the transparent color; ensure your BMP reserves pure magenta (`#FF00FF`) for pixels that should not be drawn.
- Refresh the generated header with **Arduino CLI Wrapper: Embed Assets** after updating files under `assets/` (compilation also regenerates the header automatically).

## References
- [M5Unified Library](https://github.com/m5stack/M5Unified)
- [M5GFX Sprite Guide](https://github.com/m5stack/M5GFX#sprites)
- [Arduino CLI Documentation](https://arduino.github.io/arduino-cli/latest/)
