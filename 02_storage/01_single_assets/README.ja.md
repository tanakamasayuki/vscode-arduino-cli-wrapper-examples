# Single Embedded Asset

## Overview
`assets/1.png` をプログラムメモリに埋め込み、`M5Unified::drawPng` で直接 LCD に描画するサンプルです。ループごとにランダムな座標を選び、ファイルシステムを介さずにブリット転送できることを確認できます。

## Requirements
- Arduino CLI 0.35 以上
- M5Stack Core (Basic) または M5Stack AtomS3
- ESP32 Arduino Core `esp32:esp32` (3.3.2)
- ライブラリ `M5Unified` 0.2.10 と `M5GFX` 0.2.16

## Build & Upload
```
arduino-cli compile --profile m5stack_core 02_storage/01_single_assets
arduino-cli upload --profile m5stack_core --port <port> 02_storage/01_single_assets
```
AtomS3 に書き込む場合は `--profile` を `m5stack_atoms3` に変更してください。

## Notes
- `assets/` の PNG を更新したら、VS Code コマンド **Arduino CLI Wrapper: Embed Assets** を実行して `assets_embed.h` を再生成します（コンパイル時にも自動再生成されます）。
- ランダム座標はシリアルモニタ (115200 baud) に出力されるため、描画位置を簡単に確認できます。
- デバッグ時に位置を固定したい場合は `random()` の結果を定数に置き換えて挙動を観察してください。

## References
- [M5Unified Library](https://github.com/m5stack/M5Unified)
- [M5GFX Library](https://github.com/m5stack/M5GFX)
- [Arduino CLI Documentation](https://arduino.github.io/arduino-cli/latest/)
