#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

int get_pair(int left) {
	if (left == '(')
		return ')';
	else if (left == '[')
		return ']';
	else 
		return '}';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::stack<int> st;

	std::string s;
	std::getline(std::cin, s);

	for (auto& i : s) {
		if (i == '(' || i == '[' || i == '{') {
			st.push(i);
		}
		else {
			if (st.empty()) {
				std::cout << "no" << '\n';
				return 0;
			}
			if (get_pair(st.top()) != i) {
				std::cout << "no" << '\n';
				return 0;
			}
			else {
				st.pop();
			}
		}
	}
	if (st.empty())
		std::cout << "yes\n";
	else
		std::cout << "no\n";
	return 0;
}
