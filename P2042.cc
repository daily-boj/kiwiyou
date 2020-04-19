#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int numbers;
    int changes, sums;
    cin >> numbers >> changes >> sums;
    vector<long long> arr(numbers + 1);
    vector<long long> tree(numbers + 1);

    for (int i = 1; i <= numbers; ++i) {
        auto& num = arr[i];
        cin >> num;
        int tree_index = i;
        while (tree_index <= numbers) {
            tree[tree_index] += num;
            tree_index += tree_index & (-tree_index);
        }
    }

    changes += sums;
    while (changes-- > 0) {
        int choice;
        cin >> choice;
        switch (choice) {
        case 1: {
                int index;
                long long change_to;
                cin >> index >> change_to;
                long long diff = change_to - arr[index];
                arr[index] = change_to;
                while (index <= numbers) {
                    tree[index] += diff;
                    index += index & -index;
                }
            }
            break;
        case 2: {
                int from, to;
                cin >> from >> to;
                long long to_sum = 0;
                from -= 1;
                while (to) {
                    to_sum += tree[to];
                    to -= to & -to;
                }
                long long from_sum = 0;
                while (from) {
                    from_sum += tree[from];
                    from -= from & -from;
                }
                cout << (to_sum - from_sum) << "\n";
            }
            break;
        }
    }
}