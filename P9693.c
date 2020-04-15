#include <stdio.h>

int main() {
    int fives[1000000];
    int input;

    fives[0] = 0;
    for (int i = 2; i <= 1000000; ++i) {
        int j = i;
        int five = 0;
        while (!(j % 5)) {
            five += 1;
            j /= 5;
        }
        fives[i - 1] = fives[i - 2] + five;
    }

    for (int i = 1; ; ++i) {
        scanf("%d", &input);
        if (!input) {
            break;
        }
        printf("Case #%d: %d\n", i, fives[input - 1]);
    }
}