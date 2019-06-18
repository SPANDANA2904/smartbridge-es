void setup() 
{
  Serial.begin(115200);
}

void loop() 
{
 int LDRvalue = analogRead(4)/4;
 Serial.print("LDR value is ");
 Serial.println(LDRvalue);
 Serial.println("ohms");
}
