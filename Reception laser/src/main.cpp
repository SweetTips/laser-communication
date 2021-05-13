#include <Arduino.h>

char pin_signal_entrant = 3;
long debut_chrono = -1;
long fin_chrono = -1;
byte last_signal = LOW;

int lire_signal()
{
  int duration_signal = 0;
  
  byte state_signal = digitalRead(pin_signal_entrant);
  if(last_signal != state_signal)
  {
    if(state_signal == HIGH)
    {
      debut_chrono = millis();
      //start
    }
    else
    {
      fin_chrono = millis();
      //stop
    }
    last_signal = state_signal;
  }

  if(debut_chrono > -1 && fin_chrono > -1)
  {
    duration_signal = fin_chrono - debut_chrono;
    debut_chrono = -1;
    fin_chrono = -1;
  }

  return duration_signal;
}

char decode_signal(int duration_signal)
{
  char character = 0;
  
  if(duration_signal > 10 && duration_signal < 30)
  {
    character = 'a';
  }
  else if(duration_signal >= 30 && duration_signal < 50)
  {
    character = 'b';
  }
  else if(duration_signal >= 50 && duration_signal < 70)
  {
    character = 'c';
  }
  else if(duration_signal >= 70 && duration_signal < 90)
  {
    character = 'd';
  }
  else if(duration_signal >= 90 && duration_signal < 110)
  {
    character = 'e';
  }
  else if(duration_signal >= 110 && duration_signal < 130)
  {
    character = 'f';
  }
  else if(duration_signal >= 130 && duration_signal < 150)
  {
    character = 'g';
  }
  else if(duration_signal >= 150 && duration_signal < 170)
  {
    character = 'h';
  }
  else if(duration_signal >= 170 && duration_signal < 190)
  {
    character = 'i';
  }
  else if(duration_signal >= 190 && duration_signal < 210)
  {
    character = 'j';
  }
  else if(duration_signal >= 210 && duration_signal < 230)
  {
    character = 'k';
  }
  else if(duration_signal >= 230 && duration_signal < 250)
  {
    character = 'l';
  }
  else if(duration_signal >= 250 && duration_signal < 270)
  {
    character = 'm';
  }
  else if(duration_signal >= 270 && duration_signal < 290)
  {
    character = 'n';
  }
  else if(duration_signal >= 290 && duration_signal < 310)
  {
    character = 'o';
  }
  else if(duration_signal >= 310 && duration_signal < 330)
  {
    character = 'p';
  }
  else if(duration_signal >= 330 && duration_signal < 350)
  {
    character = 'q';
  }
  else if(duration_signal >= 350 && duration_signal < 370)
  {
    character = 'r';
  }
  else if(duration_signal >= 370 && duration_signal < 390)
  {
    character = 's';
  }
  else if(duration_signal >= 390 && duration_signal < 410)
  {
    character = 't';
  }
  else if(duration_signal >= 410 && duration_signal < 430)
  {
    character = 'u';
  }
  else if(duration_signal >= 430 && duration_signal < 450)
  {
    character = 'v';
  }
  else if(duration_signal >= 450 && duration_signal < 470)
  {
    character = 'w';
  }
  else if(duration_signal >= 470 && duration_signal < 490)
  {
    character = 'x';
  }
  else if(duration_signal >= 490 && duration_signal < 510)
  {
    character = 'y';
  }
  else if(duration_signal >= 510 && duration_signal < 530)
  {
    character = 'z';
  }
  else if(duration_signal >= 530 && duration_signal < 550)
  {
    character = ' ';
  }
  else
  {
    character = '8';
  }

  return character;
}

void setup() {
  Serial.begin(2400);

  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  
  pinMode(pin_signal_entrant, INPUT);
}

void loop() {
  int duration_signal = lire_signal();
  //Serial.println(analogRead(A0)/100);
  if(duration_signal > 0)
  {
   Serial.print(decode_signal(duration_signal));
  }
}
