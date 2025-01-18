#include <iostream>
#include <vector>

void getData(std::vector<int>& numbers) {
	char num = 0;

	num = std::cin.get();
	while (num != '\n') {
		if (num != '+') {
			numbers.push_back(num - 48);
		}
		num = std::cin.get();
	}
}

void printResult(std::vector<int> vec) {
	for (int i = 0; i < (int)vec.size(); i++) {
		std::cout << vec[i];
		if (i + 1 != (int)vec.size()) {
			std::cout << "+";
		}
	}
	std::cout << std::endl;
}

void SortBubble(std::vector<int>& numbers) {
	for (int i = 0; i < (int)numbers.size(); i++) {
		for (int j = i + 1; j < (int)numbers.size(); j++) {
			int tmp = numbers.at(i);	
			if (numbers.at(i) > numbers.at(j)) {
				numbers.at(i) = numbers.at(j);
				numbers.at(j) = tmp;
			}
		}
	}
}

int main() {
	std::vector<int> numbers;
	getData(numbers);
	SortBubble(numbers);
	printResult(numbers);
}
