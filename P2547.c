#include <stdio.h>

int main() {
    int cases;
    int students;
    unsigned long long candy;
    int remainder;

    scanf("%d", &cases);
    while (cases-- > 0) {
        remainder = 0;
        scanf("%d", &students);
        for (int i = 0; i < students; ++i) {
            scanf("%llu", &candy);
            remainder = (candy % students + remainder) % students;
        }
        if (remainder) {
            puts("NO");
        } else {
            puts("YES");
        }
    }
}