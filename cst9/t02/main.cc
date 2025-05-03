#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

#define min(string, i) *(std::min_element(string.begin() + i, string.end()))

static inline void reload_all2min(size_t& idx, std::vector<int>& s, std::stack<int>& t) {
	int min_el = min(s, idx);
	for ( ; s[idx] > min_el; ++idx) {
		t.push(s[idx]);
	}
	while (s[idx] == min_el) {
		t.push(s[idx]);
		++idx;
	}
}

static inline void print(std::queue<int> u) {
	while(!u.empty()) {
		std::cout << (char)u.front();
		u.pop();
	}
	std::cout << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string input;
	std::vector<int> s;
	std::stack<int> t;
	std::queue<int> u;
	
	std::getline(std::cin, input);
	for (auto& i : input) {
		s.push_back(i);
	}

	size_t idx = 0;

	reload_all2min(idx, s, t);
	while (!t.empty()) {
		if (idx == s.size()) {
			while (!t.empty()) {
				u.push(t.top());
				t.pop();
			}
			print(u);
			return 0;
		}
		while (t.top() < min(s, idx)) {
			u.push(t.top());
			t.pop();
			if (t.empty()) break;
		}
		reload_all2min(idx, s, t);
	}
	print(u);
	return 0;
}
