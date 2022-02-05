
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "public.h"
#include "student.h"


#define GO_BACK \
                puts("Press any key to continue...");\
                fflush(NULL);\
                key = (char) getch();\
                goto choices

extern char password[6];
extern student_info students[500];

int login(void) {
    char password_buf[32];
    return strequal(secret_get(password_buf, 32), password, 6);
}

char page_welcome(void);

char page_edit(void);

char page_query(void);

char page_load(void);

int main(void) {
    char next_page;
    printf("Enter password: ");

    load_student_info(DEFAULT_FILENAME);
    sort_students('0');

//    student_info tmp;
//    tmp.id = 222;
//    tmp.score_chinese = 2;
//    add_student_info(tmp);
//    save_student_info(DEFAULT_FILENAME);

    while (1)
        if (login())
            break;
        else {
            system("cls");
            printf("Authorization failed.\nEnter password again:");
        }


welcome:
    next_page = page_welcome();
    switch (next_page) {
        case '1':
            next_page = page_edit();
            break;
        case '2':
            next_page = page_query();
            break;
        case '3':
            next_page = page_load();
            break;
        default:
            ;
    }

    if (next_page == 'q')
            goto welcome;
    else {

    }


    system("pause");


    return 0;
}


char page_welcome(void) {
    char key;
    system("cls");
    puts("+--------------------------------+");
    puts("|             welcome!           |");
    puts("| press this key to continue:    |");
    puts("|   1) Edit student information  |");
    puts("|   2) Query student information |");
    puts("|   3) Save student information  |");
    puts("|   q) quit                      |");
    puts("+--------------------------------+");
    while (1) {
        key = (char) getch();
        switch (key) {
            case '1':
            case '2':
            case '3':
                return key;
            case 'q':
                exit(EXIT_SUCCESS);
            default:
                continue;
        }
    }
}


char page_edit(void) {
    char key;
    student_info tmp_student;


choices:
    system("cls");
    puts("+--------------------------------+");
    puts("|            edit page           |");
    puts("| what do you want?              |");
    puts("|    1) add a new information    |");
    puts("|    2) delete a information     |");
    puts("|    3) modify a information     |");
    puts("|    q) quit this page           |");
    puts("+--------------------------------+");
    while (1) {
        key = (char) getch();
        switch (key) {
            case '1':
                system("cls");
                printf("Enter student id:");
                if (scanf("%d", &tmp_student.id) != 1)
                    tmp_student.id = 0;
                for (int i = 0; i < N; i++)
                    if (tmp_student.id == 0 || tmp_student.id == students[i].id) {
                        puts("Sorry, that student id is already in database.");
                        puts("If you want to change it, back to the page and press '3'.");
                        GO_BACK;
                    }
                puts("Enter score of Chinese, math and English");
                if (scanf("%d %d %d", &tmp_student.score_chinese,
                          &tmp_student.score_math, &tmp_student.score_english) != 3)
                    puts("Not enough information");
                else
                    for (int i = 0; ; i++)
                        if (students[i].id == 0) {
                            students[i] = tmp_student;
                            puts("Operation successful.");
                            break;
                        }
                GO_BACK;
            case '2':
                system("cls");
                printf("Enter student id:");
                if (scanf("%d", &tmp_student.id) != 1)
                    tmp_student.id = 0;
                for (int i = 0; i < N; i++) {
                    if (tmp_student.id == 0 || tmp_student.id == students[i].id) {
                        students[i].id = 0;
                        puts("Successful delete from database.");
                        GO_BACK;
                    }
                }
                puts("This student_id not found");
                GO_BACK;
            case '3':
                system("cls");
                printf("Enter student id:");
                if (scanf("%d", &tmp_student.id) != 1)
                    tmp_student.id = 0;
                for (int i = 0; i < N; i++) {
                    if (tmp_student.id == 0 || tmp_student.id == students[i].id) {
                        puts("Enter score of Chinese, math and English");
                        if (scanf("%d %d %d", &students[i].score_chinese,
                                  &students[i].score_math, &students[i].score_english) != 3)
                            puts("Not enough information");
                        else
                            printf("successful modify student %d.\n",students[i].id);
                        GO_BACK;
                    }
                }
                puts("This student id not found");
                GO_BACK;
            case 'q':
                return 'q';
            default:
                continue;
        }
    }
}

