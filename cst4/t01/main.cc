#include <iostream>
#include <string>
#include <vector>

#define opt std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

int getSubs(std::string& s) {
	int j = 0;
	char last = '2';
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == '0' && s[i] != last) j++;
		if (j == 2) return 2;
		last = s[i];
	}
	return j;
}

int main() {
	opt;
	int t;
	std::string s;

	std::cin >> t;
	std::cin.ignore();
	while (--t >= 0) {
		std::getline(std::cin, s);
		int res = getSubs(s);
		if (!res) {
			std::cout <<  (s[0] == '1' ? 0 : 1) << '\n';;
		}
		else if (res == 1) {
			std::cout << 1 << '\n';
		}
		else {
			std::cout << 2 << '\n';
		}
	}
}
