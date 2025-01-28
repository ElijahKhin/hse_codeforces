#include <iostream>
#include <string>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t, n;

	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		std::cin >> n;
		std::string s = std::string(n, '(') + std::string(n, ')');
		std::cout << s << '\n';
		for (int i = 1, j = 2*n - 2; i < n; ++i, --j) {
			std::cout << 
				std::string_view(s.begin(), s.begin() + i) <<
				')' <<
				std::string_view(s.begin() + i + 1, s.begin() + n) << 
				std::string_view(s.begin() + n, s.begin() + j) << 
				'(' << 
				std::string_view(s.begin() + j + 1, s.end()) << 
				'\n'; 
		}
	}
}
