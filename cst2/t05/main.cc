#include <iostream>

int main() {
	int i = 0, a, b;

	std::cin >> a >> b;
	
	while (a <= b) {
		++i;
		a *= 3;	
		b *= 2;	
	}
	std::cout << i << std::endl;
}
