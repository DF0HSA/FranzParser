void setup_fkt()
{

}

void idn(){server.print("FGAletsee 2014 SIGGEN V1.0.0x\n");}
void info(){server.print("FGAletsee 2014 SIGGEN V1.0.0x,,*idn? Infos about Device,basic.readanalog <int> Read analog channel,source.frequency <float> Sets Frequency to DDS\n");}

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
float ret;  
char *arg; 
  arg = Fcmd.next(); 
  if (arg != NULL) 
  {
    sscanf(arg, "%f", &ret);
    return ret;
  }
}

 double parse2double(){
double ret;  
char *arg; 
  arg = Fcmd.next(); 
  if (arg != NULL) 
  {
    sscanf(arg, "%d", &ret);
    return ret;
  }
}