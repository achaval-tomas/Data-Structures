#include "handlers.h"

void clearConsole(){
    fprintf(stdout, "\033c");
    fflush(stdout);
}