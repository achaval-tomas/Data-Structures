#include "../Array/array.h"
#include "handlers.h"

/*  COMPARE FUNCTION FOR QUICK SORT  */
bool cmp(int a, int b)
{
    return a <= b;
}

/*  PRINT INFO OF ARRAY (size and current state)  */
void printArrayInfo(MyArray* arr)
{
    printf("\n\t\tCURRENT ARRAY: ");
    printArray(arr);
    printf("\t\tSIZE: %d\n", arraySize(arr));
    fflush(stdout);
}

/*  PRINT ARRAY MENU  */
void printArrayMenu(MyArray* arr)
{
    printf("\n- MAIN MENU -> ARRAY MENU\n");
    printArrayInfo(arr);
    printf("\n"
           MENUOPTION("Add at index", "a")
           MENUOPTION("Remove element", "r")
           MENUOPTION("Set in Range", "R")
           MENUOPTION("Swap Indexes", "s")
           MENUOPTION("Remove at Index", "i")
           MENUOPTION("Set all to Zero", "z")
           MENUOPTION("Quick Sort the array", "q")
           MENUOPTION("Print Array", "p")
           EXIT
           SELECT);
    fflush(stdout);
}

void handleArray()
{
    MyArray* arr = init();
    char quit = 0, choice = 0;
    int in0 = 0, in1 = 0, in2 = 0;
    while (!quit) {

        clearConsole();
        printArrayMenu(arr);
        scanf(" %c", &choice); // Get user input.

        switch (choice) {
            case 'a':

                printf("\n\t\t\tSelect element: ");
                scanf(" %d", &in0);

                printf("\n\t\t\tSelect Index: ");
                scanf(" %d", &in1);

                // PLACE ELEM AT INDEX, MAKING SPACE IF NEEDED.
                setInRange(arr, in1, in1 + 1, in0);
                break;

            case 'r':

                printf("\n\t\t\tSelect elem to remove: ");
                scanf(" %d", &in0);

                // REMOVE ALL INSTANCES OF SELECTED ELEMENT
                removeMatches(arr, in0);
                break;

            case 'R':

                printf("\n\t\t\tSelect elem to add: ");
                scanf(" %d", &in0);

                printf("\n\t\t\tStart of range (>= 0): ");
                scanf(" %d", &in1);

                printf("\n\t\t\tEnd of range: ");
                scanf(" %d", &in2);

                setInRange(arr, in1, in2, in0);

                break;

            case 's':

                printf("\n\t\t\tSelect First Index: ");
                scanf(" %d", &in1);

                printf("\n\t\t\tSelect Second Index: ");
                scanf(" %d", &in2);

                swap(arr, in1, in2);
                break;

            case 'i':

                printf("\n\t\t\tSelect index to remove: ");
                scanf(" %d", &in1);

                // REMOVE ELEMENT AT INDEX in1
                removeAtIndex(arr, in1);
                break;

            case 'z':
                setZeroes(arr);
                break;

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

        if (!quit) {
            printf("\n\t\t\tContinue? Y/n -> ");
            scanf(" %c", &choice);

            while (1) {
                if (choice == 'n' || choice == 'N') {
                    freeArray(arr);
                    fflush(stdout);
                    return;
                } else if (choice == 'y' || choice == 'Y') {
                    break;
                } else {
                    printf("\n\t\t\tInvalid Input. Continue? Y/n -> ");
                    scanf(" %c", &choice);
                }
            }
        }
    }
}
