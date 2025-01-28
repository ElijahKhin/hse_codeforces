#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int t, x;
	
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		std::cin >> x;
		std::cout << x - 1 << " " << 1 << '\n';
	}
}
