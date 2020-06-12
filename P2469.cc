#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    char src[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", dest[27];
    int people;
    int height;
    cin >> people >> height >> dest;
    char bars[1000][26];
    for (int i = 0; i < height; ++i) {
        cin >> bars[i];
    }
    int bar;
    for (bar = 0; bar < height; ++bar) {
        if (bars[bar][0] == '?') break;
        int x = 0;
        while (x < people - 1) {
            if (bars[bar][x] == '*') {
                ++x;
            } else {
                swap(src[x], src[x + 1]);
                x += 2;
            }
        }
    }
    for (int back = height - 1; back > bar; --back) {
        int x = 0;
        while (x < people - 1) {
            if (bars[back][x] == '*') {
                ++x;
            } else {
                swap(dest[x], dest[x + 1]);
                x += 2;
            }
        }
    }
    char output[26];
    int x = 0;
    while (x < people - 1) {
        if (src[x] == dest[x]) {
            output[x] = '*';
            ++x;
        } else if (src[x] == dest[x + 1] && src[x + 1] == dest[x]) {
            output[x] = '-';
            output[x + 1] = '*';
            x += 2;
        } else {
            cout << string(people - 1, 'x');
            return 0;
        }
    }
    output[people - 1] = '\0';
    puts(output);
}