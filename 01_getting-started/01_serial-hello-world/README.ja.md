# Serial Hello World

## Overview
115200 baud のシリアル出力を行う「Hello World」スケッチを、ボード別に 3 つ用意したセットです。各ディレクトリが特定ボード専用になっているため、Arduino CLI の基本操作を学ぶときに対象を絞って試せます。

## Requirements
- Arduino CLI 0.35 以上
- 対応ボード本体と USB データケーブル
  - Arduino Uno R3
  - ESP32 Dev Module
  - M5Atom

## Build & Upload
Arduino Uno R3 の例:
```
arduino-cli compile 01_getting-started/01_serial-hello-world/serial-hello-world-uno
arduino-cli upload --port <port> 01_getting-started/01_serial-hello-world/serial-hello-world-uno
```
ESP32 系のボードでは `serial-hello-world-esp32-dev` や `serial-hello-world-m5stack-atom` にパスを置き換えて同じコマンドを実行します。`<port>` には環境で検出されたシリアルポート名を指定し、シリアルモニタは 115200 baud で開いてください。

## Notes
- 各ディレクトリの `sketch.yaml` は単一のプロファイルのみを公開しているため、`--profile` の指定は不要です。
- 複数ボードをひとつのプロジェクトで切り替えたい場合は、`getting-started/serial-hello-world-multi-board/` にあるプロファイル活用例を参照してください。
- 1 秒ごとにメッセージを出力するため、動作タイミングの安定性を簡単に確認できます。

## References
- [Arduino Uno R3 Board Package](https://docs.arduino.cc/hardware/uno-rev3)
- [ESP32 Arduino Core](https://github.com/espressif/arduino-esp32)
- [M5Stack クイックスタート](https://docs.m5stack.com/ja/start)

