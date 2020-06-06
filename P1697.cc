#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    queue<int> next;
    bool visited[1000001] = {};
    int children_left = 1;
    int children_next = 0;
    int depth = 0;
    visited[N] = true;
    next.push(N);
    while (true) {
        auto current = next.front();
        if (current == K) break;
        next.pop();
        if (current < K && current <= 500000 && !visited[current << 1]) {
            ++children_next;
            visited[current << 1] = true;
            next.push(current << 1);
        }
        if (current < K && !visited[current + 1]) {
            ++children_next;
            visited[current + 1] = true;
            next.push(current + 1);
        }
        if (current > 0 && !visited[current - 1]) {
            ++children_next;
            visited[current] = true;
            next.push(current - 1);
        }
        children_left -= 1;
        if (!children_left) {
            children_left = children_next;
            children_next = 0;
            depth += 1;
        }
    }
    cout << depth;
}