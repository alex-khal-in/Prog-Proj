#include <stdio.h>
#include <stdlib.h> // Для system() и exit()
// Подключаем заголовочные файлы наших модулей
#include "lab1.h"
#include "lab2.h"
#include "lab3.h"
#include "lab4.h"
#include "lab5.h"
#include "lab6.h"
#include "lab7.h"
void print_menu() {
printf("\n--- Главное меню ---\n");
printf("1. Задание 1 (Линейные алгоритмы)\n");
printf("2. Задание 2 (Циклические алгоритмы)\n");
printf("3. Задание 3 (Обработка потока символов)\n");
printf("4. Задание 4 (Обработка символьных строк)\n");
printf("5. Задание 5 (Одномерные массивы)\n");
printf("6. Задание 6 (Двумерные массивы)\n");
printf("7. Задание 7 (Поразрядная обработка целых чисел)\n");
printf("8. Доп. задание 1\n");
printf("9. Доп. задание 3\n");
printf("0. Выход\n");
printf("Ваш выбор: ");
}

int main() {
int choice;
int running = 1;
while (running){
    print_menu();
    // Проверка на корректность ввода
    if (scanf("%d", &choice) != 1) {
        printf("Ошибка ввода. Пожалуйста, введите число.\n");
        // Очищаем буфер ввода
        while (getchar() != '\n');
        continue;
    }
    switch (choice) {
        case 1: {
                printf("\n--- Задание 1: Линейные алгоритмы ---\n");
                run_lab1();
            break;
        }
        case 2: {
            printf("\n--- Задание 2: Циклические алгоритмы ---\n");
            run_lab2();
        break;
        }
        case 3: {
            printf("\n--- Задание 3: Обработка потока символов ---\n");
            run_lab3();
        break;
        }
        case 4: {
            printf("\n--- Задание 4: Обработка символьных строк ---\n");
            run_lab4();
        break;
        }
        case 5: {
            printf("\n--- Задание 5: Одномерные массивы ---\n");
            run_lab5();
        break;
        }
        case 6: {
            printf("\n--- Задание 6: Двумерные массивы ---\n");
            run_lab6();
            break;
        }
         case 7: {
            printf("\n--- Задание 7: Поразрядная обработка целых чисел ---\n");
            run_lab7();
            break;
        }
        case 8: {
            printf("\n--- Доп. задание 1 ---\n");
            run_lab1_add();
            break;
        }
        case 9: {
            printf("\n--- Доп. задание 3 ---\n");
            run_lab3_add();
            break;
        }
        case 0: {
            printf("Выход из программы.\n");
            running = 0;
        break;
        }
        default: {
            printf("Неверный выбор. Пожалуйста, выберите пункт из меню.\n");
            break;
        }
    }
}
return 0;
}
