#include <iostream>
#include <string>
#include <stdlib.h>


int main(void) {
	std::string input;
	std::getline(std::cin, input);
	int i = std::stoi(input);
	if (!(i % 2) && i != 2) std::cout << "YES" << std::endl;
	else std::cout << "NO" << std::endl;
}

