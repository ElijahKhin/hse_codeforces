#include <iostream>

int main() {
	char ch;

	ch = std::cin.get();

	if (ch >= 97 && ch <= 123) {
		std::cout << (char)(ch - 32);
	}
	else {
		std::cout << ch;
	}
	while (ch != '\n') {
		ch = std::cin.get();
		std::cout << ch;
	}
	std::cout << std::endl;
}
