#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9 + 7;

class SegmentTree {
    int n;
    vector<int> tree;

public:
    SegmentTree(const vector<int>& a) {
        n = a.size();
        tree.resize(n * 4);
        build(a, 1, 0, n - 1);
    }

    void build(const vector<int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            tree[v] = max(tree[v*2], tree[v*2+1]);
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
                update(pos, val, v*2+1, tm+1, tr);
            tree[v] = max(tree[v*2], tree[v*2+1]);
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
            res = get(v*2, tl, tm, l, min(r, tm), x);
        if (res == -1 && r > tm)
            res = get(v*2+1, tm+1, tr, max(l, tm+1), r, x);
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int& x : a) cin >> x;

    SegmentTree st(a);

    for (int i = 0; i < m; ++i) {
        int t, idx, x;
        cin >> t >> idx >> x;
        --idx; // переходим к 0-индексации

        if (t == 0) {
            st.update(idx, x);
        } else {
            int res = st.get(idx, x);
            if (res == -1) cout << -1 << '\n';
            else cout << res + 1 << '\n'; // обратно в 1-индексацию
        }
    }

    return 0;
}

