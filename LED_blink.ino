int RGB[] = {49, 51, 53};
int LED_prev = 0;
int LED_now;
int t = 500;
int color = 1;

void setup() {
  // put your setup code here, to run once:
  for (int color=0; color < 4; color++) 
  {
    pinMode(RGB[color],OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  LED_on();
}

void LED_on()
{
  LED_now = millis();
  switch (color)
  {
    case 0:
      white();
      break;
    case 1:
      off();
      break;
  }
  if (t > 0)
  {
    fluorescent();
  }
  else
  {
    color = 0;
  }
}

void LED_start()
{
  //parpadeo luces en rojo acompasado con los latidos
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////COLORS///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void white()
{
  digitalWrite(RGB[0], HIGH);
  digitalWrite(RGB[1], HIGH);
  digitalWrite(RGB[2], HIGH);
}

void red()
{
  digitalWrite(RGB[0], HIGH);
  digitalWrite(RGB[1], LOW);
  digitalWrite(RGB[2], LOW);
}

void green()
{
  digitalWrite(RGB[0], LOW);
  digitalWrite(RGB[1], HIGH);
  digitalWrite(RGB[2], LOW);
}

void blue()
{
  digitalWrite(RGB[0], LOW);
  digitalWrite(RGB[1], LOW);
  digitalWrite(RGB[2], HIGH);
}

void yellow()
{
  digitalWrite(RGB[0], HIGH);
  digitalWrite(RGB[1], HIGH);
  digitalWrite(RGB[2], LOW);
}

void purple()
{
  digitalWrite(RGB[0], HIGH);
  digitalWrite(RGB[1], LOW);
  digitalWrite(RGB[2], HIGH);
}

void cyan()
{
  digitalWrite(RGB[0], LOW);
  digitalWrite(RGB[1], HIGH);
  digitalWrite(RGB[2], HIGH);
}

void off()
{
  digitalWrite(RGB[0], LOW);
  digitalWrite(RGB[1], LOW);
  digitalWrite(RGB[2], LOW);
}

void fluorescent()
{
  if (LED_now - LED_prev > t)
  {
    if (color == 1)
    {
      color = 0;
    }
    else if (color == 0)
    {
      color = 1;
    }
    LED_prev = LED_now;
    blinker();
  }
}

void blinker()
{
  if((t<=500)&&(t>350))
  {
  t=t-50; 
  }
  if((t<=350)&&(t>150))
  {
    t=t-35;
  }
  if((t<=150)&&(t>0))
  {
    t=t-20;
  }
}

