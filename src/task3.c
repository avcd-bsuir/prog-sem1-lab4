// License: CC BY-NC-SA 4.0
/*
 * task3.c
 *
 * You are given a two-dimensional array of non-zero integers. Determine the longest possible sequence of positive numbers.
 * The array is viewed line by line from top to bottom, and in each line - from left to right.
 * Also take into account the preservation of the sign when moving to a new line.
 *
 * Written by AlexeyFilich
 * 09 oct 2020
 */

#define STORAGE_OPTIMAL

#include <stdio.h>
#include "Interactions.h"
#include "Random.h"
#include "storage/Storage.h"

int main(int argc, char* args[]) {
    Array array; // Declaratin of array and dimensions
    int W, H;
    loop: // Label to avoid wrapping all of the code below in for(;;) loop
    aScanCheck("Array size [w, h]: ", "%d %d", &W, &H); // Read array dimensions
    aArrayInit(&array, W * H, int);
    for (int y = 0; y < H; y++) { // Iterate rows
        for (int x = 0; x < W; x++) { // Cols
            int val;
            do {
                val = aRandInt(-10, 10);
            } while (val == 0);
            aArraySetI(&array, x + y * W, val); // Set x, y item a random value but not 0
            printf("%3d ", val);
        }
        printf("\n");
    }
    int max = 0, cur = 0;
    for (int i = 0; i < array.size; i++) { // Go through array
        if (aArrayGetAs(&array, i, int) >= 0) // If element is >= 0
            cur++; // Inc seq
        else { // If not
            if (cur > max) max = cur; // max = maximum of max and cur
            cur = 0; // cur = 0
        }
    }
    printf("Max sequence: %d \n", max != 0 ? max : cur);
    printf("\nPress ENTER to start again\n");
    if (getchar() == '\n') goto loop; // Restart if user pressed enter
    aArrayDestroy(&array); // Free allocated space
    printf("Done!\n");
    return 0;
}
