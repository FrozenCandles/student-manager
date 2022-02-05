//
// Created by Hello on 2022-01-29.
//

#ifndef STDC_STUDENT_H
#define STDC_STUDENT_H

typedef struct {
    int id;
    int score_chinese;
    int score_math;
    int score_english;
} student_info;

#define N 500
#define DEFAULT_FILENAME "save.studentinfo"

int get_student_number(void);

void sort_students(char type);

int load_student_info(char *filename);

int save_student_info(char *filename);

int add_student_info(student_info info);

#endif //STDC_STUDENT_H
