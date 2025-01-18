#include <iostream>

int main() {
	int dum, del = 0, prev, curr = 0;

	std::cin >> dum;
	prev = std::cin.get();

	while (--dum >= 0) {
		curr = std::cin.get();
		if (prev == curr) {
			del += 1;
		}
		else {
			prev = curr;
		}
	}
	std::cout << del << std::endl;
}
