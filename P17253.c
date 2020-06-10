#include <stdio.h>
int main() {
    long long N;
    scanf("%lld", &N);
    if (N == 0) N = 2;
    while (N) {
        if (N % 3 == 2) {
            puts("NO");
            return 0;
        }
        N /= 3;
    }
    puts("YES");
    return 0;
}