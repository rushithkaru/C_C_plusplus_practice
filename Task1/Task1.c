#include "LookUp.h"
#include <stdio.h>

#define UPPER 10000

FloatingPoint convert(int ADC_val,const int lookUp[][2]){
    //check for least or most possible reading
    if (ADC_val == lookUp[0][1]){
        return (FloatingPoint) {lookUp[0][0],0,0};
    }
    else if (ADC_val == lookUp[90][1]){
        return (FloatingPoint) {lookUp[90][0],0,0};
    }

    //check for inbetween values
    for (int i = 0; i < 90 ; i++){
        if (ADC_val == lookUp[i][1]){
            return (FloatingPoint) {lookUp[i][0],0,0};
        }
        else if (lookUp[i][1] < ADC_val && ADC_val < lookUp[i+1][1]){
            int lowX = lookUp[i][1];
            int upperX = lookUp[i+1][1];
            int lowY = lookUp[i][0];
            //Interpolation via fitting a straight line (y = mx + b).

            int den = upperX - lowX;
            int gradient = UPPER/den;

            int diff = ADC_val - lowX;
            FloatingPoint pressure = (FloatingPoint) {gradient*diff,-3,lowY};
            return pressure;
        }
    }
    FloatingPoint f = (FloatingPoint) {23,ADC_val,0};
    return f;
}
