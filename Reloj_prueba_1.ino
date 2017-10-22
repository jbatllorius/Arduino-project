/*This code was modified from pablobacho's TM1627FinalCountdown.ino repository on GitHub
   (https://gist.github.com/pablobacho/e94ef8af001e76901ae1)
*/

// Initialization of the TM1637 module library
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 2
#define DIO 3

// The amount of time (in milliseconds) between display changes
int SPEED = 1000;

// Setting of the pins that control the display
TM1637Display display(CLK, DIO);

int count = 400;
//The byte command stores unsigned 8-bit numbers from 0 to 255
//Whith this array, we are setting 4 byte variables that will represent the 4 digits in the module display
byte data[] = {0, 0, 0, 0};

void setup() {

}

void loop() {
  //Brightness is set in hexadecimal values, where 0x0f (15) is the maximum
  display.setBrightness(0x0f);

  //The function display.encodeDigit() is a function from the library that transforms the number obtained in the operation into
  //the segments that the module must turn on to show it on screen.
  //Display numbers are set from right to the left, thus we are starting from data[3].
  data[3] = display.encodeDigit(count / 1 % 10);
  data[2] = display.encodeDigit(count / 10 % 10);
  data[1] = display.encodeDigit(count / 100 % 10);
  data[0] = display.encodeDigit(count / 1000 % 10);

  //The function display.setSegments() is the function that will define the array "data" as the element to be represented on screen
  display.setSegments(data);

  //These are the fucntions that make the countdown
  basic();
  //mayhem();

  //We delay the Arduino so that the process will repeat every 1000 milis (1 second).
  delay(SPEED);
}


///////////////////////////////////////////////FUNCTIONS/////////////////////////////////////////////
void basic() {
    if ((count / 10 % 10 == 0) && (count % 10 == 0)) {
      count = count - 41;
    }
    else {
      count--;
    }
  }
}

void mayhem() {
  if ((count / 100 % 10 == 0) && (count /1000 % 10 == 0)) {
    count = 5999;
    count--;
    SPEED = 10;
  }
}

