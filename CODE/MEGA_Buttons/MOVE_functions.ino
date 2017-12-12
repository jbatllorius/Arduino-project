void MOVE()
{
  if (gamestarted == true)
  {
    x_left(); //This controls the movement of the X axis to the left
    x_right(); //This controls the movement of the X axis to the right
    y_left(); //This controls the movement of the Y axis to the left
    y_right(); //This controls the movement of the Y axis to the left
    down(); //This controls the descent of the hook
    blooper(); //This triggers the blooper event
  }
}

void x_left()
{
  //X motor left
  if (digitalRead(P1B) == LOW && digitalRead(P3D) == LOW) //This means that the function will start only if P1B and P3D buttons are pressed at the same time
  {
    digitalWrite(move_OUT[0], HIGH);
  }
  else
  {
    digitalWrite(move_OUT[0], LOW);
  }
}

void y_left()
{
  //Y motor left
  if (digitalRead(P2D) == LOW && digitalRead(P4A) == LOW) //This means that the function will start only if P2D and P4A buttons are pressed at the same time
  {
    digitalWrite(move_OUT[1], HIGH);
  }
  else
  {
    digitalWrite(move_OUT[1], LOW);
  }
}

void x_right()
{
  //X motor right
  if (digitalRead(P2B) == LOW && digitalRead(P4C) == LOW) //This means that the function will start only if P2B and P4C buttons are pressed at the same time
  {
    digitalWrite(move_OUT[2], HIGH);
  }
  else
  {
    digitalWrite(move_OUT[2], LOW);
  }
}

void y_right()
{
  //Y motor right
  if (digitalRead(P1C) == LOW && digitalRead(P3A) == LOW) //This means that the function will start only if P1C and P3A buttons are pressed at the same time
  {
    digitalWrite(move_OUT[3], HIGH);
  }
  else
  {
    digitalWrite(move_OUT[3], LOW);
  }
}

void down()
{
  //Down motor
  if (digitalRead(P1W) == LOW && digitalRead(P2W) == LOW && digitalRead(P3W) == LOW && digitalRead(P4W) == LOW)
  {
    digitalWrite(down_OUT, HIGH);
  }
  else
  {
    digitalWrite(down_OUT, LOW);
  }
}

void blooper()
{
  //Bloopers trigger
  if ((digitalRead(P1A) == LOW) || (digitalRead(P1D) == LOW) || (digitalRead(P2A) == LOW) || (digitalRead(P2C) == LOW) || (digitalRead(P3B) == LOW) || (digitalRead(P3C) == LOW) || (digitalRead(P4B) == LOW) || (digitalRead(P4D) == LOW))
  {
    digitalWrite(blooper_OUT, HIGH);
  }
  else
  {
    digitalWrite(blooper_OUT, LOW);
  }
}

void PANIC()
{
  {
    if (digitalRead(PANIC_IN) == LOW)
    {
      digitalWrite(PANIC_OUT, HIGH);
    }
    else
    {
      digitalWrite(PANIC_OUT, LOW);
    }
  }
}

