# Arduino CLI Wrapper Samples

[English version](README.md)

## Overview
本リポジトリは VS Code 拡張機能「Arduino CLI Wrapper」で利用するサンプル集です。各カテゴリでは、アセット埋め込みやファイルシステム経由の読み込みなど、Arduino CLI を使ったビルド・アップロード手順を日英併記で解説しています。

## Requirements
- PATH に設定された Arduino CLI 0.35 以上
- VS Code と Arduino CLI Wrapper 拡張機能
- 各スケッチ README に記載された対応ボードと USB データケーブル
- 初回セットアップ時にボードコアやライブラリを取得するためのネットワーク接続

## Build & Upload
```
arduino-cli core update-index
arduino-cli core install <vendor>:<architecture>
arduino-cli lib update-index
arduino-cli compile --profile <profile-name> <category>/<sketch>
arduino-cli upload --profile <profile-name> --port <port> <category>/<sketch>
```
`<profile-name>` には該当スケッチの `sketch.yaml` に定義されたプロファイル名を指定します。プロファイルには必要なコアやパッケージインデックス URL、`M5Unified`・`M5GFX` などのライブラリが含まれています。特記がない限り、シリアルモニタは 115200 baud で開いてください。

## Categories
- [`01_getting-started`](01_getting-started/README.ja.md): シリアル出力の入門スケッチとマルチボード構成例。
- [`02_storage`](02_storage/README.ja.md): 画像アセットの埋め込み、スプライト化、SPIFFS・LittleFS・microSD からの読み込み手法。

## Notes
- `assets/` 配下のファイルを編集したら **Arduino CLI Wrapper: Embed Assets** を実行（またはコンパイル）して `assets_embed.h` を再生成します。
- ファイルシステムを利用するサンプルでは `data/` や `copy_to_sd/` 内のアセットを事前に書き込み／コピーしてください。
- ボード固有の配線やアップロード手順、トラブルシューティングは各スケッチの README を参照してください。

## References
- [Arduino CLI Documentation](https://arduino.github.io/arduino-cli/latest/)
- [Arduino Language Reference](https://www.arduino.cc/reference/en/)
- [M5Unified](https://github.com/m5stack/M5Unified)
- [M5GFX](https://github.com/m5stack/M5GFX)
