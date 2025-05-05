#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
	std::deque<int> q;

	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}

  for (int i = 0; i < n; i++) {
		while (!q.empty() && a[q.back()] > a[i]) {
			q.pop_back();
		}
		q.push_back(i);
		if (q.front() <= i - k) {
			q.pop_front();
		}
		if (k - 1 <= i) {
			std::cout << a[q.front()] << '\n';
		}
  }
}

