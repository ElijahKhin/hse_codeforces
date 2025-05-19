#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

class Fenwick {
  public:
    Fenwick(int n) {
      tree.assign(n, 0);
    }

    void update(int idx, int val) {
      for (; idx < tree.size(); idx |= (idx + 1))
        tree[idx] += val;
    }

    int query(int idx) {
      int res = 0;
      for (; idx >= 0; idx = (idx & (idx + 1)) - 1)
        res += tree[idx];
      return res;
    }

    int query(int l, int r) {
      if (l > r) return 0;
      return query(r) - query(l - 1);
    }

    void reset() {
      std::fill(tree.begin(), tree.end(), 0);
    }

  private:
    std::vector<int> tree;
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<int> a(n), comp(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    comp[i] = a[i];
  }

  std::sort(comp.begin(), comp.end());
  comp.erase(std::unique(comp.begin(), comp.end()), comp.end());
  for (int i = 0; i < n; ++i) {
    a[i] = std::lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin();
  }

  int m = comp.size();
  std::vector<int> left(n), right(n);
  Fenwick bit(m);

  for (int i = 0; i < n; ++i) {
    left[i] = bit.query(a[i] + 1, m - 1);
    bit.update(a[i], 1);
  }

  bit.reset();

  for (int i = n - 1; i >= 0; --i) {
    right[i] = bit.query(0, a[i] - 1);
    bit.update(a[i], 1);
  }

  uint64_t answer = 0;
  for (int i = 0; i < n; ++i) {
    answer += (uint64_t)(left[i]) * right[i];
  }

  std::cout << answer << '\n';
}
