/*
 * Project: This code demostrates how to read data from an analog soil moisture sensor 
 * and then converts this as a value from 0 to 100%
 * Author: CDM /  chris@layadcircuits.com for Layad Circuits Electronics Engineering
 * Revision: v.1.0 / 20 Sept 2016
 * Notes: The analog output pin of the soil moisture sensor connects to pin A0 of the Arduino
 *        If using a relay module, connect the IN pin to Arduino pin 13
 *        Both Vcc's connect to 5V pin of the Arduino
 *        Both Gnd's connect to the Gnd pin of the Arduino
 */


unsigned int accumulator;
byte moistureLevel;
const byte relayPin = 13;

void setup() {
  pinMode(relayPin,OUTPUT);
  digitalWrite(relayPin,HIGH); // turn off relay on power up
  Serial.begin(9600);
}

void loop() { 
  accumulator = 0;
  for(byte i=0;i<10;i++)
  {
      accumulator += analogRead(A0);
  }
  accumulator /= 10;
  moistureLevel = map(accumulator,0,1023,0,100);
  Serial.print("Moisture Level = ");
  Serial.print(moistureLevel);
  Serial.println("%");
  delay(1000); // avoid this in the final code

  /* Enable this section if you need to turn on a relay after a certain threshold is reached

     byte counter;

     if(moistureLevel < 20)
     {
        if(digitalRead(relayPin) == HIGH)
        {
          counter++;
          if(counter > 3) //if moisture remains low for 3sec,then turn on relay
          {
            digitalWrite(relayPin,LOW);
          }
        }
     }
     else
     {
        digitalWrite(relayPin,HIGH);
        counter=0;
        
     }
   */
}

