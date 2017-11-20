void LED_on()
{
  LEDon_now = millis();
  switch (color_on)
  {
    case 0:
      white();
      break;
    case 1:
      off();
      break;
  }
  if (t_on > 0)
  {
    fluorescent();
  }
  else
  {
    color_on = 0;
  }
}

void LED_start()
{
  LEDstart_now = millis();
  switch (color_start)
  {
    case 0:
      white();
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
  for (LED = 0; LED < 4; LED++)
  {
    digitalWrite(RGB[LED], HIGH);
  }
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
  for (LED = 0; LED < 4; LED++)
  {
    digitalWrite(RGB[color], LOW);
  }
}

void fluorescent()
{
  if (LEDon_now - LEDon_prev > t_on)
  {
    if (color_on == 1)
    {
      color_on = 0;
    }
    else if (color_on == 0)
    {
      color_on = 1;
    }
    LEDon_prev = LEDon_now;
    blink_on();
  }
}

void blink_on()
{
  if ((t_on <= 500) && (t_on > 350))
  {
    t_on = t_on - 50;
  }
  if ((t_on <= 350) && (t_on > 150))
  {
    t_on = t_on - 35;
  }
  if ((t_on <= 150) && (t_on > 0))
  {
    t_on = t_on - 20;
  }
}

void heart()
{
  if (LEDstart_now - LEDstart_prev >= t_start)
  {
    if (color_start == 1)
    {
      color_start = 0;
    }
    else if (color_start == 0)
    {
      color_start = 1;
    }
    LEDstart_prev = LEDstart_now;
    blink_start();
  }
}

void blink_start()
{
  switch (state_start)
  {
    case 0:
      t_start = 1000;
      state_start = state_start + 1;
      break;
    case 1:
      t_start = 75;
      state_start = state_start + 1;
      break;
    case 2:
      t_start = 75;
      state_start = state_start + 1;
      break;
    case 3:
      t_start = 75;
      state_start = 0;
      break;
  }
}


