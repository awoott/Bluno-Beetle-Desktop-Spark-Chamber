/*
Desktop Spark Chamber based on DFRobot Bluno Beetle.
Using an 8x8 addressable LED grid and Adafruit Neopixel library.
Runs 16 sequences of 'sparks' at random time intervals.
*/

#include <Adafruit_NeoPixel.h>

// Define the number of LEDs and the pin connected to the data line
#define NUM_LEDS 64
#define DATA_PIN 5

int ledSwitchDelay = 0;  // Delay between each individual LED switching on in milliseconds
int maxBrightness = 250;  // Maximum brightness for LEDs

// Create a NeoPixel object
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, DATA_PIN, NEO_GRB + NEO_KHZ800);

// Define the specific combinations of LEDs for each sequence
const int sequence0[] = {56, 54, 53, 43, 44, 34, 33, 31};
const int sequence1[] = {55, 54, 53, 52, 51, 50, 49, 48};
const int sequence2[] = {24, 25, 26, 36, 35, 34, 46, 47};
const int sequence3[] = {23, 25, 37, 43, 51, 61};
const int sequence4[] = {8, 9, 10, 11, 19, 18, 17, 16};
const int sequence5[] = {56, 41, 26, 4};
const int sequence6[] = {23, 22, 10, 11, 12, 13, 1, 0};
const int sequence7[] = {56, 54, 42, 36, 28, 18, 14, 0};
const int sequence8[] = {23, 22, 26, 27, 35, 34, 46, 47};
const int sequence9[] = {23, 22, 21, 20, 19, 18, 17, 16};
const int sequence10[] = {55, 54, 53, 52, 44, 45, 46, 47};
const int sequence11[] = {8, 9, 10, 11, 12, 13, 14, 15};
const int sequence12[] = {39, 22, 5};
const int sequence13[] = {7, 9, 21, 20, 28, 29, 33, 47};
const int sequence14[] = {55, 41, 42, 43, 35, 34, 30, 31};
const int sequence15[] = {55, 57, 58, 59, 60};
// Add more sequences as needed...

// Total number of sequences
#define TOTAL_SEQUENCES 16  // Adjust this number based on how many sequences you have

void setup() {
  // Initialize the NeoPixel strip
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  randomSeed(analogRead(0)); // Seed random number generator with a random value
  delay(1000);
}

void loop() {
  // Cycle through each sequence, one at a time
  for (int i = 0; i < TOTAL_SEQUENCES; i++) {
    executeSequence(i);
    
    // Random delay between 0.5 and 5 seconds
    int sequenceDelay = random(300, 6000); // 300 ms to 6000 ms
    delay(sequenceDelay);
  }
}

// Function to clear the strip
void clearStrip() {
  strip.clear();
  strip.show();
}

// Define functions for each sequence
void runSequence0() {
  const int* indices = sequence0;
  for (int i = 0; i < 8; i++) {
    strip.setPixelColor(indices[i], strip.Color(maxBrightness, 0, 0)); // Turn on LED
    strip.show();
    delay(ledSwitchDelay);
    clearStrip(); // Clear the strip before the next LED turns on
  }
}

void runSequence1() {
  const int* indices = sequence1;
  for (int i = 0; i < 8; i++) {
    strip.setPixelColor(indices[i], strip.Color(maxBrightness, 0, 0)); // Turn on LED
    strip.show();
    delay(ledSwitchDelay);
    clearStrip(); // Clear the strip before the next LED turns on
  }
}

void runSequence2() {
  const int* indices = sequence2;
  for (int i = 0; i < 8; i++) {
    strip.setPixelColor(indices[i], strip.Color(maxBrightness, 0, 0)); // Turn on LED
    strip.show();
    delay(ledSwitchDelay);
    clearStrip(); // Clear the strip before the next LED turns on
  }
}

void runSequence3() {
  const int* indices = sequence3;
  for (int i = 0; i < 6; i++) {
    strip.setPixelColor(indices[i], strip.Color(maxBrightness, 0, 0)); // Turn on LED
    strip.show();
    delay(ledSwitchDelay);
    clearStrip(); // Clear the strip before the next LED turns on
  }
}

void runSequence4() {
  const int* indices = sequence4;
  for (int i = 0; i < 8; i++) {
    strip.setPixelColor(indices[i], strip.Color(maxBrightness, 0, 0)); // Turn on LED
    strip.show();
    delay(ledSwitchDelay);
    clearStrip(); // Clear the strip before the next LED turns on
  }
}

