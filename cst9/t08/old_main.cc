#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>

typedef std::string st;
typedef std::queue<std::string> qs;
typedef std::deque<std::string> ds;

static inline void print_queue(std::queue<int> q) {
	while (!q.empty()) {
		std::cout << q.front() << ' ';
		q.pop();
	}
	std::cout << '\n'; 
}

static void addOrdinaryGoblin(qs& first_half, ds& second_half, st& request, int& goblins) {
	if (goblins == 0) {
		first_half.push(request);	
	}
	else if (goblins == 1) {
		second_half.push_back(request);
	}
	else if (goblins % 2 == 1){
		second_half.push_back(request);
	}
	else {
		first_half.push(second_half.front());
		second_half.pop_front();
		second_half.push_back(request);
	}
	++goblins;
}

static void addPrivateGoblin(qs& first_half, ds& second_half, st& request, int& goblins) {
	if (goblins == 0) {
		first_half.push(request);	
	}
	else if (goblins == 1) { 
		second_half.push_front(request);
	}
	else if (goblins % 2 == 1) {
		second_half.push_front(request);
	}
	else {
		first_half.push(request);
	}
	++goblins;
}

static void reorderQueue(qs& first_half, ds& second_half, int& goblins) {
	std::cout << first_half.front().substr(2) << '\n';
	first_half.pop();
	--goblins;
	if (goblins) {
		if (goblins == 1) {
			first_half.push(second_half.front());
			second_half.pop_front();
		}
		else if (goblins % 2 != 0) {
			first_half.push(second_half.front());
			second_half.pop_front();
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, goblins = 0;

	st request;
	qs first_half;
	ds second_half;

	std::cin >> n;
	std::cin.ignore();

	while (--n >= 0) {
		std::getline(std::cin, request);
		char gobline_type = request[0];
		if (gobline_type == '+') {
			addOrdinaryGoblin(first_half, second_half, request, goblins);
		}
		else if (gobline_type == '*') {
			addPrivateGoblin(first_half, second_half, request, goblins);
		}
//		std::cout << "first_half: " << first_half.back() << '\n';

	//	std::cout << "second_half: " << second_half.back() << "\n\n";
		else {
			reorderQueue(first_half, second_half, goblins);
		}
	}
	return 0;
}
