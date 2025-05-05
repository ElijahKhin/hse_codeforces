#include <iostream>
#include <vector>
#include <queue>

#define LIMIT 1000000

//static inline void print_queue(std::queue<int> q) {
//	while (!q.empty()) {
//		std::cout << q.front() << ' ';
//		q.pop();
//	}
//	std::cout << '\n'; 
//}

static inline void read_data(std::queue<int>& first, std::queue<int>& second) {
	for(int i = 0; i < 5; ++i) {
		int ch;
		std::cin >> ch;
		first.push(ch);
	}
	std::cin.ignore();
	for(int i = 0; i < 5; ++i) {
		int ch;
		std::cin >> ch;
		second.push(ch);
	}
}

static inline bool isEmpty(std::queue<int>& first, std::queue<int>& second, int i) {
	if (first.empty()) {
		std::cout << "second" << ' ' << i << '\n';
		return 1;
	}
	if (second.empty()) {
		std::cout << "first" << ' ' << i << '\n';
		return 1;
	}
	return 0;
}

static inline void play_move(std::queue<int>& winner, std::queue<int>& loser, int order) {
	if (order) {
		winner.push(loser.front());
		winner.push(winner.front());
	}
	else {
		winner.push(winner.front());
		winner.push(loser.front());
	}
	winner.pop();
	loser.pop();
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::queue<int> first;
	std::queue<int> second;
	
	read_data(first, second);
	for(int i = 0; i < LIMIT; ++i) {
		if (isEmpty(first, second, i)) {
			return 0;
		}
		if (first.front() > second.front()) {
			if (first.front() == 9 && second.front() == 0)
				play_move(second, first, 1);
			else 
				play_move(first, second, 0);
		}
		else {
			if (first.front() == 0 && second.front() == 9)
				play_move(first, second, 0);
			else 
			play_move(second, first, 1);
		}
	}
	std::cout << "botva\n";
}
