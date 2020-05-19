#include <iostream>
#include <iterator>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    auto iit = istream_iterator<int>(cin);
    auto stack = std::stack<int>();
    stack.push(1);
    auto highest = stack.top();
    string output = "+\n";
    auto count = *iit;
    while (count--) {
        auto num = *++iit;
        while (highest < num) {
            ++highest;
            output.append("+\n");
            stack.push(highest);
        }
        if (stack.empty() || stack.top() < num) {
            cout << "NO\n";
            return 0;
        }
        while (!stack.empty() && stack.top() >= num) {
            output.append("-\n");
            stack.pop();
        }
    }
    cout << output;
}