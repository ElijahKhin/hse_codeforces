#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, k;
	
	std::cin >> n >> k;
	std::vector<int> a(n);
//	std::set<int> aa(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
//		std::cin >> aa[i];
	}
//	if (aa.size() == 1)  {
//		std::cout << n << '\n';
//		return 0;
//	}
	std::sort(a.begin(), a.end());
//	for(auto& i : a) {
//		std::cout << i << ' ';
//	}
//	std::cout << '\n';
	int z = 0, res = n;
	for (int i = 1; i < n; ++i) {
//		std::cout <<"i: " << i << " z: " << z << " a[i]: " << a[i] << " a[z]: " << a[z] << '\n';
		while (z < i && a[i] - a[z] > k) {
			++z;
//			std::cout << "drop\n";
		}
		while (z < i && a[i] > a[z] && a[i] - a[z] <= k) {
//			std::cout << "here" << '\n';
			--res;
			++z;
		}
	}
	std::cout << res<< '\n';
//	std::cout << (res == n ? n : res - 1) << '\n';
}
