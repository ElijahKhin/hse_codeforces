#include <iostream>

bool isPalindrome(std::string s) {
	for (int i = 0, j = s.size() - 1; i < (int)s.size() / 2; i++, j--)
		if (s[i] != s[j]) return 0;
	return 1;
}

void DoAntiPalindrome(std::string& s, std::vector<int>& info) {
	char tmp;
	
	tmp = s[info[0] - 1];
	s[info[0] - 1] = s[info[0]];
	s[info[0]] = tmp;
}

void getInfo(std::string& s, std::vector<int>& info) {
	int curr = s[0], cnt = 1;

	for (int i = 1; i < (int)s.size(); i++) {
		if (curr == s[i]) {
			cnt++;
		}
		else {
			info.push_back(cnt);
			curr = s[i];
			cnt = 1;
		}
	}
	info.push_back(cnt);
}

int main() {
	int t;
	std::string s;
	std::vector<int> info;

	std::cin >> t;
	std::cin.ignore();

	while (--t >= 0) {
		std::getline(std::cin, s);
		if (isPalindrome(s)) {
			getInfo(s, info);
			if (info.size() > 1) {
				DoAntiPalindrome(s, info);
				std::cout << s << std::endl;
			} 
			else {
				std::cout << -1 << std::endl;
			}
		}
		else {
			std::cout << s << std::endl;
		}
		info.clear();
	}
}
