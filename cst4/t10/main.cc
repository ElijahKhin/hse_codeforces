#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;

	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		int n, res = 0;
		std::cin >> n;
		std::vector<int> r(n);
		for (int j = 0; j < n; ++j) {
			std::cin >> r[j];
		}
		for (int& j : r) {
			if (j != 2) ++res;
		}
		std::cout << res << '\n';
	}
}
