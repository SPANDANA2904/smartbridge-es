#include <deprecated.h>
#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <require_cpp11.h>

#include <deprecated.h>
#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <require_cpp11.h>

#include <SPI.h>
#include <MFRC522.h>

constexpr uint8_t RST_PIN = 5;     // Configurable, see typical pin layout above
constexpr uint8_t SS_PIN = 4;     // Configurable, see typical pin layout above
 
MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class

MFRC522::MIFARE_Key key; 

// Init array that will store new NUID 
byte nuidPICC[4];
int a[] = {120,120,225,59};     //data of the pre saved card
int b[] = {219,105,206,54};
int c[] = {235,29,97,53};
int allow1=1000;
int allow2=1000;
int allow3=40;
char d;
int allowance;
int qu;

void setup() { 
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522 

  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;
  }

  Serial.println(F("This code scan the MIFARE Classsic NUID."));
  Serial.print(F("Using the following key:"));
  printHex(key.keyByte, MFRC522::MF_KEY_SIZE);
}
 
void loop() {

  // Look for new cards
  if ( ! rfid.PICC_IsNewCardPresent())
    return;

  // Verify if the NUID has been readed
  if ( ! rfid.PICC_ReadCardSerial())
    return;

  Serial.print(F("PICC type: "));
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  Serial.println(rfid.PICC_GetTypeName(piccType));

  // Check is the PICC of Classic MIFARE type
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&  
    piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
    piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Your tag is not of type MIFARE Classic."));
    return;
  }

  if (rfid.uid.uidByte[0] == a[0] &&
    rfid.uid.uidByte[1] == a[1] &&
    rfid.uid.uidByte[2] == a[2] &&
    rfid.uid.uidByte[3] == a[3] ) 
    {
    Serial.println(F("ACCESS GRANTED."));
    allowance=allow1;
    calculate();
    }
    else if (rfid.uid.uidByte[0] == b[0] &&
    rfid.uid.uidByte[1] == b[1] &&
    rfid.uid.uidByte[2] == b[2] &&
    rfid.uid.uidByte[3] == b[3] ) 
    {
    Serial.println(F("ACCESS GRANTED."));
    allowance=allow2;
    calculate();
    }
    else if (rfid.uid.uidByte[0] == c[0] &&
    rfid.uid.uidByte[1] == c[1] &&
    rfid.uid.uidByte[2] == c[2] &&
    rfid.uid.uidByte[3] == c[3] ) 
    {
    Serial.println(F("ACCESS GRANTED."));
    allowance=allow3;
    calculate();
    }
    else Serial.println(F("ACCESS DENIED"));
  
  

  // Halt PICC
  rfid.PICC_HaltA();

  // Stop encryption on PCD
  rfid.PCD_StopCrypto1();
}


/**
 * Helper routine to dump a byte array as hex values to Serial. 
 */
void printHex(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}

/**
 * Helper routine to dump a byte array as dec values to Serial.
 */
void printDec(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], DEC);
  }
}


void calculate()
{
  if(Serial.available()>0)
  {
Serial.println("The Menu Available is:");
Serial.println(" 1:PURI    Rs:35 ");
Serial.println(" 2:IDLI    Rs:30 ");
Serial.println(" 3:DOSA    Rs:45 ");
Serial.println(" 4:VADA    Rs:25 ");
Serial.println(" 5:JUICE   Rs:20 ");
Serial.println(" Enter Your Order ");
d=Serial.read();
if(d=='1')
{
  Serial.println("ITEM CHOSEN IS PURI");
}
else if(d=='2')
{
  Serial.println("ITEM CHOSEN IS IDLI");
}
else if(d=='3')
{
  Serial.println("ITEM CHOSEN IS DOSA");
}
else if(d=='4')
{
  Serial.println("ITEM CHOSEN IS VADA");
}
else if(d=='5')
{
  Serial.println("ITEM CHOSEN IS JUICE"); 
}
else
{
  Serial.println("INVALID INPUT");
}

Serial.println("Enter the quantity ");
qu=Serial.read();

if(d=='1')
{
  Serial.print("Quantity chosen is:");
  Serial.println(qu);
  allowance=allowance-35*qu;
}
else if(d=='2')
{
  Serial.println("Quantity chosen is:");
  Serial.println(qu);
  allowance=allowance-30*qu;
}
else if(d=='3')
{
  Serial.println("Quantity chosen is:");
  Serial.println(qu);
  allowance=allowance-45*qu;
}
else if(d=='4')
{
  Serial.println("Quantity chosen is:");
  Serial.println(qu);
  allowance=allowance-25*qu;
}
else if(d=='5')
{
  Serial.println("Quantity chosen is:");
  Serial.println(qu);
  
  allowance=allowance-20*qu;  
}
else
{
  Serial.println("INVALID INPUT");
}
if(allowance>0)
{
Serial.println("Your balance allowance is:");
Serial.println(allowance);
}
else
{
  Serial.println("Your balance is low");
  digitalWrite(2,HIGH);
  delay(2000);
  digitalWrite(2,LOW);
}
}
}
