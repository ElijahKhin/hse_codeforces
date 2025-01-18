#include <iostream>
#include <string>


int main() {
	std::string left, right;

	std::getline(std::cin, left);
	std::getline(std::cin, right);

	for (int i = 0, j = 0; i < (int)left.length() && j < (int)right.length(); i++, j++) {
		if (std::tolower(left.at(i)) < std::tolower(right.at(j))) {
			std::cout << "-1" << std::endl; return 0;
		}
		if (std::tolower(left.at(i)) > std::tolower(right.at(j))) {
			std::cout << "1" << std::endl; return 0;
		}
	}
	std::cout << "0" << std::endl;

	
}
