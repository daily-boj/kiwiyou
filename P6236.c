#include <stdio.h>
#include <stdlib.h>

#define MIN(x, y) (((x) > (y)) ? (y) : (x))

int compare_use(int use[], int daily_usage, int days, int split_by) {
    int balance = 0;
    for (int i = 0; i < days; ++i) {
        if (balance < use[i]) {
            balance = daily_usage;
            --split_by;
        }
        balance -= use[i];
        if (balance < 0) {
            return -1;
        }
    }
    if (split_by < 0) {
        return -1;
    } else {
        return split_by || balance;
    }
}

int main() {
    int days, split_by;
    int use[100000];
    long low = 1000000, high = 0, mid;
    int compare;
    scanf("%d%d", &days, &split_by);
    for (int i = 0; i < days; ++i) {
        scanf("%d", &use[i]);
        low = MIN(low, use[i]);
        high += use[i];
    }
    while (low < high) {
        mid = (low + high) / 2;
        compare = compare_use(use, mid, days, split_by);
        if (compare > 0) {
            high = mid;
        } else if (compare < 0) {
            low = mid + 1;
        } else {
            break;
        }
    }
    printf("%d", low);
}