#include <iostream>
#include <vector>
#include <cmath>


int main() {
//    int res = 0;
		std::vector<int> a(5); 
		
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				std::cin >> a[j];
				if (a[j]) {
					std::cout << std::abs(2 - i) + std::abs(2 - j) << std::endl;
					break;
				}
			}
		} 
}
