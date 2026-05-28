#include "lab6.h"
#include <stdio.h>
#define K 3
#define N 4
int run_lab6()
{
int x[K][N];
// массив из K на N элементов
int a = 0;
int i, j;
// ввод массива
for( i = 0; i < K; i++ )
    for( j = 0; j < N; j++ )
        scanf("%d", &x[i][j]);


for( i = 0; i < K; i++ ){
    a = 0;
    for( j = 0; j < N/2 ; j++ ){
        if (x[i][j] == x[i][N-1-j])
            a++;
        else
            a = 0;
    if (a == N/2)
        for( j = 0; j < N ; j++ )
        x[i][j] = 0;
    }
}
// вывод массива
for( i = 0; i < K; i++ ){
    for( j = 0; j < N; j++ )
    printf("%4d ", x[i][j]);
    printf("\n");
}
return 0;
}
