# BMP Sprite Asset

## Overview
`createFromBmp()` で BMP ファイルを `M5Canvas` スプライトへ読み込み、マゼンタ色を透過色として LCD に描画するサンプルです。PNG へ変換せずに既存の BMP 素材を活用しつつ、スプライト描画の利点 (チラつき抑制や再利用) を確認できます。

## Requirements
- Arduino CLI 0.35 以上
- M5Stack Core (Basic) または M5Stack AtomS3
- ESP32 Arduino Core `esp32:esp32` (3.3.2)
- ライブラリ `M5Unified` 0.2.10 と `M5GFX` 0.2.16

## Build & Upload
```
arduino-cli compile --profile m5stack_core 02_storage/04_bmp_sprite_assets
arduino-cli upload --profile m5stack_core --port <port> 02_storage/04_bmp_sprite_assets
```
AtomS3 向けには `--profile m5stack_atoms3` を指定してください。

## Notes
- `sprite.createFromBmp()` は埋め込んだ BMP から自動的にキャンバスサイズを決定します。`assets/` のファイルを差し替えたら **Arduino CLI Wrapper: Embed Assets** で `assets_embed.h` を更新してください（コンパイル時にも自動再生成されます）。
- `sprite.pushSprite()` に `TFT_MAGENTA` を渡し、純粋なマゼンタ (`#FF00FF`) を透過色として扱います。透過させたいピクセルはこの色で塗ってください。
- シリアルモニタ (115200 baud) には描画座標が出力されるため、表示位置を簡単に確認できます。

## References
- [M5Unified Library](https://github.com/m5stack/M5Unified)
- [M5GFX Sprite Guide](https://github.com/m5stack/M5GFX#sprites)
- [Arduino CLI Documentation](https://arduino.github.io/arduino-cli/latest/)
