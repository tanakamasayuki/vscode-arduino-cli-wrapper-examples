#include "sourcebackup_embed.h"

namespace
{
    constexpr int kBackupTriggerPin = 33; // External trigger input for Source Backup output

    bool shouldPrintBackup()
    {
        delay(1000);
        pinMode(kBackupTriggerPin, INPUT_PULLUP);
        delay(10);
        return digitalRead(kBackupTriggerPin) == LOW;
    }
} // namespace

void setup()
{
    Serial.begin(115200);

    if (shouldPrintBackup())
    {
        sourcebackup::writeArchiveBase64WithInfoTo(Serial);
        return;
    }

    Serial.printf("Source Backup skipped. Hold GPIO%d LOW during boot to print.\n", kBackupTriggerPin);
    sourcebackup::printRestoreUrl(Serial);
    Serial.println();
}

void loop()
{
}
