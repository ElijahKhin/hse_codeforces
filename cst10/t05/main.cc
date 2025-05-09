#include <iostream>
#include <vector>
#include <cmath>
#include <stack>

#define LEN 1e7

typedef struct {
	std::stack<int> info;
	int max_length;
} elem_info;

std::tuple<int, int, int> getLenOfRightSeq(int left, int right) {
	if (left >= std::abs(right)) {
		std::make_tuple(-right, left+right, 0);
		return -right;
	}
	return std::make_tuple(left, 0, left+right);
}

std::tuple<int, int, int> getMergeInfo(int left, int right) {
	if (left < LEN && right < LEN) {
		if (left > 0 && right < 0) {
			return getLenOfRightSeq(left, right);
		} 
		else if (left > 0 && right > 0) {
			return std::make_tuple(0, left+right, 0);
		}
		else if (left < 0 && right < 0) {
			return std::make_tuple(0, 0, left+right);
		}
		else {
			return std::make_tuple(0, left, right);
		}
	}
	else if (left > LEN && right < LEN) {
		return std::make_tuple(left, 0, right);
	} 
	else if (left < LEN && right > LEN) {
		return std::make_tuple(right, left, 0);
	} 
	else {
		return std::make_tuple(left+right, 0, 0);
	}
}

class SegmentTree {
	public:
		SegmentTree(std::string& s) : arr(s) {
			tn = s.size() * 2;
			tree.resize(tn);
		}

		void build() {
			for (int i = 0; i < tn / 2; ++i) {
				std::stack<int> item;
				if (arr[i] == '(') {
					item.push(1);
					tree[i+tn / 2].info = item;
				}
				else {
					item.push(-1);
					tree[i+tn / 2].info = item;
				}
				tree[i+tn / 2].max_length = max_length = 0;
			}

			for (int i = tn / 2 - 1; i > 0; --i) {
				int left = tree[i<<1].info.top(), right = tree[i<<1|1].info.top();

				tree[i<<1].info.pop();
				tree[i<<1|1].info.pop();
				std::tupe<int, int, int> merge_info = getMergeInfo(left, right);

				std::stack<int> current_left = tree[i<<1].info;
				int left = tree[i<<1].info.top(), right = tree[i<<1|1].info.top();
				
				//first
				if (left > LEN) {
					if (std::get<0>(merge_info) != 0 && 
							std::get<1>(merge_info) == 0 &&
							std::get<2>(merge_info) == 0) {
						if (right > LEN) {
							current_left.pop();	
							current_left.push(left + std::get<0>(merge_info) + right);
							tree[i<<1|1].info.pop();
						}
						current_left.pop();	
						current_left.push(left + std::get<0>(merge_info));
					}
					else if (std::get<0>(merge_info) != 0 && 
							std::get<1>(merge_info) != 0 &&
							std::get<2>(merge_info) == 0) {
						current_left.push(std::get<1>(merge_info));
						if (right > LEN) {
							current_left.push(std::get<0>(merge_info) + right);
							tree[i<<1|1].info.pop();
						}
						current_left.push(std::get<0>(merge_info));
					}
					else if (std::get<0>(merge_info) != 0 && 
							std::get<1>(merge_info) == 0 &&
							std::get<2>(merge_info) != 0) {
						current_left.pop();
						current_left.push(left+std::get<0>(merge_info));
						current_left.push(std::get<2>(merge_info));
					}
					else if (std::get<0>(merge_info) == 0 && 
							std::get<1>(merge_info) != 0 &&
							std::get<2>(merge_info) != 0) {
						current_left.push(std::get<1>(merge_info));
						current_left.push(std::get<2>(merge_info));
					}
					else if (std::get<0>(merge_info) == 0 && 
							std::get<1>(merge_info) == 0 &&
							std::get<2>(merge_info) != 0) {
						current_left.push(std::get<2>(merge_info));
					}
					else if (std::get<0>(merge_info) == 0 && 
							std::get<1>(merge_info) != 0 &&
							std::get<2>(merge_info) == 0) {
						current_left.push(std::get<2>(merge_info));
					}
				}

				//second
				else if (left > 0) {
					if (std::get<0>(merge_info) != 0 && 
							std::get<1>(merge_info) == 0 &&
							std::get<2>(merge_info) != 0) {
						current_left.push(std::get<0>(merge_info));
						current_left.push(std::get<2>(merge_info));
					}
					else if (std::get<0>(merge_info) != 0 && 
							std::get<1>(merge_info) == 0 &&
							std::get<2>(merge_info) == 0) {
						current_left.push(std::get<0>(merge_info));
					}
				}
				
				//third
				else if (left < 0) {
					if (std::get<0>(merge_info) != 0 && 
							std::get<1>(merge_info) != 0 &&
							std::get<2>(merge_info) == 0) {
						current_left.push(std::get<1>(merge_info));
						current_left.push(std::get<0>(merge_info));
					}
					else if (std::get<0>(merge_info) != 0 && 
							std::get<1>(merge_info) == 0 &&
							std::get<2>(merge_info) != 0) {
						current_left.push(std::get<0>(merge_info));
						current_left.push(std::get<2>(merge_info));
					}
					else if (std::get<0>(merge_info) != 0 && 
							std::get<1>(merge_info) == 0 &&
							std::get<2>(merge_info) == 0) {
						current_left.push(std::get<0>(merge_info));
					}
					else if (std::get<0>(merge_info) == 0 && 
							std::get<1>(merge_info) != 0 &&
							std::get<2>(merge_info) == 0) {
						current_left.push(std::get<1>(merge_info));
					}
				}
				while (!tree[i<<1|1].info.empty()) {
					current_left.push(tree[i<<1|1].info.top());
					tree[i<<1|1].info.pop();
				}
			}
		}

	private:
		size_t tn;
		std::string arr;
		std::vector<elem_info> tree;
};

int main(void) {
//	int m;
//	std::string s;
//
//	std::cin >> s;
//	std::cin >> m;
//
//	SegmentTree st(s);
//	st.build();
//	st.show_tree();
}
