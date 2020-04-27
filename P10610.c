#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return *((char *) b) - *((char *) a);
}

int main() {
    char input[100001];
    int has_zero = 0;
    long digit_sum = 0;
    char *cursor = input;
    scanf("%s", input);
    while (*cursor) {
        digit_sum += *cursor;
        if (*cursor == '0') {
            has_zero = 1;
        }
        ++cursor;
    }
    if (!has_zero || digit_sum % 3) {
        puts("-1");
    } else {
        qsort(input, strlen(input), 1, compare);
        printf("%s", input);
    }
}