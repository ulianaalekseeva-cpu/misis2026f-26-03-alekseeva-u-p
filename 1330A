#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>ans;


void solve() {
	int n, x;
	std::cin >> n >> x;
	std::vector<int>V(n);
	for (int i = 0; i < n; i++) {
		std::cin >> V[i];
	}
	sort(V.begin(), V.end());
	int v = 0;
	for (int c = 1; c<=200; c++) {
		bool found = false;
		for (int i = 0; i < n; ++i) {
			if (V[i] == c) {
				found = true;
				break;
			}
		}
		if (found) {
			v = c;
		}
		else {
			if (x > 0) {
				x--;
				v = c;
			}
			else {
				break;
			}
		}
	}
	ans.push_back(v);
}

int main(){
	int t;
	std::cin >> t;
	while (t--) {
		solve();
	}
	for (int i = 0;i < ans.size();i++) {
		std::cout << ans[i]<<endl;
	}
}
