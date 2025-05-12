#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

class SegmentTree {
public:
    SegmentTree(int size) : n(size) {
        tree.resize(4 * n, 0);
        build(1, 1, n);
    }

    // Освобождаем или занимаем место
    void update(int pos, int val, int v = 1, int tl = 1, int tr = -1) {
        if (tr == -1) tr = n;

        if (tl == tr) {
            tree[v] = val ? tl : INT_MAX;
            return;
        }

        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(pos, val, v * 2, tl, tm);
        else
            update(pos, val, v * 2 + 1, tm + 1, tr);

        tree[v] = std::min(tree[v * 2], tree[v * 2 + 1]);
    }

    // Найти минимальное свободное место в отрезке [l, r]
    int query(int l, int r, int v = 1, int tl = 1, int tr = -1) {
        if (tr == -1) tr = n;

        if (l > r) return INT_MAX;
        if (l == tl && r == tr) return tree[v];

        int tm = (tl + tr) / 2;
        return std::min(
            query(l, std::min(r, tm), v * 2, tl, tm),
            query(std::max(l, tm + 1), r, v * 2 + 1, tm + 1, tr)
        );
    }

private:
    int n;
    std::vector<int> tree;

    void build(int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = tl; // Все места изначально свободны
        } else {
            int tm = (tl + tr) / 2;
            build(v * 2, tl, tm);
            build(v * 2 + 1, tm + 1, tr);
            tree[v] = std::min(tree[v * 2], tree[v * 2 + 1]);
        }
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;

    SegmentTree st(n);

    for (int i = 0; i < m; ++i) {
        std::string cmd;
        int x;
        std::cin >> cmd >> x;

        if (cmd == "enter") {
            int res = st.query(x, n); // ищем от x до конца
            if (res == INT_MAX) {
                res = st.query(1, x - 1); // кольцевой переход
            }
            std::cout << res << "\n";
            st.update(res, 0); // заняли место
        } else {
            st.update(x, 1); // освободили место
        }
    }
    return 0;
}

