# Source Backup サンプル

## Overview
このカテゴリでは、`.sourcebackupconfig` を使ってスケッチのビルドに必要なファイルを zip アーカイブへまとめ、その内容を `sourcebackup_embed.h` / `sourcebackup_embed.cpp` としてプログラムに埋め込む流れを扱います。実機のシリアル出力から Base64 化されたバックアップを取得できるため、配布済みバイナリから元のソース構成を追跡したい場合の検証に向いています。

## Requirements
- PATH に設定された Arduino CLI 0.35 以上
- USB データケーブルで接続した ESP32 Dev Module 互換ボード
- ESP32 Arduino Core `esp32:esp32` (3.3.7)

## Build & Upload
```
arduino-cli compile --profile esp32_dev 03_source-backup/<sketch-folder>
arduino-cli upload --profile esp32_dev --port <port> 03_source-backup/<sketch-folder>
```
`<sketch-folder>` には対象ディレクトリ名を指定します。現時点では `01_boot-print` と `02_gpio-low-print` を利用できます。シリアルモニタは 115200 baud で開いてください。

## Notes
- `.sourcebackupconfig` の `include` / `exclude` パターンで、アーカイブへ入れるファイルと除外する生成物を制御します。
- コンパイル時に `sourcebackup_embed.h` と `sourcebackup_embed.cpp` が再生成され、zip 本体とマニフェストがプログラムメモリへ埋め込まれます。
- 生成コードには復元用 URL や Base64 出力ヘルパーが含まれるため、シリアルログからバックアップを取り出して復元ページ `https://tanakamasayuki.github.io/arduino-cli-helper/sourcebackup.html` へ渡せます。

## References
- [Arduino CLI Documentation](https://arduino.github.io/arduino-cli/latest/)
- [ESP32 Arduino Core](https://github.com/espressif/arduino-esp32)
- [Source Backup Restore](https://tanakamasayuki.github.io/arduino-cli-helper/sourcebackup.html)
