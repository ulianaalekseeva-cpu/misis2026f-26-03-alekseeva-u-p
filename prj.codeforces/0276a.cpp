#include <iostream>
#include <algorithm>

int main() {
	int n;
	long long k;
	std::cin >> n >> k;

	long long max_satisfaction = -2000000000000000000LL;

	for (int i = 0; i < n; ++i) {
		long long f, t;
		std::cin >> f >> t;

		long long current_satisfaction;
		if (t > k) {
			current_satisfaction = f - (t - k);
		}
		else {
			current_satisfaction = f;
		}

		max_satisfaction = std::max(max_satisfaction, current_satisfaction);
	}

	std::cout << max_satisfaction << "\n";

	return 0;
}
