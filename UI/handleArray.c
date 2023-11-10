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
    int in0 = 0, in1 = 0, in2 = 0;
    while (!quit){

        clearConsole();
        printArrayMenu(arr);
        fscanf(stdin, " %c", &choice);  // Get user input.

        switch(choice){
            case 'a':

                fprintf(stdout, "\n\t\t\tSelect element: ");
                fscanf(stdin, " %d", &in0);

                fprintf(stdout, "\n\t\t\tSelect Index: ");
                fscanf(stdin, " %d", &in1);

                // PLACE ELEM AT INDEX, MAKING SPACE IF NEEDED.
                setInRange(arr, in1, in1+1, in0);
                break;
            
            case 'r':

                fprintf(stdout, "\n\t\t\tSelect elem to remove: ");
                fscanf(stdin, " %d", &in0);
                
                // REMOVE ALL INSTANCES OF SELECTED ELEMENT
                removeMatches(arr, in0);
                break;

            case 'R':

                fprintf(stdout, "\n\t\t\tSelect elem to add: ");
                fscanf(stdin, " %d", &in0);

                fprintf(stdout, "\n\t\t\tStart of range (>= 0): ");
                fscanf(stdin, " %d", &in1);

                fprintf(stdout, "\n\t\t\tEnd of range: ");
                fscanf(stdin, " %d", &in2);
                
                setInRange(arr, in1, in2, in0);

                break;

            case 's':

                fprintf(stdout, "\n\t\t\tSelect First Index: ");
                fscanf(stdin, " %d", &in1);

                fprintf(stdout, "\n\t\t\tSelect Second Index: ");
                fscanf(stdin, " %d", &in2);
                
                swap(arr, in1, in2);
                break;
            
            case 'i':

                fprintf(stdout, "\n\t\t\tSelect index to remove: ");
                fscanf(stdin, " %d", &in1);
                
                // REMOVE ELEMENT AT INDEX in1
                removeAtIndex(arr, in1);
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
                fflush(stdout);
                break;

            default:
                break;
        }
        
        if (!quit){
            fprintf(stdout, "\n\t\t\tContinue? Y/n -> ");
            fscanf(stdin, " %c", &choice);

            while (1) {
                if (choice == 'n' || choice == 'N'){
                    freeArray(arr);
                    fflush(stdout);
                    return;
                } else if (choice == 'y' || choice == 'Y'){
                    break;
                } else {
                    fprintf(stdout, "\n\t\t\tInvalid Input. Continue? Y/n -> ");
                    fscanf(stdin, " %c", &choice);
                }
            }
        }

    }
}
