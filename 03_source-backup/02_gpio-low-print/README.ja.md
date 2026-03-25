# GPIO Low Print Source Backup

## Overview
このスケッチは、起動直後に特定 GPIO が LOW だった場合だけ、埋め込み済みの Source Backup をシリアルへ出力します。既定では `GPIO33` を監視しており、外部スイッチやジャンパで LOW にすると Base64 の zip バックアップを表示できます。

## Requirements
- Arduino CLI 0.35 以上
- ESP32 Dev Module 互換ボード
- ESP32 Arduino Core `esp32:esp32` (3.3.7)

## Build & Upload
```
arduino-cli compile --profile esp32_dev 03_source-backup/02_gpio-low-print
arduino-cli upload --profile esp32_dev --port <port> 03_source-backup/02_gpio-low-print
```
書き込み後はシリアルモニタを 115200 baud で開き、`GPIO33` を LOW にした状態でリセットまたは再起動するとバックアップを出力します。

## Notes
- `kBackupTriggerPin` は `02_gpio-low-print.ino` 内で `33` に設定してあり、必要に応じて任意の GPIO へ変更できます。
- `GPIO0` のようなブートストラップ用ピンは通常起動に影響するため、この用途には使わず、通常起動へ影響しない GPIO を選んでください。
- 入力は `INPUT_PULLUP` で扱うため、監視するピンは通常 HIGH、トリガ時のみ LOW になる配線を前提としています。
- 条件を満たさずに起動した場合はバックアップ本文を出さず、復元ページの URL のみ案内します。
- Base64 が出力された場合は `-----BEGIN SOURCEBACKUP ZIP BASE64-----` と `-----END SOURCEBACKUP ZIP BASE64-----` の範囲を抽出し、復元ページ `https://tanakamasayuki.github.io/arduino-cli-helper/sourcebackup.html` に貼り付けて展開できます。

## References
- [Arduino CLI Documentation](https://arduino.github.io/arduino-cli/latest/)
- [ESP32 Arduino Core](https://github.com/espressif/arduino-esp32)
- [Source Backup Restore](https://tanakamasayuki.github.io/arduino-cli-helper/sourcebackup.html)
