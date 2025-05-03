#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::string s;
	std::stack<int> left_sk;
	int val = 0, mval = 0, mcnt = 0;

	std::getline(std::cin, s);

	for (auto& i : s) {
		if (i == '(') {
			left_sk.push(1);
		}
		else {
			if (!left_sk.empty()) {
				left_sk.pop();
				val += 2;
				if (left_sk.empty()) {
					if (val == mval && mval) {
						++mcnt;
					}
					else if (val > mval) {
						mcnt = 1;
						mval = val;
					}
					val = 0;
				}
			}
		}
	}
	if (val > mval) {
		mcnt = 1;
		mval = val;
	}
	else if (val == mval && mval) {
		++mcnt;	
	}
	else if (!val && !mval) {
		mcnt = 1;
	}
	std::cout << mval << ' ' << mcnt << '\n';
}
