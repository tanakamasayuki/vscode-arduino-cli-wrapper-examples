# Single SD Asset

## Overview
microSD カードから PNG ファイルを読み込み、LCD に描画するサンプルです。カードが認識されるまで SPI マウントを繰り返し、シリアルコンソールに進捗を表示します。

## Requirements
- Arduino CLI 0.35 以上
- フォーマット済み microSD カードを用意した M5Stack Core (Basic) または M5Stack AtomS3
- ESP32 Arduino Core `esp32:esp32` (3.3.2)
- ライブラリ `M5Unified` 0.2.10 と `M5GFX` 0.2.16

## Build & Upload
```
arduino-cli compile --profile m5stack_core 02_storage/07_single_sd
arduino-cli upload --profile m5stack_core --port <port> 02_storage/07_single_sd
```
AtomS3 向けには `--profile m5stack_atoms3` を指定してください。

## Notes
- 実行前に `copy_to_sd/` 内のファイルを microSD カードのルートへコピーします。
- `SD.begin(GPIO_NUM_4, SPI, 25000000)` を使用しているため、チップセレクトに GPIO 4 を割り当てていることを確認してください。別配線の場合は引数を調整します。
- カードが未挿入の間は 500 ms ごとに `SD Wait...` をシリアルモニタ (115200 baud) に表示し、状態を把握できるようにしています。

## References
- [ESP32 SD API](https://docs.espressif.com/projects/arduino-esp32/en/latest/api/filesystem.html#sd)
- [M5Unified Library](https://github.com/m5stack/M5Unified)
- [Arduino CLI Documentation](https://arduino.github.io/arduino-cli/latest/)
