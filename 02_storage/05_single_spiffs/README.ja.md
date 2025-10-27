# Single SPIFFS Asset

## Overview
ESP32 の SPIFFS パーティションから PNG ファイルを読み込み、LCD に描画するサンプルです。`data/` ディレクトリへ配置したバイナリアセットを、Arduino CLI Wrapper で書き込んでからスケッチを実行する手順を確認できます。

## Requirements
- Arduino CLI 0.35 以上
- M5Stack Core (Basic) または M5Stack AtomS3
- ESP32 Arduino Core `esp32:esp32` (3.3.2)
- ライブラリ `M5Unified` 0.2.10 と `M5GFX` 0.2.16

## Build & Upload
```
arduino-cli compile --profile m5stack_core 02_storage/05_single_spiffs
arduino-cli upload --profile m5stack_core --port <port> 02_storage/05_single_spiffs
```
AtomS3 を使用するときは `--profile m5stack_atoms3` に変更してください。

## Notes
- スケッチを書き込む前に、VS Code コマンド **Arduino CLI Wrapper: Upload Data** を実行して `data/` の内容を SPIFFS へ転送します。マウントに失敗するとシリアルモニタに `Run Upload Data!` が出力されます。
- `M5.Lcd.drawPngFile(SPIFFS, "/1.png", x, y)` は毎フレームファイルを読み込むため、再コンパイルせずにアセットを差し替えられます。

## References
- [SPIFFS on ESP32](https://docs.espressif.com/projects/arduino-esp32/en/latest/api/filesystem.html#spiffs)
- [M5Unified Library](https://github.com/m5stack/M5Unified)
- [Arduino CLI Documentation](https://arduino.github.io/arduino-cli/latest/)
