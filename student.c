//
// Created by Hello on 2022-01-29.
//

#include <stdio.h>

#include "student.h"


const char password[6] = "233333";

student_info students[N];

int get_student_number(void) {
    int number = 0;
    for (int i = 0; ; i++)
        if (students[i].id != 0)
            number++;
        else
            break;
    return number;
}

void sort_students(char type) {
    int i, j;
    student_info temp;
    switch (type) {
        case '0':
            for (i = 0; i < N - 1; i++) {
                for (j = 0; j < N - 1 - i; j++) {
                    if (students[j].score_chinese + students[j].score_math + students[j].score_english
                            < students[j + 1].score_chinese + students[j + 1].score_math
                            + students[j + 1].score_english) {
                        temp = students[j];
                        students[j] = students[j + 1];
                        students[j + 1] = temp;
                    }
                }
            }
            break;
        case '1':
            for (i = 0; i < N - 1; i++) {
                for (j = 0; j < N - 1 - i; j++) {
                    if (students[j].score_chinese < students[j + 1].score_chinese) {
                        temp = students[j];
                        students[j] = students[j + 1];
                        students[j + 1] = temp;
                    }
                }
            }
            break;
        case '2':
            for (i = 0; i < N - 1; i++) {
                for (j = 0; j < N - 1 - i; j++) {
                    if (students[j].score_math < students[j + 1].score_math) {
                        temp = students[j];
                        students[j] = students[j + 1];
                        students[j + 1] = temp;
                    }
                }
            }
            break;
        case '3':
            for (i = 0; i < N - 1; i++) {
                for (j = 0; j < N - 1 - i; j++) {
                    if (students[j].score_english < students[j + 1].score_english) {
                        temp = students[j];
                        students[j] = students[j + 1];
                        students[j + 1] = temp;
                    }
                }
            }
            break;
        default:
            return;
    }
}

int load_student_info(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
        return 1;

    int i = 0;
    int line_count = 0;
    char line[100];

    char ch;
    while (line[i] != EOF) {
        while (line[i] != '\n' && line[i] != EOF) {
            ch = (char) fgetc(fp);
            if (ch == '\n') {
                line[i] = 0;
                sscanf(line, "%3d:%3d-%3d-%3d", &students[line_count].id,
                       &students[line_count].score_chinese, &students[line_count].score_math,
                       &students[line_count].score_english);
                line_count++;
                i = 0;
            } else if (ch == EOF)
                goto escape;
            else
                line[i++] = ch;

        }
    }

escape:
    fclose(fp);
    return 0;
}

int save_student_info(char *filename) {
    FILE *fp = fopen(filename, "w");
    char line[50];
    if (fp == NULL)
        return 1;
    for (int i = 0; i < N; i++) {
        if (students[i].id != 0) {
            sprintf(line, "%03d:%03d-%03d-%03d\n",students[i].id,
                    students[i].score_chinese, students[i].score_math,
                    students[i].score_english);
            fputs(line, fp);
        }

    }

    fclose(fp);

    return 0;
}

int add_student_info(student_info info) {
    for (int i = 0; i < N; i++) {
        if (students[i].id == 0) {
            students[i].id = info.id;
            students[i].score_chinese = info.score_chinese;
            students[i].score_math = info.score_math;
            students[i].score_english = info.score_english;
            return 0;
        }

    }
    return 1;
}