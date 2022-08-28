#include "functions.h"


/*!
\file
\brief Главный файл проекта с функцией main
\authors Zhdanov_EA
*/


int main ()
{   
    char *str = (char *)calloc(2, sizeof (char));
    size_t length = 2;

    GETLINE(&str, &length, stdin);
    // puts(str);
    // PUTS(string);
}