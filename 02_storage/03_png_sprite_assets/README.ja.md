# PNG Sprite Asset

## Overview
PNG 画像をオフスクリーンの `M5Canvas` スプライトへ読み込み、透明度を保ったまま LCD に転送するサンプルです。埋め込みアセットとスプライト合成を組み合わせることで、フリッカーを抑えた描画やレイヤー構成を検証できます。

## Requirements
- Arduino CLI 0.35 以上
- M5Stack Core (Basic) または M5Stack AtomS3
- ESP32 Arduino Core `esp32:esp32` (3.3.2)
- ライブラリ `M5Unified` 0.2.10 と `M5GFX` 0.2.16

## Build & Upload
```
arduino-cli compile --profile m5stack_core 02_storage/03_png_sprite_assets
arduino-cli upload --profile m5stack_core --port <port> 02_storage/03_png_sprite_assets
```
AtomS3 を使う場合は `--profile m5stack_atoms3` に切り替えてください。

## Notes
- スプライトのサイズは `sprite_width` と `sprite_height` で指定しています。アセットの解像度を変えるときは値を合わせて更新してください。
- `assets/` 配下を編集したら **Arduino CLI Wrapper: Embed Assets** を実行して `assets_embed.h` を再生成します（コンパイル時にも自動再生成されます）。
- `sprite.pushSprite()` に `TFT_TRANSPARENT` を渡し、PNG のアルファチャンネル情報をそのまま LCD 描画へ反映しています。

## References
- [M5Unified Library](https://github.com/m5stack/M5Unified)
- [M5GFX Sprite Guide](https://github.com/m5stack/M5GFX#sprites)
- [Arduino CLI Documentation](https://arduino.github.io/arduino-cli/latest/)
