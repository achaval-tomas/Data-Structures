#include "handlers.h"

void clearConsole()
{
    printf("\033c");
    fflush(stdout);
}