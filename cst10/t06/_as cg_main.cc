#include <iostream>
#include <vector>
#include <algorithm>

class SegmentTree {
private:
    std::vector<int> tree;
    int size;

public:
    SegmentTree(int n) {
        size = n;
        tree.assign(4 * n, 0);
    }

    void update(int node, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            tree[node] += val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(2 * node, tl, tm, pos, val);
            else
                update(2 * node + 1, tm + 1, tr, pos, val);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    int query(int node, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return tree[node];
        int tm = (tl + tr) / 2;
        return query(2 * node, tl, tm, l, std::min(r, tm)) +
               query(2 * node + 1, tm + 1, tr, std::max(l, tm + 1), r);
    }

    void update(int pos, int val) {
        update(1, 0, size - 1, pos, val);
    }

    int query(int l, int r) {
        return query(1, 0, size - 1, l, r);
    }

    void reset() {
        std::fill(tree.begin(), tree.end(), 0);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a(n), comp;

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        comp.push_back(a[i]);
    }

    // Coordinate compression
    std::sort(comp.begin(), comp.end());
    for (int i = 0; i < n; ++i)
        a[i] = std::lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin();

    std::vector<int> left(n), right(n);
    SegmentTree seg(n);

    for (int i = 0; i < n; ++i) {
        left[i] = seg.query(a[i] + 1, n - 1);
        seg.update(a[i], 1);
    }

    seg.reset();

    for (int i = n - 1; i >= 0; --i) {
        right[i] = seg.query(0, a[i] - 1);
        seg.update(a[i], 1);
    }

    long long answer = 0;
    for (int i = 0; i < n; ++i)
        answer += static_cast<long long>(left[i]) * right[i];

    std::cout << answer << '\n';
    return 0;
}