void runSequence5() {
  const int* indices = sequence5;
  for (int i = 0; i < 4; i++) {
    strip.setPixelColor(indices[i], strip.Color(maxBrightness, 0, 0)); // Turn on LED
    strip.show();
    delay(ledSwitchDelay);
    clearStrip(); // Clear the strip before the next LED turns on
  }
}

void runSequence6() {
  const int* indices = sequence6;
  for (int i = 0; i < 8; i++) {
    strip.setPixelColor(indices[i], strip.Color(maxBrightness, 0, 0)); // Turn on LED
    strip.show();
    delay(ledSwitchDelay);
    clearStrip(); // Clear the strip before the next LED turns on
  }
}

void runSequence7() {
  const int* indices = sequence7;
  for (int i = 0; i < 8; i++) {
    strip.setPixelColor(indices[i], strip.Color(maxBrightness, 0, 0)); // Turn on LED
    strip.show();
    delay(ledSwitchDelay);
    clearStrip(); // Clear the strip before the next LED turns on
  }
}

void runSequence8() {
  const int* indices = sequence8;
  for (int i = 0; i < 8; i++) {
    strip.setPixelColor(indices[i], strip.Color(maxBrightness, 0, 0)); // Turn on LED
    strip.show();
    delay(ledSwitchDelay);
    clearStrip(); // Clear the strip before the next LED turns on
  }
}

void runSequence9() {
  const int* indices = sequence9;
  for (int i = 0; i < 8; i++) {
    strip.setPixelColor(indices[i], strip.Color(maxBrightness, 0, 0)); // Turn on LED
    strip.show();
    delay(ledSwitchDelay);
    clearStrip(); // Clear the strip before the next LED turns on
  }
}

void runSequence10() {
  const int* indices = sequence10;
  for (int i = 0; i < 8; i++) {
    strip.setPixelColor(indices[i], strip.Color(maxBrightness, 0, 0)); // Turn on LED
    strip.show();
    delay(ledSwitchDelay);
    clearStrip(); // Clear the strip before the next LED turns on
  }
}

void runSequence11() {
  const int* indices = sequence11;
  for (int i = 0; i < 8; i++) {
    strip.setPixelColor(indices[i], strip.Color(maxBrightness, 0, 0)); // Turn on LED
    strip.show();
    delay(ledSwitchDelay);
    clearStrip(); // Clear the strip before the next LED turns on
  }
}

void runSequence12() {
  const int* indices = sequence12;
  for (int i = 0; i < 3; i++) {
    strip.setPixelColor(indices[i], strip.Color(maxBrightness, 0, 0)); // Turn on LED
    strip.show();
    delay(ledSwitchDelay);
    clearStrip(); // Clear the strip before the next LED turns on
  }
}

void runSequence13() {
  const int* indices = sequence13;
  for (int i = 0; i < 8; i++) {
    strip.setPixelColor(indices[i], strip.Color(maxBrightness, 0, 0)); // Turn on LED
    strip.show();
    delay(ledSwitchDelay);
    clearStrip(); // Clear the strip before the next LED turns on
  }
}

void runSequence14() {
  const int* indices = sequence14;
  for (int i = 0; i < 8; i++) {
    strip.setPixelColor(indices[i], strip.Color(maxBrightness, 0, 0)); // Turn on LED
    strip.show();
    delay(ledSwitchDelay);
    clearStrip(); // Clear the strip before the next LED turns on
  }
}

void runSequence15() {
  const int* indices = sequence15;
  for (int i = 0; i < 5; i++) {
    strip.setPixelColor(indices[i], strip.Color(maxBrightness, 0, 0)); // Turn on LED
    strip.show();
    delay(ledSwitchDelay);
    clearStrip(); // Clear the strip before the next LED turns on
  }
}

// Add additional sequence functions for more

// Function to call the appropriate sequence
void executeSequence(int sequenceIndex) {
  switch(sequenceIndex) {
    case 0: runSequence0(); break;
    case 1: runSequence1(); break;
    case 2: runSequence2(); break;
    case 3: runSequence3(); break;
    case 4: runSequence4(); break;
    case 5: runSequence5(); break;
    case 6: runSequence6(); break;
    case 7: runSequence7(); break;
    case 8: runSequence8(); break;
    case 9: runSequence9(); break;
    case 10: runSequence10(); break;
    case 11: runSequence11(); break;
    case 12: runSequence12(); break;
    case 13: runSequence13(); break;
    case 14: runSequence14(); break;
    case 15: runSequence15(); break;
    // Add cases for additional sequences here
    default: break;
  }
}