#include "Easyrobot.h"
#include "LED.h"
Easyrobot MainProcess;
LED* led2;
void setup() {
    LED* led2 = new LED();
    led2->pin = 12;
    MainProcess.Add(led2);


    
}

void loop() {
  MainProcess.Update();
}
