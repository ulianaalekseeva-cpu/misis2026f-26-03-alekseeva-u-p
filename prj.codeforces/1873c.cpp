#include <iostream>
#include <string>
#include <algorithm>

void solve() {
	int score = 0;
	for (int i = 0; i < 10; ++i) {
		std::string row;
		std::cin >> row;
		for (int j = 0; j < 10; ++j) {
			if (row[j] == 'X') {
				int dist = std::min({ i, j, 9 - i, 9 - j });
				score += dist + 1;
			}
		}
	}
	std::cout << score << "\n";
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