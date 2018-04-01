


#include "LED.h"
void ER_LED :: Start()
{
    pinMode(pin,OUTPUT);
}
void ER_LED :: Update()
{
    if (count > 0)
    {
        if (state == 0)
        {
           update_delay = ontime;
           state = 1;
        }
        else
        {
           update_delay = offtime;
            state = 0;
            count--;
        }
        digitalWrite(pin,state);
    }
}
void ER_LED :: On(int newcount,int ontime,int offtime)
{
    count = newcount;
    this->ontime = ontime;
    this->offtime = offtime;
}

