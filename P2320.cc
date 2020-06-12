#include <bits/stdc++.h>
using namespace std;

char first[16];
char last[16];
int len[16];
int wcount;
bool visited[16];
int max_from[16];

int track(int i) {
    if (max_from[i] != -1) return max_from[i];
    max_from[i] = 0;
    for (int mid = 0; mid < wcount; ++mid) {
        if (!visited[mid] && last[i] == first[mid]) {
            visited[mid] = true;
            max_from[i] = max(max_from[i], len[mid] + track(mid));
            visited[mid] = false;
        }
    }
    return max_from[i];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> wcount;
    char buffer[101];
    for (int i = 0; i < wcount; ++i) {
        cin >> buffer;
        len[i] = strlen(buffer);
        first[i] = buffer[0];
        last[i] = buffer[len[i] - 1];
    }
    int point = 0;
    for (int i = 0; i < wcount; ++i) {
        fill(visited, visited + 16, false);
        fill(max_from, max_from + 16, -1);
        visited[i] = true;
        point = max(point, len[i] + track(i));
    }
    cout << point;
}