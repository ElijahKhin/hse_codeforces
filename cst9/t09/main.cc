#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Функция для вычисления разницы между очками A и B
int solve(int i, int j, vector<int>& A, vector<int>& B, vector<vector<int>>& dp, bool isPlayerA) {
    // Если оба списка пусты, разница равна 0
    if (i == 0 && j == 0) return 0;

    // Если результат уже вычислен, возвращаем его
    if (dp[i][j] != -1) return dp[i][j];

    int result;
    if (isPlayerA) {
        // Ход игрока A: максимизирует разницу
        result = -1e9;
        if (i > 0) {
            // Добавить элемент из списка A
            result = max(result, A[i - 1] + solve(i - 1, j, A, B, dp, false));
        }
        if (j > 0) {
            // Удалить элемент из списка B
            result = max(result, solve(i, j - 1, A, B, dp, false));
        }
    } else {
        // Ход игрока B: минимизирует разницу
        result = 1e9;
        if (i > 0) {
            // Добавить элемент из списка B (эквивалентно удалению из A)
            result = min(result, -B[j - 1] + solve(i - 1, j, A, B, dp, true));
        }
        if (j > 0) {
            // Удалить элемент из списка A
            result = min(result, solve(i, j - 1, A, B, dp, true));
        }
    }

    // Сохраняем результат в dp
    dp[i][j] = result;
    return result;
}

int maxDifference(vector<int>& A, vector<int>& B) {
    // Сортируем списки по убыванию
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    int n = A.size();
    // Инициализируем таблицу dp
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    // Вычисляем результат
    return solve(n, n, A, B, dp, true);
}

int main() {
    // Пример входных данных
    vector<int> A = {100, 100, 100};
    vector<int> B = {100, 100, 100};

    // Вычисляем и выводим результат
    int result = maxDifference(A, B);
    cout << "Разница между очками A и B: " << result << endl;

    return 0;
}
