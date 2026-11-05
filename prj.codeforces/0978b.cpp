#include <iostream>
#include <string>

int main() {

	int n;
	std::string s;

	if (std::cin >> n >> s) {
		int deleted_count = 0;
		int consecutive_x = 0;

		for (int i = 0; i < n; ++i) {
			if (s[i] == 'x') {
				consecutive_x++;
				if (consecutive_x > 2) {
					deleted_count++;
				}
			}
			else {
				consecutive_x = 0;
			}
		}

		std::cout << deleted_count << "\n";
	}

	return 0;
}