void ON()
{
  // This if works as a variable switch that reads the button in order to start the sequence.
  if ((((digitalRead(P1S) == LOW) || (digitalRead(P2S) == LOW) || (digitalRead(P3S) == LOW) || (digitalRead(P4S) == LOW)) && (START_ctrl == false)))
  {
    digitalWrite(on_OUT, HIGH);
    ON_ctrl = true;
    delay(3000);
    START_ctrl = true;
    Serial.println(START_ctrl);
  }
}

void START()
{
  if (((digitalRead(P2S) == LOW) && (ON_ctrl == true)))
  {
    //START_ctrl = true;
    digitalWrite(on_OUT, LOW);
    digitalWrite(start_OUT, HIGH);
    gamestarted = true;
    ON_ctrl = false;
    Serial.println(ON_ctrl);
  }
}