char page_query(void) {
    char key;
    student_info tmp_student;
choices:
    system("cls");
    puts("+--------------------------------+");
    puts("|           query page           |");
    puts("| what do you want?              |");
    puts("|    1) query by student id      |");
    puts("|    2) sort by student score    |");
    puts("|    3) show student ranking     |");
    puts("|    q) quit this page           |");
    puts("+--------------------------------+");

    while (1) {
        key = (char) getch();
        switch (key) {
            case '1':
                system("cls");
                printf("Enter student id:");
                if (scanf("%d", &tmp_student.id) != 1)
                    tmp_student.id = 0;
                for (int i = 0; students[i].id != 0; i++) {
                    if (tmp_student.id == students[i].id) {
                        printf("student %d :\n    Chinese: %d\n"
                               "    math: %d\n    English: %d\n",
                               students[i].id, students[i].score_chinese,
                               students[i].score_math, students[i].score_english);
                        GO_BACK;
                    }
                }
                puts("This student id not found");
                GO_BACK;

            case '2':
                system("cls");
                puts("+--------------------------------+");
                puts("| sort by want?                  |");
                puts("|    0) all scores               |");
                puts("|    1) score: Chinese           |");
                puts("|    2) score: math              |");
                puts("|    3) score: English           |");
                puts("|    q) quit this page           |");
                puts("+--------------------------------+");
                while (1) {
                    key = (char) getch();
                    switch (key) {
                        case '0':
                        case '1':
                        case '2':
                        case '3':
                            sort_students(key);
                            puts("Success to sort.");
                            GO_BACK;
                        default:
                            continue;
                    }
                }
            case '3':
                system("cls");
                puts("Top 10 students information:\n");
                for (int i = 0; i < 10; i++) {
                    printf("%2d: student id: %d\n"
                           "     Chinese score: %d\n"
                           "     math score: %d\n"
                           "     English score: %d\n",
                           i + 1, students[i].id,students[i].score_chinese,
                           students[i].score_math, students[i].score_english);
                }
                GO_BACK;
            case 'q':
                return 'q';
            default:
                ;
        }

        break;
    }
    return key;
}

char page_load(void) {
    char key;
    int file_status;
    char filename_buf[256];
    /* 0: successful load
     * -1: failed to save
     * 1: failed to load
     * */
    choices:
    system("cls");
    puts("+--------------------------------+");
    puts("|            file page           |");
    puts("| what do you want?              |");
    puts("|    1) load from local file     |");
    puts("|    2) load from default file   |");
    puts("|    3) save to local file       |");
    puts("|    4) save to default file     |");
    puts("|    q) quit this page           |");
    puts("+--------------------------------+");
    while (1) {
        key = (char) getch();
        switch (key) {
            case '1':
                system("cls");
                printf("Enter filename:\n    ");
                file_status = load_student_info(fgets(filename_buf, 32, stdin));
                break;
            case '2':
                system("cls");
                file_status = load_student_info(DEFAULT_FILENAME);
                break;
            case '4':
                system("cls");
                file_status = save_student_info(DEFAULT_FILENAME);
                break;
            case '3':
                system("cls");
                printf("Enter filename:\n    ");
                file_status = save_student_info(fgets(filename_buf, 32, stdin));
                break;
            case 'q':
                return 'q';
            default:
                file_status = 100;
        }
        switch (file_status) {
            case 0:
                puts("Success to load/save from local file");
                GO_BACK;
            case 1:
                puts("Failed to load from local file");
                GO_BACK;
            case 2:
                puts("Failed to save to local file");
                GO_BACK;
            default:
                puts("An error has occurred");
                GO_BACK;
        }
    }
}