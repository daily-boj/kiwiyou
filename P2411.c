#include <stdio.h>
#include <string.h>
int main() {
    int N, M, A, B, x, y, i, items = 0, temp;
    char board[100][100] = {};
    int count[100] = {};
    scanf("%u%u%u%u", &N, &M, &A, &B);
    for (i = 0; i < A; ++i) {
        scanf("%u%u", &y, &x);
        board[y - 1][x - 1] = 1;
    }
    while (B--) {
        scanf("%u%u", &y, &x);
        board[y - 1][x - 1] = 2;
    }
    count[0] = 1;
    for (y = 0; y < N; ++y) {
        switch (board[y][0]) {
        case 1:
            ++items;
            temp = count[0];
            memset(count, 0, 4 * M);
            count[0] = temp;
            break;
        case 2:
            count[0] = 0;
            break;
        }
        for (x = 1; x < M; ++x) {
            switch (board[y][x]) {
            case 0:
                count[x] += count[x - 1];
                break;
            case 1:
                ++items;
                temp = count[x] + count[x - 1];
                memset(count, 0, 4 * M);
                count[x] = temp;
                break;
            case 2:
                count[x] = 0;
                break;
            }
        }
    }
    if (items == A) printf("%u", count[M - 1]);
    else printf("0");
}