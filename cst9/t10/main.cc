#include <iostream>
#include <vector>
#include <algorithm>

void cuts(std::vector<int>& a, int& n, int& b) {
	std::vector<int> costs;
	int even = 0, odd = 0;
	
	for (int i = 0; i < n - 1; i++) {
	  if (a[i] % 2 == 0) {
			even++;
		}
	  else odd++;
	
	  if (even == odd) {
	    costs.push_back(std::abs(a[i] -a[i+1]));
	  }
	}
	std::sort(costs.begin(), costs.end());
	int cuts = 0;
	for (auto& j : costs) {
	  if (b >= j) {
			b -= j;
	  	++cuts;
	  } else break;
	}
  std::cout << cuts<< std::endl;
}

int main() {
  int n, b;
  std::cin >> n >> b;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
	cuts(a, n, b);
}

