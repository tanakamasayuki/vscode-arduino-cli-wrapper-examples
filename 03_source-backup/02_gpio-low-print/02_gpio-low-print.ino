#include "sourcebackup_embed.h"

constexpr int kBackupTriggerPin = 33; // External trigger input for Source Backup output

void setup()
{
    Serial.begin(115200);
    delay(1000);

    pinMode(kBackupTriggerPin, INPUT_PULLUP);
    delay(10);
    if (digitalRead(kBackupTriggerPin) == LOW)
    {
        sourcebackup::writeArchiveBase64WithInfoTo(Serial);
    }
    else
    {
        Serial.printf("Source Backup skipped. Hold GPIO%d LOW during boot to print.\n", kBackupTriggerPin);
        sourcebackup::printRestoreUrl(Serial);
        Serial.println();
    }
}

void loop()
{
}
