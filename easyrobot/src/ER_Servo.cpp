#include "ER_Servo.h"
ER_Servo :: ER_Servo(int pin)
{
    this->pin = pin;
    myservo = new Servo();
   // pinMode(pin,OUTPUT);
}
void ER_Servo :: Move(int angle, int timer, char endattach)
{
    this->timer = timer;
    this->target_angle = angle;
     this->target_attach = endattach;
     myservo->attach(pin);
     move_speed = (target_angle - now_angle) / timer;
}

void ER_Servo :: Update()
{
    if (timer > 0)
    {
        now_angle += move_speed;
        myservo->write((int)now_angle);
        timer -= 1;
        if (timer == 0)
        {
            if (target_attach == 1) myservo->attach(pin);
            else myservo->detach();
        }
    }
}

void ER_Servo :: Close()
{
    delete(myservo);
}
int ER_Servo :: GetAngle()
{
    return now_angle;
}


