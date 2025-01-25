#include <iostream>
#include <string>
#include <vector>

int main() {
	int n, mark1 = 0, mark2 = 0;
	std::string pass, part;

	std::getline(std::cin, pass);
	std::cin >> n;
	std::cin.ignore();

	while (--n >= 0) {
		std::getline(std::cin, part);
		if (part == pass) {
			mark1 = 1;
			mark2 = 1;
		}
		if (part[1] == pass[0])
			mark1 = 1;
		if (part[0] == pass[1])
			mark2 = 1;
	}
	if (mark1+mark2 == 2)
		std::cout << "YES" << std::endl;
	else
		std::cout << "NO" << std::endl;
}
