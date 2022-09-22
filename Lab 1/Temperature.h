/** Temperature.h
* Class Description:_______________________________________________________
* Class Invariant: myScale == 'C' && myDegrees >= ABSOLUTE_ZERO_CELSIUS ||
* myScale == 'F' && myDegrees >= ABSOLUTE_ZERO_FAHRENHEIT
* Author: AL
* Modified on: Sept. 2022
*/
#ifndef Temperature_H
#define Temperature_H

#include <string>

using namespace std;

class Temperature {

private:
    double myDegrees; // >= ABSOLUTE_ZERO for myScale
    char myScale; // 'F' or 'C'
    
    /** Definition: Temperature validation utility.
    * Returns true if Temperature( degrees, scale ) represents a
    * valid temperature, false otherwise. */
    bool isValidTemperature( const double degrees, const char scale );

public:
    constexpr const double ABSOLUTE_ZERO_FAHRENHEIT = -459.67;
    constexpr const double ABSOLUTE_ZERO_CELSIUS = -273.15;
    
    /** Postcondition: _______________________________________________________. */
    Temperature();
    
    /** Precondition: scale is one of 'f', 'F', 'c', 'C'
    * and degrees is a valid number of degrees for scale.
    * Postcondition: myDegrees == degrees && myScale == (uppercase) scale, if
    * temperature valid otherwise myDegrees == 0.0 && myScale == 'C'.*/
    Temperature( const double degrees, const char scale );
    
    /** Definition: Converts to Fahrenheit.
    * Postcondition: A valid Fahrenheit temperature is returned. */
    Temperature inFahrenheit() const;
    
    /** Definition: Converts to Celsius.
    * Postcondition: A valid Celsius is returned. */
    Temperature inCelsius() const;
    
    /** Definition: Raise this Temperature by amount in degrees (in myScale).
    * Precondition: _______________________________________________________. */
    void raise( const double amount );
}; // end Temperature
#endif
// End of header file
