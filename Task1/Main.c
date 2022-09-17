/*
* Test code to excercise function
* Set value of ADC_val to test function with various inputs
*  Author: Rushith Karunaratne
* Compiled on Mac with: gcc -Wall -o Main.a Main.c
*/

#include <stdio.h>
#include "Task1.c"
#include <math.h>

int main(int argc, char const *argv[])
{
    //Edit this to change input
    int ADC_val = 11333;


    int f = convert_ADC_val_to_pressure(ADC_val);
    printf("%d Pa\n",f);
    printf("Or \n");
    printf("%0.3f kPa\n",(float) f*1/BASE);
    return 0;
}
