#include <LittleFS.h>
#include <M5Unified.h>

void setup()
{
    // 初期化
    auto cfg = M5.config();
    cfg.serial_baudrate = 115200;
    M5.begin(cfg);
    delay(500);

    // LittleFSの初期化。Upload Dataで事前で転送が必要
    if (!LittleFS.begin())
    {
        Serial.println("LittleFS Mount Failed");
        Serial.println("Run Upload Data!");
    }
}

void loop()
{
    // ランダムな位置に描画
    int x = random(-M5.Lcd.width() * 3 / 4, M5.Lcd.width() * 3 / 4);
    int y = random(-M5.Lcd.height() * 3 / 4, M5.Lcd.height() * 3 / 4);
    Serial.printf("x=%d, y=%d\n", x, y);

    // PNGを画面に描画、PNGで指定した透明部分は自動で透過する
    M5.Lcd.drawPngFile(LittleFS, "/1.png", x, y);

    // ウエイト、この値を1にすると処理の最高速がわかる
    delay(100);
}
