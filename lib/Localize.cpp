/*
  Localize.cpp
*/

/*************************************************
 *	Header file for Interface for localized settings resourse files
 *************************************************/

// Include Header files
#include <Arduino.h>
#include "H2OtoHHO.h"

// #include <fstream>

#include "Localize.h"
//#include "Localize.h"

/* Define H2OtoHHO Class member function used for loading configuration locale settings  */
Localize::Localize()
{
    Localize(LOCALE_DEFAULT);
}
//---------------------------------------------

/* Define H2OtoHHO Class member function used for loading configuration locale settings  */
Localize::Localize(const String &locale)
{
    _locale = locale;
}
//---------------------------------------------

/* Define H2OtoHHO Class member function used for loading configuration locale settings  */
// int Localize::Reload()
// {
//     return this.locale_file.open(String(LOCALE_DIR_PATH).concat(locale).concat(".xml"));
// }
//---------------------------------------------

/* Define H2OtoHHO Class member function used to set locale */
int Localize::SetLocale(const String &new_locale)
{
    _locale = new_locale;

    return EXEC_SUCCESS;
}
//---------------------------------------------

/* Define H2OtoHHO Class member function used to set locale */
String Localize::GetLocale() const
{
    return _locale;
}
//---------------------------------------------
