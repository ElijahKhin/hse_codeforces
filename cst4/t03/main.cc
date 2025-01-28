#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int getCombo(int& x, int summ, std::vector<int>& pieces, std::vector<int>& visited) {
	int res = 0;	

	for (int i = 0; i < (int)pieces.size(); i++) {
		int tst = 0;
		if (std::find(visited.begin(), visited.end(), i) == visited.end())
			tst = summ + pieces[i];
		if (tst) {
			if (tst > x) {
				visited.push_back(i);
				return 1;
			}
			if (tst != x) {
				visited.push_back(i);
				if (visited.size() == pieces.size()) {
					return 1;
				}
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
		int n, x, p;
		
		std::cin >> n >> x; std::cin.ignore();

		std::vector<int> pieces;
		for (int i = 0; i < n; ++i) {
			std::cin >> p; std::cin.ignore();
			pieces.push_back(p);
		}
		if (std::accumulate(pieces.begin(), pieces.end(), 0) == x) {
			std::cout << "NO" << '\n';
			continue;
		}

		std::vector<int> visited;
		int res = getCombo(x, 0, pieces, visited);
		if (res) {
			std::cout << "YES\n" << pieces[visited[0]];
			for (int i = 1; i < (int)visited.size(); ++i) {
				std::cout << " " << pieces[visited[i]];
			}
			for (int i = 0; i < n; ++i) {
				if (std::find(visited.begin(), visited.end(), i) == visited.end()) {
					std::cout << " " << pieces[i];
				}
			}
			std::cout << '\n';
		}
		else {
			std::cout << "NO" << '\n';
		}
	}
}
