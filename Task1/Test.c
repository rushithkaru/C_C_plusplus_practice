#include <stdio.h>
#include "Task1.c"

int main(int argc, char const *argv[])
{
    FloatingPoint f = convert(3,lookUp);
    printf("%d ^ %d\n",f.exponent,f.mantissa);
    return 0;
}
