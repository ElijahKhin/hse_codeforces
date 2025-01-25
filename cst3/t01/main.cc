#include <iostream>
#include <vector>

void getChange(char& first, char& last, char mark) {
	if (mark == 'a') {
		first = 'b';
		last = 'a';
	}
	else {
		first = 'a';
		last = 'b';
	}
}

bool tryDrop(std::string& t, int cnt_first, int cnt_last, char mark) {
	char first, last;

	getChange(first, last, mark);
	if (cnt_first == 1) {
		t[0] = first;
		return 1;
	}
	if (cnt_last == 1) {
		t[t.size() - 1] = last;
		return 1;
	}
	return 0;
}

bool tryAdd(std::string& t, int cnt_first, int cnt_last, char mark) {
	char first, last;

	getChange(first, last, mark);
	if (cnt_first > 1) {
		t[0] = first;
		return 1;
	}
	if (cnt_last > 1) {
		t[t.size() - 1] = last;
		return 1;
	}
	return 0;
}

void modifyT(std::string& t, char first, int cnt_first, int cnt_last) {
	if (first == 'a') {
		if (!tryDrop(t, cnt_first, cnt_last, 'a'))
			tryAdd(t, cnt_first, cnt_last, 'a');
	}
	else {
		if (!tryDrop(t, cnt_first, cnt_last, 'b'))
		tryAdd(t, cnt_first, cnt_last, 'b');
	}
}

void getInfo(std::string t, std::vector<int>& info) {
	int cnt = 0;
	char curr = t[0];
	
	info.push_back(t[0]);
	info.push_back(t[t.size()-1]);
	for (int i = 0; i < (int)t.size(); i++) {
		if (t[i] == curr) cnt++;
		else {
			info.push_back(cnt);
			cnt = 1;
			curr = t[i];
		}
	}
	info.push_back(cnt);
}

int main() {
	int q;
	std::vector<int> info;
	std::string t;

	std::cin >> q;
	std::cin.ignore();

	while (--q >= 0) {
		std::getline(std::cin, t);
		getInfo(t, info);
		if (info.size() % 2) {
			std::cout << t << std::endl;
		}
		else {
			modifyT(t, info[0], info[2], info[info.size() - 1]);
			std::cout <<  t << std::endl;
		}
		info.clear();
	}
}
