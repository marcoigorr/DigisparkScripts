#include "DigiKeyboard.h"

void digiEnd() {
  // Red led when program finishes
  const int led=1;
  pinMode(led, OUTPUT);
  while (1) {
    digitalWrite(led, !digitalRead(led));
    DigiKeyboard.delay(1000);
  }
}

void setup() {
  //empty
}

void loop() {
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(600);
  DigiKeyboard.print("https://youtu.be/dQw4w9WgXcQ?t=0s");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(3500);
  DigiKeyboard.sendKeyStroke(KEY_F11);
  DigiKeyboard.delay(500);
  DigiKeyboard.print('f');  
  for(;;){ /*empty*/ }
  /*
  DigiKeyboard.delay(1000)
  // Clear the Run history and exit
  DigiKeyboard.print("powershell \"Remove-ItemProperty -Path 'HKCU:\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RunMRU' -Name '*' -ErrorAction SilentlyContinue\"");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  // exit
  printText(GetPsz(line2));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  */
}
