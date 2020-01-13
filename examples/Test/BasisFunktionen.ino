void setup_fkt()
{

}

void idn(){ComInterface.println("FGAletsee 201 Voltage V1.0.0x");}


void setPinmodeX()
{
// first parameter pin number
// second parameter INPUT 0x0 OUTPUT 0x1 INPUT_PULLUP 0x2
unsigned char ch;
unsigned char mode;
ch=(unsigned char)parsedec2int();
mode=(unsigned char)parsedec2int();
pinMode(ch, mode);
}

void setPinX()
{
unsigned char ch;
unsigned char mode;
ch=(unsigned char)parsedec2int();
mode=(unsigned char)parsedec2int();
digitalWrite(ch, mode);
}
char getPinX()
{
unsigned char ch;
ch=(unsigned char)parsedec2int();
ch=digitalRead(ch);
return ch;
}



unsigned int getADCvalue()
{
unsigned char ch;
unsigned int val;
ch=(unsigned char)parsedec2int();
val=analogRead(ch);
return val;
}

int parsedec2int(){
int ch;  
char *arg; 
arg = Fcmd.next(); 
  if (arg != NULL) 
  {
    ch=atoi(arg);   
    return ch;
  }
}

 int parsehex2int(){
int ch;  
char *arg; 
  arg = Fcmd.next(); 
  if (arg != NULL) 
  {
    sscanf(arg, "%x", &ch);
    return ch;
  }
}

float parse2float(){
float res;  
char *arg; 
  arg = Fcmd.next(); 
  if (arg != NULL) 
  {
    res=atof(arg);
    return res;
  }
}


void unrecognized(){ComInterface.println("Error: unkonwn command");}

void readAnalogX()
{
  unsigned int val;
  val=getADCvalue();
  ComInterface.println(val);
}

void getPinValueX()
{
  unsigned char val;
  val=getPinX();
  ComInterface.println(val);
}

