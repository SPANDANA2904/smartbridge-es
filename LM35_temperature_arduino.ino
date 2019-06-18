void setup() 
{
  Serial.begin(115200);
}

void loop() 
{
 int temp = analogRead(4)/4;
 Serial.print("Temperature is ");
 Serial.println(temp);
 Serial.println("celsius");
}
