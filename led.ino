
/*************************************************************************/
const int redPin = 11;  // R petal on RGB LED module connected to digital pin 11 
const int greenPin = 10;  // G petal on RGB LED module connected to digital pin 10 
const int bluePin = 9;  // B petal on RGB LED module connected to digital pin 9
const int onFor = 50;
const String pubkey = String("1010000101111000111100110000100110010001000111101101111000110000010010011000011111111000000100010000101011100010110001010100000101000100011110011110110011001011");


/**************************************************************************/

void turn(unsigned char r, unsigned char g, unsigned char b)
{
    color(255, 0, 0); // turn the RGB LED red 
    delay(onFor); // delay for 1 second  
  
    color(r,g,b); // turn the RGB LED green  
    delay(onFor); // delay for 1 second  
    
}
void setup()
{ 
  pinMode(redPin, OUTPUT); // sets the redPin to be an output 
  pinMode(greenPin, OUTPUT); // sets the greenPin to be an output 
  pinMode(bluePin, OUTPUT); // sets the bluePin to be an output
  color (255,0,0);
  delay (1000);
  for(int i = 0; i < 160; i++)
  {
   if (pubkey[i]=='0') turn(0,0,255);
   else turn(0,255,0);
  }

}    
/***************************************************************************/
void loop()  // run over and over again  
{    
  // Basic colors:

//char sequence = "YRGBWY"

  

}     
/******************************************************/
void color (unsigned char red, unsigned char green, unsigned char blue)// the color generating function  
{    
  analogWrite(redPin, red);   
  analogWrite(greenPin, green); 
  analogWrite(bluePin, blue); 
}
/******************************************************/


