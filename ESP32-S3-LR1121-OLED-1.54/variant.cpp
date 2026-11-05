#include "variant.h"
#include "Arduino.h"

void InitVariant()
{
    pinMode(PA_CTRL, OUTPUT);
    digitalWrite(PA_CTRL, HIGH);
}
