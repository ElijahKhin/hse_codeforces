#include <iostream>
#include <vector>
#include <cmath>

class SegmentTree {
	public:
		SegmentTree(int n) : n(n) {
			tree.resize(2*n, 0);
		}
		
		void update(int pos, int val) {
			pos = pos + n;
			tree[pos] = val;
			for (int i = pos; i > 0; i >>= 1) {
				tree[i>>1] = tree[i] + tree[i|1];
			}
		}

		int query(int pos) {
			--pos;
			if (!tree[pos + n]) {
				return pos+1;
			}

			int res = query(1, 0, n - 1, pos+1, n-1, n);
			if (res == -1) {
				return query(1, 0, n - 1, 0, pos, n) + 1;
			}
			else {
				return res + 1;
			}
		}

		int query(int v, int tl, int tr, int l, int r, int val) {
			if (l > r || tree[v] == val) return -1;
			if (tl == tr) {
				return tl;
			}
			int tm = (tl + tr) / 2;
			int res = -1;
			if (l <= tm) {
				res = query(v<<1, tl, tm, l, std::min(r, tm), val >> 1);
			}
			if (res == -1 && r > tm) {
				res = query(v<<1|1, tm+1, tr, std::max(l, tm+1), r, val >> 1);
			}
			return res;
		}

		void show() {
			for (auto i : tree) {
				std::cout << i << ' ';
			}
			std::cout << '\n';
		}

	private:
		int n;
		std::vector<int> tree;
};

int main(void) {
	int n, m;
	std::cin >> n >> m;

	SegmentTree st(n);
	st.show();
	for (int i = 0; i < m; ++i) {
		int x;
		std::string s;
		std::cin >> s >> x;
		if (s == "enter") {
			int pos = st.query(x);
			std::cout << pos << '\n';
			st.update(pos - 1, 1);
		}
		else {
			st.update(x - 1, 0);
		}
	}
}
