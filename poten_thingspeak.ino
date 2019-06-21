#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>
 
#include <ThingSpeak.h>  
  
const char* ssid = "AndroidAP";  
const char* password = "29041999";  
WiFiClient client;  
unsigned long myChannelNumber = 804394;  
const char * myWriteAPIKey = "O7R9T7CYL8E50EL6";  
int a;

void setup()  
{  
  Serial.begin(115200);  
  pinMode(32,INPUT);   
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
 a = analogRead(32);
 Serial.print("potentiometer value is ");
 Serial.println(a); 
    
   
  // Write to ThingSpeak. There are up to 8 fields in a channel, allowing you to store up to 8 different  
  // pieces of information in a channel. Here, we write to field 1. 
   ThingSpeak.writeField(myChannelNumber, 2, a, myWriteAPIKey);  
    
} 
