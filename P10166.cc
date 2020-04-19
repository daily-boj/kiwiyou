#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;

int main() {
	int sieve[2000];
	int d1, d2;
	cin >> d1 >> d2;
	iota(sieve, sieve + d2, 0);
	auto last_sieve = d2 >> 1;
	int first_appear = 1;
	for (int n = 2; n <= last_sieve; ++n) {
		auto factor_count = sieve[n - 1];
		bool first_added = n >= d1;
		for (int multiple = n << 1; multiple <= d2; multiple += n) {
			if (!first_added && multiple >= d1) {
				first_appear += factor_count;
				first_added = true;
			}
			sieve[multiple - 1] -= factor_count;
		}
	}

	auto sum = first_appear + accumulate(sieve + d1 - 1, sieve + d2, 0);

	cout << sum;
}
