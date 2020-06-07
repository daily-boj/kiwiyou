#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;

tuple<int, int, int> dijikstra(int n, vector<pair<int, int>> edges[], int from, int a, int b, int c) {
    int distance[800];
    bool processed[800] = {};
    fill(distance, distance + n, INF);
    distance[from] = 0;
    priority_queue<pair<int, int>> q;
    q.emplace(0, from);
    while (!q.empty()) {
        auto [dist, current] = q.top();
        q.pop();
        if (processed[current]) continue;
        processed[current] = true;
        for (auto& [p, w] : edges[current]) {
            if (w - dist < distance[p]) {
                distance[p] = w - dist;
                q.emplace(-distance[p], p);
            }
        }
    }
    return { distance[a], distance[b], distance[c] };
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> edges[800];
    for (int i = 0; i < e; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        --a, --b;
        edges[a].emplace_back(b, w);
        edges[b].emplace_back(a, w);
    }
    int v1, v2;
    cin >> v1 >> v2;
    --v1, --v2;
    auto [fst_to_v1, v1_to_v2, v1_to_lst] = dijikstra(n, edges, v1, 0, v2, n - 1);
    auto [fst_to_v2, v2_to_lst, ignore] = dijikstra(n, edges, v2, 0, n - 1, v2);
    if (v1_to_v2 >= INF) {
        cout << "-1";
        return 0;
    }
    int v1_first = fst_to_v1 >= INF || v2_to_lst >= INF ? INF : fst_to_v1 + v1_to_v2 + v2_to_lst;
    int v2_first = fst_to_v2 >= INF || v1_to_lst >= INF ? INF : fst_to_v2 + v1_to_v2 + v1_to_lst;
    if (v1_first >= INF && v2_first >= INF) {
        cout << "-1";
        return 0;
    }
    cout << min(v1_first, v2_first);
}