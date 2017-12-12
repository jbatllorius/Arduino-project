void MOVE()
{
  if (gamestarted == true)
  {
    if (digitalRead(down_IN) == LOW)
    {
      Spin();
      x_left(); //This controls the movement of the X axis to the left
      x_right(); //This controls the movement of the X axis to the right
      y_left(); //This controls the movement of the Y axis to the left
      y_right(); //This controls the movement of the Y axis to the left
      blooper();
    }
    else
    {
      down();
      downctrl = true;
    }
  }
}

void PANIC()
{
  if ((digitalRead(PANIC_IN) == HIGH) && digitalRead(lastmin_IN) == HIGH)
  {
    WIN();
  }
}
////////////////////////////////////////////////FUNCTIONS/////////////////////////////
void Spin()
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
  delayMicroseconds(speed_S);           // We delay it for 5 millis to create the pulse in STEP
  digitalWrite(steps_S, LOW);         // A4988 makes makes a step inside the motor
  delayMicroseconds(speed_S);           // We delay it for 5 millis to avoid overlapping on the steps
}

void Spinchange()
{
  if (digitalRead(spin_change1) == HIGH)
  {
    Serial.println("cambio 1");
    speed_S = 800;
  }
  else if (digitalRead(spin_change2) == HIGH)
  {
    Serial.println("cambio 2");
    speed_S = 500;
  }
  else if (digitalRead(lastmin_IN) == HIGH)
  {
    Serial.println("cambio 3");
    speed_S = 1000;
  }
  //Serial.println("Saliendo de spinchange");
}

void x_left()
{
  //Moves the hook to the left through the X axis
  if ((digitalRead(move_IN[0]) == HIGH) && (digitalRead(fcarr_XI) == HIGH))
  {
    digitalWrite(direct_X, LOW);    // Here we change the direction

    digitalWrite(steps_X, HIGH);        // Here we generate a HIGH-LOW wave
    delayMicroseconds(500);           // We delay it for 5 millis to create the pulse in STEP
    digitalWrite(steps_X, LOW);         // A4988 makes makes a step inside the motor
    delayMicroseconds(500);           // We delay it for 5 millis to avoid overlapping on the steps
  }
}

void y_left()
{
  //Moves the hook to the left through the Y axis
  if ((digitalRead(move_IN[1]) == HIGH) && (digitalRead(fcarr_YI) == HIGH))
  {
    digitalWrite(direct_Y, LOW);    // Here we change the direction

    digitalWrite(steps_Y, HIGH);        // Here we generate a HIGH-LOW wave
    delayMicroseconds(500);           // We delay it for 5 millis to create the pulse in STEP
    digitalWrite(steps_Y, LOW);         // A4988 makes makes a step inside the motor
    delayMicroseconds(500);           // We delay it for 5 millis to avoid overlapping on the steps
  }
}

void x_right()
{
  //Moves the hook to the right through the X axis
  if ((digitalRead(move_IN[2]) == HIGH) && (digitalRead(fcarr_XD) == HIGH))
  {
    digitalWrite(direct_X, HIGH);    // Here we change the direction

    digitalWrite(steps_X, HIGH);        // Here we generate a HIGH-LOW wave
    delayMicroseconds(500);           // We delay it for 5 millis to create the pulse in STEP
    digitalWrite(steps_X, LOW);         // A4988 makes makes a step inside the motor
    delayMicroseconds(500);           // We delay it for 5 millis to avoid overlapping on the steps
  }
}

void y_right()
{
  //Moves the hook to the right through the Y axis
  if ((digitalRead(move_IN[3]) == HIGH) && (digitalRead(fcarr_YD) == HIGH))
  {
    digitalWrite(direct_Y, HIGH);    // Here we change the direction

    digitalWrite(steps_Y, HIGH);        // Here we generate a HIGH-LOW wave
    delayMicroseconds(500);           // We delay it for 5 millis to create the pulse in STEP
    digitalWrite(steps_Y, LOW);         // A4988 makes makes a step inside the motor
    delayMicroseconds(500);           // We delay it for 5 millis to avoid overlapping on the steps
  }
}

void down()
{
  while (downctrl == true)
  {
    for (int i = 0; i < stepsPerRev * 3; i++)
    {
      clockwise();
      delayMicroseconds(motorSpeed);
    }
    if(digitalRead(win)==LOW)
    {
      WIN();
    }
    else
    {
    for (int i = 0; i < stepsPerRev * 3; i++)
    {
      anticlockwise();
      delayMicroseconds(motorSpeed);
    }
    }
    downctrl = false;
  }
}

void clockwise()
{
  stepCounter++;
  if (stepCounter >= numSteps) stepCounter = 0;
  setOutput(stepCounter);
}

void anticlockwise()
{
  stepCounter--;
  if (stepCounter < 0) stepCounter = numSteps - 1;
  setOutput(stepCounter);
}

void setOutput(int step)
{
  digitalWrite(motorPin1, bitRead(stepsLookup[step], 0));
  digitalWrite(motorPin2, bitRead(stepsLookup[step], 1));
  digitalWrite(motorPin3, bitRead(stepsLookup[step], 2));
  digitalWrite(motorPin4, bitRead(stepsLookup[step], 3));
}
