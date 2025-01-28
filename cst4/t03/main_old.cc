#include <iostream>
#include <string>
#include <vector>
#include <numeric>

int getCombo(int& x, int summ, std::vector<int>& pieces, std::vector<int>& visited) {
	int res = 0;	

	std::cout << x << " " << summ << '\n';
	for (int i = 0; i < (int)pieces.size(); i++) {
		int tst = 0;
		if (std::find(visited.begin(), visited.end(), i) == visited.end())
			tst = summ + pieces[i];

		std::cout << "current_summ " << tst << '\n';
		if (tst) {
			if (tst > x) {
				visited.push_back(i);
				return 1;
			}
			if (tst != x) {
				visited.push_back(i);
				res = getCombo(x, tst, pieces, visited);
			}
			if (res) {
				return 1;
	 	  }
			else if (res && tst != x) {
				std::cout << visited.back() << '\n';
				visited.pop_back();
			}
		}	
	}
	return 0;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int t;

	std::cin >> t;
	std::cin.ignore();

	while(--t >= 0) {
		int n, x, p, ttl_summ, diff;
		
		std::cin >> n >> x;
		std::cin.ignore();

		if (n == 1) {
			std::cin >> p;
			std::cin.ignore();
			if (p == x) {
				std::cout << "NO" << '\n';
			}
			else {
				std::cout << "YES" << '\n' << p << '\n';
			}
			continue;
		}


		std::vector<int> pieces;
		int mark = -1;

		for (int i = 0; i < n; ++i) {
			std::cin >> p;
			std::cin.ignore();
			if (p == x) {
				mark = i;  
			}
			pieces.push_back(p);
		}
		if (mark != -1) {
			int printed;
			if (mark) {
				printed = 0;
			}
			else {
				printed = 1;
			}
			std::cout << "YES\n" << pieces[printed] << " " << pieces[mark];
			for (int i = 0; i < n; ++i) {
				if (i != mark && i != printed) {
					std::cout << " " << pieces[i];
				}
			}
			std::cout << '\n';
			continue;
		}
		ttl_summ = std::accumulate(pieces.begin(), pieces.end(), 0);
		diff = ttl_summ - x;
		if (diff < 0) {
			std::cout << "YES\n" << pieces[0];
			for (int i = 1; i < n; ++i) {
				std::cout << " " << pieces[i];
			}	
			std::cout << '\n';
		}
		else if (diff > 0) {
			auto it = std::find_if(pieces.begin(), pieces.end(), [&](int& piece) { return piece > x; });
			if (it != pieces.end()) {
				std::cout << "YES\n" << *it;
				for (int i = 0; i < n; ++i) {
					std::cout << " " << pieces[i];
				}
				continue;
			}
			std::vector<int> visited;
			int res = getCombo(x, 0, pieces, visited);
			if (res) {
				for (int i = 0; i < (int)visited.size(); ++i) {
					std::cout << pieces[visited[i]];
				}
				for (int i = 0; i < n; ++i) {
					if (std::find(visited.begin(), visited.end(), i) == visited.end()) {
						std::cout << pieces[i];
					}
				}
				std::cout << '\n';
			}
			else {
				std::cout << "NO" << '\n';
			}
		}
	}
}
