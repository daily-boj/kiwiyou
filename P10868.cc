#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll init(vector<ll> &seq, vector<ll> &tree, int node, int start, int end) {
    if (start == end) return tree[node] = seq[start];
    else return tree[node] = min(init(seq, tree, node * 2, start, (start + end) / 2), init(seq, tree, node * 2 + 1, (start + end) / 2 + 1, end));
}
ll query(vector<ll> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) return numeric_limits<ll>::max();
    if (left <= start && end <= right) return tree[node];
    return min(query(tree, node * 2, start, (start + end) / 2, left, right), query(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<ll> seq(n);
    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
    }
    vector<ll> tree(1 << ((int)ceil(log2(n)) + 1));
    init(seq, tree, 1, 0, n - 1);
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << query(tree, 1, 0, n - 1, l - 1, r - 1) << '\n';
    }
}