#include "functions.h"


/*!
\file
\brief Главный файл проекта с функцией main, по умолчанию проверяет корректность работы функций библиотеки
\authors Zhdanov_EA
*/


int main ()
{
    int test_PUTS = 1;
    int test_STRCHR = 0;
    int test_STRLEN = 0;
    int test_STRCPY = 0;
    int test_STRNCPY = 0;
    int test_STRCAT = 0;
    int test_STRNCAT = 0;
    int test_FGETS = 0;
    int test_STRDUP = 0;
    int test_GETLINE = 0;

    if (test_GETLINE) {
        char *str1 = (char *) calloc(2, sizeof (char));
        char *str2 = (char *) calloc(2, sizeof (char));
        size_t length = 2;
        FILE* stream = fopen("file.txt", "r");
        GETLINE(&str1, &length, stream);
        printf("test_str = %s\n", str1);
        getline(&str2, &length, stream);
        printf("true_str = %s\n", str2);
        if (str1 == str2){
            printf("str1 == str2\n");
        }
        else{
            printf("str1 != str2\n");
        }
    }

    if (test_STRDUP) {
        const char* str = "hello_Russia";
        char* str1 = STRDUP(str);
        char* str2 = strdup(str);
        printf("test_str = %s\n", str1);
        printf("true_str = %s\n", str2);
        if (*str1 == *str2){
            printf("str1 == str2\n");
        }
        else{
            printf("str1 != str2\n");
        }
    }

    if (test_FGETS) {
        char st[] = "";
        char* str1 = st;
        char* str2 = st;
        FILE* stream = fopen("file.txt", "r");
        FGETS(str1, 256, stream);
        fgets(str2, 256, stream);
        printf("test_str = %s", str1);
        printf("true_str = %s", str2);
        if (*str1 == *str2){
            printf("str1 == str2\n");
        }
        else{
            printf("str1 != str2\n");
        }
    }

    if (test_STRNCAT) {
        const char* cnst = "hello_Russia";
        char st1[] = "";
        char st2[] = "";
        char* str1 = st1;
        char* str2 = st2;
        STRNCAT(str1, cnst, 15);
        strncat(str2, cnst, 15);
        printf("test_str = %s\n", str1);
        printf("true_str = %s\n", str2);
        if (*str1 == *str2){
            printf("str1 == str2\n");
        }
        else{
            printf("str1 != str2\n");
        }
    }

    if (test_STRNCPY) {
        const char* cnst = "hello_Russia";
        char st1[] = "";
        char st2[] = "";
        char* str1 = st1;
        char* str2 = st2;
        STRNCAT(str1, cnst, 7);
        strncat(str2, cnst, 7);
        printf("test_str = %s\n", str1);
        printf("true_str = %s\n", str2);
        if (*str1 == *str2){
            printf("str1 == str2\n");
        }
        else{
            printf("str1 != str2\n");
        }
    }

    if (test_STRCAT) {
        const char* cnst = "hello_Russia";
        char st1[] = "";
        char st2[] = "";
        char* str1 = st1;
        char* str2 = st2;
        STRCAT(str1, cnst);
        strcat(str2, cnst);
        printf("test_str = %s\n", str1);
        printf("true_str = %s\n", str2);
        if (*str1 == *str2){
            printf("str1 == str2\n");
        }
        else{
            printf("str1 != str2\n");
        }
    }

    if (test_STRCPY) {
        const char* cnst = "hello_Russia";
        char st1[] = "";
        char st2[] = "";
        char* str1 = st1;
        char* str2 = st2;
        STRCPY(str1, cnst);
        strcpy(str2, cnst);
        printf("test_str = %s\n", str1);
        printf("true_str = %s\n", str2);
        if (*str1 == *str2){
            printf("str1 == str2\n");
        }
        else{
            printf("str1 != str2\n");
        }
    }

    if (test_STRLEN) {
        const char* cnst = "hello_Russia";
        int len1 = (int) STRLEN(cnst);
        int len2 = (int) strlen(cnst);
        printf("test_len = %d\n", len1);
        printf("true_len = %d\n", len2);
        if (len1 == len2){
            printf("len1 == len2\n");
        }
        else{
            printf("len1 != len2\n");
        }
    }

    if (test_STRCHR){
        char* cnst = "hello_Russia";
        char* el1 = STRCHR(cnst, 'R');
        char* el2 = strchr(cnst, 'R');
        if (el1 == el2){
            printf("el1 == el2\n");
        }
        else{
            printf("el1 != el2\n");
        }
    }

    if (test_PUTS){
        char* cnst = "hello_Russia";
        printf("Compare by yourself:\n");
        printf("str1 = ");
        PUTS(cnst);
        printf("str2 = ");
        puts(cnst);
    }
}