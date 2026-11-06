#include <iostream>
#include <vector>
#include <string>

void solve() {
	std::vector<std::string> grid(8);
	for (int i = 0; i < 8; ++i) {
		std::cin >> grid[i];
	}

	for (int i = 1; i < 7; ++i) {
		for (int j = 1; j < 7; ++j) {
			if (grid[i][j] == '#' &&
				grid[i - 1][j - 1] == '#' &&
				grid[i - 1][j + 1] == '#' &&
				grid[i + 1][j - 1] == '#' &&
				grid[i + 1][j + 1] == '#') {
				std::cout << i + 1 << " " << j + 1 << "\n";
				return;
			}
		}
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