#include <iostream>
#include <string>
#include <vector>

int main() {
	int n,curr, cnt = 1;
	std::string s;
	std::vector<int> nums, chars;

	std::cin >> n;
	std::cin.ignore();
	std::getline(std::cin, s);
	
	curr = s[0];
	for (int i = 1; i < (int)s.size(); i++) {
		if (curr == s[i]) cnt++;
		else {
			chars.push_back(s[i-1]);
			nums.push_back(cnt);
			curr = s[i];
			cnt = 1;
		}
	}
	chars.push_back(s[s.size() - 1]);
	nums.push_back(cnt);
	int ans = 0;
	for (int i = 0; i < (int)chars.size(); i++) {
		if (nums[i] > 2 && chars[i] == 'x') 
			ans += (nums[i] - 2);
	//	std::cout << (char)chars[i] << " " << nums[i] << std::endl;
	}
	std::cout << ans << std::endl;
}
