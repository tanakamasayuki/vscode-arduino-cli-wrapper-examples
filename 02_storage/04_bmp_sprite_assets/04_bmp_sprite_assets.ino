#include <M5Unified.h>
#include "assets_embed.h"

M5Canvas sprite(&M5.Lcd);

void setup()
{
    // 初期化
    auto cfg = M5.config();
    cfg.serial_baudrate = 115200;
    M5.begin(cfg);
    delay(500);

    // spriteを作成、画像データからサイズを自動取得して作成
    sprite.createFromBmp(assets_1_bmp, assets_1_bmp_len);
}

void loop()
{
    // ランダムな位置に描画
    int x = random(-M5.Lcd.width() * 3 / 4, M5.Lcd.width() * 3 / 4);
    int y = random(-M5.Lcd.height() * 3 / 4, M5.Lcd.height() * 3 / 4);
    Serial.printf("x=%d, y=%d\n", x, y);

    // スプライトを画面に転送、マゼンタ色を透過する
    sprite.pushSprite(x, y, TFT_MAGENTA);

    // ウエイト、この値を1にすると処理の最高速がわかる
    delay(100);
}
