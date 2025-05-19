#include <iostream>

int main() {
	int x = 5;
	std::cout << "x: " << x << '\n';
	std::cout << "x << 1: " << (x << 1) << '\n';
	std::cout << "x << 1 | 1: " << (x << 1 | 1) << '\n';
}
