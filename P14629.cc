#include <bits/stdc++.h>
using namespace std;

long long compute(int index) {
    if (index < 10) return index;
    if (index > 8877690) return 9876543210;
    bool used[10] = {};
    long long count_table[] = {10, 81, 648, 4536, 27216, 136080, 544320, 1632960, 3265920, 3265920};
    long long div_table[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 1};
    long long divisor = 1;
    long long base = 1;
    for (int i = 0; index >= count_table[i]; ++i) {
        divisor *= div_table[i];
        base *= 10;
        index -= count_table[i];
    }
    int di = 0;
    long long first_digit = index / divisor + 1;
    long long result = first_digit * base;
    used[first_digit] = true;
    index %= divisor;
    divisor /= div_table[di++];
    base /= 10;
    while (base) {
        int digit_index = index / divisor;
        int digit = 0;
        do {
            while (used[digit]) ++digit;
        } while (digit_index-- && ++digit);
        result += digit * base;
        used[digit] = true;
        index %= divisor;
        divisor /= div_table[di++];
        base /= 10;
    }
    return result;
}

int main() {
    long long num;
    cin >> num;
    int low = 1, high = 8877690;
    while (low < high) {
        int mid = (low + high) >> 1;
        if (compute(mid + 1) < num) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    long long lower_bound = compute(low);
    low = 1;
    high = 8877690;
    while (low < high) {
        int mid = (low + high) >> 1;
        if (compute(mid) < num) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    long long upper_bound = compute(low);
    if (num - lower_bound <= upper_bound - num) {
        cout << lower_bound;
    } else {
        cout << upper_bound;
    }
}