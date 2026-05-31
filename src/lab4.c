#include "lab4.h"
#include <stdio.h>

#define YES 1
#define NO 0
#define MAXLINE 1000

int N;

void process_line(char buffer[]);

// Функция для записи удалённого слова в файл
void write_discarded_word(const char buffer[], int start, int end)
{
    // Открываем файл в режиме добавления (создаётся, если не существует)
    static FILE *file = NULL;
    if (file == NULL) {
        file = fopen("discarded.txt", "a");
        if (file == NULL) {
            fprintf(stderr, "Error opening discarded.txt\n");
            return;
        }
    }
    // Записываем слово
    for (int k = start; k < end; k++) {
        fputc(buffer[k], file);
    }
    // Добавляем перевод строки, чтобы каждое слово было на новой строке
    fputc('\n', file);
}

int run_lab4()
{
    char line[MAXLINE];

    // Ввод максимальной длины слова
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
    int flag = NO;   // YES, если находимся внутри слова
    int i = 0;       // индекс чтения из исходной строки
    int pos = 0;     // индекс записи в результирующую строку
    int start = 0;   // начало текущего слова в исходной строке
    int length;      // длина текущего слова

    do {
        char c = buffer[i];

        // Проверка, является ли символ разделителем
        if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0') {
            // Если только что закончилось слово
            if (flag == YES) {
                length = i - start;   // длина слова
                // Если длина не превышает N, копируем слово
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
            // Начало нового слова
            if (flag == NO) {
                start = i;
                flag = YES;
            }
        }
        i++;
    } while (buffer[i-1] != '\0');
}

void process_line_add(char buffer[])
{
    int flag = NO;   // YES, если находимся внутри слова
    int i = 0;       // индекс чтения из исходной строки
    int pos = 0;     // индекс записи в результирующую строку
    int start = 0;   // начало текущего слова в исходной строке
    int length;      // длина текущего слова

    do {
        char c = buffer[i];

        // Если встретили разделитель
        if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0') {
            if (flag == YES) {
                length = i - start;
                if (length <= N) {
                    // Слово подходит – копируем его
                    for (int j = start; j < i; j++) {
                        buffer[pos++] = buffer[j];
                    }
                } else {
                    // Слово слишком длинное – отбрасываем (не копируем)
                    // Записываем его в файл
                    write_discarded_word(buffer, start, i);
                }
                flag = NO;
            }
            // Копируем разделитель (включая пробелы и \0)
            buffer[pos++] = c;
        }
        else {
            // Не разделитель – часть слова
            if (flag == NO) {
                start = i;   // запоминаем начало нового слова
                flag = YES;
            }
        }
        i++;
    } while (buffer[i-1] != '\0');
}

int run_lab4_add(void)
{
    char line[MAXLINE];

    printf("Enter N: ");
    scanf("%d", &N);
    // Очистка буфера после scanf
    while (getchar() != '\n');

    printf("Enter string: ");
    gets(line);   // допускается по условию (но небезопасно)

    process_line_add(line);
    puts(line);

    return 0;
}
