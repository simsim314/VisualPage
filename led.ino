//RGB LED
//The RGB LED will appear red, green, and blue first, then red, orange, yellow, green, blue, indigo, and purple.
//Email:info@primerobotics.in
//Website:www.primerobotics.in
//2015.5.7
/*************************************************************************/
const int redPin = 11;  // R petal on RGB LED module connected to digital pin 11 
const int greenPin = 10;  // G petal on RGB LED module connected to digital pin 10 
const int bluePin = 9;  // B petal on RGB LED module connected to digital pin 9
const int onFor = 100;

/**************************************************************************/
void setup()
{ 
  pinMode(redPin, OUTPUT); // sets the redPin to be an output 
  pinMode(greenPin, OUTPUT); // sets the greenPin to be an output 
  pinMode(bluePin, OUTPUT); // sets the bluePin to be an output
}    
/***************************************************************************/
void loop()  // run over and over again  
{    
  // Basic colors:

//char sequence = "YRGBWY"

  
  color(255, 0, 0); // turn the RGB LED red 
  delay(onFor); // delay for 1 second  
  color(0,255, 0); // turn the RGB LED green  
  delay(onFor); // delay for 1 second  
  color(0, 0, 255); // turn the RGB LED blue  
  delay(onFor); // delay for 1 second 
  color(255, 255, 255); // turn the RGB LED blue  
  delay(onFor); // delay for 1 second 

}     
/******************************************************/
void color (unsigned char red, unsigned char green, unsigned char blue)// the color generating function  
{    
  analogWrite(redPin, red);   
  analogWrite(greenPin, green); 
  analogWrite(bluePin, blue); 
}
/******************************************************/
