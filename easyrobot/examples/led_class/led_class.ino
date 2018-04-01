#include "Easyrobot.h"
#include "ER_LED.h"
Easyrobot MainProcess;
ER_LED* led2;
void setup() {
    ER_LED* led2 = new ER_LED();
    led2->pin = 12;
    MainProcess.Add(led2);
}

void loop() {
  MainProcess.Update();
}
