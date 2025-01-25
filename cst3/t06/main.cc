#include <iostream>
#include <string>
#include <vector>

int main() {
	int n, answer = 0;
	std::string s;

	std::cin >> n;
	std::cin.ignore();

	while (--n >= 0) {
		std::getline(std::cin, s);	
		if (s == "Tetrahedron")
			answer += 4;
		if (s == "Cube")
			answer += 6;
		if (s == "Octahedron")
			answer += 8;
		if (s == "Dodecahedron")
			answer += 12;
		if (s == "Icosahedron")
			answer += 20;
	}
	std::cout << answer << std::endl;
}
