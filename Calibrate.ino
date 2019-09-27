#include <Wire.h>
#include <SparkFun_APDS9960.h>
#include <Vector.h> 


SparkFun_APDS9960 apds = SparkFun_APDS9960();

uint16_t ambient_light = 0;
uint16_t red_light = 0;
uint16_t green_light = 0;
uint16_t blue_light = 0;
Vector<int> colors;
bool started = false; 

#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip(12, 16, NEO_GRB + NEO_KHZ800); 

void setup() {

  // Initialize Serial port
  Serial.begin(9600);
  apds.init();
  apds.enableLightSensor(false);
  
  // Wait for initialization and calibration to finish
  delay(500);
  
  // Initiate strip
  strip.begin();
}

int countval(int val)
{
  int count = 0; 
  for(int i = 0; i < colors.size(); i++)
    if(colors[i] == val)
      count++; 

     return count; 
}
void loop() {
  
  // Read the light levels (ambient, red, green, blue)
  if (  !apds.readAmbientLight(ambient_light) ||
        !apds.readRedLight(red_light) ||
        !apds.readGreenLight(green_light) ||
        !apds.readBlueLight(blue_light) ) {
    Serial.println("Error reading light values");
  } else {
 //   Serial.print("Ambient: ");
 //   Serial.print(ambient_light);

 if(started == false)
 {
   if(colors[colors.size() - 1] != red_light)
      colors.push_back(red_light); 

   if(countval(red_light) >= 5)
   {
      Serial.print(" Repeat: ");
      Serial.println(red_light);
      started = true; 
   }
 }
 
    Serial.print(" Red: ");
    Serial.print(red_light);
    Serial.print(" Green: ");
    Serial.println(green_light);
 //   Serial.print(" Blue: ");
 //   Serial.println(blue_light);

  for(uint16_t j = 0; j <= 12; j++)
  {
    strip.setPixelColor(j, red_light/10, green_light/10, blue_light/10);
    strip.show();
  }
  }
  
  // Wait 1 second before next reading
  delay(50);
}
