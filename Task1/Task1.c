//author Rushith Karunaratne

#include "LookUp.h"
#include <stdio.h>

/*Used to multiply values to avoid needing floating point numbers */
#define BASE 10000


/* Function convert_ADC_val_to_pressure
----------------------------------------
* Converts readings from ADC to a pressure value in Pascals
* with a resolution of 10Pa (0.01kPa).

* Pressure values based on lookup table with straight line 
* interpolation when needed.
* 
* Assumes no floating point support so only uses int variables.
*
* \param[in] ADC_val: input ADC value.
* \return pressure: Pressure value in Pa (with resolution of 0.01Kpa) 
*
*/
int convert_ADC_val_to_pressure(int ADC_val){
    //check for lower and upper limits
    if (ADC_val <= lookUp[0][1]){
        return lookUp[0][0]*BASE;
    }
    else if (ADC_val >= lookUp[90][1]){
        return lookUp[90][0]*BASE;
    }

    //check for values inbetween
    for (int i = 0; i < 90 ; i++){
        //Exact matches from the lookup table
        if (ADC_val == lookUp[i][1]){
            return lookUp[i][0]*BASE;
        }
        // Using lookup table values to perform interpolation
        else if (lookUp[i][1] < ADC_val && ADC_val < lookUp[i+1][1]){
            int lowX = lookUp[i][1];
            int upperX = lookUp[i+1][1];
            int lowY = lookUp[i][0];
            //Interpolation via fitting a straight line (y = mx).
            int denominator = upperX - lowX;
            int gradient = BASE/denominator;

            //Difference between closest lower ADC value and reading
            int diff = ADC_val - lowX;
            // Pressure value (interpolated) in Pa.
            int pressure = gradient*diff+BASE*lowY;
            return pressure;
        }
    }
    //Should not reach here
    return -1;
}
