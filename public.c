
#include <conio.h>
#include <stdio.h>
#include <ctype.h>

#include "public.h"

int strequal(const char* restrict a, const char* restrict b, int size) {
    for (int i = 0; i < size; i++)
        if (a[i] != b[i]) return 0;

    return 1;
}

char* secret_get(char *buf, int len) {
    char ch;
    int index = 0;
    while(index < len) {
        ch = (char) getch();
        if (ch == '\r') {
            putchar('\n');
            break;
        }
        if (ch == '\b' && index > 0){
            index--;
            printf("\b \b");
        }
        else if (isprint(ch)) {
            buf[index] = ch;
            putchar('*');
            index++;
        }
    }
    buf[index] = 0;
    return buf;
}


void bubble_sort(int list[], int N) {
    int i, j;
    int temp = 0;
    for (i = 0; i < N - 1; i++) {
        for (j = 0; j < N - 1 - i; j++) {
            if (list[j] > list[j + 1]) {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}