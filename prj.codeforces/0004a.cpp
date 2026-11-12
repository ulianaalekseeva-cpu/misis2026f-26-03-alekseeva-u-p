#include<iostream>

int32_t main() {
	int w; std::cin >> w;
	if (w > 2 && w % 2 == 0) std::cout << "YES";
	else std::cout << "NO";
}