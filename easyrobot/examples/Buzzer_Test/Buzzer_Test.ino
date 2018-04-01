#include "buzzer.h"

const int BUZZER_PIN = 4; 
const int LED_PIN = 3; 
const int DIGITAL_14_PIN = 14; 
const int DIGITAL_15_PIN = 15;
Buzzer buzzer = Buzzer(BUZZER_PIN); 


void setup() {  
    Serial.begin(9600);         // for debug
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    buzzer.buzzBlocking(100); 
}

void loop() {
   
    buzzer.doUpdate();
    delay(1);
    
    if (digitalRead(DIGITAL_14_PIN))
    {        
        if(millis() % 400 > 200) 
            buzzer.buzz(200); 
        else 
            buzzer.buzz(0);
        digitalWrite(LED_PIN, millis() % 500 > 450);
    }
    else if (digitalRead(DIGITAL_15_PIN))
    {
        if(millis() % 400 > 200) 
            buzzer.buzz(200); 
        else 
            buzzer.buzz(0);
        digitalWrite(LED_PIN, millis() % 200 > 100);
    }
    else
    {
        digitalWrite(LED_PIN, millis() % 500 > 50);
    }
}
 
