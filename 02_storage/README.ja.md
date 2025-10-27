# Storage サンプル

## Overview
このカテゴリでは、M5Stack 系デバイスで画像などのバイナリアセットを扱うための手法をまとめています。PNG/BMP をソースコードに埋め込む方法、スプライトに展開する方法、SPIFFS・LittleFS・SD から読み込む方法を比較しながら、用途に合ったストレージ構成を選べます。

## Requirements
- PATH に設定された Arduino CLI 0.35 以上
- USB データケーブルで接続した M5Stack Core (Basic) または M5Stack AtomS3
- ESP32 Arduino Core `esp32:esp32` (3.3.2)
- ライブラリ `M5Unified` 0.2.10 と `M5GFX` 0.2.16

## Build & Upload
```
arduino-cli compile --profile m5stack_core 02_storage/<sketch-folder>
arduino-cli upload --profile m5stack_core --port <port> 02_storage/<sketch-folder>
```
`<sketch-folder>` には動作させたいディレクトリ名（例: `01_single_assets`、`06_single_littlefs`）を指定してください。AtomS3 を使う場合は `--profile m5stack_atoms3` に切り替えます。シリアルモニタは 115200 baud で開きます。

## Notes
- `assets_embed.h` を含むスケッチは、`assets/` 下のファイルを更新したあとに VS Code コマンド **Arduino CLI Wrapper: Embed Assets** を実行してヘッダーを再生成します（コンパイル時にも自動再生成されます）。
- `data/` フォルダを持つスケッチは、実行前に **Arduino CLI Wrapper: Upload Data** コマンドでファイルシステム領域へ書き込みます。
- `07_single_sd/copy_to_sd/` 内のファイルは実行前に microSD カードへ手動コピーしてください。
- 各 `sketch.yaml` に必要なコアやライブラリのバージョンを記載しているため、指定したプロファイルで依存関係が自動解決されます。

## References
- [Arduino CLI Documentation](https://arduino.github.io/arduino-cli/latest/)
- [ESP32 Arduino Core](https://github.com/espressif/arduino-esp32)
- [M5Unified Library](https://github.com/m5stack/M5Unified)
- [M5GFX Library](https://github.com/m5stack/M5GFX)
