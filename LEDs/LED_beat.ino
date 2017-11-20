int RGB[] = {11, 12, 13};
int LEDstart_prev = 0;
int LEDstart_now;
int t_start = 2000;
int color = 0;
int estado = 0;

void setup() {
  // put your setup code here, to run once:
  for (int color = 0; color < 4; color++)
  {
    pinMode(RGB[color], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  LED_start();
}


void LED_on()
{
  //parpadeo luces en blanco con sonido fluorescente
}

void LED_start()
{
  LEDstart_now = millis();
  switch (color)
  {
    case 0:
      red();
      break;
    case 1:
      off();
      break;
  }
  heart();
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

void heart()
{
  if (LEDstart_now - LEDstart_prev >= t_start)
  {
    if (color == 1)
    {
      color = 0;
    }
    else if (color == 0)
    {
      color = 1;
    }
    LEDstart_prev = LEDstart_now;
    blink_start();
  }
}

void blink_start()
{
  switch (estado)
  {
    case 0:
      t_start = 1000;
      estado = estado + 1;
      break;
    case 1:
      t_start = 75;
      estado = estado + 1;
      break;
    case 2:
      t_start = 75;
      estado = estado + 1;
      break;
    case 3:
      t_start = 75;
      estado = 0;
      break;
  }
}
