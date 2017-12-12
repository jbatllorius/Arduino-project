void ON()
{
  //Serial.println("entro en ON");
  // This if works as a variable switch that reads the button in order to start the sequence.
  if ((digitalRead(on_IN) == HIGH) && (startpressed == false))
  {
    Sound_on();
    if (soundctrl1 == true)
    {
      delay(200);
      soundctrl1 = false;
    }
    LED_on();
  }
}

void START()
{
  //Serial.println("entro en START");
  // This if works as a variable switch that reads the button in order to start the sequence.
  if ((digitalRead(start_IN) == HIGH) && (onpressed == true))
  {
    Sound_start();
    if (soundctrl2 == true)
    {
      delay(500);
      soundctrl2 = false;
    }
    LED_start();
  }
}

void TIMER()
{
  if (timeron == true)
  {
    digitalWrite(Timer_start, HIGH);
    Sound_Timer();
    delay(15);
    gamestarted = true;
    timeron = false;
  }
}

void WIN()
{
  if (winctrl == true)
  {
    myDFPlayer.play(15);
    yellow();
    gamestarted = false;
    digitalWrite(PANIC_OUT, HIGH);
    digitalWrite(prize, HIGH); //mover el servo para dar premio
    val = digitalRead(prize);           // reads the value of the potentiometer (value between 0 and 1023)
    val = map(val, 0, 1, 0, 180);        // scale it to use it with the servo (value between 0 and 180)
    myservo.write(val);                  // sets the servo position according to the scaled value
    delay(15);
    winctrl = false;
    if (digitalRead(PANIC_IN) == LOW)
    {
      for (int i = 0; i < stepsPerRev * 3; i++)
      {
        anticlockwise();
        delayMicroseconds(motorSpeed);
      }
    }
  }
}

