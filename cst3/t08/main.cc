#include <iostream>
#include <string>
#include <vector>

int getEntries(std::string sub, std::string s) {
	int res = 0;
	for (int i = 0; i < (int)s.size() - 1; i++) {
		if (sub[0] == s[i] && sub[1] == s[i+1])
			res++;
	}
	return res;
}

int main() {
	int n,res, max = 0;
	std::string s, sub, ans;

	std::cin >> n;
	std::cin.ignore();
	std::getline(std::cin, s);

	for (int i = 0; i < (int)s.size() - 1; i++) {
		sub.push_back(s[i]);
		sub.push_back(s[i+1]);
		res = getEntries(sub, s);
		if (res > max){
			max = res;
			ans = sub;
		}
		sub.clear();
	}
	std::cout << ans << std::endl;
}
