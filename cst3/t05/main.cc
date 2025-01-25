#include <iostream>
#include <string>
#include <vector>

int main() {
	std::string first, last, heap, shared;

	std::getline(std::cin, first);
	std::getline(std::cin, last);
	std::getline(std::cin, heap);
	shared = first + last;	
	for (int i = 0; i < (int)shared.size(); i++) {
		int mark = heap.size();
		for (int j = 0; j < (int)heap.size(); j++) {
			if (shared[i] == heap[j]) {
				heap.erase(j, 1);
				break;
			}
		}
		if (mark == (int)heap.size()) {
			std::cout << "NO" << std::endl;
			return 0;
		}
	}
	if (heap.size()) {
		std::cout << "NO" << std::endl;
	}
	else {
		std::cout << "YES" << std::endl;
	}
}
