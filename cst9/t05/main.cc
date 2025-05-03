#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	std::vector<int> even, odd;

	for (int i = 0; i < n; ++i) {
		int val;
		std::cin >> val;
		if (val % 2 == 0) {
			even.push_back(val);
		}
		else {
			odd.push_back(val);
		}
		a[i] = val;
	}
	if (!odd.size() || !even.size()) {
		for (int j = 0; j < n; ++j) {
			std::cout << a[j] << ' ';
		}
		return 0;
	}
	else {
		std::sort(a.begin(), a.end());
		for (auto& i : a) {
			std::cout << i << ' ';
		}
		std::cout << '\n';
	}
}
