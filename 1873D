#include <iostream>
#include <algorithm>
#include <string>

void solve() {
	int n, k, c=0;
	std::cin >> n >> k;
	std::string s;
	std::cin >> s;
	for (int i = 0; i < n-k; i++) {
		if (s[i] == 'B') {
			for (int j = i; j < i+k; j++) {
				s[j] = 'W';
			}
			c++;
		}
	}
	for (int i = n-k; i<n; i++){
		if (s[i] == 'B') {
			c++;
			break;
		}
	}
	std::cout << c<<std::endl;

}
int main() {
	int t;
	std::cin >> t;
	while (-t) {
		solve();
	}
}
