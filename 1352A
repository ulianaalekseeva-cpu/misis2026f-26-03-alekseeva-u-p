#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    std::string s;
    std::cin >> s;

    std::vector<int> ans;
    int n = s.length();

    for (int i = 0; i < n; ++i) {
        if (s[i] != '0') {
            int digit = s[i] - '0';
            int power = 1;
            for (int j = 0; j < n - 1 - i; ++j) {
                power *= 10;
            }
            ans.push_back(digit * power);
        }
    }

    std::cout << ans.size() << "\n";

    for (int i = 0; i < ans.size(); ++i) {
        std::cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
    }
    std::cout << "\n";
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
