/*
  H2OtoHHO.h
*/

// include this library's header file
#include "H2OtoHHO.h"

/* Define Locale Variables */
// int FuncKey = 0;
// String keyString = "";
// int F_Resonace = 4243;                                                  //Variable for Locked frequency
// int hz = freqmin;
// int scalerg = 0;                                                  //Variable for SLRANGE POT
// int scale = 0;                                                    //Scale variable for manual frequency adjust buttons
// int adjfreq = freq;                                               //Resulting frequency from auto scan and fine tune - firepinto 10/27/14
// int volt = 0;
// int vmax = 0;
// int intval = 0;
// int gateread = 0;
// int gatef = 1;
// int duty = 512;
// int dutyP = 50;
// int minusstate = 0;                                               //Variable for minus button manual frequency adjustment
// int plusstate = 0;                                                //Variable for plus button manual frequency adjustment
// int lastMstate = 0;                                               //last state for minus button
// int lastPstate = 0;                                               //last state for plus button
// int select = 0;                                                   //variable for select button
// int lastselect = 0;                                               //last state of the select button
// int dscan = 0;                                                    //time delay between frequency increments in milliseconds
// int stpscna = 0;                                                  //Aborts scanning when equal to 1
// int stpscnb = 0;                                                  //Aborts scanning when equal to 1
// int menu = 0;                                                     //0=No field; 1=T1 field; 2=T3 field; 3=DY field; 4=DL field; 5=SR MAX field; 6=SR MIN field.

// unsigned long it = 0;
// unsigned long itlcd = 0;
// unsigned long reflcd = 250;                                       // LCD refresh rate mS
// int odd = false;
//---------------------------------------------

/* Define static class data member INSTANCES */
// int H2OtoHHO::keyPress_cur = -1;
//---------------------------------------------

/* Define H2OtoHHO Class Constructor */
H2OtoHHO::H2OtoHHO() : Localize(),
                       LCDKeypad(PDO_LCD_RS, PDO_LCD_ENABLE, PDO_LCD_D4, PDO_LCD_D5, PDO_LCD_D6, PDO_LCD_D7),
                       DFR_Key(),
                       dds_gate(HIGH, PDO_DDS0_RESET, PDO_DDS0_FQ_UD, PDO_DDS0_SERIAL_DATA, PDO_DDS0_W_CLK),  // w_clk, fq_ud, Sdata
                       dds_pulse(HIGH, PDO_DDS1_RESET, PDO_DDS1_FQ_UD, PDO_DDS1_SERIAL_DATA, PDO_DDS1_W_CLK), // w_clk, fq_ud, Sdata
                       localKey(0),
                       keyString("")
{
  // LCDKeypad screen();
  /* Initialize special character sets */
  createChar(CURSOR_SELECT, c_select);
  createChar(CURSOR_LEFT, c_left);
  createChar(CURSOR_UP, c_up);
  createChar(CURSOR_DOWN, c_down);
  createChar(CURSOR_RIGHT, c_right);
  createChar(CUSTOM_LOCK, custom_lock);
  createChar(CUSTOM_WATER_MOLECULE, custom_watermol);
  createChar(CUSTOM_WATER_MOLECULE2, custom_watermol2);

  // this->menuList = NULL;
  // menuList( NULL, NULL )
}
//---------------------------------------------

/* Define H2OtoHHO Class member function used for loading configuration locale settings  */
// int H2OtoHHO::LoadLocale(String locale)
// {

//     // for ( int i=0; i < TOTAL_MENU_COUNT; i++ )
//     //{

//     // MenuItem temp1 = MenuItem{"MENU0_ITEM1", NULL};
//     // MenuItem temp2{"MENU0_ITEM2", NULL};
//     /*
//     this->MainMenuList = {
//       {1, "MENU0_ITEM1"},
//       {2, "MENU0_ITEM2"}
//      };
//      */
//     // std::map<int, String> test;

//     // test[1] = "MENU0_ITEM1";
//     // test[2] = "MENU0_ITEM2";

//     //}

//     return (EXEC_SUCCESS);
// }
//---------------------------------------------

/* Define H2OtoHHO Class member function used for updating the Menu Display Items  */
// int H2OtoHHO::UpdateMenu(int menu_id)
// {

//   return (EXEC_SUCCESS);
// }
//---------------------------------------------

/* Define H2OtoHHO Class member function used for accessing the current function keypress  */
// int H2OtoHHO::getKeyPress()
//{
//	return (this->keyPress_cur);
// }
//---------------------------------------------

/* Main Menu Function
int H2OtoHHO::MainMenu()
{
  int k = 0, exitCode = -1, SelectedItem = 0, keypress= 0;
  String MainItems[4] = {
    " 1. Exit Menu!",
    " 2. Re-Scan Freq.",
    " 3. [Option #2]",
    " 4. Debug Mode" };


    switch ( this->button() )
    {
      //case KEYPAD_RIGHT:
      //  break;

      case KEYPAD_UP:
          if ( SelectedItem > 0 )
          {
            SelectedItem--;
            this->setCursor(0,1);
            this->print( MainItems[SelectedItem] );
            delay(2000);
          }
          //else
           // buzzer.play( NOTE_C4, BuzzerShortTone );

          //exitCode = 0;
        break;

      case KEYPAD_DOWN:
          if ( SelectedItem < 4 )
          {
            SelectedItem++;
            this->setCursor(0,1);
            this->print( MainItems[SelectedItem] );
            delay(2000);
          }
          //else
            //buzzer.play( NOTE_C4, BuzzerShortTone );

             //exitCode = 0;
        break;

      //case KEYPAD_LEFT:
      //  break;

      case KEYPAD_SELECT:
          this->begin(16, 2);
          this->clear();
          this->print("     MAIN");
          this->setCursor(0,1);
          this->print("     MENU");
          delay(3000);

          for (k=0;k<16;k++)
          {
            this->scrollDisplayLeft();
            delay(200);
          }

          MainMenu();

        break;

      default:
        exitCode = 0;
    }

  } while (exitCode!=-1);


  return exitCode;
}
//---------------------------------------------
*/

/* Scans Resonant Frequency */
/*
static int H2OtoHHO::ResonanceScan()
{
  uint32_t lockFreq = 0;

  this->clear();
  this->print("  SCANNING RANGE....  ");

  // Sweep frequency from 'F_Scan_min' to 'F_Scan_max'
  for (uint32_t i = SCAN_FREQ_MIN; i < SCAN_FREQ_MAX; i++)
  {
    this->setCursor(3,1);
    this->print(i);
    this->print(" Hz  ");

    this->setfreq(i);
    this->setfreq(i*10);
  }

  delay(200);
  lockFreq = 4243;
  this->print(" ");
  this->write(CUSTOM_LOCK);
  this->print(" ");
  this->print( lockFreq );
  this->print(" Hz  ");
  delay(2000);

  return lockFreq;
}
*/
//---------------------------------------------

/* Updates Display upon Keypress */
/*
static ExecStatus H2OtoHHO::UpdateKeypress(int keyPress)
{
  //if (keyPress != KEYPAD_NONE)
  //{
    this->clear();
    this->setCursor(0, 0);
    this->print("Current Key:");
    this->setCursor(0, 1);
    this->print(keyPress);
    this->print(" => ");
    this->print(analogRead(0));
    this->print(", ");
    this->print( this->button() );
    delay(1000);
  //}
  return EXEC_SUCCESS;
}
*/
//---------------------------------------------
