#include "consts.h"

int counter = 0;
bool isLedOn = false;

void setup()
{
    setupSerial();
    
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);

    setupConnection();
    setupServer();
}

void loop()
{
    // loopConnection();
    loopServer();

    driveLED();
    delay(LOOP_PERIOD);
}

void setupSerial()
{
    Serial.begin(BAUD_RATE);
    Serial.println();
}

void driveLED()
{
    if (counter >= LED_PERIOD)
    {
        counter = 0;
        if (isLedOn)
            digitalWrite(LED_BUILTIN, LOW);
        else
            digitalWrite(LED_BUILTIN, HIGH);
        isLedOn = !isLedOn;
    }
    else
        counter += LOOP_PERIOD;
}
