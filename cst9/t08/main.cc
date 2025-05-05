#include <iostream>
#include <deque>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::deque<int> q;

  for (int i = 0; i < n; ++i) {
    std::string sgn;
    std::cin >> sgn;

		if (sgn == "+") {
			int number;
			std::cin >> number;
			q.push_back(number);
		}
		else if (sgn == "*") {
			int number;
			std::cin >> number;
			q.insert(q.begin() + (q.size() + 1) / 2, number);	
		}
		else {
			std::cout << q.front() << '\n';
			q.pop_front();
		}
  }

  return 0;
}
