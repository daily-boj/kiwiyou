#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int words_count;
    string passwords[100];
    cin >> words_count;
    for (int i = 0; i < words_count; ++i) {
        cin >> passwords[i];
        auto reversed = passwords[i];
        reverse(reversed.begin(), reversed.end());
        auto element = find(passwords, passwords + i + 1, reversed);

        if (element != passwords + i + 1) {
            cout << element->length() << " " << (*element)[element->length() / 2];
            break;
        }
    }
}