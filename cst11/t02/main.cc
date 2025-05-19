#include <iostream>
#include <vector>
#include <algorithm>

const int N = 1e5;

std::vector<int> t(4 * N);
std::vector<int> add_val(4 * N);

void build(const std::vector<int>& a, int v, int l, int r) {
    if (r - l == 1) {
        t[v] = a[l];
    } else {
        int m = (l + r) / 2;
        build(a, v * 2 + 1, l, m);
        build(a, v * 2 + 2, m, r);
        t[v] = std::max(t[v * 2 + 1], t[v * 2 + 2]);
    }
}

void push(int v, int l, int r) {
    if (add_val[v]) {
        t[v] += add_val[v];
        if (r - l > 1) {
            add_val[v * 2 + 1] += add_val[v];
            add_val[v * 2 + 2] += add_val[v];
        }
        add_val[v] = 0;
    }
}

void update(int v, int l, int r, int ql, int qr, int x) {
    push(v, l, r);
    if (r <= ql || qr <= l) return;
    if (ql <= l && r <= qr) {
        add_val[v] += x;
        push(v, l, r);
    } else {
        int m = (l + r) / 2;
        update(v * 2 + 1, l, m, ql, qr, x);
        update(v * 2 + 2, m, r, ql, qr, x);
        t[v] = std::max(t[v * 2 + 1], t[v * 2 + 2]);
    }
}

int get_max(int v, int l, int r, int ql, int qr) {
    push(v, l, r);
    if (r <= ql || qr <= l) return -1e9;
    if (ql <= l && r <= qr) return t[v];
    int m = (l + r) / 2;
    return std::max(get_max(v * 2 + 1, l, m, ql, qr),
                    get_max(v * 2 + 2, m, r, ql, qr));
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int& x : a) std::cin >> x;

    build(a, 0, 0, n);

    int m;
    std::cin >> m;

    while (m--) {
        char type;
        std::cin >> type;
        if (type == 'm') {
            int l, r;
            std::cin >> l >> r;
            std::cout << get_max(0, 0, n, l - 1, r) << '\n';
        } else if (type == 'a') {
            int l, r, add;
            std::cin >> l >> r >> add;
            update(0, 0, n, l - 1, r, add);
        }
    }

    std::cout << '\n';
}

