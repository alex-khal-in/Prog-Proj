#include "lab2.h"
#include <stdio.h>

int run_lab2()
{
    float s;
    float a;
    int n;
    int i;
    int sign;
    printf("n=");
    scanf("%d", &n);
    s = 0;
    sign = 1;
    i = 0;
    while( i < n )
{
    a = (float)(3+i)/(1+i*3);
    s += a*sign;
    sign = -sign;
    i += 1;
    printf("a = %f\n", a);
    printf("s = %f\n", s);
 }
// вывод результата
    printf("s = %f\n", s);
    return 0;
}
