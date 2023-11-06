#include "handlers.h"

/*  PRINT INFO OF ARRAY (size and current state)  */
void printArrayInfo(MyArray* arr){
    fprintf(stdout, "\n\t\tCURRENT ARRAY: ");
    printArray(arr);
    fprintf(stdout, "\t\tSIZE: %d\n", arraySize(arr));
    fflush(stdout);
}

/*  PRINT ARRAY MENU  */
void printArrayMenu(MyArray* arr){
        fprintf(stdout, "\n- MAIN MENU -> ARRAY MENU\n");
        printArrayInfo(arr);
        fprintf(stdout, "\t\tAdd at index: 'a'\n"
                        "\t\tRemove element: 'r'\n"
                        "\t\tPrint Array: 'p'\n"
                        "\t\tExit: 'e'\n"
                        "\t\tSelect Option: ");
        fflush(stdout);
}

void handleArray(){
    MyArray* arr = init();
    char quit = 0;
    while (!quit){

        printArrayMenu(arr);

        /*  HANDLE ARRAY MENU  */
        switch(getchar()){
            case 'a':
                int elem, idx;
                fprintf(stdout, "\n\t\t\tSelect elem: ");
                fflush(stdin);
                fscanf(stdin, " %d", &elem);

                fprintf(stdout, "\n\t\t\tSelect Index: ");
                fflush(stdin);
                fscanf(stdin, " %d", &idx);

                // PLACE ELEM AT INDEX, MAKING SPACE IF NEEDED.
                setInRange(arr, idx, idx+1, elem);
                break;
            
            case 'r':
                int val;
                fprintf(stdout, "\n\t\t\tSelect elem to remove: ");
                fflush(stdin);
                fscanf(stdin, " %d", &val);
                
                // REMOVE ALL INSTANCES OF SELECTED ELEMENT
                removeMatches(arr, val);
                break;

            case 'p':
                printArrayInfo(arr);
                break;

            case 'e':
                quit = 1;
                freeArray(arr);
                fflush(stdin);
                fflush(stdout);
                break;

            default:
                break;
        }

    }
}