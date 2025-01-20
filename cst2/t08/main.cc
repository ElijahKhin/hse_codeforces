#include <iostream>

int main() {
	int x;

	std::cin >> x;
	if (x <= 5) {
		std::cout << 1 << std::endl;
	}
	else {
		if (x % 5) {
			std::cout << x / 5 + 1 << std::endl;
		}
		else {
			std::cout << x / 5 << std::endl;
		}
	}
}
