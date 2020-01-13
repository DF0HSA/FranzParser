#include <SPI.h>
#include <Ethernet.h>
#include <FranzCommand.h>

#define LCD_support 1

#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
  LiquidCrystal_I2C	lcd(0x27,2,1,0,4,5,6,7);


FranzCommand Fcmd;   
byte mac[] = { 0xFA, 0x21, 0x06, 0x88, 0x00, 0x01 };  
EthernetServer server = EthernetServer(5023);

void setup()
{
  setup_fkt();
  Serial.begin(115200); 
  while (!Serial) {;}
	lcd.begin (16,2); 
	lcd.setBacklightPin(3,POSITIVE);
	lcd.home (); 
	lcd.print("SigGen V1.0"); 
	lcd.setCursor (0,1);  
	lcd.print("FGAletsee"); 
	lcd.setBacklight(HIGH);
  Ethernet.begin(mac);
  server.begin();
  Serial.print("server is at ");
  
  Serial.println(Ethernet.localIP());
  lcd.setCursor (0,1);  
  lcd.print(Ethernet.localIP());
  

	Fcmd.addCommand("*idn?",idn);     
	Fcmd.addCommand("info",info);   
  	Fcmd.addCommand("basic.pinmode",setPinmodeX);  
	Fcmd.addCommand("basic.setpin",setPinX);  
	Fcmd.addCommand("basic.readanalog",readAnalogX);  
	Fcmd.addCommand("basic.readpin",getPinValueX);  
	Fcmd.addDefaultHandler(unrecognized);  

}

void loop() {
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
	lcd.home (); 
	lcd.print("Connected     ");
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
		Serial.print(c);
       Fcmd.readSerial(&c);  
      }
    }
    delay(1);
    client.stop();
    Serial.println("client disconnected");
	lcd.home (); 
	lcd.print("SigGen V1.0     "); 
  }
}

void unrecognized(){server.println("Error: unkonwn command");}

void readAnalogX()
{
  unsigned int val;
  val=getADCvalue();
  server.println(val);
}

void getPinValueX()
{
  unsigned char val;
  val=getPinX();
  server.println(val);
}

