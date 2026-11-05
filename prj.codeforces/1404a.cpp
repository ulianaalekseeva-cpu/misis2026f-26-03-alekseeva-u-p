#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	vector<int> val(k, -1);

	for (int i = 0; i < n; ++i) {
		if (s[i] != '?') {
			int v = s[i] - '0';
			int rem = i % k;
			if (val[rem] != -1 && val[rem] != v) {
				cout << "NO\n";
				return;
			}
			val[rem] = v;
		}
	}

	int cnt0 = 0, cnt1 = 0;
	for (int i = 0; i < k; ++i) {
		if (val[i] == 0) cnt0++;
		else if (val[i] == 1) cnt1++;
	}
	if (cnt0 > k / 2 || cnt1 > k / 2) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
	}
}

int main() {
	int t;
	if (cin >> t) {
		while (t--) {
			solve();
		}
	}
	return 0;
}
