#include <iostream>
#include <vector>
#include <string>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t, n, k;
	
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		std::cin >> n >> k;

		std::vector<int> a(n);

		for (int j = 0; j < n; ++j) {
			std::cin >> a[j];
		}
		for (int z = 0; z < k; ++z) {
			bool isAdded = false;
			int j = 0;
			while (!isAdded && j < n - 1) {
				if (a[j]) {
					a[j] -= 1;
					a.back() += 1; 
					isAdded = true;
				}
				++j;
			}
		}
		for (auto& it : a) {
			std::cout << it << " ";
		}
		std::cout << '\n';
	}
}
