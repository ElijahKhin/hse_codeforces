#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

#define UPPER_BOUND 4294967295ULL

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);


	int l;
	unsigned long long x = 0, cf;
	std::vector<std::string> input;
	std::stack<unsigned long long> ns;

	std::cin >> l;
	std::cin.ignore();
	

	for (int i = 0; i < l; ++i) {
		std::string s;
		std::getline(std::cin, s);
		input.push_back(s);
	}
	for (auto& command : input)
		if (command == "add") {
			if (!ns.empty()) {
				cf = ns.top();
			}
			else {
				cf = 1;
			}
			if (x + cf > UPPER_BOUND) {
				std::cout << "OVERFLOW!!!\n";
				return 0;
			}
			x += cf;
		}
		else if (command == "end") {
			if (!ns.empty()) {
				ns.pop();
			}
		}
		else {
			int n = std::stoi(command.substr(4));
			if (!ns.empty()) {
				unsigned long long cur_n = n * ns.top();
				if (cur_n > UPPER_BOUND) {
					ns.push(UPPER_BOUND+1);
				}
				else {
					ns.push(cur_n);
				}
			}
			else {
				ns.push(n);
			}
		}
	std::cout << x << '\n';
}
