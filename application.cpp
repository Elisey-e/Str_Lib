#include "functions.h"


/*!
\file
\brief Главный файл проекта с функцией main
\authors Zhdanov_EA
*/


#include <stdio.h>
#include <string.h>
int main(void)
{
    char str[80];
    STRCPY(str, "this is an example");
    PUTS(str);
    return 0;
}