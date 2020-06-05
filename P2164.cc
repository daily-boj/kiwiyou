#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    deque<int> deck;
    for (int i = 1; i <= n; ++i) {
        deck.push_back(i);
    }
    while (deck.size() > 1) {
        deck.pop_front();
        int front = deck.front();
        deck.pop_front();
        deck.push_back(front);
    }
    cout << deck.front();
}