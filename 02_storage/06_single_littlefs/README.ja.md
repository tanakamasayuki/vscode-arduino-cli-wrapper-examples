# Single LittleFS Asset

## Overview
ESP32 の LittleFS パーティションをマウントし、PNG ファイルを読み込んで LCD に描画するサンプルです。ディレクトリ構造の扱いや信頼性が求められる場面で、SPIFFS の代わりに LittleFS を利用する手順を確認できます。

## Requirements
- Arduino CLI 0.35 以上
- M5Stack Core (Basic) または M5Stack AtomS3
- ESP32 Arduino Core `esp32:esp32` (3.3.2)
- ライブラリ `M5Unified` 0.2.10 と `M5GFX` 0.2.16

## Build & Upload
```
arduino-cli compile --profile m5stack_core 02_storage/06_single_littlefs
arduino-cli upload --profile m5stack_core --port <port> 02_storage/06_single_littlefs
```
AtomS3 に書き込む場合は `--profile m5stack_atoms3` を指定してください。

## Notes
- スケッチを書き込む前に `data/` の内容を **Arduino CLI Wrapper: Upload Data** で LittleFS へ転送します。マウントに失敗すると `Run Upload Data!` とシリアル出力されます。
- `LittleFS.begin()` はデフォルト設定を利用しています。パーティションサイズを変更した場合は必要に応じてオプションを調整してください。
- 描画は `M5.Lcd.drawPngFile(LittleFS, "/1.png", x, y)` に依存しているため、ファイルを差し替えるだけで表示内容を更新できます。

## References
- [LittleFS on ESP32](https://docs.espressif.com/projects/arduino-esp32/en/latest/api/filesystem.html#littlefs)
- [M5Unified Library](https://github.com/m5stack/M5Unified)
- [Arduino CLI Documentation](https://arduino.github.io/arduino-cli/latest/)
