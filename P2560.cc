#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, d, N;
    cin >> a >> b >> d >> N;
    deque<int> newface;
    deque<int> adult;
    int adult_count = 0;
    deque<int> to_die;
    newface.push_back(1);
    while (N--) {
        if (to_die.size() >= d - b) {
            to_die.pop_front();
        }
        if (adult.size() >= b - a) {
            int new_to_die = adult.front();
            adult.pop_front();
            adult_count = adult_count + 1000 - new_to_die;
            to_die.push_back(new_to_die);
        }
        if (newface.size() >= a) {
            int new_adult = newface.front();
            newface.pop_front();
            adult.push_back(new_adult);
            adult_count += new_adult;
            adult_count %= 1000;
        }
        newface.push_back(adult_count);
    }
    int sum = 0;
    for (auto it = newface.begin(); it != newface.end(); ++it) {
        sum += *it;
        sum %= 1000;
    }
    for (auto it = adult.begin(); it != adult.end(); ++it) {
        sum += *it;
        sum %= 1000;
    }
    for (auto it = to_die.begin(); it != to_die.end(); ++it) {
        sum += *it;
        sum %= 1000;
    }
    cout << sum;
}