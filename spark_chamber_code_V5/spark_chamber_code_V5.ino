/*
Desktop Spark Chamber based on DFRobot Bluno Beetle (Arduino UNO).
Using an 8x8 addressable LED grid and Adafruit Neopixel library.
Randomly OR sequentially runs 16 sequences of 'sparks' at random time intervals.
Configurable timer interrupt enters sleep mode to conserve battery until power cycle (Boost converter will still be using power)
*/

#include <Adafruit_NeoPixel.h>
#include <avr/interrupt.h>
#include <avr/power.h>
#include <avr/sleep.h>

// Configure if sequences should be chosen randomly (1) or sequentially (0)
#define RandSeq 1
// Set power saving Timeout value (seconds)
#define Timeout 300 // 300s = 5 minutes

// Define the number of LEDs and the pin connected to the data line
#define NUM_LEDS 64
#define DATA_PIN 5

// Define random delay limits (ms)
#define MIN_DELAY 300
#define MAX_DELAY 6000

// Total number of sequences
#define TOTAL_SEQUENCES 16  // Adjust this number based on how many sequences you have

int ledSwitchDelay = 0;  // Delay between each individual LED switching on in milliseconds
int maxBrightness = 250;  // Maximum brightness for LEDs

volatile bool stopProgram = false; // Flag to stop the program after 5 minutes

// Create a NeoPixel object
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, DATA_PIN, NEO_GRB + NEO_KHZ800);

// Define the specific combinations of LEDs for each sequence
const int sequences[TOTAL_SEQUENCES][8] = {
  {56, 54, 53, 43, 44, 34, 33, 31},
  {55, 54, 53, 52, 51, 50, 49, 48},
  {24, 25, 26, 36, 35, 34, 46, 47},
  {23, 25, 37, 43, 51, 61, -1, -1},
  {8, 9, 10, 11, 19, 18, 17, 16},
  {56, 41, 26, 4, -1, -1, -1, -1},
  {23, 22, 10, 11, 12, 13, 1, 0},
  {56, 54, 42, 36, 28, 18, 14, 0},
  {23, 22, 26, 27, 35, 34, 46, 47},
  {23, 22, 21, 20, 19, 18, 17, 16},
  {55, 54, 53, 52, 44, 45, 46, 47},
  {8, 9, 10, 11, 12, 13, 14, 15},
  {39, 22, 5, -1, -1, -1, -1, -1},
  {7, 9, 21, 20, 28, 29, 33, 47},
  {55, 41, 42, 43, 35, 34, 30, 31},
  {55, 57, 58, 59, 60, -1, -1, -1}
};

void setup() {
  // Initialize the NeoPixel strip
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  randomSeed(analogRead(0)); // Seed random number generator with a random value
  delay(1000);

  // Configure Timer1 for a 5-minute timeout
  cli(); // Disable global interrupts
  TCCR1A = 0; // Set Timer1 to normal mode
  TCCR1B = (1 << WGM12) | (1 << CS12) | (1 << CS10); // CTC mode, prescaler 1024
  OCR1A = 46875; // Set compare value for 1-second interval
  TIMSK1 = (1 << OCIE1A); // Enable Timer1 compare interrupt
  sei(); // Enable global interrupts
}

ISR(TIMER1_COMPA_vect) {
  static uint16_t seconds = 0;
  seconds++;
  if (seconds >= Timeout) { // 300s = 5 minutes
    stopProgram = true;
    clearStrip();
    set_sleep_mode(SLEEP_MODE_PWR_DOWN); // Set power-down sleep mode
    sleep_enable();
    sleep_cpu(); // Enter sleep mode (program halts here until reset)
  }
}

// Function to clear the strip
void clearStrip() {
  strip.clear();
  strip.show();
}

// Generic function to execute a sequence
void runSequence(const int* sequence) {
  for (int i = 0; i < 8; i++) {
    if (sequence[i] == -1) break; // Stop if the sequence has invalid indices (-1)
    strip.setPixelColor(sequence[i], strip.Color(maxBrightness, 0, 0)); // Turn on LED
    strip.show();
    delay(ledSwitchDelay);
    clearStrip(); // Clear the strip before the next LED turns on
  }
}

void loop() {
  if (stopProgram) return; // Exit loop if stopProgram flag is set

  #ifdef RandSeq  // Selection of random (1) or sequential (0) sequence progression
  while (!stopProgram) {
    // RandSeq = 1, Randomly choose each sequence
    int i = random(0, TOTAL_SEQUENCES); 
    runSequence(sequences[i]);

    // Random delay between 0.3 and 6 seconds
    int sequenceDelay = random(MIN_DELAY, MAX_DELAY);
    delay(sequenceDelay);
  }
  
  #else
  // RandSeq = 0, Progress through each sequence sequentially
  for (int i = 0; i < TOTAL_SEQUENCES; i++) {
    runSequence(sequences[i]);

    // Random delay between 0.3 and 6 seconds
    int sequenceDelay = random(MIN_DELAY, MAX_DELAY);
    delay(sequenceDelay);

    if (stopProgram) return; // Exit loop if stopProgram flag is set
  }
  #endif
}
