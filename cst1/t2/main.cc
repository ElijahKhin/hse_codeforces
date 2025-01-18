#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore(); // Игнорируем символ новой строки после числа
    while (n--) {
        std::string word;
        std::getline(std::cin, word);
        if (word.length() > 10)
            std::cout << word.front() << word.length() - 2 << word.back() << "\n";
        else
            std::cout << word << "\n";
    }
    return 0;
}
