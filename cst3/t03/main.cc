#include <iostream>
#include <string>
#include <vector>

int toLower(char ch) {
	if (ch >= 97 && ch <= 122)
		return ch;
	return ch + 32;
}

int main() {
	int n;
	std::string s;
	std::vector<int> dict(26, 0);

	std::cin >> n;
	std::cin.ignore();
	std::getline(std::cin, s);
	if (n < 26) {
		std::cout << "NO" << std::endl;
		return 0;
	}
	for (int i = 0; i < (int)s.size(); i++) {
		int lower = toLower(s[i]); 
		dict[lower - 97]++;
	}
	for (int i = 0; i < (int)dict.size(); i++) {
		if (!dict[i]) {
			std::cout << "NO" << std::endl;
			return 0;
		}
	}
	std::cout << "YES" << std::endl;
}
