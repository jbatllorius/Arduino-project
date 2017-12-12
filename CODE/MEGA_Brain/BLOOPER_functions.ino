void blooper()
{
  soundnow = millis();

  if (BLOOP > 0 && BLOOP <= 5) //5% chances of triggering this blooper
  {
    Home();
    BLOOP = 0;
    bloopctrl = true;
  }
  else if (BLOOP > 5 && BLOOP <= 20) //15% chances of triggering this blooper
  {
    Run_forrest();
    if (nowmillis - prevmillis >= 2000)
    {
      Spinchange();
      BLOOP = 0;
      bloopctrl = true;
    }
  }
  else if (BLOOP > 20 && BLOOP <= 70) //50% chances of triggering this blooper
  {
    Noise();
  }
  else if (BLOOP > 70 && BLOOP <= 100) //30% chances of triggering this blooper
  {
    Pitch_black();
    BLOOP = 0;
    bloopctrl = true;
  }
  if ((digitalRead(blooper_IN) == HIGH) && (bloopctrl == true))
  {
    prevmillis = nowmillis;
    BLOOP = int(random(0, 100)); //We generate a random number which will determine the blooper to be triggered
    bloopctrl = false;
    noisectrl = true;
  }
}

void Home()
{ 
  gamestarted = false;
  
  while (digitalRead(fcarr_XD) == HIGH)
  {
    digitalWrite(direct_X, HIGH);    // Here we change the direction

    digitalWrite(steps_X, HIGH);        // Here we generate a HIGH-LOW wave
    delayMicroseconds(700);           // We delay it for 5 millis to create the pulse in STEP
    digitalWrite(steps_X, LOW);         // A4988 makes makes a step inside the motor
    delayMicroseconds(700);           // We delay it for 5 millis to avoid overlapping on the steps
  }

  while (digitalRead(fcarr_YI) == HIGH)
  {
    digitalWrite(direct_Y, LOW);    // Here we change the direction    

    digitalWrite(steps_Y, HIGH);        // Here we generate a HIGH-LOW wave
    delayMicroseconds(700);           // We delay it for 5 millis to create the pulse in STEP
    digitalWrite(steps_Y, LOW);         // A4988 makes makes a step inside the motor
    delayMicroseconds(700);           // We delay it for 5 millis to avoid overlapping on the steps
  }
  
  gamestarted = true;
}

void Run_forrest()
{
  if (spin_control == 0)            // Here we change the direction of the rotary table
  {
    digitalWrite(direct_S, LOW);
  }
  else if (spin_control == 1)
  {
    digitalWrite(direct_S, HIGH);
  }

  digitalWrite(steps_S, HIGH);        // Here we generate a HIGH-LOW wave
  delayMicroseconds(550);           // We delay it for 5 millis to create the pulse in STEP
  digitalWrite(steps_S, LOW);         // A4988 makes makes a step inside the motor
  delayMicroseconds(550);           // We delay it for 5 millis to avoid overlapping on the steps
}

void Pitch_black()
{
  colourchange = 6;
  colourprev = colournow;
}

void Reset() //This function does the same as the Home() function but without letting the rest of the game start by itself.
{ 
  while (digitalRead(fcarr_XD) == HIGH)
  {
    digitalWrite(direct_X, HIGH);    // Here we change the direction

    digitalWrite(steps_X, HIGH);        // Here we generate a HIGH-LOW wave
    delayMicroseconds(700);           // We delay it for 5 millis to create the pulse in STEP
    digitalWrite(steps_X, LOW);         // A4988 makes makes a step inside the motor
    delayMicroseconds(700);           // We delay it for 5 millis to avoid overlapping on the steps
  }

  while (digitalRead(fcarr_YI) == HIGH)
  {
    digitalWrite(direct_Y, LOW);    // Here we change the direction    

    digitalWrite(steps_Y, HIGH);        // Here we generate a HIGH-LOW wave
    delayMicroseconds(700);           // We delay it for 5 millis to create the pulse in STEP
    digitalWrite(steps_Y, LOW);         // A4988 makes makes a step inside the motor
    delayMicroseconds(700);           // We delay it for 5 millis to avoid overlapping on the steps
  }
}
