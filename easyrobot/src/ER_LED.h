#ifndef LED111
#define LED111
#include "Easyrobot.h"
class ER_LED : public EasyObject
{
    public: // 어디서든 호출 가능
      int pin = 13;
      int state = 0;
      int count = 0;
      int ontime = 0;
      int offtime = 0;
      void Start();
      void Update();
      void On(int newcount,int ontime,int offtime);
    private: // 클래스 내부에서만

    protected: // 자기 클래스 내부 또는 이것을 상속받은 자식 클래스
        
        
};
#endif
