#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

static void calculate(char ch, std::stack<int>& operands) {
	int first = operands.top();
	operands.pop();
	int second = operands.top();
	operands.pop();

	if (ch == '+') {
		operands.push(second + first);	
	}
	else if (ch == '-') {
		operands.push(second - first);	
	}
	else {
		operands.push(second * first);	
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string s;
	std::getline(std::cin, s);
	std::stack<int> operands;
	for (auto ch : s) {
		if (ch == 32) continue;
		if (ch >= 48 && ch <= 57) {
			operands.push(ch - 48);
		}
		else {
			calculate(ch, operands);
		}
	}
	std::cout << operands.top() << '\n';
}
