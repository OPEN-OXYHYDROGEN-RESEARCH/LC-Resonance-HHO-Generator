/*
  Localize.h
*/

/*************************************************
 *	Header file for Interface for localized settings resourse files
 *************************************************/


// ensure this library description is only included once
#ifndef LOCALIZE_H
#define LOCALIZE_H

// include header files
#include <Arduino.h>
#include "H2OtoHHO.h"
//#include <fstream>

//#include "H2OtoHHO.h"


/* Define Locale Settings */
#define LOCALE_DIR_PATH "./include/"
#define LOCALE_DEFAULT "EN_JM"

#define LOCALE_EN_JM "EN_JM"
#define LOCALE_EN_US "EN_US"
#define LOCALE_EN_GB "EN_GB"
#define LOCALE_ES_ES "ES_ES"
#define LOCALE_FR_FR "FR_FR"
#define LOCALE_DE_DE "DE_DE"
#define LOCALE_PT_PT "PT_PT"

/*
#if defined(LOCALE_DIR_PATH) && defined(SET_LOCALE)
	#if LOCALE_DIR_PATH != NULL && SET_LOCALE != NULL
		#include (LOCALE_DIR_PATH & "\" & "locale_" & SET_LOCALE & ".h")
	#elseif LOCALE_DIR_PATH != NULL && SET_LOCALE == NULL
		#include (LOCALE_DIR_PATH & "\" & "locale_" & LOCALE_DEFAULT & ".h")
	#elseif	LOCALE_DIR_PATH == NULL && SET_LOCALE != NULL
		#include ("locale_" & SET_LOCALE & ".h")
	#elseif	LOCALE_DIR_PATH == NULL && SET_LOCALE == NULL
		#include ("locale_" & LOCALE_DEFAULT & ".h")
	#endif
#else
	#include ("locale_" & LOCALE_DEFAULT & ".h")
#endif
*/

class Localize
{
public:
	Localize();						 //  Default class constructor
	Localize(const String &locale); // Overridden class constructor
	int SetLocale(const String &new_locale);
	String GetLocale() const;
	//int Reload();

private:
	String _locale;
	//uint _total_menu_count = 0;
	//std::fstream locale_file;
};

//#include "Localize.cpp"

#endif
