using System;
using System.Collections.Generic;

class Program
{
    static bool FindExpression(List<int> numbers, int target, int currentSum, string currentExpression, bool[] used)
    {
        // Базовый случай: если текущая сумма равна целевому значению, значит решение найдено
        if (currentSum == target)
        {
            Console.WriteLine(currentExpression + " = " + target);
            return true;
        }

        // Рекурсивный случай: перебираем все возможные действия
        for (int i = 0; i < numbers.Count; i++)
        {
            // Если число уже использовано, пропускаем его
            if (used[i]) continue;

            // Сложение
            used[i] = true;
            if (FindExpression(numbers, target, currentSum + numbers[i], currentExpression + "+" + numbers[i], used))
                return true;
            used[i] = false;

            // Умножение
            used[i] = true;
            if (FindExpression(numbers, target, currentSum * numbers[i], currentExpression + "*" + numbers[i], used))
                return true;
            used[i] = false;
        }
        return false;
    }

    static void Main(string[] args)
    {
        Console.Write("Введите количество двузначных чисел: ");
        int n = int.Parse(Console.ReadLine());
        List<int> numbers = new List<int>();
        bool[] used = new bool[n];
        Console.WriteLine("Введите " + n + " двузначных чисел:");
        var inputs = Console.ReadLine().Split();
        for (int i = 0; i < n; i++)
        {
            numbers.Add(int.Parse(inputs[i]));
        }
        Console.Write("Введите целевое число: ");
        int target = int.Parse(Console.ReadLine());

        // Пробуем каждое число в качестве начального числа в выражении
        for (int i = 0; i < numbers.Count; i++)
        {
            used[i] = true;
            if (FindExpression(numbers, target, numbers[i], numbers[i].ToString(), used))
                return;
            used[i] = false;
        }

        Console.WriteLine("Невозможно получить заданное число используя эти числа и операции сложения и умножения.");
    }
}
