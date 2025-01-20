#include <iostream>

int main() {
	int n, k;

	std::cin >> n >> k;

	while (--k >= 0) {
		if (n % 10) {
			n -= 1;
		}
		else {
			n /= 10;
		}
	}
	std::cout << n << std::endl;
}
