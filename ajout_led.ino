// ajout_led.ino
// Reception RF 433MHz
// Boyer Alexis
// 13.01.21
// Version 1.1 LA LED

#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile
 
RH_ASK driver;


const int LED_PIN = 3; // Pin LED
const int LEDV_PIN = 4 // LED Verte
int ledState = LOW;


void setup()
{
//    Check install
    Serial.begin(9600); // Debugging only
    if (!driver.init())
         Serial.println("init failed");
    pinMode(LED_PIN, OUTPUT); // Pin sortie pour le led
    pinMode(LEDV_PIN, OUTPUT); // Pin sortie pour le led
}
 
void loop()
{
    uint8_t buf[50];
    uint8_t buflen = sizeof(buf);
    digitalWrite(LED_PIN,ledState);
    ledState = !ledState;
    if (driver.recv(buf, &buflen)) // Non-blocking
    {
      int i;
      // Message with a good checksum received, dump it.
      Serial.print("Message: ");
      Serial.println((char*)buf);
      // Activer la led
      ledState = !ledState;

      // controller la led
      digitalWrite(LEDV_PIN, ledState);
    }
}
