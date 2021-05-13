#include <Arduino.h>

char pin_power_laser = 2;

int convert_to_signal(char character)
{
  int duration_signal = 0;
  
  switch(character)
  {
    case 'a':
      duration_signal = 20;
      break;
    case 'b':
      duration_signal = 40;
      break;
    case 'c':
      duration_signal = 60;
      break;
    case 'd':
      duration_signal = 80;
      break;
    case 'e':
      duration_signal = 100;
      break;
    case 'f':
      duration_signal = 120;
      break;
    case 'g':
      duration_signal = 140;
      break;
    case 'h':
      duration_signal = 160;
      break;
    case 'i':
      duration_signal = 180;
      break;
    case 'j':
      duration_signal = 200;
      break;
    case 'k':
      duration_signal = 220;
      break;
    case 'l':
      duration_signal = 240;
      break;
    case 'm':
      duration_signal = 260;
      break;
    case 'n':
      duration_signal = 280;
      break;
    case 'o':
      duration_signal = 300;
      break;
    case 'p':
      duration_signal = 320;
      break;
    case 'q':
      duration_signal = 340;
      break;
    case 'r':
      duration_signal = 360;
      break;
    case 's':
      duration_signal = 380;
      break;
    case 't':
      duration_signal = 400;
      break;
    case 'u':
      duration_signal = 420;
      break;
    case 'v':
      duration_signal = 440;
      break;
    case 'w':
      duration_signal = 460;
      break;
    case 'x':
      duration_signal = 480;
      break;
    case 'y':
      duration_signal = 500;
      break;
    case 'z':
      duration_signal = 520;
      break;
    case ' ':
      duration_signal = 540;
      break;
    default:
      duration_signal = 0;
      break;
  }

  return duration_signal;
}

void start_signal(String message)
{
  int i = 0;
  while(message[i] != '\0')
  {
    delay(30);
    digitalWrite(pin_power_laser, HIGH);
    delay(convert_to_signal(message[i]));
    digitalWrite(pin_power_laser, LOW);
    delay(30);
    i++;
  }
}

void setup() {
  pinMode(pin_power_laser, OUTPUT);
  digitalWrite(pin_power_laser, LOW);
  
}

void loop() {
  delay(5000);
  start_signal("bonjour ce message est transmis par signaux laser ");
}
