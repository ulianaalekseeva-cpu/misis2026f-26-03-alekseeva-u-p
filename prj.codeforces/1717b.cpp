#include <iostream>
#include <vector>

void solve() {
	int n, k, r, c;
	std::cin >> n >> k >> r >> c;

	r--;
	c--;

	int target_mod = (r + c) % k;

	std::vector<std::vector<char>> grid(n, std::vector<char>(n, '.'));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if ((i + j) % k == target_mod) {
				grid[i][j] = 'X';
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cout << grid[i][j];
		}
		std::cout << "\n";
	}
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