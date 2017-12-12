//Input pins
int move_IN[] = {24,26,38,42,37,43,23,27};
int down_IN[] = {32,46,47,33};
int blooper_IN[] = {22,28,36,40,39,41,25,29};
int start_IN[] = {30,44,45,31};
int PANIC_IN = 53;

//Player 1 control board buttons
int P1A = blooper_IN[0];
int P1B = move_IN[0];
int P1C = move_IN[1];
int P1D = blooper_IN[1];
int P1W = down_IN[0];
int P1S = start_IN[0];

//Player 2 control board buttons
int P2A = blooper_IN[2];
int P2B = move_IN[2];
int P2C = blooper_IN[3];
int P2D = move_IN[3];
int P2W = down_IN[1];
int P2S = start_IN[1];

//Player 3 control board buttons
int P3A = move_IN[4];
int P3B = blooper_IN[4];
int P3C = blooper_IN[5];
int P3D = move_IN[5];
int P3W = down_IN[2];
int P3S = start_IN[2];

//Player 4 control board buttons
int P4A = move_IN[6];
int P4B = blooper_IN[6];
int P4C = move_IN[7];
int P4D = blooper_IN[7];
int P4W = down_IN[3];
int P4S = start_IN[3];

//Output pins
int move_OUT[] = {6,7,8,9};
int down_OUT = 5;
int blooper_OUT = 12;
int PANIC_OUT = 13;
int start_OUT = 3;
int on_OUT = 4;
int strtest = 52;

//Number variables
int i;

//START variables
boolean On = false;
boolean gamestarted = false;
boolean ON_ctrl = false;
boolean START_ctrl = false;

void setup() {
  //Input pins
  pinMode(move_IN[0], INPUT_PULLUP);
  pinMode(move_IN[1], INPUT_PULLUP);
  pinMode(move_IN[2], INPUT_PULLUP);
  pinMode(move_IN[3], INPUT_PULLUP);
  pinMode(move_IN[4], INPUT_PULLUP);
  pinMode(move_IN[5], INPUT_PULLUP);
  pinMode(move_IN[6], INPUT_PULLUP);
  pinMode(move_IN[7], INPUT_PULLUP);
  
  pinMode(down_IN[0], INPUT_PULLUP);
  pinMode(down_IN[1], INPUT_PULLUP);
  pinMode(down_IN[2], INPUT_PULLUP);
  pinMode(down_IN[3], INPUT_PULLUP);
  
  pinMode(blooper_IN[0], INPUT_PULLUP);
  pinMode(blooper_IN[1], INPUT_PULLUP);
  pinMode(blooper_IN[2], INPUT_PULLUP);
  pinMode(blooper_IN[3], INPUT_PULLUP);
  pinMode(blooper_IN[4], INPUT_PULLUP);
  pinMode(blooper_IN[5], INPUT_PULLUP);
  pinMode(blooper_IN[6], INPUT_PULLUP);
  pinMode(blooper_IN[7], INPUT_PULLUP);
  
  pinMode(start_IN[0], INPUT_PULLUP);
  pinMode(start_IN[1], INPUT_PULLUP);
  pinMode(start_IN[2], INPUT_PULLUP);
  pinMode(start_IN[3], INPUT_PULLUP);
  
  pinMode(PANIC_IN, INPUT_PULLUP);

  //Output pins
  pinMode(move_OUT[0], OUTPUT);
  pinMode(move_OUT[1], OUTPUT);
  pinMode(move_OUT[2], OUTPUT);
  pinMode(move_OUT[3], OUTPUT);
  pinMode(down_OUT, OUTPUT);
  pinMode(blooper_OUT, OUTPUT);
  pinMode(PANIC_OUT, OUTPUT);
  pinMode(start_OUT, OUTPUT);
  pinMode(on_OUT, OUTPUT);
  pinMode(strtest, INPUT_PULLUP);

  //Output set
  digitalWrite(move_OUT[0], LOW);
  digitalWrite(move_OUT[1], LOW);
  digitalWrite(move_OUT[2], LOW);
  digitalWrite(move_OUT[3], LOW);
  digitalWrite(down_OUT, LOW);
  digitalWrite(blooper_OUT, LOW);
  digitalWrite(PANIC_OUT, LOW);
  digitalWrite(start_OUT, LOW);
  digitalWrite(on_OUT, LOW);
  
  //Start pin set
  gamestarted=false;
  ON_ctrl=false;
  START_ctrl=false;

  Serial.begin(115200);
}

void loop()
{
  ON();
  START();
  MOVE();
  PANIC();
}
