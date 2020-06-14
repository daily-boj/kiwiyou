#include <stdio.h>

int main() {
    int n, m, i = 0;
    scanf("%u%u", &n, &m);
    while (n) {
        i += n;
        n /= m;
    }
    printf("%u", i);
}