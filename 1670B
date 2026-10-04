#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
	int t;
	std::cin >> t;
	std::vector<int>anS;
	while (t--){
		int n, m;
		std::string s;
		std::cin >> n >> s >> m;
		std::vector<char>V(m);
		for (int i = 0; i < n; i++) {
			std::cin >> V[i];
		}
		int l = s.length(), c= 0;
		for (int i = 0; i < s.length()-1; i++) {
			for (int j = 0; j < m; j++) {
				if (s[i + 1] == V[j]) {
					s.erase(i, 1);
					if (l != s.length()) {
						c++;
					}
				}
			}
		}
		anS.push_back(c);
	}
	for (int i = 0; i < anS.size(); i++) {
		if (anS[i] != 0) {
			std::cout << anS[i];
		}
	}
}
