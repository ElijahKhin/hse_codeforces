#include "task.hpp"

//void getPrimes(std::vector<int>& primes) {
//	primes[0] = 2, primes[1] = 5, primes[2] = 7;
//	for (int i = 11, k = 3; i < 1000000; ++i) {
//		bool isPrime = true;
//		for (int j = 2; j <= (int)std::sqrt(i); ++j) {
//			if (!(i % j)) isPrime = false;
//		}
//		if (isPrime) {
//			primes[k++] = i;
//		}
//	}
//}
//
//int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int t; 
//	std::cin >> t;
//
//	std::vector<int> primes(78498);
//	getPrimes(primes);
//	for (int i = 0; i < t; ++i) {
//		unsigned long long n;
//		std::cin >> n;
//		for (auto& val : primes) {
//			
//		}
//		std::cout << primes[i] << '\n';
//	}
//}

void func(std::istream& cinn) {

	int t; 
	cinn >> t;

	for (int i = 0; i < t; ++i) {
		unsigned long long n, q = 2;
		cinn >> n;
		if (!(n % 2)) {
			while(q <= n) {
				if (q == n) {
					std::cout << "NO" << '\n';
				}
				q *=2; 
			}
		} 
		else {
			std::cout << "YES" << '\n';
		}
	}
}

