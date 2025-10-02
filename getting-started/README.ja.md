# Getting Started サンプル

## Overview
Arduino CLI の最小限のワークフローを段階的に理解できる入門スケッチをまとめています。追加ハードウェアがなくても、ビルドからシリアルモニタ確認までの流れを体験できます。

## Requirements
- PATH に設定された Arduino CLI 0.35 以上
- アップロード対象のマイコンボードと接続用 USB ケーブル
- アップロード時にボードが PC と接続されていること

## Build & Upload
```
arduino-cli core update-index
arduino-cli core install <vendor>:<architecture>
arduino-cli lib update-index
arduino-cli compile --profile <profile-name>
arduino-cli upload --profile <profile-name> --port <port>
```
利用するボードに合わせて `uno`、`esp32_dev`、`m5stack_atom` などのプロファイルを選択してください。`<port>` にはお使いの環境で検出されたシリアルポート名を指定します。

## Notes
- すべてのスケッチは日本語と英語の README を同梱しています。
- コード内コメントは Arduino の慣例に合わせて英語で統一しています。
- `Serial Hello World` ではボード専用ディレクトリとマルチボードの両方の構成例を提供しており、用途に合わせて比較できます。
- 特記がない限りシリアルモニタは 115200 baud で開いてください。

## References
- [Arduino CLI Documentation](https://arduino.github.io/arduino-cli/latest/)
- [Arduino Language Reference](https://www.arduino.cc/reference/en/)

