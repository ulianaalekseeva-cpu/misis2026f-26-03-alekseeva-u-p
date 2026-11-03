#include <iostream>
#include <algorithm>

int main() {
	int n, m, c = 0;
	int m1= 1;
	std::cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int m2;
		std::cin >> m2;
		if (m2 - m1 > 0) {
			c += m2 - m1;
		}
		else if (m2 - m1 < 0) {
			c += 4 - (m1 - m2);
		}
		else if (m2==m1){
			c+=0;
		}
		m1 = m2;
	}
	std::cout << c;
}
