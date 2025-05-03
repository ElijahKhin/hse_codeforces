#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string s;
	std::cin >> s;

	int n = s.size();
	std::vector<char> min_suf(n + 1, 'z' + 1);

	for (int i = n - 1; i >= 0; --i) {
		min_suf[i] = std::min(min_suf[i + 1], s[i]);
	}

	std::stack<char> t;
	std::string u;
	int i = 0;

	while (i < n || !t.empty()) {
		while (!t.empty() && t.top() <= min_suf[i]) {
			u += t.top();
			t.pop();
		}
		if (i < n) {
			t.push(s[i]);
			++i;
		}
	}

	std::cout << u << '\n';
	return 0;
}
