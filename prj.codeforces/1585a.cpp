#include <iostream>
#include <vector>

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}

	int height = 1;
	for (int i = 0; i < n; ++i) {
		if (i > 0 && a[i] == 0 && a[i - 1] == 0) {
			std::cout << -1 << "\n";
			return;
		}

		if (a[i] == 1) {
			if (i > 0 && a[i - 1] == 1) {
				height += 5;
			}
			else {
				height += 1;
			}
		}
	}
	std::cout << height << "\n";
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