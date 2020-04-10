#include <iostream>
using namespace std;

int main() {
    // [parent][child]
    bool tree[50][50] = {0, };
    int nodes;
    cin >> nodes;
    int root = -1;
    for (int i = 0; i < nodes; ++i) {
        int parent;
        cin >> parent;
        if (parent >= 0) {
            tree[parent][i] = true;
        } else {
            root = i;
        }
    }
    int remove;
    cin >> remove;
    int stack[50];
    stack[0] = root;
    int top = 1;
    int leaves = 0;
    if (remove == root) {
        cout << "0";
        return 0;
    }
    while (top) {
        int current = stack[--top];
        bool found = false;
        for (int i = 0; i < nodes; ++i) {
            if (tree[current][i] && i != remove) {
                found = true;
                stack[top] = i;
                ++top;
            }
        }
        if (!found) {
            ++leaves;
        }
    }
    cout << leaves;
}