#include <iostream>
#include <iomanip>
#include <stdlib.h> // Do system("cls")
using namespace std;

// Prototypy funkcji
float FtoC(float F);
float FtoK(float F);
float CtoF(float C);
float CtoK(float C);
float KtoC(float K);
float KtoF(float K);

float pobierzF();
float pobierzC();
float pobierzK();

int check(float temp, char stopnie);

// Definicje funkcji
float FtoC(float F) { return (F - 32.0) * 5 / 9; }
float FtoK(float F) { return (F + 459.67) * 5 / 9; }
float CtoF(float C) { return C * 9 / 5 + 32; }
float CtoK(float C) { return C + 273.15; }
float KtoC(float K) { return K - 273.15; }
float KtoF(float K) { return K * 9 / 5 - 459.67; }

float pobierzF() {
    float fahr;
    cout << "Podaj temperature w Fahrenheita: ";
    cin >> fahr;
    return fahr;
}

float pobierzC() {
    float celsius;
    cout << "Podaj temperature w Celsjuszach: ";
    cin >> celsius;
    return celsius;
}

float pobierzK() {
    float kelwin;
    cout << "Podaj temperature w Kelwinach: ";
    cin >> kelwin;
    return kelwin;
}

int check(float temp, char stopnie) {
    if ((stopnie == 'K' && temp < 0) || 
        (stopnie == 'C' && temp < -273.15) || 
        (stopnie == 'F' && temp < -459.67)) {
        return -999; // Temperatura poza zakresem skali
    }
    return 0; // Temperatura poprawna
}

void wyswietlMenu() {
    cout << "Menu konwersji temperatur:\n";
    cout << "1. Fahrenheity -> Celsjusze\n";
    cout << "2. Fahrenheity -> Kelwiny\n";
    cout << "3. Celsjusze -> Fahrenheity\n";
    cout << "4. Celsjusze -> Kelwiny\n";
    cout << "5. Kelwiny -> Celsjusze\n";
    cout << "6. Kelwiny -> Fahrenheity\n";
    cout << "7. Zakoncz program\n";
}

int main() {
    int wybor;
    float wynik;

    while (true) { // Pętla nieskończona
        system("cls"); // Czyścimy ekran
        wyswietlMenu(); // Wyświetlenie menu
        cout << "Wybierz opcje: ";
        cin >> wybor;

        switch (wybor) {
            case 1: {
                float fahr = pobierzF();
                if (check(fahr, 'F') == -999) {
                    cout << "Nie ma takiej temperatury w skali Fahrenheita!\n";
                } else {
                    wynik = FtoC(fahr);
                    cout << "Temperatura w Celsjuszach: " << fixed << setprecision(3) << wynik << endl;
                }
                cout << "Nacisnij Enter, aby kontynuowac...";
                cin.ignore();
                cin.get(); // Czeka na naciśnięcie Enter
                break;
            }
            case 2: {
                float fahr = pobierzF();
                if (check(fahr, 'F') == -999) {
                    cout << "Nie ma takiej temperatury w skali Fahrenheita!\n";
                } else {
                    wynik = FtoK(fahr);
                    cout << "Temperatura w Kelwinach: " << fixed << setprecision(3) << wynik << endl;
                }
                cout << "Nacisnij Enter, aby kontynuowac...";
                cin.ignore();
                cin.get();
                break;
            }
            case 3: {
                float celsius = pobierzC();
                if (check(celsius, 'C') == -999) {
                    cout << "Nie ma takiej temperatury w skali Celsjusza!\n";
                } else {
                    wynik = CtoF(celsius);
                    cout << "Temperatura w Fahrenheita: " << fixed << setprecision(3) << wynik << endl;
                }
                cout << "Nacisnij Enter, aby kontynuowac...";
                cin.ignore();
                cin.get();
                break;
            }
            case 4: {
                float celsius = pobierzC();
                if (check(celsius, 'C') == -999) {
                    cout << "Nie ma takiej temperatury w skali Celsjusza!\n";
                } else {
                    wynik = CtoK(celsius);
                    cout << "Temperatura w Kelwinach: " << fixed << setprecision(3) << wynik << endl;
                }
                cout << "Nacisnij Enter, aby kontynuowac...";
                cin.ignore();
                cin.get();
                break;
            }
            case 5: {
                float kelwin = pobierzK();
                if (check(kelwin, 'K') == -999) {
                    cout << "Nie ma takiej temperatury w skali Kelwina!\n";
                } else {
                    wynik = KtoC(kelwin);
                    cout << "Temperatura w Celsjuszach: " << fixed << setprecision(3) << wynik << endl;
                }
                cout << "Nacisnij Enter, aby kontynuowac...";
                cin.ignore();
                cin.get();
                break;
            }
            case 6: {
                float kelwin = pobierzK();
                if (check(kelwin, 'K') == -999) {
                    cout << "Nie ma takiej temperatury w skali Kelwina!\n";
                } else {
                    wynik = KtoF(kelwin);
                    cout << "Temperatura w Fahrenheita: " << fixed << setprecision(3) << wynik << endl;
                }
                cout << "Nacisnij Enter, aby kontynuowac...";
                cin.ignore();
                cin.get();
                break;
            }
            case 7:
                cout << "Koniec programu.\n";
                return 0; // Zakończenie programu
            default:
                cout << "Nieprawidlowy wybor.\n";
                cout << "Nacisnij Enter, aby kontynuowac...";
                cin.ignore();
                cin.get();
                break;
        }
    }

    return 0;
}

