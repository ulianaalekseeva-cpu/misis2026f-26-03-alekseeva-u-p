#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
	int a, b;
	cin >> a >> b;
	string s;
	cin >> s;
	int n = s.length();
	for (int i = 0; i < n / 2; ++i) {
		int j = n - 1 - i;
		if (s[i] != '?' && s[j] != '?') {
			if (s[i] != s[j]) {
				cout << -1 << "\n";
				return;
			}
		}
		else if (s[i] != '?') {
			s[j] = s[i];
		}
		else if (s[j] != '?') {
			s[i] = s[j];
		}
	}
	int zeros = 0, ones = 0;
	for (char c : s) {
		if (c == '0') zeros++;
		if (c == '1') ones++;
	}
	if (zeros > a || ones > b) {
		cout << -1 << "\n";
		return;
	}
		int j = n - 1 - i;
		if (s[i] == '?') {
			if (a - zeros >= 2) {
				s[i] = '0';
				s[j] = '0';
				zeros += 2;
			}
			else if (b - ones >= 2) {
				s[i] = '1';
				s[j] = '1';
				ones += 2;
			}
			else {
				cout << -1 << "\n";
				return;
			}
		}
	}
	if (n % 2 != 0 && s[n / 2] == '?') {
		if (a - zeros >= 1) {
			s[n / 2] = '0';
			zeros++;
		}
		else if (b - ones >= 1) {
			s[n / 2] = '1';
			ones++;
		}
		else {
			cout << -1 << "\n";
			return;
		}
	}
	if (zeros == a && ones == b) {
		cout << s << "\n";
	}
	else {
		cout << -1 << "\n";
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
