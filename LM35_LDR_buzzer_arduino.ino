void setup() 
{
  Serial.begin(115200);
  pinMode(4,OUTPUT);
}

void loop() 
{
 int temp = analogRead(2)/4;
 Serial.print("Temperature is ");
 Serial.println(temp);
 Serial.println("celsius");
 if(temp > 50)
 digitalWrite(4,HIGH);
}
