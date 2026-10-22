#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>



void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::string> grid(n);

	int start_mask = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> grid[i];
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] == 'R') {
				start_mask |= (1 << (i * m + j));
			}
		}
	}

	std::queue<int> q;
	std::unordered_set<int> visited;

	q.push(start_mask);
	visited.insert(start_mask);

	int dr[] = { -1, 0, 1, 0 };
	int dc[] = { 0, 1, 0, -1 };

	while (!q.empty()) {
		int mask = q.front();
		q.pop();

		if (mask & 1) {
			std::cout << "YES\n";
			return;
		}

		for (int d = 0; d < 4; ++d) {
			int next_mask = 0;
			bool valid = true;

			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					if ((mask & (1 << (i * m + j))) != 0) {
						int ni = i + dr[d];
						int nj = j + dc[d];

						if (ni < 0 || ni >= n || nj < 0 || nj >= m) {
							valid = false;
							break;
						}
						next_mask |= (1 << (ni * m + nj));
					}
				}
				if (!valid) break;
			}

			if (valid && visited.find(next_mask) == visited.end()) {
				visited.insert(next_mask);
				q.push(next_mask);
			}
		}
	}

	std::cout << "NO\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
