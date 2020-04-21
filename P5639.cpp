#include <iostream>
#include <stack>
using namespace std;

struct Bst {
    Bst *left = nullptr;
    Bst *right = nullptr;
    int value;
};

void read_bst_prefix(Bst *node, int low, int high, int *&input, const int* end) {
    if (input == end) return;

    if (*input > low && *input < node->value) {
        node->left = new Bst;
        node->left->value = *input++;
        read_bst_prefix(node->left, low, node->value, input, end);
    }

    if (input == end) return;

    if (*input > node->value && *input < high) {
        node->right = new Bst;
        node->right->value = *input++;
        read_bst_prefix(node->right, node->value, high, input, end);
    }
}

void print_bst_postfix(Bst* node) {
    if (node->left) {
        print_bst_postfix(node->left);
    }
    if (node->right) {
        print_bst_postfix(node->right);
    }
    cout << node->value << '\n';
}

int main() {
    Bst root;
    cin >> root.value;
    int input[10000];
    int *cursor = input;
    while (!cin.eof()) {
        cin >> *cursor++;
    }
    auto begin = input;
    read_bst_prefix(&root, 0, 1000000, begin, cursor);
    print_bst_postfix(&root);
}