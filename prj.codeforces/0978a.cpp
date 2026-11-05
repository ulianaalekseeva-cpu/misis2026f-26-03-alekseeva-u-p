#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	if (!(cin >> n)) return 0;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<int> result;
	set<int> seen;

	for (int i = n - 1; i >= 0; --i) {
		if (seen.find(a[i]) == seen.end()) {
			seen.insert(a[i]);
			result.push_back(a[i]);
		}
	}

	cout << result.size() << "\n";
	for (int i = result.size() - 1; i >= 0; --i) {
		cout << result[i] << (i == 0 ? "" : " ");
	}
	cout << "\n";

	return 0;
}