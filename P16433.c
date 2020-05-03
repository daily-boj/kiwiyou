#include <stdio.h>

int main() {
    char first_filled[] = "v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v";
    char first_empty[] = ".v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.";
    int size, row, column;
    scanf("%d%d%d", &size, &row, &column);
    first_filled[size] = first_empty[size] = '\0';
    row += column;
    while (size-- > 0) {
        if (row & 1) {
            puts(first_empty);
        } else {
            puts(first_filled);
        }
        ++row;
    }
}