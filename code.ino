#include <Adafruit_NeoPixel.h>
#ifdef _AVR_
 #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 16

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 20 // Time (in milliseconds) to pause between pixels

//button start
const int leftbuttonPin = 7;
const int rightbuttonPin = 8;

//const int leftledPin =  2;
//const int rightledPin =  4;

int leftbuttonState = 1;
int rightbuttonState = 1;

//button end

void setup() 
{
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  //button start
  
  //pinMode(leftledPin, OUTPUT);
  //pinMode(rightledPin, OUTPUT);
  pinMode(leftbuttonPin, INPUT_PULLUP);
  pinMode(rightbuttonPin, INPUT_PULLUP);

  //button end
}

void loop() 
{
  leftbuttonState = digitalRead(leftbuttonPin);
  rightbuttonState = digitalRead(rightbuttonPin);
  pixels.clear();
  if (leftbuttonState == 0) 
  {
    // turn left LED on:
    //digitalWrite(leftledPin, HIGH);
      for(int i=0; i<6; i++) 
  {
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  } 
  else if (leftbuttonState == 1) 
  {
    // turn left LED on:
    //digitalWrite(leftledPin, HIGH);
      for(int i=0; i<6; i++) 
  {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  } 
  if (rightbuttonState == 0) 
  {
    // turn left LED on:
    //digitalWrite(rightledPin, HIGH);
      for(int i=6; i<12; i++) 
  {
    pixels.setPixelColor(i, pixels.Color(0, 150, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  } 
    else if (rightbuttonState == 1) 
  {
    // turn left LED on:
    //digitalWrite(rightledPin, HIGH);
      for(int i=6; i<12; i++) 
  {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  } 
  else 
  {
    // turn all LED's off:
    //digitalWrite(leftledPin, LOW);
    //digitalWrite(rightledPin, LOW);
    pixels.clear();
  }
}
