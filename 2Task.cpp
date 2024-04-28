#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <cmath>
using namespace std;

void Eratosphen(vector<int>& ProstCh) {
    for (int i=2; i<=50; i++) {
        ProstCh.push_back(i);
    }
    
    for (int i=0; i <= sqrt(ProstCh.size()); i++) {
        size_t j = i+1;
        while (j < ProstCh.size()) {
            if (ProstCh[j]%ProstCh[i]==0) {
                for (size_t k = j; k < ProstCh.size() - 1; k++) {
                    ProstCh[k] = ProstCh[k + 1];
                }
                ProstCh.pop_back();
            }
            else {
                j++;
            }
        }
    }
}

int Proizv(const vector<int>& v) {
    int product = 1;
    for (int num : v) product *= num;
    return product;
}

vector<int> findDivisors(int n) {
    vector<int> divisors;
    for (int i = 1; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) divisors.push_back(n / i);
        }
    }
    return divisors;
}

int CountOfGoodDivider(const vector<int>& Divisors, const vector<int>& vec) {
    int result = 0;
    bool fl = true;
    for (int n : Divisors) {
        for (int k : vec) {
            if (n % k != 0) {
                fl = false;
                break;
            }
        }
        if (fl == true){
            result += 1;
        }
        fl = true;
    }
    return result;
}

int maxGoodDividers(int primeFactors, const vector<int>& ProstCh, vector<int>& PrimeMn, int result = 0, size_t index = 0) {
    if (index == primeFactors * ProstCh.size()) return result;

    PrimeMn[index % primeFactors] = ProstCh[index / primeFactors];
    int p = Proizv(PrimeMn);
    vector<int> Divisors = findDivisors(p);
    int Count = CountOfGoodDivider(Divisors, PrimeMn);

    return max(result, maxGoodDividers(primeFactors, ProstCh, PrimeMn, max(result, Count), index + 1));
}

int main() {
    vector<int> ProstCh;
    Eratosphen(ProstCh);
    int primeFactors;
    cout << "Введите количество простых множителей: ";
    cin >> primeFactors;
    vector<int> primeMn (primeFactors, 2);
    int res = maxGoodDividers(primeFactors, ProstCh, primeMn);
    cout << "Максимальное количество хороших делителей: " << res;
}
