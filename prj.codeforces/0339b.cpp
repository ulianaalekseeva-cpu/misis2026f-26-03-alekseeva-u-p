#include <iostream>

int main() {
	int n, m;
	std::cin >> n >> m;

	long long total_time = 0;
	int current_pos = 1;

	for (int i = 0; i < m; ++i) {
		int target;
		std::cin >> target;

		if (target >= current_pos) {
			total_time += (target - current_pos);
		}
		else {
			total_time += (n - current_pos + target);
		}
		current_pos = target;
	}

	std::cout << total_time << "\n";

	return 0;
}
