#include <stdio.h>
#include <stdint.h>
#include "ansicolor.h"

void sp(char* s) {
    printf( ANSI_BK_RED ANSI_BLACK "[NS]:" ANSI_RED ANSI_BK_BLACK " %s" ANSI_GREEN "\n\r",s);
}
