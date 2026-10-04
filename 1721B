#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


int main() {
	int t;
	std::cin >> t;
	std::vector<int>V(t);

	while (t--) {
		int n, m, s1, s2, d;
		std::cin >> n >> m >> s1 >> s2 >> d;

		if (std::min(s1 - 1, m - s2) <= d && std::min(n - s1, s2 - 1) <= d) {
			V.push_back(-1);
		}
		else {
			V.push_back(n + m - 2);
		}
	}
	for (int i = 0; i < V.size(); i++) {
		if (V[i] != 0) {
			std::cout << V[i] << std::endl;
		}

	}
	return 0;
}
