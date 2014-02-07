// Bluetooth temperature sensor
#include "DHT.h"

// Pin for the DHT sensor
#define DHTPIN 7    
#define DHTTYPE DHT22
// #define DHTTYPE DHT11

// Create instance for the DHT sensor
DHT dht(DHTPIN, DHTTYPE);

// Setup
void setup(void)
{
  dht.begin();
  Serial.begin(115200);
}

void loop(void)
{
  
    // Get command
    if (Serial.available()) {
  
      // Read command
      byte c = Serial.read ();
      
      // If a measurement is required, measure data and send it back
      if (c == 'm'){
        
          float h = dht.readHumidity();
          float t = dht.readTemperature();
          
          // Send data (temperature,humidity)
          Serial.print(t);
          Serial.print(",");
          Serial.println(h);
                        
      }
   
  }
}
