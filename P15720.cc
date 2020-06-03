#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int burger_cnt, side_cnt, beverage_cnt;
    cin >> burger_cnt >> side_cnt >> beverage_cnt;
    int burgers[1000], sides[1000], beverages[1000];
    copy_n(istream_iterator<int>(cin), burger_cnt, burgers);
    copy_n(istream_iterator<int>(cin), side_cnt, sides);
    copy_n(istream_iterator<int>(cin), beverage_cnt, beverages);
    sort(burgers, burgers + burger_cnt, greater<int>());
    sort(sides, sides + side_cnt, greater<int>());
    sort(beverages, beverages + beverage_cnt, greater<int>());
    auto sum = accumulate(burgers, burgers + burger_cnt, 0)
        + accumulate(sides, sides + side_cnt, 0)
        + accumulate(beverages, beverages + beverage_cnt, 0);
    decltype(sum) discounted = 0;
    auto three_limit = min({burger_cnt, side_cnt, beverage_cnt});
    for (int i = 0; i < three_limit; ++i) {
        discounted += (burgers[i] + sides[i] + beverages[i]) / 10 * 9;
    }
    discounted += accumulate(burgers + three_limit, burgers + burger_cnt, 0);
    discounted += accumulate(sides + three_limit, sides + side_cnt, 0);
    discounted += accumulate(beverages + three_limit, beverages + beverage_cnt, 0);
    cout << sum << '\n' << discounted;
}