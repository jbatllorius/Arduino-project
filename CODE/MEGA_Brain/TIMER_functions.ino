void AMOK()
{
  AMOKnow = millis();
  if (digitalRead(lastmin_IN) == HIGH)
  {
    if (AMOKnow - AMOKprev >= AMOKtime)
    {
      AMOKprev = AMOKnow;
      AMOKtime = (int(random(100,10000)));
      if(spin_control == 0)
      {
        spin_control = 1;
      }
      else if(spin_control == 1)
      {
        spin_control = 0;
      }
    }
  }
}


void TIMEOUT()
{
  if (digitalRead(timeout) == HIGH)
  {
    myDFPlayer.play(14);
    off();
    gamestarted = false;
    delay(240000);
    asm("jmp 0x0000");
  }
}

