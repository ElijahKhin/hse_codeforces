#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdint>

class SegmentTree {
	public:
		SegmentTree(int n) {
			size = n;
			tree.assign(4 *n, 0);
		}
		void update(int v, int tl, int tr, int pos, int val) {
			if (tl == tr) {
				tree[v] += val;
			}
			else {
				int tm = (tl + tr) / 2;
				if (pos <= tm) {
					update(v * 2, tl, tm, pos, val);
				}
				else {
					update(v * 2 + 1, tm + 1, tr, pos, val);
				}
				tree[v] = tree[2*v] + tree[v*2+1];
			}
		}

		int query(int v, int tl, int tr, int l, int r) {
			if (l > r) {
				return 0;
			}
			if (l == tl && r == tr) {
				return tree[v];
			}
			int tm = (tl + tr) / 2;
			return query(2 * v, tl, tm, l, std::min(r, tm)) +
							query(2*v+1, tm+1, tr, std::max(l, tm+1), r);
		}

		void update(int pos, int val) {
			update(1, 0, size-1, pos, val);
		}
		int query(int l, int r) {
			return query(1, 0, size - 1, l, r);
		}
		void reset() {
			std::fill(tree.begin(), tree.end(), 0);
		}
	private:
		int size;
		std::vector<int> tree;
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;;;;
	std::vector<int> a(n), comp(n);
	for(int i = 0; i < n; ++i) {
		std::cin >> a[i];
		comp[i] = a[i];
	}
	std::sort(comp.begin(), comp.end());
	comp.erase(std::unique(comp.begin(), comp.end()), comp.end());
	int m = comp.size();

	for(int i =0; i<n; ++i) {
		a[i] = std::lower_bound(comp.begin(), comp.end(),a[i]) - comp.begin();
	}
	std::vector<int> left(n), right(n);
	SegmentTree st(n);

	for(int i =0; i < n; ++i) {
		left[i] = st.query(a[i] + 1, m - 1);
		st.update(a[i], 1);
	}

	st.reset();

	for(int i = n - 1; i >= 0; --i) {
		right[i] = st.query(0, a[i] - 1);
		st.update(a[i], 1);
	}
	uint64_t answer = 0;
	for (int i = 0; i < n; ++i) {
		answer += (uint64_t)(left[i] * right[i]);
	}
	std::cout << answer << '\n';
}
