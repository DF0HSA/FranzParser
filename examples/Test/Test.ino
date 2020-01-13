
#include <FranzCommand.h>
#define ComInterface Serial

FranzCommand Fcmd;   // The demo SerialCommand object

void setup()
{  
	setup_fkt();
  Serial.begin(115200); 

	Fcmd.addCommand("*idn?",idn);    
	Fcmd.addCommand("basic.pinmode",setPinmodeX);  
	Fcmd.addCommand("basic.setpin",setPinX);  
	Fcmd.addCommand("basic.readanalog",readAnalogX);  
	Fcmd.addCommand("basic.readpin",getPinValueX); 
	Fcmd.addCommand("test.float",testFloat);  	
	Fcmd.addDefaultHandler(unrecognized);  
  Serial.println("Ready"); 

}

void loop()
{  
char c=Serial.read(); 
  Fcmd.readSerial(&c);     // We don't do much, just process serial commands
}

void testFloat()
{
Serial.println(Fcmd.countArgs(),DEC);
  float test;
  test=parse2float();
  Serial.println(test,10);
  
}