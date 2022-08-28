#include "functions.h"


int PUTS(const char* line)
{
    if (line == NULL) {
        return EOF;
    }

    // TODO: think how to implement puts with syscalls (like write),
    //       or at least something smarter...
    printf("%s\n", line);

    return 1;
}

char* STRCHR(char* string, int symbol)
{
    for (int i = 0; string[i] != '\0'; ++i){
        if (string[i] == symbol){
            return &string[i];
        }
    }
    return NULL;
}

size_t STRLEN(const char* string)
{
    int length = 0;
    while (string[length] != '\0') ++length;

    return length;
}


char* STRCPY (char* destination, const char* source)
{
    ASSERT(destination != NULL && source != NULL);

    int i = 0;
    while (source[i] != '\0'){
        destination[i] = source[i];
        // TODO: think if this can be made faster with memcpy
        ++i;
    }
    destination[i] = '\0';

    return destination;
}

char* STRNCPY (char* destination, const char* source, size_t n)
{
    ASSERT(destination != NULL && source != NULL);

    int i = 0;
    while (i < (int) n) {
        if (source[i] == '\0') {
            break;
        }
        destination[i] = source[i];
        ++i;
    }
    destination[i] = '\0';

    return destination;
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


char* FGETS(char* string, int num, FILE* filestream)
{
    if (string == NULL || filestream == NULL) {
        return NULL;
    }

    char symb = 0;
    for (int i = 0; i != num; ++i){
        fscanf(filestream, "%c", &symb);
        string[i] = symb;
        if (symb == '\n') {
            break;
        }
    }
    return string;
}


char* STRDUP(const char* str){
    ASSERT(str != NULL);

    int len = (int) STRLEN(str);
    char* buffer = (char*) malloc(len + 1);
    STRCPY(buffer, str);

    return buffer;
}


size_t getline(char** lineptr, size_t* n, FILE* stream);