#include <iostream>
#include <stdlib.h> 
#include "headerFile.h";
using namespace std;
 // globalne zmienne i tablice 
double historyTemps[100]; 
char historyUnits[100];   
int dataCounter = 0;      

// Definicje funkcji
float FtoC(float F) {
    return (F - 32.0) * 5.0 / 9.0;
}
float FtoK(float F) {
    return (F + 459.67) * 5.0 / 9.0;
}
float CtoF(float C) {
    return C * 9.0 / 5.0 + 32.0;
}
float CtoK(float C) {
    return C + 273.15;
}
float KtoC(float K) {
    return K - 273.15;
}
float KtoF(float K) {
    return K * 9.0 / 5.0 - 459.67;
}

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
    if ((stopnie == 'K' && temp < 0) || (stopnie == 'C' && temp < -273.15) || (stopnie == 'F' && temp < -459.67)) {
        return -999; 
    return 0; 
}

void wyswietlMenu() {
    cout << "Menu konwersji temperatur:\n";
    cout << "1. Fahrenheity -> Celsjusze\n";
    cout << "2. Fahrenheity -> Kelwiny\n";
    cout << "3. Celsjusze -> Fahrenheity\n";
    cout << "4. Celsjusze -> Kelwiny\n";
    cout << "5. Kelwiny -> Celsjusze\n";
    cout << "6. Kelwiny -> Fahrenheity\n";
    cout << "7. Pokaz historie\n";
    cout << "8. Usuwanie z historii\n";
    cout << "9. Modyfikacja wpisu z historii\n";
    cout << "10. Losowe wypelnienie historii\n";
    cout << "-1. Zakoncz program\n";
}

void zapiszDoHistorii(double staraTemp, char staraJednostka, double nowaTemp, char nowaJednostka) {

    historyTemps[dataCounter] = staraTemp;
    historyUnits[dataCounter] = staraJednostka;
    dataCounter++;

    historyTemps[dataCounter] = nowaTemp;
    historyUnits[dataCounter] = nowaJednostka;
    dataCounter++;
}

void pokazHistorie() {
    int liczbaPar = dataCounter / 2;
    cout << "Historia przeliczen:\n";
    for (int i = 0; i < liczbaPar; i++) {
        //  para to i*2 i i*2+1
        cout << "<" << i + 1 << "> "
            << historyTemps[i * 2] << historyUnits[i * 2]
            << " = "
            << historyTemps[i * 2 + 1] << historyUnits[i * 2 + 1]
            << endl;
    }

    if (liczbaPar == 0) {
        cout << "Brak historii.\n";
    }

    cout << "Nacisnij Enter, aby kontynuowac...";
    cin.ignore();
    cin.get();
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
            }
            else {
                wynik = FtoC(fahr);
                cout << "Temperatura w Celsjuszach: " << wynik << endl;
                // Zapis do historii: stara: fahr 'F', nowa: wynik 'C'
                zapiszDoHistorii(fahr, 'F', wynik, 'C');
            }
            cout << "Nacisnij Enter, aby kontynuowac...";
            cin.ignore();
            cin.get();
            break;
        }
        case 2: {
            float fahr = pobierzF();
            if (check(fahr, 'F') == -999) {
                cout << "Nie ma takiej temperatury w skali Fahrenheita!\n";
            }
            else {
                wynik = FtoK(fahr);
                cout << "Temperatura w Kelwinach: " << wynik << endl;
                zapiszDoHistorii(fahr, 'F', wynik, 'K');
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
            }
            else {
                wynik = CtoF(celsius);
                cout << "Temperatura w Fahrenheita: " << wynik << endl;
                zapiszDoHistorii(celsius, 'C', wynik, 'F');
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
            }
            else {
                wynik = CtoK(celsius);
                cout << "Temperatura w Kelwinach: " << wynik << endl;
                zapiszDoHistorii(celsius, 'C', wynik, 'K');
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
            }
            else {
                wynik = KtoC(kelwin);
                cout << "Temperatura w Celsjuszach: " << wynik << endl;
                zapiszDoHistorii(kelwin, 'K', wynik, 'C');
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
            }
            else {
                wynik = KtoF(kelwin);
                cout << "Temperatura w Fahrenheita: " << wynik << endl;
                zapiszDoHistorii(kelwin, 'K', wynik, 'F');
            }
            cout << "Nacisnij Enter, aby kontynuowac...";
            cin.ignore();
            cin.get();
            break;
        }
        case 7:
            cout << "Koniec programu.\n";
            return 0; // Zakończenie programu
        case 8:
            pokazHistorie();
            break;
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

