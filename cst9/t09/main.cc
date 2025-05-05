#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	std::stack<int> st;

	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	
	for (int i = 0; i < n; ++i) {
		while (!st.empty() && a[st.top()] <= a[i]) {
			st.pop();
		}
		if (st.empty()) {
			std::cout << -1 << ' ';
		}
		else
			std::cout << st.top() + 1 << ' ';
		st.push(i);
	}
	return 0;
}
