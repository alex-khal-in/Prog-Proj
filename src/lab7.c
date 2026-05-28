#include "lab7.h"
#include <stdio.h>

int run_lab7(void)
{
    long N;                  // исходное число
    unsigned long y;         // беззнаковая копия для побитовой работы
    unsigned long result = 0; // результат после отражения битов
    int i;
    int bits = sizeof(unsigned long) * 8;

    printf("N = ");
    scanf("%x", &N);

    y = (unsigned long)N;

    // Зеркальное отражение битов
    for (i = 0; i < bits; i++) {
        result = (result << 1) | (y & 1); // сдвигаем результат влево и добавляем младший бит y
        y >>= 1;
    }

    printf("result: %lx\n", result); // вывод результата в шестнадцатеричном виде

    return 0;
}
