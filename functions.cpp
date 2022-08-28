#include "functions.h"


/*!
\file
\brief Исполняемый файл с библиотечными функциями
*/


int PUTS(const char* line)
{
    if (line == NULL) {
        return EOF;
    }
    for(int i = 0; line[i] != '\0'; ++i){
        putchar(line[i]);
    }
    putchar('\n');
    return 1;
}

char* STRCHR(char* str, int symbol)
{
    for (int i = 0; str[i] != '\0'; ++i){
        if (str[i] == symbol){
            return &str[i];
        }
    }
    return NULL;
}

size_t STRLEN(const char* str)
{
    int length = 0;
    while (str[length] != '\0') ++length;

    return length;
}


char* STRCPY (char* destptr, const char* srcpt)
{
    ASSERT(destptr != NULL && srcpt != NULL);

    int i = 0;
    while (srcpt[i] != '\0'){
        destptr[i] = srcpt[i];
        ++i;
    }
    destptr[i] = '\0';

    return destptr;
}

char* STRNCPY (char* destptr, const char* srcpt, size_t num)
{
    ASSERT(destptr != NULL && srcpt != NULL);

    int i = 0;
    while (i < (int) num) {
        if (srcpt[i] == '\0') {
            break;
        }
        destptr[i] = srcpt[i];
        ++i;
    }
    destptr[i] = '\0';

    return destptr;
}


char* STRCAT(char* destptr, const char* srcptr)
{
    ASSERT(destptr != NULL && srcptr != NULL);

    int len = (int) STRLEN(destptr);
    STRCPY(destptr + len, srcptr);

    return destptr;
}


char* STRNCAT(char* destptr, const char* srcptr, size_t num)
{
    ASSERT(destptr != NULL && srcptr != NULL);

    int len = (int) STRLEN(destptr);
    STRNCPY(destptr + len, srcptr, num);

    return destptr;
}


char* FGETS(char* str, int num, FILE* stream)
{
    if (str == NULL || stream == NULL) {
        return NULL;
    }

    char symb = 0;
    for (int i = 0; i != num; ++i){
        fscanf(stream, "%c", &symb);
        str[i] = symb;
        if (symb == '\n') {
            break;
        }
    }
    return str;
}


char* STRDUP(const char* str){
    ASSERT(str != NULL);

    int len = (int) STRLEN(str);
    char* buffer = (char*) malloc(len + 1);
    STRCPY(buffer, str);

    return buffer;
}


size_t GETLINE(char** lineptr, size_t* num, FILE* stream)
{
    ASSERT(num != NULL && stream != NULL);

    int len = (int) *num;
    if (*lineptr == NULL){
        *lineptr = (char*) calloc(len, sizeof(char));
    }

    int symb = 0;
    int curr_len = 0;

    for ( ; symb != '\n'; ++curr_len){
        symb = getc(stream);
        if (symb == EOF){
            return len;
        }
        if (curr_len >= len){
            *lineptr = (char*) realloc(*lineptr, ++len);
        }
        *lineptr[curr_len] = (char) symb;
    }

    *lineptr[curr_len] = '\0';
    return len;
}