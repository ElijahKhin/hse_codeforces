#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;

	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		int n;
		std::cin >> n;
		std::cout << n - 1 << '\n';; 
		std::cout << 2; 
		for (int j = 2; j < n; ++j) {
			std::cout << " " << j + 1; 
		}
		std::cout << '\n';; 
	}
}
