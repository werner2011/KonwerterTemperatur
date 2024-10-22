#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n;
    cout << "Podaj liczbe naturalna:\t";
    cin >> n;
    if (n <= 1) {
        cout << "Liczba musi byc wieksza od 1\t" << endl;
        return 1;
    }
    double pierwiastek = sqrt(n);
    for (int i = 2; i <= pierwiastek; i++) {
        if (n % i == 0) {
            cout << "Liczba\t" << n << " ma dzielnik\t" << i << " w przedziale [2;pierwiastek z n]\t" << endl;
            return 0;
        }
    }
    cout << "Liczba\t" << n << "nie ma dzielnika w przedziale [2;pierwiastek z n]\t" << endl;
    return 0;
}
