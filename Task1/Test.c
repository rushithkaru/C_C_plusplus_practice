#include <stdio.h>
#include "Task1.c"
#include <math.h>

void printInFloat(FloatingPoint f){
    float val = f.mantissa* pow(10,f.exponent);
    printf("Float value %f: \n",val+f.offset);
}

int main(int argc, char const *argv[])
{
    FloatingPoint f = convert(14043,lookUp);
    printf("%d ^ %d\n",f.mantissa,f.exponent);
    printInFloat(f);
    return 0;
}
