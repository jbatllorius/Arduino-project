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

int count = 359;
//The byte command stores unsigned 8-bit numbers from 0 to 255
//Whith this array, we are setting 4 byte variables that will represent the 4 digits in the module display
byte data[] = {0, 0, 0, 0};

int Timer_start = 9;
int start_time = 0;
byte k = 0b10000000;
int change = 1;
int lastmin_OUT = 10;
int spin_change1 = 7;
int spin_change2 = 11;
int PANIC_IN = 8;
int timeout = 12;
int data0 = 0;

void setup()
{
  pinMode(Timer_start, INPUT);
  pinMode(PANIC_IN, INPUT);
  pinMode(timeout, OUTPUT);
  pinMode(lastmin_OUT, OUTPUT);
  pinMode(spin_change1, OUTPUT);
  pinMode(spin_change2, OUTPUT);

  data0 = 0;
  Serial.begin(9600);
}

void loop()
{
  //This if works as a variable switch that reads the button in order to start the countdown
  if (digitalRead(Timer_start) == HIGH)
  {
    start_time = 1;
    data[0] = 0b01000000;
    Serial.println("It's in");
  }
  else
  {
    start_time = 0;
  }

  // This is the block that controls the countdown.
  if (start_time == 1)
  {
    // This also works as a variable switch, which changes the countdown mode when time reaches the last minute.
    if ((count <= 100) && (data0 == 0))
    {
      // This sets the mode to mayhem.
      change = 2;
      // Count is set in 59:99, as it works only in the last minute.
      count = 5999;
      // Delay is set to 1 milisecond as this mode runs in seconds and hundredths.
      SPEED = 1;
    }

    // This condition gets triggered when the countdown ends. It returns the module to the stanby phase and delays
    // it for 4 minutes as a punishment for the players for not wining the game in time.
    if ((count == 0) && (data0 == 1))
    {
      Serial.println("GAME OVER");
      delay(5);
      digitalWrite(timeout, HIGH);
      delay(5);
      standby();
      delay(240000);
      // This command takes the program to the "reset vector" memory zone, from which the program will start again.
      asm("jmp 0x0000");
    }

    if (digitalRead(PANIC_IN) == HIGH)
    {
      Serial.println("I PANICKED");

      delay(5);
      standby();
      delay(240000);
      //This command takes the program to the "reset vector" memory zone, from which the program will start again
      asm("jmp 0x0000");
    }

    screen();
    state();
    blnk();
  }

  // This if statement contains the function that puts the module on standby.
  if (start_time == 0)
  {
    standby();
  }
}



///////////////////////////////////////////////FUNCTIONS/////////////////////////////////////////////
//This function contains the switch which controls the countdown modes (basic mode and last minute mayhem)
void state() {
  switch (change)
  {
    //This case controls the basic countdown of the module
    case 1:
      //This byte writes a - in the first segment
      data[0] = 0b01000000;

      //This condition subsracts 41 to the count variable every time the seconds run to 0, so that the next minute
      //will begin from 59 and not 99, as the module counts one by one
      if ((count / 10 % 10 == 0) && (count % 10 == 0)) {
        
        //digitalWrite(spin_control,HIGH);
        if ((count / 100 % 10 == 3)) {
        digitalWrite(spin_change1, HIGH);
        }
        else if ((count / 100 % 10 == 2)) {
        digitalWrite(spin_change2, HIGH);
        digitalWrite(spin_change1, LOW);
        }
        count = count - 41;
        Serial.println("cambia la velocidad");
      }
      //Whenever the secons are different from 0, it just substracts 1
      else {
        count--;
        //digitalWrite(spin_control,LOW);
      }
      break;

    //This case controls the mayhem countdown of the module
    case 2:
      //This is used to change the display in the first segment from - to actual numbers
      data0 = 1;
      //As this mode runs in seconds and hundreths, it just substracts 1 each time
      count--;
      digitalWrite(lastmin_OUT, HIGH);
      digitalWrite(spin_change2, LOW);
      break;
  }
}

void screen()
{
  //Brightness is set in hexadecimal values, where 0x0f (15) is the maximum
  display.setBrightness(0x0f);

  //The function display.encodeDigit() is a function from the library that transforms the number obtained in the operation into
  //the segments that the module must turn on to show it on screen.
  //Display numbers are set from right to the left, thus we are starting from data[3].
  data[3] = display.encodeDigit(count / 1 % 10);
  data[2] = display.encodeDigit(count / 10 % 10);
  data[1] = display.encodeDigit(count / 100 % 10) + k;
  if (data0 == 1)
  {
    data[0] = display.encodeDigit(count / 1000 % 10);
  }

  //The function display.setSegments() is the function that will define the array "data" as the element to be represented on screen
  display.setSegments(data);

  //We delay the Arduino so that the process will repeat every 1000 milis (1 second).
  delay(SPEED);
}

void standby()
{
  //Brightness is set to 10 to make the module look like it is in standby
  display.setBrightness(0x0a);

  //Display numbers are set from right to the left, thus we are starting from data[3].
  data[3] = 0b01101110;
  data[2] = 0b01110111;
  data[1] = 0b00111000;
  data[0] = 0b01110011;

  //The function display.setSegments() is the function that will define the array "data" as the element to be represented on screen
  display.setSegments(data);
}

void blnk()
{
  //This byte controls the two dots in the module. 0b00000000 sets them off, and 0b10000000 sets them on.
  //With this conditionals, we are making a simple blink function for them.
  if (k == 0b00000000)
  {
    k = 0b10000000;
  }
  else if (k == 0b10000000)
  {
    k = 0b00000000;
  }
}


