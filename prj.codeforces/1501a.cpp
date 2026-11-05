#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
	int n;
	std::cin >> n;
	std::vector<long long> a(n), b(n), tm(n);

	for (int i = 0; i < n; ++i) {
		std::cin >> a[i] >> b[i];
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> tm[i];
	}

	long long current_time = 0;

	for (int i = 0; i < n; ++i) {
		long long expected_travel = a[i] - (i == 0 ? 0 : b[i - 1]);
		current_time += expected_travel + tm[i];

		if (i < n - 1) {
			long long wait_time = (b[i] - a[i] + 1) / 2;
			current_time = std::max(current_time + wait_time, b[i]);
		}
	}

	std::cout << current_time << "\n";
}

int main() {
	int t;
	if (std::cin >> t) {
		while (t--) {
			solve();
		}
	}
	return 0;
}