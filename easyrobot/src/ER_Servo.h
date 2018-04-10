#ifndef ERSERVO
#define ERSERVO
#include "Easyrobot.h"
#include <Servo.h>
class ER_Servo : public EasyObject
{
    public:
      ER_Servo(int pin);
      void Move(int angle, int time, char endattach);
      void Update();
      void Close();
      int GetAngle();
    private: 
    Servo *myservo;
      int pin = 13;
      char target_attach = 0;
      float now_angle = 0;
      float target_angle = 0;
      float move_speed = 0;
      int timer = 0;
        
};
#endif
