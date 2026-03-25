#include "sourcebackup_embed.h"

void setup()
{
    Serial.begin(115200);
    delay(1000);
    sourcebackup::writeArchiveBase64WithInfoTo(Serial);
}

void loop()
{
}
