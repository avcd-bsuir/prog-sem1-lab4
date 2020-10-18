[![License](https://img.shields.io/badge/license-CC%20BY--NC--SA%204.0-blue.svg)](https://bit.ly/cc-by-nc-sa-40)

# Usage

To clone repository correctly use `--recursive` flag with `git`.

To compile and run a program use:
```
$ ./build.sh gcc src/<filename>
```

Executable will be started automatically. It can be found in `build/scr/` folder.

# Semester \<1\> lab \<4\>

## Task \<1\>

Fill the array with natural numbers from the keyboard. Remove all numbers that are not prime.

Original (ru):

Заполнить с клавиатуры массив натуральными числами. Удалить все числа, не являющиеся простыми.

## Task \<2\>

Find a saddle point in a two-dimensional array: element, minimum in a column and maximum in a row.

Original (ru):

Найти в двумерном массиве седловую точку: элемент, минимальный в столбце и максимальный в строке.

## Task \<3\>

You are given a two-dimensional array of non-zero integers. Determine the longest possible sequence of positive numbers. The array is viewed line by line from top to bottom, and in each line - from left to right. Also take into account the preservation of the sign when moving to a new line.

Original (ru):

Дан двумерный массив ненулевых целых чисел. Определить максимально длинную последовательность положительных чисел. Массив просматривается построчно сверху вниз, а в каждой строке - слева направо. Сохранение знака при переходе на новую строку также учитывать.

# Credits

Written by Alexey Filich.

# License

This repository is licensed under [Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International](LICENCE.md).

# Notes

For compiling with SDL2:
```
-lmingw32 -lSDL2main -lSDL2
```

For compiling with ncurses
```
-lncursesw
```

## Description for some `include` files:

- stdarg.h

    Variable arguments with `va_list args; va_start(args, last_variable_in_function); va_arg(args, type)`.

- stdbool.h

    `True` and `false`.

- stdio.h

    `printf`, `scanf`, `NULL`, etc.

- stdlib.h

    Memory: `malloc`, `calloc`, `free`, \
    Random: `rand`, `srand`.

- string.h

    `memset`, `memcpy`, `memmove`.

- time.h

    `time(0)`.
