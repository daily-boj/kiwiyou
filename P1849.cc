#include <bits/stdc++.h>
using namespace std;

struct Tree {
    int startInclusive, endExclusive;
    int auxCount = 0;
    Tree *smaller = nullptr, *bigger = nullptr;
    int count() {
        return smaller ? auxCount : endExclusive - startInclusive;
    }
    int get(int index) {
        if (smaller) {
            if (index < smaller->count()) {
                return smaller->get(index);
            } else {
                return bigger->get(index - smaller->count());
            }
        } else {
            return startInclusive + index;
        }
    }
    bool remove(int index) {
        if (smaller) {
            if (index < smaller->count()) {
                if (smaller->remove(index)) {
                    auto tmp_b = bigger;
                    auto tmp_s = smaller;
                    *this = *bigger;
                    delete tmp_b;
                    delete tmp_s;
                }
            } else {
                if (bigger->remove(index - smaller->count())) {
                    auto tmp_b = bigger;
                    auto tmp_s = smaller;
                    *this = *smaller;
                    delete tmp_b;
                    delete tmp_s;
                }
            }
            return !--auxCount;
        } else if (index == 0) {
            ++startInclusive;
        } else if (index + 1 == this->count()) {
            --endExclusive;
        } else {
            auxCount = this->count() - 1;
            smaller = new Tree;
            smaller->startInclusive = startInclusive;
            smaller->endExclusive = startInclusive + index;
            bigger = new Tree;
            bigger->startInclusive = startInclusive + index + 1;
            bigger->endExclusive = endExclusive;
        }
        return !this->count();
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    Tree tree { .startInclusive = 0, .endExclusive = n };
    int output[100000];
    for (int i = 1; i <= n; ++i) {
        int front;
        cin >> front;
        output[tree.get(front)] = i;
        tree.remove(front);
    }
    for (int i = 0; i < n; ++i) {
        cout << output[i] << '\n';
    }
}