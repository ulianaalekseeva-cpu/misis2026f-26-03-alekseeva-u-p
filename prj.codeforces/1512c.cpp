#include <iostream>
#include <string>

void solve() {
	int a, b;
	std::cin >> a >> b;
	std::string s;
	std::cin >> s;
	int n = a + b;

	for (int i = 0; i < n / 2; ++i) {
		int j = n - 1 - i;
		if (s[i] == '?' && s[j] != '?') {
			s[i] = s[j];
		}
		else if (s[i] != '?' && s[j] == '?') {
			s[j] = s[i];
		}
		else if (s[i] != '?' && s[j] != '?' && s[i] != s[j]) {
			std::cout << -1 << "\n";
			return;
		}
	}

	int count0 = 0, count1 = 0;
	for (char c : s) {
		if (c == '0') count0++;
		else if (c == '1') count1++;
	}

	if (count0 > a || count1 > b) {
		std::cout << -1 << "\n";
		return;
	}

	int rem0 = a - count0;
	int rem1 = b - count1;

	for (int i = 0; i < n / 2; ++i) {
		int j = n - 1 - i;
		if (s[i] == '?') {
			if (rem0 >= 2) {
				s[i] = s[j] = '0';
				rem0 -= 2;
			}
			else if (rem1 >= 2) {
				s[i] = s[j] = '1';
				rem1 -= 2;
			}
			else {
				std::cout << -1 << "\n";
				return;
			}
		}
	}

	if (n % 2 != 0) {
		int mid = n / 2;
		if (s[mid] == '?') {
			if (rem0 > 0) {
				s[mid] = '0';
				rem0--;
			}
			else if (rem1 > 0) {
				s[mid] = '1';
				rem1--;
			}
			else {
				std::cout << -1 << "\n";
				return;
			}
		}
	}

	if (rem0 != 0 || rem1 != 0) {
		std::cout << -1 << "\n";
		return;
	}

	std::cout << s << "\n";
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
