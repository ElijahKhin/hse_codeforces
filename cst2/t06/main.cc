#include <iostream>

int main() {
	int n, x, y, z;
	int rx = 0, ry = 0, rz = 0;


	std::cin >> n;
	while (--n >= 0) {
		std::cin >> x >> y >> z;
		rx += x; ry += y; rz += z;
	}
	if (!(rx) && !(ry) && !(rz)) {
		std::cout << "YES" << std::endl;
	}
	else {
		std::cout << "NO" << std::endl;
	}
}
