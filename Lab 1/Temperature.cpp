/** Temperature.cpp
* Class Description: ditto
* Class Invariant: myScale == 'C' && myDegrees >= ABSOLUTE_ZERO_CELSIUS ||
* myScale == 'F' && myDegrees >= ABSOLUTE_ZERO_FAHRENHEIT
* Author: AL
* Modified: Sept. 2022
*/
#include <iostream>
#include <cctype>
#include "Temperature.h"
using namespace std;

/** See contract in Temperature.h */
Temperature::Temperature() : myDegrees(0.0), myScale('C') {}

/** contract */
Temperature::Temperature(____________________, __________________) 
{
 if ( isValidTemperature( degrees, scale ) ) 
 {
    myDegrees = degrees;
    myScale = toupper( scale );
 }
}

/** See contract in Temperature.h */
Temperature Temperature::inFahrenheit( ) const 
{
 Temperature result;

 if ( myScale == 'F' )
 result = Temperature( myDegrees, 'F' );
 else if ( myScale == 'C' )
 result = Temperature( myDegrees * 1.8 + 32.0, 'F' );

 return result;
}

/** See contract in Temperature.h */
Temperature Temperature::inCelsius( ) const 
{
 Temperature result;

 if ( myScale == 'C' )
 result = Temperature( myDegrees, 'C' );
 else if ( myScale == 'F' )
 result = Temperature( ( myDegrees - 32.0 ) / 1.8, 'C' );

 return result;
}

/** See contract in Temperature.h */
void Temperature::raise( const double amount ) 
{
 double newDegrees = myDegrees + amount;
 if ( isValidTemperature( newDegrees, myScale ) )
 myDegrees = newDegrees;
}

/** See contract in Temperature.h */
bool Temperature::isValidTemperature( const double degrees, const char scale ) {
 bool result = false;
 if ( scale == 'C' || scale == 'c' )
    result = degrees >= ABSOLUTE_ZERO_CELSIUS;
 else if ( scale == 'F' || scale == 'f' )
    result = degrees >= ABSOLUTE_ZERO_FAHRENHEIT;

 return result;
}
// End of implementation file