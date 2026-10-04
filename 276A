#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	std::cin >> n >> k;

	struct point {
		int f;
		int t;
	};
	vector <point>V(n);
	for (int i = 0; i < n; i++) {
		std::cin >> V[i].f>>V[i].t;
	}
	for (int i = 0; i < n; i++) {
		if (V[i].t > k) {
			V[i].f = V[i].f - (V[i].t - k);
		}
	}
	int ansf = -10000000;
	for (int i = 0; i < n; i++) {
		if (V[i].f > ansf) {
			ansf = V[i].f;
		}
	}
	std::cout << ansf;
}
