#include <iostream>
#include <vector>
#include <algorithm>

void showMtx(std::vector<int>& vec, int n, int m) {
	std::cout << '\n';
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cout << vec[i*n + j] << ' ';
		}
		std::cout << '\n';
	}
}

void showVec(std::vector<int>& vec) {
	for(auto& i : vec) {
		std::cout << i << ' ';
	}
	std::cout << '\n';
}

void fillVec(std::vector<int>& vec, int dim) {
	for (int i = 0; i < dim; ++i) {
		std::cin >> vec[i];
	}
}
void getDiagLimits(std::vector<int>& diagLimits, int& n, int& m) {
	int max_diag_size = std::min(n, m), diag_qty = std::max(n, m) - std::min(n, m);

	int k = 0;
	for (int i = 0; i < max_diag_size; ++i) {
		diagLimits[k++] = i;
	}
	for (int i = 0; i < diag_qty; ++i) {
		diagLimits[k++] = max_diag_size - 1;
	}
	for (int i = max_diag_size - 2; i >= 0; --i) {
		diagLimits[k++] = i;
	}
}

void Square(std::vector<int>& a, std::vector<int>& b,std::vector<int>& diagLimits, int& n, int& m) {
	int max_diag_size = std::min(n, m);
	int dim = n * m, diag_n = n + m - 1, for_idx = std::max(n, m);
	int offset = 0;
	for (int i = 0; i < diag_n; ++i) {
		std::vector<int> sa;
		std::vector<int> sb;
		for (int j = 0; j <= diagLimits[i]; ++j) {
			int idx = for_idx * j - j + diagLimits[i] + offset;
			if (idx < dim) {
				sa.push_back(a[idx]);
				sb.push_back(b[idx]);
			}
			else break;
		}
//		std::cout << "sa: "; showVec(sa); std::cout << "sb: "; showVec(sb);
		std::sort(sa.begin(), sa.end());
		std::sort(sb.begin(), sb.end());
		if (sa != sb) {
			std::cout << "NO\n";
			return ;
		}
		if (i >= (m - 1)) {
			offset += m;
//			std::cout << "lim: " << diagLimits[i+1] << '\n';;
			if (i + 1 < diag_n && diagLimits[i+1] < max_diag_size - 1) {
//				std::cout << "here" << '\n';
				++offset;
			}
		}
	}	
	std::cout << "YES\n";
}

void N(std::vector<int>& a, std::vector<int>& b,std::vector<int>& diagLimits, int& n, int& m) {
	int max_diag_size = std::min(n, m);
	int dim = n * m, diag_n = n + m - 1, for_idx = m;
	int offset = 0;
	for (int i = 0; i < diag_n; ++i) {
		std::vector<int> sa;
		std::vector<int> sb;
		for (int j = 0; j <= diagLimits[i]; ++j) {
			int idx = for_idx * j - j + diagLimits[i] + offset;
			if (idx < dim) {
				sa.push_back(a[idx]);
				sb.push_back(b[idx]);
			}
			else break;
		}
//		std::cout << "sa: "; showVec(sa); std::cout << "sb: "; showVec(sb);
		std::sort(sa.begin(), sa.end());
		std::sort(sb.begin(), sb.end());
		if (sa != sb) {
			std::cout << "NO\n";
			return ;
		}
		if (i >= (m - 1)) {
			offset += m;
//			std::cout << "lim: " << diagLimits[i+1] << '\n';;
			if (i + 1 < diag_n && diagLimits[i+1] < max_diag_size - 1) {
//				std::cout << "here" << '\n';
				++offset;
			}
		}
	}	
	std::cout << "YES\n";
}

void M(std::vector<int>& a, std::vector<int>& b,std::vector<int>& diagLimits, int& n, int& m) {
	int max_diag_size = std::min(n, m);
	int dim = n * m, diag_n = n + m - 1, for_idx = m;
	int offset = 0, o2 = 0;
	for (int i = 0; i < diag_n; ++i) {
		std::vector<int> sa;
		std::vector<int> sb;
		if (diagLimits[i] == n - 1) (++o2); 
		else o2 = 0;
		for (int j = 0; j <= diagLimits[i]; ++j) {
			int idx = for_idx * j - j + diagLimits[i] + offset + (!o2 ? 0 : o2 - 1);
			if (idx < dim) {
				sa.push_back(a[idx]);
				sb.push_back(b[idx]);
			}
			else break;
		}
//		std::cout << "sa: "; showVec(sa); std::cout << "sb: "; showVec(sb);
		std::sort(sa.begin(), sa.end());
		std::sort(sb.begin(), sb.end());
		if (sa != sb) {
			std::cout << "NO\n";
			return ;
		}
		if (i >= (m - 1)) {
			if (i == m - 1) { 
				offset += m - diagLimits[i+1]- 2;
			}
			offset += m;
//			std::cout << "lim: " << diagLimits[i+1] << '\n';;
			if (i + 1 < diag_n && diagLimits[i+1] < max_diag_size - 1) {
//				std::cout << "here" << '\n';
				++offset;
			}
		}
	}	
	std::cout << "YES\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m, dim;

	std::cin >> n >> m;
	dim = n * m;
	std::vector<int> a(dim), b(dim), diagLimits(n + m - 1);

	fillVec(a, dim); fillVec(b, dim);
	getDiagLimits(diagLimits, n, m);
	if (a == b) {
		std::cout << "YES\n";
		return 0;
	}
	if (n == 1 || m == 1) {
		std::cout << "NO\n";
		return 0;
	}
	showVec(diagLimits);
	if (n == m) Square(a, b, diagLimits, n, m);
	else if (n > m) N(a, b, diagLimits, n, m);
	else M(a, b, diagLimits, n, m);
}
