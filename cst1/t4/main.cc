#include <iostream>

int main() {
    int n, m1, m2, m3, c = 0;
    std::cin >> n;
		while (n--) {
			std::cin >> m1 >> m2 >> m3;
			if (m1 + m2 + m3 > 1) c++;
		}
		std::cout << c << std::endl;
}
