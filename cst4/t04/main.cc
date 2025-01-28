#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t, n, k;
	
	std::cin >> t; std::cin.ignore();
	for (int i = 0; i < t; ++i) {
		std::cin >> n >> k; std::cin.ignore();	

		std::string s;
		std::getline(std::cin, s);
		if (!k) {
			std::cout << "YES" << '\n';
		}
		else {
			int d = (n % 2 == 0), kth = 0;
			for (int i = 0, j = (int)s.size() - 1; i < (n / 2 - d); ++i, --j) {
				if (s[i] == s[j]) ++kth;
				else break;
			}
			if (kth >= k) {
				std::cout << "YES" << '\n'; 
			}
			else {
				std::cout << "NO" << '\n';
			}
		}
	}
}
