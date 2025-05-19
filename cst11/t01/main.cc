#include <iostream>
#include <vector>
#include <cstdint>

const int N = 1e5;

std::vector<int64_t> t(4*N, 0);
std::vector<int64_t> set_val(4*N, -1);

void push(int v, int l, int r) {
  if (set_val[v] != -1) {
    if (r-l == 1) {
      t[v] = set_val[v];
    }
    else {
      set_val[(v<<1) + 1] = set_val[v];
      set_val[(v<<1) + 2] = set_val[v];
      t[v] = set_val[v] * (r-l);
    }
    set_val[v] = -1;
  }

}

void build(int v, int l, int r) {
  if (r - l == 1) {
    t[v] = 0;
  }  
  else {
    int m = (r+l)/2;
    build((v<<1) + 1, l, m);
    build((v<<1) + 2, m,r);
    t[v] = t[(v<<1) + 1] + t[(v<<1) + 2];
  }
}

void update(int v, int l, int r, int ql, int qr, int x) {
  push(v, l, r); 
  if (r <= ql || qr <= l) {
    return;
  }
  else if (ql <= l && r <= qr) {
    set_val[v] = x;
    push(v, l, r);
  }
  else {
    int m = (r + l) /2 ;
    update((v<<1) + 1, l, m, ql, qr, x);
    update((v<<1) + 2, m, r, ql, qr, x);
    t[v] = t[(v<<1) + 1] + t[(v<<1) + 2];
  }
}


long long sum(int v, int l, int r, int ql, int qr) {
  push(v, l, r);
  if (r <= ql | qr <= l) {
    return 0;
  }
  else if (ql <= l && r <= qr) {
    return t[v];
  }
  else {
    int m = (r + l) /2;
    return sum((v<<1) + 1, l, m, ql, qr) + sum((v<<1) + 2, m, r, ql, qr);
  }
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

	int n, q;
	std::cin >> n >> q;

  while(q--) {
    char cmd;
    std::cin >> cmd;
    if (cmd == 'Q') {
      int l, r;
      std::cin >> l >> r;
      std::cout << sum(0, 0, n, --l, r) << '\n';
    }
    else {
      int l, r, x;
      std::cin >> l >> r >> x;
      update(0, 0, n, --l, r, x);
    }
  }
}
