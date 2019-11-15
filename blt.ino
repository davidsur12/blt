#include <SoftwareSerial.h>
SoftwareSerial BT(4,2); // RX, TX recorder que se cruzan

void setup()
   {
       Serial.begin(9600);
       Serial.println("Enter AT commands:");
       BT.begin(9600);
   }
   
void loop()
   {

    if(BT.available())    // Si llega un dato por el puerto BT se envía al monitor serial
  {
    Serial.write(BT.read());
  }
 
  if(Serial.available())  // Si llega un dato por el monitor serial se envía al puerto BT
  {
     BT.write(Serial.read());
  }
       
}
