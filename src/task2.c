// License: CC BY-NC-SA 4.0
/*
 * task2.c
 *
 * Find a saddle point in a two-dimensional array: element, minimum in a column and maximum in a row.
 *
 * Written by AlexeyFilich
 * 09 oct 2020
 */

#define STORAGE_OPTIMAL

#include <stdbool.h>
#include <stdio.h>
#include <Interactions.h>
#include <Random.h>
#include <storage/Storage.h>

int main(int argc, char* args[]) {
    Array array; // Declaratin of array and dimensions
    int W, H;
    loop: // Label to avoid wrapping all of the code below in for(;;) loop
    aScanCheck("Array size [w, h]: ", "%d %d", &W, &H); // Read array dimensions
    aArrayInit(&array, W * H, int);
    for (int y = 0; y < H; y++) { // Fill array with random numbers and print them
        for (int x = 0; x < W; x++) {
            aArraySetI(&array, x + y * W, aRandInt(1, 10));
            printf("%3d ", aArrayGetAs(&array, x + y * W, int));
        }
        printf("\n");
    }
    for (int y = 0; y < H; y++) { // For each row
        for (int x = 0; x < W; x++) { // For each columns
            bool isMin = true, isMax = true; // We assume that [x][y] element is a saddle point
            for (int i = 0; i < H; i++) // Check if it is not minimum in a column
                if (aArrayGetAs(&array, x + y * W, int) > aArrayGetAs(&array, x + i * W, int)) {
                    isMin = false;
                    break;
                }
            for (int i = 0; i < W; i++) // Check if it is not maximum in a row
                if (aArrayGetAs(&array, x + y * W, int) < aArrayGetAs(&array, i + y * W, int)) {
                    isMax = false;
                    break;
                }
            if (isMin && isMax) printf("[%d %d] %d\n", x, y, aArrayGetAs(&array, x + y * W, int)); // Print it if it is still a saddle point
        }
    }
    printf("\nPress ENTER to start again\n");
    if (getchar() == '\n') goto loop; // Restart if user pressed enter
    aArrayDestroy(&array); // Free allocated space
    printf("Done!\n");
    return 0;
}
