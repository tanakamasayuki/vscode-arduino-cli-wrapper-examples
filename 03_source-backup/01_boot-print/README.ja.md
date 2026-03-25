# Boot Print Source Backup

## Overview
このスケッチは、起動時に埋め込み済みの Source Backup をシリアルへ毎回出力する最小サンプルです。`setup()` で `sourcebackup::writeArchiveBase64WithInfoTo(Serial)` を呼び出し、復元ページの URL と zip アーカイブの Base64 をまとめて表示します。

## Requirements
- Arduino CLI 0.35 以上
- ESP32 Dev Module 互換ボード
- ESP32 Arduino Core `esp32:esp32` (3.3.7)

## Build & Upload
```
arduino-cli compile --profile esp32_dev 03_source-backup/01_boot-print
arduino-cli upload --profile esp32_dev --port <port> 03_source-backup/01_boot-print
```
書き込み後はシリアルモニタを 115200 baud で開き、ボードのリセットまたは再起動で出力を確認します。

## Notes
- `.sourcebackupconfig` により、`01_boot-print.ino`、`sketch.yaml`、設定ファイル自身などビルド再現に必要なファイルが zip に含まれます。
- `sourcebackup_embed.h` と `sourcebackup_embed.cpp` は生成物なので、設定や対象ファイルを更新したあとに再コンパイルして内容を反映してください。
- 起動のたびに Base64 全文を出力するため、長いシリアルログを扱える端末での確認が向いています。
- 出力には `-----BEGIN SOURCEBACKUP ZIP BASE64-----` と `-----END SOURCEBACKUP ZIP BASE64-----` の区切りが含まれるため、該当範囲をそのまま抽出して復元ページ `https://tanakamasayuki.github.io/arduino-cli-helper/sourcebackup.html` に貼り付けられます。

## References
- [Arduino CLI Documentation](https://arduino.github.io/arduino-cli/latest/)
- [ESP32 Arduino Core](https://github.com/espressif/arduino-esp32)
- [Source Backup Restore](https://tanakamasayuki.github.io/arduino-cli-helper/sourcebackup.html)
