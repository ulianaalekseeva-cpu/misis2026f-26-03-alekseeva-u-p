#include <iostream>
#include <string>

int main() {
	int n;
	std::string s;
	if (std::cin >> n >> s) {
		int x = 0, y = 0;
		int coins = 0;
		int last_side = 0;

		for (char c : s) {
			if (c == 'R') {
				x++;
			}
			else if (c == 'U') {
				y++;
			}

			int current_side = 0;
			if (x > y) {
				current_side = 1;
			}
			else if (x < y) {
				current_side = 2;
			}

			if (last_side != 0 && current_side != 0 && last_side != current_side) {
				coins++;
			}

			if (current_side != 0) {
				last_side = current_side;
			}
		}

		std::cout << coins << "\n";
	}
	return 0;
}