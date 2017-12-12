void Sound_on()
{
  if (on_played == false)
  {
    soundnow = millis();
    myDFPlayer.play(2);
    on_played = true;
    Serial.println("dfplayer cancion 1");
    if (soundnow - soundprev > 40000) //We give time so that the file can be reproduced completely
    {
      soundprev = soundnow;
      myDFPlayer.pause();
    }
  }
}

void Sound_start()
{
  if (start_played == false)
  {
    soundnow = millis();
    myDFPlayer.play(1);
    start_played = true;
    Serial.println("dfplayer cancion 2");
    if (soundnow - soundprev > 40000) //We give time so that the file can be reproduced completely
    {
      soundprev = soundnow;
      myDFPlayer.pause();
    }
  }
}

void Sound_Timer()
{
  myDFPlayer.play(3);
  myDFPlayer.loop(3);
}

void Noise()
{
  if (noisectrl == true)
  {
    mocked = (int(random(4, 13)));
    noisectrl = false;
    gamestarted = false;
    myDFPlayer.play(mocked);
  }
  delay(3000);
  BLOOP = 0;
  bloopctrl = true;
  timeron = true;
}



void printDetail(uint8_t type, int value) {
  switch (type) {
    case TimeOut:
      Serial.println(F("Time Out!"));
      break;
    case WrongStack:
      Serial.println(F("Stack Wrong!"));
      break;
    case DFPlayerCardInserted:
      Serial.println(F("Card Inserted!"));
      break;
    case DFPlayerCardRemoved:
      Serial.println(F("Card Removed!"));
      break;
    case DFPlayerCardOnline:
      Serial.println(F("Card Online!"));
      break;
    case DFPlayerPlayFinished:
      Serial.print(F("Number:"));
      Serial.print(value);
      Serial.println(F(" Play Finished!"));
      break;
    case DFPlayerError:
      Serial.print(F("DFPlayerError:"));
      switch (value) {
        case Busy:
          Serial.println(F("Card not found"));
          break;
        case Sleeping:
          Serial.println(F("Sleeping"));
          break;
        case SerialWrongStack:
          Serial.println(F("Get Wrong Stack"));
          break;
        case CheckSumNotMatch:
          Serial.println(F("Check Sum Not Match"));
          break;
        case FileIndexOut:
          Serial.println(F("File Index Out of Bound"));
          break;
        case FileMismatch:
          Serial.println(F("Cannot Find File"));
          break;
        case Advertise:
          Serial.println(F("In Advertise"));
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
}

/***************************************************
  DFPlayer - A Mini MP3 Player For Arduino
  <https://www.dfrobot.com/index.php?route=product/product&product_id=1121>

 ***************************************************
  This example shows the basic function of library for DFPlayer.

  Created 2016-12-07
  By [Angelo qiao](Angelo.qiao@dfrobot.com)

  GNU Lesser General Public License.
  See <http://www.gnu.org/licenses/> for details.
  All above must be included in any redistribution
 ****************************************************/

/***********Notice and Trouble shooting***************
  1.Connection and Diagram can be found here
  <https://www.dfrobot.com/wiki/index.php/DFPlayer_Mini_SKU:DFR0299#Connection_Diagram>
  2.This code is tested on Arduino Uno, Leonardo, Mega boards.
 ****************************************************/
