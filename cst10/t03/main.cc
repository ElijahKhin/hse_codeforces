#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <numeric>

static void showTree(std::vector<uint64_t>& tree) {
	for (auto i : tree) {
		std::cout << i << ' ';
	}
	std::cout << '\n';
}

static int get_power(int length) {
	int p = 0;
	while (1 << (p + 1) <= length) {
		++p;
	}
	return p;
}

static int query(std::vector<std::vector<int>>& sparseTree, std::vector<int>&arr, int l, int r) {
	int length = r - l + 1;
	int p = get_power(length);
	int val1 = sparseTree[l][p];
	int val2 = sparseTree[r - (1 << p) + 1][p];
	return std::gcd(val1, val2);
}

static void preprocessSparseTree (
		std::vector<int>& arr, 
		std::vector<std::vector<int>>& sparseTree, 
		int n) {

  int max_p = sparseTree[0].size();

  for (int i = 0; i < n; ++i) {
		sparseTree[i][0] = arr[i];
  }

  for (int k = 1; k < max_p; ++k) {
		for (int i = 0; i + (1 << k) <= n; ++i) {
			int val1 = sparseTree[i][k - 1];
  		int val2 = sparseTree[i + (1 << (k - 1))][k - 1];
  		sparseTree[i][k] = std::gcd(val1, val2);
  	}
  }

//		---

//	for (int i = 0; i < n; ++i) {
//		sparseTree[i][0] = arr[i];
//	}
//	for (int k = 1; k <= p; ++k) {
//		for (int i = 0; i + (1 << k) - 1 < n; ++i) {
//			sparseTree[i][k] = std::max(sparseTree[i][k-1], sparseTree[i + (1 << (k - 1))][k-1]);
//		//	std::cout << "here" << ' ' << sparseTree[i][k] << '\n';
//		}
//	}
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, k, p;
  std::cin >> n;
	
	p = get_power(n);

	std::vector<int> arr(n);
	std::vector<std::vector<int>> sparseTree(n, std::vector<int>(p + 1));

	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i];
	}
	
	preprocessSparseTree(arr, sparseTree, n);

	std::cin >> k;

	for (int i = 0; i < k; ++i) {
		int l, r;
		std::cin >> l >> r;
		--l;
		--r;
		std::cout << query(sparseTree,arr, l, r) << ' ';
	}
	std::cout << '\n';

  return 0;
}
