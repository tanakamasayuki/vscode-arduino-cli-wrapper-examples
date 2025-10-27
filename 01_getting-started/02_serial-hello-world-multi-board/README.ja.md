# Serial Hello World (Multi-Board)

## Overview
単一のスケッチを維持したまま、`sketch.yaml` に定義したプロファイルを切り替えて Arduino Uno R3、ESP32 Dev Module、M5Atom を動かす例です。複数ボード向けに同一コードを管理したい場合のサンプルとして利用できます。

## Requirements
- PATH に設定された Arduino CLI 0.35 以上
- 対象ボード本体と USB データケーブル
- `sketch.yaml` に記載されたボードサポートパッケージ（未導入の場合は事前にインストール）

## Build & Upload
```
arduino-cli compile --profile uno 01_getting-started/02_serial-hello-world-multi-board/serial-hello-world-multi-board
arduino-cli upload --profile uno --port <port> 01_getting-started/02_serial-hello-world-multi-board/serial-hello-world-multi-board
```
ESP32 系ボードを使うときは `--profile` の値を `esp32_dev` または `m5stack_atom` に変更します。シリアルモニタは 115200 baud で開いてください。

## Notes
- `default_profile` は `uno` に設定しているため、Arduino Uno R3 に向けてビルドする場合は `--profile` を省略できます。
- 各プロファイルに必要なコア名とパッケージインデックス URL を記載しています。
- `getting-started/serial-hello-world/` にあるボード別プロジェクトと併せて比較し、運用に合う構成を選んでください。

## References
- [Arduino CLI Documentation](https://arduino.github.io/arduino-cli/latest/)
- [Arduino Uno R3 Board Package](https://docs.arduino.cc/hardware/uno-rev3)
- [ESP32 Arduino Core](https://github.com/espressif/arduino-esp32)
- [M5Stack クイックスタート](https://docs.m5stack.com/ja/start)

