#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int k;
    std::cin >> k;
    std::vector<int>V(k);
    for (int i = 0; i < k; i++) {
        int a, b, c, sh = 0;
        std::cin >> a >> b >> c;
        int t = abs(a - b);
        if (a > b) {
            while (a > b ) {
                sh++;
                a -= c;
                b += c;
            }
        }
        else {
            while (b >a) {
                sh++;
                a += c;
                b -= c;
            }
        }
        V[i]=sh;

    }
    for (int i = 0; i < V.size(); i++) {
        std::cout << V[i] << std::endl;
    }
}
