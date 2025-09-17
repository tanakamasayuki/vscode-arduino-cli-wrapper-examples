# AGENTS ガイド

## リポジトリの目的
- `arduino-cli` を用いたスケッチのサンプル集を保守する
- 各スケッチの英語・日本語 README を整備し、利用者が素早く概要と使い方を理解できるようにする
- 実機が無くてもビルドやシミュレーション手順が追えるよう、ドキュメントで補足する
- エージェントからの応答は既定で日本語です。必要に応じて英語訳を追加する場合は、利用者のロケールを確認してから提供します。

## 標準ディレクトリ構成
```
.
|-- AGENTS.md
|-- README.en.md
|-- README.ja.md
|-- <category>/
|   |-- README.en.md
|   |-- README.ja.md
|   |-- <sketch-name>/
|   |   |-- README.en.md
|   |   |-- README.ja.md
|   |   |-- sketch.yaml
|   |   |-- <sketch-name>.ino
|   |   `-- <sketch-name>-<platform>/
|   |       |-- README.en.md
|   |       |-- README.ja.md
|   |       |-- sketch.yaml
|   |       `-- <sketch-name>-<platform>.ino
|   `-- ...
`-- tools/
    `-- (任意の補助スクリプト)
```

- `<category>` はスケッチのテーマ名をケバブケースで表記する（例: `communication`, `sensors`）
- ESP32 をターゲットとする標準ケースは `<category>/<sketch-name>/` 配下に配置する
- 追加のプラットフォーム向けバリエーションは `<category>/<sketch-name>/<sketch-name>-<platform>/` の 3 階層構成で管理する（例: `communication/serial-hello-world/serial-hello-world-uno/`）
- `<platform>` にはボード種別をケバブケースで記載し、README に想定 FQBN を明記する
- プラットフォーム別フォルダ名と `.ino` ファイル名には必ずプラットフォーム名を含める（例: `serial-hello-world-uno/serial-hello-world-uno.ino`）
- すべての階層（カテゴリ、スケッチ、プラットフォーム）に `README.en.md` と `README.ja.md` を配置する
- コード内コメントは英語のみを使用すること
- 追加資料や画像が必要な場合は各スケッチ（またはプラットフォーム）ディレクトリ内に `docs/` や `assets/` を作成する

## スケッチ追加フロー
1. 基本スケッチを作成する: `arduino-cli sketch new <category>/<sketch-name>`
2. 追加プラットフォームがある場合は `arduino-cli sketch new <category>/<sketch-name>/<sketch-name>-<platform>` で専用ディレクトリを作成
3. 想定ボードを決め、`arduino-cli board list` と `arduino-cli board details <fqbn>` で必要な情報を確認
4. コードを実装しながらコメントは英語で記述
5. 各階層の `README.en.md` と `README.ja.md` をそれぞれ作成し、概要・必要ハードウェア・ビルド手順・トラブルシューティングを含める
6. `arduino-cli compile --fqbn <fqbn> <category>/<sketch-name>` で標準バージョンをビルド確認し、プラットフォーム別バージョンは `arduino-cli compile --fqbn <fqbn> <category>/<sketch-name>/<sketch-name>-<platform>` で確認
7. 実機で検証可能な場合は `arduino-cli upload --port <port> --fqbn <fqbn> <category>/<sketch-name>`、またはプラットフォーム別パスでアップロードし、成功結果とログを README に追記

## README 作成ガイド
- 目次: Overview / Requirements / Build & Upload / Notes / References を共通セクションとする
- 英語版・日本語版の内容は同等に保ち、専門用語は英語をカタカナ化せず原語で記載
- コマンド例はフェンス付きコードブロックで示し、環境依存の値は `<placeholder>` で明示する
- 図版や写真を添付する場合は該当ディレクトリ配下の `assets/` に保存し、Markdown から相対パスで参照する

## コーディング規約
- 変数名や関数名は `lowerCamelCase`、定数は `UPPER_SNAKE_CASE`
- マジックナンバーは `constexpr` で定義し、意味をコメントで補足 (英語)
- 1 ファイルが 200 行を超える場合はロジックを関数へ分割
- 入出力ピンは冒頭にまとめて宣言し、README に実配線図を載せる

## 推奨する検証手順
```
arduino-cli core update-index
arduino-cli core install <vendor>:<architecture>
arduino-cli lib update-index
arduino-cli compile --fqbn <fqbn> <category>/<sketch-name>
arduino-cli compile --fqbn <fqbn> <category>/<sketch-name>/<sketch-name>-<platform>
arduino-cli upload --fqbn <fqbn> --port <port> <category>/<sketch-name>
arduino-cli upload --fqbn <fqbn> --port <port> <category>/<sketch-name>/<sketch-name>-<platform>
```
- 失敗したコマンドとログは README の Troubleshooting セクションで共有
- CI でビルドチェックを回す場合は `arduino-cli.yaml` をルートに配置し、対象スケッチを `<category>/**` で指定

## プルリクエストチェックリスト
- [ ] 新規／更新スケッチに対応するすべての階層の README.en.md と README.ja.md がそろっている
- [ ] コード内コメントが英語のみである
- [ ] 少なくとも 1 回 `arduino-cli compile` を実行しログを確認した
- [ ] 追加した依存ライブラリが README に明記されている
- [ ] 既存サンプルのビルドに影響が無いことを確認した

## よく使うボードの FQBN メモ
| Board | FQBN | Platform URL|
| ----- | ----- | ----- |
| Arduino Uno R3 | arduino:avr:uno ||
| ESP32 Dev Module | esp32:esp32:esp32 |https://espressif.github.io/arduino-esp32/package_esp32_index.json|
| M5Atom | m5stack:esp32:m5stack_atom |https://m5stack.oss-cn-shenzhen.aliyuncs.com/resource/arduino/package_m5stack_index.json|

必要に応じて追加ボードがあればこの表を更新してください。

## sketch.yamlのフォーマット
```
profiles:
  m5stack_atom:
    fqbn: m5stack:esp32:m5stack_atom
    platforms:
      - platform: m5stack:esp32 (3.2.2)
        platform_index_url: https://m5stack.oss-cn-shenzhen.aliyuncs.com/resource/arduino/package_m5stack_index.json
default_profile: m5stack_atom
```

上記のようなフォーマットでプロファイル名、fqbn、platform関連のパラメータを対象ボードに応じて修正してください。
