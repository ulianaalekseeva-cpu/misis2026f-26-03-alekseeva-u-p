#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n, k, c = 0;
	std::cin >> n >> k;
	std::vector<int>V(n);
	for (int i = 0; i < n; i++) {
		std::cin >> V[i];
	};
	int cur = 0;
	std::sort(V.begin(), V.end(), std::greater<int>());
	for (int i =  0; i < n; i++) {
		if (k % V[i] == 0) {
			c = k / V[i];
			break;
		}
	}
	std::cout << c;
			
}
