/*
  H2OtoHHO.h
*/

// ensure this library description is only included once
#ifndef H2OtoHHO_h
#define H2OtoHHO_h

// include Standard library header files
// #include <Arduino.h>
// #include <queue>
// #include <map>
// #include <Dhcp.h>
// #include <Dns.h>
// #include <WiFi.h>
// #include <WiFiClient.h>
// #include <WiFiServer.h>
// #include <WiFiUdp.h>
// #include <LiquidCrystal.h>

// include Project library header files
//#include "Localize.h"
#include "LCDKeypad\LCDKeypad.h"
#include "DFR_Key\DFR_Key.h"
#include "pitches.h"
#include "Tone.h"
// #include "MenuItem.h"
// #include "include\AD9850\AD9850.h"
#include "AD985X.h"

/* I\O PIN MAPPING SAINSMART LCDKeypad LiquidCrystal 1602 SHIELD  */
#define PDO_LCD_RS 8
#define PDO_LCD_ENABLE 9
#define PDO_LCD_D4 4
#define PDO_LCD_D5 5
#define PDO_LCD_D6 6
#define PDO_LCD_D7 7

/* I\O PIN MAPPING AD9850 MODULE 0- Gate Frequency Generator  */
#define PDO_DDS0_W_CLK 22
#define PDO_DDS0_FQ_UD 23
#define PDO_DDS0_SERIAL_DATA 24
#define PDO_DDS0_RESET 25

/* I\O PIN MAPPING AD9850 MODULE 1- Pulse Frequency Generator */
#define PDO_DDS1_W_CLK 26
#define PDO_DDS1_FQ_UD 27
#define PDO_DDS1_SERIAL_DATA 28
#define PDO_DDS1_RESET 29

/* I\O PIN MAPPING BUZZER MODULE  */
// const uint8_t Buzzer_Pin = 30;
// const unsigned int BuzzerToneFq = NOTE_C4;
// const unsigned long BuzzerShortTone = 500;
// const unsigned long BuzzerLongTone = 1000;

#define FREQ_MIN 1         // Low end of freqency fine tune scale
#define FREQ_MAX 1000      // High end of freqency fine tune scale
#define SCAN_FREQ_MIN 500  // Low end of freqency auto tune scale
#define SCAN_FREQ_MAX 5000 // High end of freqency auto tune scale
// #define KEYPRESS_BUFF_LEN 5									                    //Maximum Keypress History

byte c_right[8] = {
    B00000,
    B00100,
    B00010,
    B11111,
    B11111,
    B00010,
    B00100,
    B00000};

byte c_up[8] = {
    B00100,
    B01110,
    B10101,
    B00100,
    B00100,
    B00100,
    B00100,
    B00100};

byte c_down[8] = {
    B00100,
    B00100,
    B00100,
    B00100,
    B00100,
    B10101,
    B01110,
    B00100};

byte c_left[8] = {
    B00000,
    B00100,
    B01000,
    B11111,
    B11111,
    B01000,
    B00100,
    B00000};

byte c_select[8] = {
    B00000,
    B01110,
    B11111,
    B11111,
    B11111,
    B11111,
    B01110,
    B00000};

byte custom_lock[8] = { // custom character, it's a lock
    B01110,
    B10001,
    B10001,
    B11111,
    B11011,
    B11011,
    B11111,
    B00000};

byte custom_watermol[8] = { // custom character, it's a Water Molecule
    B11000,
    B11000,
    B00110,
    B01111,
    B01111,
    B00110,
    B11000,
    B11000};

byte custom_watermol2[8] = { // custom character, it's a Water Molecule
    B10100,
    B11100,
    B10110,
    B01111,
    B01111,
    B10110,
    B11100,
    B10100};

/* CREATE BUZZER CLASS INSTANCE */
// Tone buzzer[1];
// buzzer[0].begin(Buzzer_Pin);

/* Define local constant definitions  */
// #define EXEC_SUCCESS 0
// #define EXEC_FAILED -1
enum ExecStatus
{
  EXEC_FAILED = -1,
  EXEC_SUCCESS = 0
};

// library interface description
enum CustomLCDIcons
{
  CURSOR_SELECT,
  CURSOR_LEFT,
  CURSOR_UP,
  CURSOR_DOWN,
  CURSOR_RIGHT,
  CUSTOM_LOCK,
  CUSTOM_WATER_MOLECULE,
  CUSTOM_WATER_MOLECULE2
};

class H2OtoHHO : public  LCDKeypad, DFR_Key //Localize,
{
public:
  H2OtoHHO();
  // enum SupportedLocale { EN_US, EN_JM };
  // int LoadLocale( String locale );
  // int UpdateMenu(int menu_id);
  // static ExecStatus ResonanceScan();
  // static ExecStatus UpdateKeypress(int keypress);
  // int getKeyPress();
  AD9850 dds_gate, dds_pulse;
  // const LCDKeypad lcd;
  // const DFR_Key keypad;
  //  typedef std::map<int, String> SubMenuList;
  //  struct MenuItem
  //{
  //    String itemName;
  //    SubMenuList *SubMenu;
  //  };
  //  std::map<int, String> MainMenuList;
  //  MenuItem menuList;

private:
  int localKey;
  String keyString;
  // int keyPress_cur = -1;
  //, keyPress_buffer[KEYPRESS_BUFF_LEN];
};

#endif
