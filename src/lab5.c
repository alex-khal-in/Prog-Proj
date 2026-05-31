#include "lab5.h"
#include <stdio.h>
#include <stdlib.h>
#define N 10
int run_lab5()
{
int x[N];
// массив из N элементов
int rev[N];
int i;
int c = 0;
// ввод массива
printf("Введите массив из 10 целых чисел\n");
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

// сравнение для сортировки по убыванию
int cmp_desc(const void *a, const void *b) {
    int ia = *(int*)a;
    int ib = *(int*)b;
    return ib - ia;   // если ib > ia -> положительное, значит a идёт после b (убывание)
}

// сравнение для сортировки по возрастанию
int cmp_asc(const void *a, const void *b) {
    int ia = *(int*)a;
    int ib = *(int*)b;
    return ia - ib;   // стандартное возрастание
}

int run_lab5_add(void) {
    int x[N];
    int rev[N];
    int i, c;

    // ввод массива x
    for (i = 0; i < N; i++)
        scanf("%d", &x[i]);

    // формирование rev – обратный порядок x
    c = 0;
    for (i = N - 1; i >= 0; i--) {
        rev[c] = x[i];
        c++;
    }

    // сортировка первой половины по убыванию
    qsort(rev, N/2, sizeof(int), cmp_desc);

    // сортировка второй половины по возрастанию
    qsort(rev + N/2, N/2, sizeof(int), cmp_asc);

    // вывод результата
    for (i = 0; i < N; i++)
        printf("%d ", rev[i]);
    printf("\n");

    return 0;
}
