#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool findExpression(vector<int> numbers, int target, int currentSum, string currentExpression, vector<bool>& used) {
    // Базовый случай: если текущая сумма равна целевому значению, значит решение найдено
    if (currentSum == target) {
        cout << currentExpression << " = " << target << endl;
        return true;
    }

    // Рекурсивный случай: перебираем все возможные действия
    for (size_t i = 0; i < numbers.size(); i++) {
        // Если число уже использовано, пропускаем его
        if (used[i]) continue;

        // Сложение
        used[i] = true;
        if (findExpression(numbers, target, currentSum + numbers[i], currentExpression + "+" + to_string(numbers[i]), used))
            return true;
        used[i] = false;

        // Умножение
        used[i] = true;
        if (findExpression(numbers, target, currentSum * numbers[i], currentExpression + "*" + to_string(numbers[i]), used))
            return true;
        used[i] = false;
    }

    return false;
}

int main() {
    int n, target;
    cout << "Введите количество двузначных чисел: ";
    cin >> n;
    vector<int> numbers(n);
    vector<bool> used(n, false);
    cout << "Введите " << n << " двузначных чисел:\n";
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    cout << "Введите целевое число: ";
    cin >> target;

    // Пробуем каждое число в качестве начального числа в выражении
    for (size_t i = 0; i < numbers.size(); i++) {
        used[i] = true;
        if (findExpression(numbers, target, numbers[i], to_string(numbers[i]), used))
            return 0;
        used[i] = false;
    }

    cout << "Невозможно получить заданное число используя эти числа и операции сложения и умножения." << endl;

    return 0;
}
