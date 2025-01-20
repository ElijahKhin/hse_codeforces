#include <iostream>
#include <string>



int main() {
	std::string input;
	int low = 0, high = 0;

	std::getline(std::cin, input);
	for (int i = 0; i < (int)input.size(); i++) {
		if (input[i] >= 65 && input[i] <= 90) {
			high++;
		}
		else {
			low++;
		}
	}
	if (high > low) {
		for (int i = 0; i < (int)input.size(); i++) {
			if (!(input[i] >= 65 && input[i] <= 90)) {
				std::cout << (char)(input[i] - 32);
			}
			else {
				std::cout << input[i];
			}
		}
	}
	else {
		for (int i = 0; i < (int)input.size(); i++) {
			if (input[i] >= 65 && input[i] <= 90) {
				std::cout << (char)(input[i] + 32);
			}
			else {
				std::cout << input[i];
			}
		}
	}
	std::cout << std::endl;
}
