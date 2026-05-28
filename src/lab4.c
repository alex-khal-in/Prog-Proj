#include "lab4.h"
#include <stdio.h>

#define YES 1
#define NO 0
#define MAXLINE 1000

int N;

void process_line(char buffer[]);

int run_lab4()
{
    char line[MAXLINE];

    // ¬вод максимальной длины слова
    printf("Enter N: ");
    scanf("%d", &N);

    while (getchar() != '\n');

    printf("Enter string: ");
    fgets(line, 1000, stdin);

    process_line(line);
    puts(line);

    return 0;
}

void process_line(char buffer[])
{
    int flag = NO;   // YES, если находимс€ внутри слова
    int i = 0;       // индекс чтени€ из исходной строки
    int pos = 0;     // индекс записи в результирующую строку
    int start = 0;   // начало текущего слова в исходной строке
    int length;      // длина текущего слова

    do {
        char c = buffer[i];

        // ѕроверка, €вл€етс€ ли символ разделителем
        if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0') {
            // ≈сли только что закончилось слово
            if (flag == YES) {
                length = i - start;   // длина слова
                // ≈сли длина не превышает N, копируем слово
                if (length <= N) {
                    for (int j = start; j < i; j++) {
                        buffer[pos++] = buffer[j];
                    }
                }
                flag = NO;
            }
            buffer[pos++] = c;
        }
        else {
            // Ќачало нового слова
            if (flag == NO) {
                start = i;
                flag = YES;
            }
        }
        i++;
    } while (buffer[i-1] != '\0');
}
