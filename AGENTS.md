# AGENTS ガイド

## リポジトリの目的
- `arduino-cli` を用いたスケッチのサンプル集を保守する
- 各スケッチの英語・日本語 README を整備し、利用者が素早く概要と使い方を理解できるようにする
- 実機が無くてもビルドやシミュレーション手順が追えるよう、ドキュメントで補足する

## 標準ディレクトリ構成
```
.
|-- AGENTS.md
|-- README.en.md
|-- README.ja.md
|-- sketches/
|   |-- <sketch-name>/
|   |   |-- <sketch-name>.ino
|   |   |-- README.en.md
|   |   `-- README.ja.md
|   `-- ...
`-- tools/
    `-- (任意の補助スクリプト)
```

- スケッチフォルダ名と `.ino` ファイル名は一致させる
- コード内コメントは英語のみを使用すること
- 追加資料や画像が必要な場合は `docs/` や `assets/` のような下位フォルダをスケッチディレクトリ内に作成する

## スケッチ追加フロー
1. `arduino-cli sketch new sketches/<sketch-name>` で土台を作成
2. 想定ボードを決め、`arduino-cli board list` と `arduino-cli board details <fqbn>` で必要な情報を確認
3. コードを実装しながらコメントは英語で記述
4. `README.en.md` と `README.ja.md` をそれぞれ作成し、概要・必要ハードウェア・ビルド手順・トラブルシューティングを含める
5. `arduino-cli compile --fqbn <fqbn> sketches/<sketch-name>` でビルド確認
6. 実機で検証可能な場合は `arduino-cli upload --port <port> --fqbn <fqbn> sketches/<sketch-name>` を実行し、成功結果とログを README に追記

## README 作成ガイド
- 目次: Overview / Requirements / Build & Upload / Notes / References を共通セクションとする
- 英語版・日本語版の内容は同等に保ち、専門用語は英語をカタカナ化せず原語で記載
- コマンド例はフェンス付きコードブロックで示し、環境依存の値は `<placeholder>` で明示する
- 図版や写真を添付する場合は `assets/` 配下に保存し、Markdown から相対パスで参照する

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
arduino-cli compile --fqbn <fqbn> sketches/<sketch-name>
arduino-cli upload --fqbn <fqbn> --port <port> sketches/<sketch-name>
```
- 失敗したコマンドとログは README の Troubleshooting セクションで共有
- CI でビルドチェックを回す場合は `arduino-cli.yaml` をルートに配置し、対象スケッチを `sketches/**` で指定

## プルリクエストチェックリスト
- [ ] 新規／更新スケッチに対応する README.en.md と README.ja.md がそろっている
- [ ] コード内コメントが英語のみである
- [ ] 少なくとも 1 回 `arduino-cli compile` を実行しログを確認した
- [ ] 追加した依存ライブラリが README に明記されている
- [ ] 既存サンプルのビルドに影響が無いことを確認した

## よく使うボードの FQBN メモ
| Board | FQBN |
| ----- | ----- |
| Arduino Uno R3 | arduino:avr:uno |
| ESP32 Dev Module | esp32:esp32:esp32 |

必要に応じて追加ボードがあればこの表を更新してください。
