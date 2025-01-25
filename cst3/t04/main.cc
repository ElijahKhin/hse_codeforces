#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	int t;
	std::string s;
	std::string q;

	std::cin >> t;
	std::cin.ignore();

	while (--t >= 0) {
		std::getline(std::cin, s);
		q.push_back(s[0]);
		for (int i = 1; i < (int)s.size() - 1; i++) {
			if (i % 2) {
				q.push_back(s[i]);
			}
		}
		q.push_back(s[s.size() - 1]);
		std::cout << q << std::endl;
		q.clear();
	}
}
