#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

class SegmentTree {
	public:
    SegmentTree(std::vector<int>& a) {
			n = a.size();
    	tree.resize(n * 4);
    	build(a, 1, 0, n - 1);
    }

    void build(std::vector<int>& a, int v, int tl, int tr) {
			if (tl == tr) {
				tree[v] = a[tl];
    	} else {
				int tm = (tl + tr) / 2;
    		build(a, v*2, tl, tm);
    		build(a, v*2+1, tm+1, tr);
    		tree[v] = std::max(tree[v *2], tree[v* 2 + 1]);
    	}
    }

    void update(int pos, int val, int v, int tl, int tr) {
			if (tl == tr) {
				tree[v] = val;
    	} else {
				int tm = (tl + tr) / 2;
    		if (pos <= tm)
					update(pos, val, v*2, tl, tm);
    		else
					update(pos, val, v * 2+1, tm+1, tr);
				tree[v] = std::max(tree[v*2], tree[v* 2 + 1]);
    	}
    }

    void update(int pos, int val) {
			update(pos, val, 1, 0, n - 1);
    }

    int get(int l, int x) {
      return get(1, 0, n - 1, l, n - 1, x);
    }

    int get(int v, int tl, int tr, int l, int r, int x) {
      if (l > r || tree[v] < x) return -1;
      if (tl == tr) return tl;

      int tm = (tl + tr) / 2;
      int res = -1;
      if (l <= tm)
				res = get(v*2, tl, tm, l, std::min(r, tm), x);
      if (res == -1 && r > tm)
				res = get(v*2+1, tm+ 1, tr, std::max(l, tm+1), r, x);
      return res;
    }

		int query(int lidx, int x, int tidx) {
			std::cout << '\n' << 
				"lidx: " << lidx << '\n' << "limits[lidx]: " << limits[lidx]  << '\n'
				<< "tidx: " << tidx << '\n' << "tree[tidx]: " << tree[tidx] << '\n';
			if (limits[lidx] <= tidx) {
				if (tree[tidx] >= x && lidx == 0) {
					std::cout << "exit1" << '\n';
					return tidx;
				}
				if (tree[tidx] >= x) {
					int left = query(lidx-1, x, tidx<<1);
					if (left) return left;
					int right = query(lidx-1, x, tidx<<1|1);
					if (right) return right;
					return 0;
				}
				else {
					std::cout << "exit4" << '\n';
					return 0;
				}
			}
			else {
				std::cout << "exit5" << '\n';
				return 0;
			}
			std::cout << "exit6" << '\n';
			return 0;
		}

		void getLimits(int l) {
			l = l - 1 + n;
			while (l >= 1) {
				limits.push_back(l);
				l >>= 1;
			}
		}

		void show_tree() {
			for (auto i : tree) {
				std::cout << i << ' ';
			}
			std::cout << '\n';
		}

		void show_limits() {
			for (auto i : limits) {
				std::cout << i << ' ';
			}
			std::cout << '\n';
		}
		
		void clear_limits() {
			limits.clear();
		}

		int get_limits_size() {
			return limits.size() - 1;
		}

	private:
		int n;
		int size;
		std::vector<int> tree;
		std::vector<int> limits;
			
};


//static void update(std::vector<uint64_t>& tree, int pos, int val, int n) {
//	pos = pos - 1 + n;
//	tree[pos] = val;
//	for (int i = pos; i > 1; i>>=1) {
//		tree[i>>1] = tree[i] + tree[i^1];
//	}
//}
//
//static uint64_t query(std::vector<uint64_t>&tree, int l, int r, int n) {
//	uint64_t res = 0;
//	
//	--l;
//
//  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
//		if (l&1)
//			res += tree[l++];
//		if (r&1)
//			res += tree[--r];
//  }
//  return res;
//}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
	
  int n, m;
  std::cin >> n >> m;
	
	std::vector<int> arr(n);

	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i];
	}

	SegmentTree st(arr);

	for (int j = 0; j < m; ++j) {
		int t, i, x;
		std::cin >> t >> i >> x;
		--i;
		if (t == 1) {
			int val = st.get(i, x);
			if (val!=-1) {
				std::cout << val + 1 << std::endl;
			}
			else {
				std::cout << -1 << std::endl;
			}

		//	if (val>0) {
		//		std::cout << val - n << std::endl;
		//	}
		//	else {
		//		std::cout << -1 << std::endl;
		//	}
		}
		else {
			st.update(i, x);
		}
//		else {
//			std::cout << query(tree, a, b, n) << '\n'; 
//		}
	}

  return 0;
}
