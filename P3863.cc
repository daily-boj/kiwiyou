#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    while (true) {
        int N, M;
        cin >> N >> M;
        if (!N && !M) break;
        vector<pair<int, int>> calls(N);
        for (int i = 0; i < N; ++i) {
            int _src, _dest;
            cin >> _src >> _dest >> calls[i].first >> calls[i].second;
            calls[i].second += calls[i].first;
        }
        while (M--) {
            int start, end;
            cin >> start >> end;
            end += start;
            int count = 0;
            for (auto& [call_start, call_end] : calls) {
                int hear_dur = min(end, call_end) - max(start, call_start);
                if (hear_dur >= 1) ++count;
            }
            cout << count << '\n';
        }
    }
}