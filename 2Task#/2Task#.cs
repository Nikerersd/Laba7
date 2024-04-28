using System;
using System.Collections.Generic;

class Program
{
    static void Eratosphen(List<int> ProstCh)
    {
        for (int i = 2; i <= 50; i++)
        {
            ProstCh.Add(i);
        }

        for (int i = 0; i <= Math.Sqrt(ProstCh.Count); i++)
        {
            int j = i + 1;
            while (j < ProstCh.Count)
            {
                if (ProstCh[j] % ProstCh[i] == 0)
                {
                    for (int k = j; k < ProstCh.Count - 1; k++)
                    {
                        ProstCh[k] = ProstCh[k + 1];
                    }
                    ProstCh.RemoveAt(ProstCh.Count - 1);
                }
                else
                {
                    j++;
                }
            }
        }
    }

    static int Proizv(List<int> v)
    {
        int product = 1;
        foreach (int num in v)
        {
            product *= num;
        }
        return product;
    }

    static List<int> findDivisors(int n)
    {
        List<int> divisors = new List<int>();
        for (int i = 1; i <= Math.Sqrt(n); ++i)
        {
            if (n % i == 0)
            {
                divisors.Add(i);
                if (i != n / i)
                {
                    divisors.Add(n / i);
                }
            }
        }
        return divisors;
    }

    static int CountOfGoodDivider(List<int> Divisors, List<int> vec)
    {
        int result = 0;
        bool fl = true;
        foreach (int n in Divisors)
        {
            foreach (int k in vec)
            {
                if (n % k != 0)
                {
                    fl = false;
                    break;
                }
            }
            if (fl == true)
            {
                result += 1;
            }
            fl = true;
        }
        return result;
    }

    static int maxGoodDividers(int primeFactors, List<int> ProstCh, List<int> PrimeMn, int result = 0, int index = 0)
    {
        if (index == primeFactors * ProstCh.Count)
        {
            return result;
        }

        PrimeMn[index % primeFactors] = ProstCh[index / primeFactors];
        int p = Proizv(PrimeMn);
        List<int> Divisors = findDivisors(p);
        int Count = CountOfGoodDivider(Divisors, PrimeMn);

        return Math.Max(result, maxGoodDividers(primeFactors, ProstCh, PrimeMn, Math.Max(result, Count), index + 1));
    }

    static void Main(string[] args)
    {
        List<int> ProstCh = new List<int>();
        Eratosphen(ProstCh);
        int primeFactors;
        Console.Write("Введите количество простых множителей: ");
        primeFactors = int.Parse(Console.ReadLine());
        List<int> primeMn = new List<int>(new int[primeFactors]);
        int res = maxGoodDividers(primeFactors, ProstCh, primeMn);
        Console.WriteLine("Максимальное количество хороших делителей: " + res);
    }
}