void setup() 
{
  Serial.begin(115200);
}

void loop() 
{
 int potentiometerValue = analogRead(2)/4;
 Serial.print("potentiometer value is ");
 Serial.println(potentiometerValue);
 Serial.println("volts");
}
