#include <iostream>
#include <string>

bool inSet(char ch) {
	std::string set("aoyeui");

	for (int i = 0; i < 6; i++) {
		if (ch == set.at(i)) return true;
	}
	return false;	
}

int main() {
	std::string str;

	std::getline(std::cin, str);

	for (int i = 0; i < (int)str.length(); i++) {
		char ch = std::tolower(str.at(i));
		if (!inSet(ch)) {
			std::cout << "." << ch;
		}
	}
	std::cout << std::endl;
}
