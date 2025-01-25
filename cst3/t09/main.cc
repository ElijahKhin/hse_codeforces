#include <iostream>
#include <vector>
#include <string>

void PrintOmega(int n, std::string s) {
	for (int i = 0; i < n; i++) {
		bool val = 0;
		for (int j = i; j < (n + i); j++)
			val = val || (s[j] - 48);
		std::cout << val;
	}
	std::cout << std::endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	int t, n;
	std::string s;
	
	std::cin >> t;
	std::cin.ignore();

	while(--t>=0){
		std::cin >> n;
		std::cin.ignore();
		std::getline(std::cin, s);
		PrintOmega(n, s);
	}
}
