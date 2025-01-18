#include <iostream>

int main() {
    int n, k, kth = 0, res = 0;

    std::cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			int next;
			std::cin >> next;	
			if (next) {
				if (i < k)
					res++;
				else if (i == k) {
					kth = next; res++;
				}
				else {
					if (next == kth) res++;
					else break;
				}
			}
		}
		std::cout << res << std::endl;
}
