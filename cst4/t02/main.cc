#include <iostream>
#include <string>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int t;
	unsigned int n, m, i, j;

	std::cin >> t;
	std::cin.ignore();
	while(--t >= 0) {
		std::cin >> n >> m >> i >> j;
		std::cin.ignore();
		if (n / 2 < i) {
			if (m / 2 < j) {
				std::cout << 1 << " " << 1 << " " << n << " " << m <<  '\n';
			}
			else {
				std::cout << 1 << " " << m << " " << n << " " << 1 <<  '\n';
			}
		}
		else {
			if (m / 2 < j) {
				std::cout << n << " " << 1 << " " << 1 << " " << m <<  '\n';
			}
			else {
				std::cout << n << " " << m << " " << 1 << " " << 1 <<  '\n';
			}
		}
	}
}
