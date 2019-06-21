#include <DHT.h>
#include <DHT_U.h>

#include<ETH.h>
#include <WiFi.h>
#include<WiFiAP.h>
#include <WiFiClient.h>
#include <WiFiGeneric.h>
#include <WiFiMulti.h>
#include <WiFiScan.h>
#include <WiFiServer.h>
#include <WiFiSTA.h>
#include <WiFiType.h>
#include <WiFiUdp.h>
 
#include <ThingSpeak.h>  
#include <Adafruit_Sensor.h>


#define DHTPIN 2
#define DHTTYPE    DHT11
DHT dht(DHTPIN, DHTTYPE);

String readDHTTemperature() {
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  //float t = dht.readTemperature(true);
  // Check if any reads failed and exit early (to try again).
  
}

String readDHTHumidity() {
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  
}

const char* ssid = "AndroidAP";  
const char* password = "29041999";  
WiFiClient client;  
unsigned long myChannelNumber = 804394;  
const char * myWriteAPIKey = "O7R9T7CYL8E50EL6";  

void setup()  
{  
  Serial.begin(115200);  
  dht.begin();  
  delay(10);  
  // Connect to WiFi network  
  Serial.println();  
  Serial.println();  
  Serial.print("Connecting to ");  
  Serial.println(ssid);  
  WiFi.begin(ssid, password);  
  while (WiFi.status() != WL_CONNECTED)  
  {  
   delay(500);  
   Serial.print(".");  
  }  
  Serial.println("");  
  Serial.println("WiFi connected");  
  // Print the IP address  
  Serial.println(WiFi.localIP());  
  ThingSpeak.begin(client);  
}  
void loop()   
{  
  static boolean data_state = false;  
 float t = dht.readTemperature();
  Serial.print("Temperature:");
  Serial.println(t);
  delay(500);
  float h = dht.readHumidity();
  Serial.print("Humidity:");
  Serial.println(h);
  delay(500);  
   ThingSpeak.writeField(myChannelNumber, 1, t, myWriteAPIKey);    
   ThingSpeak.writeField(myChannelNumber, 2, h, myWriteAPIKey);   
}
