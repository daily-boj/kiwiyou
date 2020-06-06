#include <bits/stdc++.h>
using namespace std;

bool board[128][128];

struct QuadTree {
    enum { TREE = 0, WHITE, BLUE } color = TREE;
    array<QuadTree*, 4> cells = {};
};

QuadTree* construct(int x, int y, int size) {
    if (size == 1) return new QuadTree { .color = board[x][y] ? QuadTree::BLUE : QuadTree::WHITE };
    size >>= 1;
    auto lt = construct(x, y, size);
    auto rt = construct(x + size, y, size);
    auto lb = construct(x, y + size, size);
    auto rb = construct(x + size, y + size, size);
    if (lt->color && lt->color == rt->color && rt->color == lb->color && lb->color == rb->color) {
        auto coalesced = new QuadTree { .color = lt->color };
        delete lt;
        delete rt;
        delete lb;
        delete rb;
        return coalesced;
    } else {
        return new QuadTree {
            .color = QuadTree::TREE,
            .cells = { lt, rt, lb, rb }
        };
    }
}

tuple<int, int> count_colors(const QuadTree* root) {
    if (root->color == QuadTree::WHITE) {
        return { 1, 0 };
    } else if (root->color == QuadTree::BLUE) {
        return { 0, 1 };
    } else {
        int w = 0, b = 0;
        for (auto cell : root->cells) {
            auto colors = count_colors(cell);
            w += get<0>(colors);
            b += get<1>(colors);
        }
        return { w, b };
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }
    auto tree = construct(0, 0, n);
    auto [white, blue] = count_colors(tree);
    cout << white << '\n' << blue;
}