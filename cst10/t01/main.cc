#include <iostream>
#include <vector>
#include <cstdint>

static void show_tree(std::vector<uint64_t>& tree) {
	for (auto i : tree) {
		std::cout << i << ' ';
	}
	std::cout << '\n';
}

static void build(std::vector<uint64_t>& tree, std::vector<int>& arr, int n) {
	for (int i = 0; i < n; ++i) {
		tree[n+i] = arr[i];
	}
	for (int i = n - 1; i > 0; --i) {
		tree[i] = tree[i<<1] + tree[i<<1 | 1];
	}
}

static void update(std::vector<uint64_t>& tree, int pos, int val, int n) {
	--pos;
	tree[n+pos] = val;
	for (int i = pos + n; i > 1; i>>=1) {
		tree[i>>1] = tree[i] + tree[i^1];
	}
}

static uint64_t query(std::vector<uint64_t>&tree, int l, int r, int n) {
	uint64_t res = 0;
	
	--l;
	--r;

	if (l == r) {
		return tree[l+n];
	}
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1)
			res += tree[l++];
		if (r&1)
			res += tree[--r];
  }
  return res;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, k;
  std::cin >> n >> k;

	std::vector<int> arr(n, 0);
	std::vector<uint64_t> tree(2*n, 0);

	for (int i = 0; i < k; ++i) {
		char type;
		int a, b;
		std::cin >> type >> a >> b;
		if (type == 'A') {
			update(tree, a, b, n);
			show_tree(tree);
		}
		else {
			std::cout << query(tree, a, b, n) << '\n'; 
		}
	}

  return 0;
}
