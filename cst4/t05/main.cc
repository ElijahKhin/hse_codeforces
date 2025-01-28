#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n, k;
	std::vector<int> a, b, u;

	std::cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		int p;

		std::cin >> p;
		a.push_back(p);
	}

	for (int i = 0; i < k; ++i) {
		int p;

		std::cin >> p;
		b.push_back(p);
	}
	std::sort(b.begin(), b.end());
	int prev = 0;
	for (int i = 0, j = 0; i < n; ++i) {
		if (!a[i] && j < k) {
			++j;
			auto it = std::find_if(b.begin(), b.end(), [&prev](int val) {return val < prev;});
			if (it == b.end()) {
				prev = b.back();
				b.pop_back();
			}
			else {
				std::cout << "YES\n";
				return 0;
			}
		}
		else {
			if (prev > a[i]) {
				std::cout << "YES\n";
				return 0;
			}	
			else {
				prev = a[i];
			}
		}
	}
	std::cout << "NO\n";
}
