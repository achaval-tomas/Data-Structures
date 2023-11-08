#include "handlers.h"
#include "../Array/array.h"

/*  COMPARE FUNCTION FOR QUICK SORT  */
bool cmp(int a, int b){return a<=b;}

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
        fprintf(stdout, "\n\t\tAdd at index: 'a'\n"
                        "\t\tRemove element: 'r'\n"
                        "\t\tSet in Range: 'R'\n"
                        "\t\tSwap Indexes: 's'\n"
                        "\t\tRemove at Index: 'i'\n"
                        "\t\tSet all to Zero: 'z'\n"
                        "\t\tQuick Sort the array: 'q'\n"
                        "\t\tPrint Array: 'p'\n"
                        "\t\tExit: 'e'\n"
                        "\t\tSelect Option: ");
        fflush(stdout);
}

void handleArray(){
    MyArray* arr = init();
    char quit = 0, choice = 0;
    int elem = 0, idx = 0, idx2 = 0;
    while (!quit){

        clearConsole();
        printArrayMenu(arr);
        fflush(stdin);
        fscanf(stdin, " %c", &choice);  // Get user input.

        switch(choice){
            case 'a':

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

                fprintf(stdout, "\n\t\t\tSelect elem to remove: ");
                fflush(stdin);
                fscanf(stdin, " %d", &elem);
                
                // REMOVE ALL INSTANCES OF SELECTED ELEMENT
                removeMatches(arr, elem);
                break;

            case 'R':

                fprintf(stdout, "\n\t\t\tSelect elem to add: ");
                fflush(stdin);
                fscanf(stdin, " %d", &elem);

                fprintf(stdout, "\n\t\t\tStart of range (>= 0): ");
                fflush(stdin);
                fscanf(stdin, " %d", &idx);

                fprintf(stdout, "\n\t\t\tEnd of range: ");
                fflush(stdin);
                fscanf(stdin, " %d", &idx2);
                
                setInRange(arr, idx, idx2, elem);

                break;

            case 's':

                fprintf(stdout, "\n\t\t\tSelect First Index: ");
                fflush(stdin);
                fscanf(stdin, " %d", &idx);

                fprintf(stdout, "\n\t\t\tSelect Second Index: ");
                fflush(stdin);
                fscanf(stdin, " %d", &idx2);
                
                swap(arr, idx, idx2);
                break;
            
            case 'i':

                fprintf(stdout, "\n\t\t\tSelect index to remove: ");
                fflush(stdin);
                fscanf(stdin, " %d", &idx);
                
                // REMOVE ELEMENT AT INDEX idx
                removeAtIndex(arr, idx);
                break;
            
            case 'z':
                setZeroes(arr);

            case 'q':
                quickSort(arr, cmp);
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
        if (!quit){
            fprintf(stdout, "\n\t\t\tContinue? Y/n -> ");
            fflush(stdin);
            fscanf(stdin, " %c", &choice);
            while (1) {
                if (choice == 'n' || choice == 'N'){
                    freeArray(arr);
                    fflush(stdin);
                    fflush(stdout);
                    return;
                } else if (choice == 'y' || choice == 'Y'){
                    break;
                } else {
                    fprintf(stdout, "\n\t\t\tInvalid Input. Continue? Y/n -> ");
                    fflush(stdin);
                    fscanf(stdin, " %c", &choice);
                }
            }
        }

    }
}
