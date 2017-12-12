void LED_on()
{
  if (t_on > 0)
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
    fluorescent();
  }
  else
  {
    white();
    onpressed = true;
    startpressed = true;
  }
}

void LED_start()
{
  LEDstart_now = millis();
  switch (color_start)
  {
    case 0:
      red();
      break;
    case 1:
      off();
      break;
  }
  if (heartcount < 32)
  {
    heart();
  }
  else if (heartcount == 32)
  {
    onpressed = false;
    timeron = true;
  }
}

void Colour_change()
{
  colournow=millis();
  if (gamestarted == true)
  {
    if (colournow - colourprev >= 10000)
    {
      if (colourchange == 5)
      {
        colourchange = 0;
        colourprev=colournow;
      }
      else if (colourchange < 5)
      {
        colourchange = colourchange + 1;
        colourprev=colournow;
      }
      else if (colourchange > 5)
      {
        colourchange = 0;
        colourprev=colournow;
      }
    }
    switch (colourchange)
    {
      case 0:
        red();
        break;
      case 1:
        yellow();
        break;
      case 2:
        green();
        break;
      case 3:
        cyan();
        break;
      case 4:
        blue();
        break;
      case 5:
        purple();
        break;
      case 6:
        off();
        break;
    }
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////COLORS///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void white()
{
  digitalWrite(RGB[0], LOW);
  digitalWrite(RGB[1], LOW);
  digitalWrite(RGB[2], LOW);
}

void red()
{
  digitalWrite(RGB[0], LOW);
  digitalWrite(RGB[1], HIGH);
  digitalWrite(RGB[2], HIGH);
}

void green()
{
  digitalWrite(RGB[0], HIGH);
  digitalWrite(RGB[1], LOW);
  digitalWrite(RGB[2], HIGH);
}

void blue()
{
  digitalWrite(RGB[0], HIGH);
  digitalWrite(RGB[1], HIGH);
  digitalWrite(RGB[2], LOW);
}

void yellow()
{
  digitalWrite(RGB[0], LOW);
  digitalWrite(RGB[1], LOW);
  digitalWrite(RGB[2], HIGH);
}

void purple()
{
  digitalWrite(RGB[0], LOW);
  digitalWrite(RGB[1], HIGH);
  digitalWrite(RGB[2], LOW);
}

void cyan()
{
  digitalWrite(RGB[0], HIGH);
  digitalWrite(RGB[1], LOW);
  digitalWrite(RGB[2], LOW);
}

void off()
{
  digitalWrite(RGB[0], HIGH);
  digitalWrite(RGB[1], HIGH);
  digitalWrite(RGB[2], HIGH);
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
    t_on = t_on - 35;
  }
  if ((t_on <= 350) && (t_on > 150))
  {
    t_on = t_on - 30;
  }
  if ((t_on <= 150) && (t_on > 0))
  {
    t_on = t_on - 25;
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
      t_start = 1700;
      state_start = state_start + 1;
      break;
    case 1:
      t_start = 100;
      state_start = state_start + 1;
      break;
    case 2:
      t_start = 100;
      state_start = state_start + 1;
      break;
    case 3:
      t_start = 100;
      state_start = 0;
      break;
  }
  heartcount = heartcount + 1;
}
