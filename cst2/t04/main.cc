#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	std::vector<int> unq;
	int ch;

	ch = std::cin.get();
	while (ch != '\n') {
		if (std::find(unq.begin(), unq.end(), ch) == unq.end()) {
			unq.push_back(ch);
		}
		ch = std::cin.get();
	}
	if (unq.size() % 2 == 0) {
		std::cout << "CHAT WITH HER!" << std::endl;
	}
	else {
		std::cout << "IGNORE HIM!" << std::endl;
	}
}
