#include <stdio.h>

int main() {
    int press_count;
    int a = 1, b = 0;
    int temp;
    scanf("%d", &press_count);
    while (press_count--) {
        temp = a;
        a = b;
        b += temp;
    }
    printf("%d %d", a, b);
}