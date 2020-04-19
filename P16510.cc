#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tasks, cases;
    cin >> tasks >> cases;

    long long aggregated_time[200000];
    for (int i = 0; i < tasks; ++i) {
        cin >> aggregated_time[i];
        if (i > 0) {
            aggregated_time[i] += aggregated_time[i - 1];
        }
    }

    while (cases-- > 0) {
        long long find;
        cin >> find;
        auto can_do = upper_bound(aggregated_time, aggregated_time + tasks, find) - aggregated_time;
        cout << can_do << '\n';
    }
}