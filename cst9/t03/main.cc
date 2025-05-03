#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int s,b;
	long long summ=0;
	std::cin >> s >> b;

	std::vector<std::pair<int, int>> a(s);
	std::vector<std::pair<int, int>> c(b);

	for (int i = 0; i < s; ++i) {
		std::cin >> a[i].first;
		a[i].second = i;
	}
	std::sort(a.begin(), a.end());

	for (int i = 0; i < b; ++i) {
		std::cin >> c[i].first >> c[i].second;
	}
	std::sort(c.begin(), c.end());

	std::vector<int> res(s);
	for (int i = 0, j = 0; i < b && j < s; ++i) {
		while (j < s && c[i].first > a[j].first) {
			res[a[j].second] = summ;
			++j;
		}
		summ += c[i].second;
		if (i == b - 1) {
			while (j < s) {
				res[a[j].second] = summ;
				++j;
			}
		}
	}
	for (auto& i : res) {
		std::cout << i << ' ';
	}
}
