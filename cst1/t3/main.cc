#include <iostream>

int main() {
    int n, m, a;
    std::cin >> n >> m >> a;
		if (!(n % a) && !(m % a)) 
			std::cout << (long long)(n / a) * (m / a) << std::endl;
		else if ((n % a) && !(m % a))
			std::cout << (long long)(n / a + 1) * (m / a) << std::endl;
		else if (!(n % a) && (m % a))
			std::cout << (long long)(n / a) * (m / a + 1) << std::endl;
		else
			std::cout << (long long)(n / a + 1) * (m / a + 1) << std::endl;
}
