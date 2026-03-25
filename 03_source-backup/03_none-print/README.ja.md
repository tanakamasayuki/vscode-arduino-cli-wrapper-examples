# Hidden Source Backup

## Overview
このスケッチは Source Backup をファームウェアへ埋め込みますが、スケッチ本体からは参照しないサンプルです。プログラム実行中に `sourcebackup::writeArchiveBase64WithInfoTo()` などを呼ばないため、実機のシリアル出力から直接バックアップを取り出すことはできません。

## Requirements
- Arduino CLI 0.35 以上
- ESP32 Dev Module 互換ボード
- ESP32 Arduino Core `esp32:esp32` (3.3.7)
- 実機から flash を読み出す場合は `esptool.py`

## Build & Upload
```
arduino-cli compile --profile esp32_dev 03_source-backup/03_none-print
arduino-cli upload --profile esp32_dev --port <port> 03_source-backup/03_none-print
```
このスケッチは起動時に Source Backup 本文を出力せず、埋め込み済みであることだけをシリアルへ表示します。

## Notes
- Source Backup 自体は `sourcebackup_embed.cpp` に埋め込まれているため、実行コードが参照しなくてもファームウェア内には残ります。
- 実機から抽出する場合は、まず flash イメージを読み出します。例:
```bash
esptool.py -p /dev/ttyUSB0 read-flash 0x00000 0x400000 flash.bin
```
- 読み出した `flash.bin` を抽出ページ `https://tanakamasayuki.github.io/arduino-cli-helper/sourcebackup.html` に渡すと、埋め込まれた Source Backup を検出して ZIP をダウンロードできます。
- このサンプルではプログラムから Source Backup を読まないため、実機上の通常動作だけではバックアップの存在を確認できません。解析時はファームウェアイメージの取得が前提です。

## References
- [Arduino CLI Documentation](https://arduino.github.io/arduino-cli/latest/)
- [ESP32 Arduino Core](https://github.com/espressif/arduino-esp32)
- [Source Backup Restore](https://tanakamasayuki.github.io/arduino-cli-helper/sourcebackup.html)
- [esptool](https://github.com/espressif/esptool)
