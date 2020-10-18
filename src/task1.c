// License: CC BY-NC-SA 4.0
/*
 * task1.c
 *
 * Fill the array with natural numbers from the keyboard. Remove all numbers that are not prime.
 *
 * Written by AlexeyFilich
 * 09 oct 2020
 */

#include <stdbool.h>
#include <stdio.h>
#include "Interactions.h"
#include "storage/Storage.h"

bool chk(int n) {
    for (int i = 2; i < n; i++) // From 2 to n-1
        if (n % i == 0) return true; // If n is divideable by i it is not prime
    return false; // Prime
}

int main(int argc, char* args[]) {
    Array array; // Declaring dynamic array
    int inp, n; // Declaring inp and n
    loop: // Label to avoid wrapping all of the code below in for(;;) loop
    aScanCheck("Array size: ", "%d", &n); // Read array size
    aArrayInit(&array, n, int); // Initialize array for int with size n
    for (int i = 0; i < array.size; i++) { // Read numbers in array
        aScanCheck("Num: ", "%d", &inp);
        aArraySet(&array, i, &inp);
    }
    for (int i = 0; i < array.size; i++) { // For each array element
        if (chk(aArrayGetAs(&array, i, int))) { // If array[i] is not prime
            aArrayRemove(&array, i); // Delete it
            i--;
        }
    }
    printf("Array after removing non-simple numbers: ");
    for (int i = 0; i < array.size; i++) printf("%d ", aArrayGetAs(&array, i, int)); // Print array
    printf("\nPress ENTER to start again\n");
    if (getchar() == '\n') goto loop; // Restart if user pressed enter
    aArrayDestroy(&array); // Free allocated space
    printf("\nDone!\n");
    return 0;
}
