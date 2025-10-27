# Multiple Embedded Assets

## Overview
4 つの PNG ファイルをプログラムメモリへ埋め込み、毎フレームランダムに選んで描画するサンプルです。Arduino CLI Wrapper が複数アセットをまとめたヘッダーを生成し、フラッシュ上のスプライトを高速に切り替えられる点を確認できます。

## Requirements
- Arduino CLI 0.35 以上
- M5Stack Core (Basic) または M5Stack AtomS3
- ESP32 Arduino Core `esp32:esp32` (3.3.2)
- ライブラリ `M5Unified` 0.2.10 と `M5GFX` 0.2.16

## Build & Upload
```
arduino-cli compile --profile m5stack_core 02_storage/02_multi_assets
arduino-cli upload --profile m5stack_core --port <port> 02_storage/02_multi_assets
```
AtomS3 で動かす場合は `--profile m5stack_atoms3` を指定してください。

## Notes
- 自動生成された `assets_embed.h` には PNG ごとのポインタとサイズが配列で公開されます。`assets/` を更新したら **Arduino CLI Wrapper: Embed Assets** によりヘッダーを再生成します（コンパイル時にも自動再生成されます）。
- ランダムに選択したインデックスと座標をシリアルモニタ (115200 baud) へ出力するため、描画内容の確認が容易です。
- 再現性のあるテストを行いたい場合は `setup()` で `randomSeed()` を設定してください。

## References
- [M5Unified Library](https://github.com/m5stack/M5Unified)
- [M5GFX Library](https://github.com/m5stack/M5GFX)
- [Arduino CLI Documentation](https://arduino.github.io/arduino-cli/latest/)
