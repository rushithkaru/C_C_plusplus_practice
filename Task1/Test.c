#include <stdio.h>
#include "Task1.c"
#include <math.h>



int main(int argc, char const *argv[])
{
    int f = convert_ADC_val_to_pressure(1900);
    // printInFloat(f);
    printf("%d\n",f);
    return 0;
}
