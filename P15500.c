#include <stdio.h>

#define LEFT_TO_RIGHT "1 2"
#define LEFT_TO_RESULT "1 3"
#define RIGHT_TO_LEFT "2 1"
#define RIGHT_TO_RESULT "2 3"

#define MAX(x, y) ((x) < (y) ? (y) : (x))

int main() {
    int count;
    char* solutions[12345];
    int solutions_top = 0;
    int left_bar[123];
    int right_bar[123];
    int left_top = 0;
    int right_top = 0;
    int max = 0;
    scanf("%d", &count);
    max = count;
    while (count-- > 0) {
        scanf("%d", &left_bar[left_top++]);
    }
    while (left_top || right_top) {
        while (left_top) {
            --left_top;
            if (left_bar[left_top] == max) {
                solutions[solutions_top++] = LEFT_TO_RESULT;
                max -= 1;
                break;
            } else {
                right_bar[right_top++] = left_bar[left_top];
                solutions[solutions_top++] = LEFT_TO_RIGHT;
            }
        }
        while (right_top) {
            --right_top;
            if (right_bar[right_top] == max) {
                solutions[solutions_top++] = RIGHT_TO_RESULT;
                max -= 1;
                break;
            } else {
                left_bar[left_top++] = right_bar[right_top];
                solutions[solutions_top++] = RIGHT_TO_LEFT;
            }
        }
    }
    printf("%d\n", solutions_top);
    for (int i = 0; i < solutions_top; ++i) {
        puts(solutions[i]);
    }
}