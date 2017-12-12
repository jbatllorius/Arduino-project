#include <Servo.h>
#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

////////BRAIN//////////////////////////////////////
//NEMA signal output
int steps_X = 23;
int direct_X = 25;
int steps_Y = 27;
int direct_Y = 29;
int steps_S = 31;
int direct_S = 33;
int speed_S = 1200;
//Down stepmotor output
//pin definition
const int motorPin1 = 46;    // 28BYJ48 In1
const int motorPin2 = 48;    // 28BYJ48 In2
const int motorPin3 = 50;   // 28BYJ48 In3
const int motorPin4 = 52;   // 28BYJ48 In4                   
//variable definition
int motorSpeed = 1000;   // this variable sets the rotation speed of the motor
int stepCounter = 0;     // this variable counts the number of steps made
int stepsPerRev = 4076;  // this variable defines the amount of steps there are in a revolution
//sequence definition
//stepmotors can be used in three diferent ways to obtain different performances (1 fase, 2 fases or half fase).
//We use half fase as recommended by the motor producer.
const int numSteps = 8;
const int stepsLookup[8] = { B1000, B1100, B0100, B0110, B0010, B0011, B0001, B1001 };

//LED variables
int RGB[] = {53, 51, 49};
int LED;
int heartcount = 0;
/////ON
int LEDon_prev;
int LEDon_now;
int t_on=500;
int color_on;
/////START
int LEDstart_prev;
int LEDstart_now;
int t_start = 2000;
int color_start;
int state_start;
boolean startctrl = true;
//Colour change
int colourchange = 0;
int colourprev = 0;
int colournow;
//START variables
boolean gamestarted=false;
boolean onpressed=false;
boolean startpressed=false;
boolean timeron=false;
int win = 47;
int prize = 32;
int val;
Servo myservo;  // create servo object to control a servo

//DFPlayer MP3 SOUND
SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
int mocked;
boolean on_played = false;
boolean start_played = false;
int soundnow;
int soundprev = 0;
boolean soundctrl1 = false;
boolean soundctrl2 = false;
boolean bloopctrl = true;
boolean noisectrl = true;
boolean downctrl = false;
boolean winctrl = true;

//Rail end sensors
int fcarr_XI = 26;
int fcarr_YI = 28;
int fcarr_XD = 22;
int fcarr_YD = 24;

////////BUTTONS////////////////////////////////////
////Input
//Move buttons
int move_IN[] = {6,7,8,9};
//Down buttons
int down_IN = 5;
//Blooper buttons
int blooper_IN = 12;
//Start buttons
int start_IN = 3;
int on_IN = 4;
//PANIC button
int PANIC_IN = 13;
int PANIC_OUT = 37;

////Number variables
int BLOOP;
int i;
int prevmillis;
int nowmillis;
int paused=8000;
boolean lastmin;

////////TIMER//////////////////////////////////////
int lastmin_IN = 41;
int spin_change1 = 44;
int spin_change2 = 43;
int timeout = 45;
int Timer_start = 39;
int AMOKnow;
int AMOKprev = 0;
int AMOKtime = 1000;
int spin_control = 0;

void setup() 
{

  ///////////////////////////////////////BRAIN setup
  //NEMAS
  pinMode(steps_X, OUTPUT); 
  pinMode(direct_X, OUTPUT);
  pinMode(steps_Y, OUTPUT); 
  pinMode(direct_Y, OUTPUT);
  pinMode(steps_S, OUTPUT); 
  pinMode(direct_S, OUTPUT);
  //Stepmotor
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT); 
  //Rail end sensors
  pinMode(fcarr_XI, INPUT_PULLUP);
  pinMode(fcarr_YI, INPUT_PULLUP);
  pinMode(fcarr_XD, INPUT_PULLUP);
  pinMode(fcarr_YD, INPUT_PULLUP);
  //LED sequences
  pinMode(RGB[0], OUTPUT);
  pinMode(RGB[1], OUTPUT);
  pinMode(RGB[2], OUTPUT);
  //
  digitalWrite(RGB[0],HIGH);
  digitalWrite(RGB[1],HIGH);
  digitalWrite(RGB[2],HIGH);
  //Start setup
  pinMode(on_IN, INPUT);
  pinMode(start_IN, INPUT);
  //Servo setup
  pinMode(win, INPUT_PULLUP);
  pinMode(prize, OUTPUT);
  myservo.attach(prize);
  //SOUND setup
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);
  
  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    //while(true);
  }
  Serial.println(F("DFPlayer Mini online."));
  
  myDFPlayer.volume(30);  //Set volume value. From 0 to 30

  ///////////////////////////////////////Buttons input pins setup
  pinMode(move_IN[0], INPUT);
  pinMode(move_IN[1], INPUT);
  pinMode(move_IN[2], INPUT);
  pinMode(move_IN[3], INPUT);
  pinMode(down_IN, INPUT);
  pinMode(blooper_IN, INPUT);
  pinMode(start_IN, INPUT);
  pinMode(PANIC_IN, INPUT);
  pinMode(PANIC_OUT, OUTPUT);

  ///////////////////////////////////////Timer input pins setup
  pinMode(Timer_start, OUTPUT);
  pinMode(lastmin_IN, INPUT);
  pinMode(spin_change1, INPUT);
  pinMode(spin_change2, INPUT);
  pinMode(timeout, INPUT);
 
  //////////////////////////////////////RESET
  Reset();
}

void loop()
{
  nowmillis=millis();
  Spinchange();
  ON();
  START();
  TIMER();
  Colour_change();
  MOVE(); 
  AMOK(); //This is the function that puts AMOK in berserk mode in the last minute
  if(digitalRead(lastmin_IN)==HIGH)
  {
    lastmin=true;
  }
  PANIC();
  TIMEOUT();
}

