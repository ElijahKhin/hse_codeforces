#include <iostream>

int main() {
	int ones = 0, zeros = 0;

	while (char ch = std::cin.get()) {
		if (ch == '1') {
			ones++;
			zeros = 0;
		}
		if (ch == '0') {
			ones = 0;
			zeros++;
		}
		if (ones == 7 || zeros == 7) {
			std::cout << "YES" << std::endl;
			return 0;
		}
		if (ch == '\n') break; 
	}
	std::cout << "NO" << std::endl;
}
