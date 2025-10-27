#include <M5Unified.h>
#include "assets_embed.h"

M5Canvas sprite(&M5.Lcd);

// スプライトのサイズ
const uint8_t sprite_width = 100;
const uint8_t sprite_height = 100;

void setup()
{
    // 初期化
    auto cfg = M5.config();
    cfg.serial_baudrate = 115200;
    M5.begin(cfg);
    delay(500);

    // spriteを作成、サイズは事前に定義したものを使用
    sprite.createSprite(sprite_width, sprite_height);

    // スプライトを透明色で塗りつぶす
    sprite.fillScreen(TFT_TRANSPARENT);

    // スプライトにPNGを描画、PNGで指定した透明部分は自動で透過する(事前に塗りつぶした透明色が残る)
    sprite.drawPng(assets_1_png, assets_1_png_len, 0, 0);
}

void loop()
{
    // ランダムな位置に描画
    int x = random(-M5.Lcd.width() * 3 / 4, M5.Lcd.width() * 3 / 4);
    int y = random(-M5.Lcd.height() * 3 / 4, M5.Lcd.height() * 3 / 4);
    Serial.printf("x=%d, y=%d\n", x, y);

    // スプライトを画面に描画、透明色を透過する
    sprite.pushSprite(x, y, TFT_TRANSPARENT);

    // ウエイト、この値を1にすると処理の最高速がわかる
    delay(100);
}
