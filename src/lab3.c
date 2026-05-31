#include "lab3.h"
#include <stdio.h>

#define YES 1
#define NO 0

int run_lab3()
{
int c;
int in_word;
int has_vowel;
int cnt;
printf("Нахождение кол-ва слов, содержащих гласные");
in_word = NO;
has_vowel = NO;
cnt = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '.' || c == ',' || c == '\n')
        {
            if (in_word == YES)
            {
                if (has_vowel == YES)
                {
                    cnt+=1 ;
                }
            }
            // Сбрасываем флаги для следующего слова
            in_word = NO;
            has_vowel = NO;
        }
        else
        {
            in_word = YES;

            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            {
                has_vowel = YES;
            }
        }
    }

    if (in_word == YES && has_vowel == YES) {
        cnt+=1 ;
    }

    printf("Number of words containing vowels: %d\n", cnt);
    return 0;
}


char invert_case(char ch) {
    if (ch >= 'a' && ch <= 'z')
        return ch - 'a' + 'A';
    else if (ch >= 'A' && ch <= 'Z')
        return ch - 'A' + 'a';
    else
        return ch;
}

int run_lab3_add(void) {
    int c;

    while ((c = getchar()) != EOF) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                putchar(invert_case(c));
            } else {
                putchar(c);
            }
        }
return 0;
}
