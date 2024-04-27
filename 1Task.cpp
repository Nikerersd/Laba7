#include <iostream>
#include <vector>

using namespace std;

// Функция для проверки, можно ли получить сумму S из элементов вектора numbers
bool canGetSum(vector<int>& numbers, int S, size_t index = 0, int currentSum = 0) {
    // Если текущая сумма равна S, значит, можно получить сумму из элементов вектора
    if (currentSum == S)
        return true;
    
    // Базовый случай: если мы прошлись по всем числам или текущая сумма больше S
    if (index == numbers.size() || currentSum > S)
        return false;
    
    // Рекурсивно проверяем, можно ли получить S с добавлением текущего числа
    if (canGetSum(numbers, S, index + 1, currentSum + numbers[index]))
        return true;
    
    // Рекурсивно проверяем, можно ли получить S с умножением на текущее число
    if (canGetSum(numbers, S, index + 1, currentSum * numbers[index]))
        return true;

    // Рекурсивно проверяем, можно ли получить S с добавлением текущего числа к предыдущему умноженному числу
    if (index > 0 && canGetSum(numbers, S, index + 1, (currentSum - numbers[index - 1]) + numbers[index - 1] * numbers[index]))
        return true;
    
    // Если ни одно из действий не приводит к S
    return false;
}

int main() {
    // Заданные значения N и S
    int N, S;
    cout << "Введите количество двузначных чисел N: ";
    cin >> N;
    cout << "Введите число S: ";
    cin >> S;

    // Вектор для хранения двузначных чисел
    vector<int> numbers(N);
    cout << "Введите " << N << " двузначных чисел:\n";
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
        // Проверяем, что числа двузначные
        if (numbers[i] < 10 || numbers[i] > 99) {
            cout << "Число должно быть двузначным. Пожалуйста, введите снова: ";
            cin >> numbers[i];
        }
    }

    // Проверяем, можно ли получить сумму S из заданных чисел
    if (canGetSum(numbers, S))
        cout << "Можно получить сумму " << S << " из заданных чисел.\n";
    else
        cout << "Нельзя получить сумму " << S << " из заданных чисел.\n";

    return 0;
}
