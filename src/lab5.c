#include "lab5.h"
#include <stdio.h>
#define N 10
int run_lab5()
{
int x[N];
// массив из N элементов
int rev[N];
int i;
int c = 0;
// ввод массива
for( i = 0; i < N; i++ )
    scanf("%d", &x[i]);
for( i = N-1; i >= 0; i-- ) {
    rev[c] = x[i];
    c++;
}
// вывод массива
for( c = 0; c < N; c++ )
printf("%d ", rev[c]);
printf("\n");
return 0;
}
