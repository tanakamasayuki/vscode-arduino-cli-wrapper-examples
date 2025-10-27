#include <M5Unified.h>
#include "assets_embed.h"

const uint8_t *png_list[] = {assets_1_png, assets_2_png, assets_3_png, assets_4_png};
const size_t png_len_list[] = {assets_1_png_len, assets_2_png_len, assets_3_png_len, assets_4_png_len};

void setup()
{
    // 初期化
    auto cfg = M5.config();
    cfg.serial_baudrate = 115200;
    M5.begin(cfg);
    delay(500);
}

void loop()
{
    // ランダムな位置に描画、画像もランダムに選択
    int x = random(-M5.Lcd.width() * 3 / 4, M5.Lcd.width() * 3 / 4);
    int y = random(-M5.Lcd.height() * 3 / 4, M5.Lcd.height() * 3 / 4);
    int index = random(0, sizeof(png_list) / sizeof(png_list[0]));
    Serial.printf("index=%d, x=%d, y=%d\n", index, x, y);

    // PNGを画面に描画、PNGで指定した透明部分は自動で透過する
    M5.Lcd.drawPng(png_list[index], png_len_list[index], x, y);

    // ウエイト、この値を1にすると処理の最高速がわかる
    delay(100);
}
