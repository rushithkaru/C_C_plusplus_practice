#include "LookUp.h"
#include <stdio.h>

FloatingPoint convert(int ADC_val,const int lookUp[][2]){

    for (int i = 0; i < 91 ; i++){
        printf("%d\n",lookUp[i][0]);
    }

    FloatingPoint f = (FloatingPoint) {23,ADC_val};
    return f;
}
