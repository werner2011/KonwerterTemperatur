#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
#include <limits>

using namespace std;

// Tablice
double temperatury[100] = {0}; // Przechowuje wartości temperatur
char symbole[100] = {0};	   // Przechowuje symbole skali ('C','F','K')
int dataCounter = 0;

// Funkcje walidacji
double readDouble()
{
	double value;
	while (!(cin >> value))
	{
		cin.clear();										 // Czyszczenie stanu strumienia
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Usuwanie błędnych danych z bufora
		cout << "Niepoprawne dane. Wprowadz liczbe:\a ";
	}
	return value;
}

int readInt()
{
	int value;
	while (!(cin >> value))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Niepoprawne dane. Wprowadz liczbe calkowita:\a ";
	}
	return value;
}

// Definicje funkcji:
double FtoC(double F)
{
	return (F - 32.0) * 5.0 / 9.0;
}
double FtoK(double F)
{
	return (F + 459.67) * 5.0 / 9.0;
}
double CtoF(double C)
{
	return (C * 9.0 / 5.0 + 32.0);
}
double CtoK(double C)
{
	return (C + 273.15);
}
double KtoF(double K)
{
	return (K * 9.0 / 5.0 - 459.67);
}
double KtoC(double K)
{
	return (K - 273.15);
}
// Funkcje pomocnicze
double pobierz_F()
{
	cout << "Podaj temperature w stopniach Fahrenheita: ";
	return readDouble();
}

double pobierz_C()
{
	cout << "Podaj temperature w stopniach Celsjusza: ";
	return readDouble();
}

double pobierz_K()
{
	cout << "Podaj temperature w Kelwinach: ";
	return readDouble();
}

// Funkcja do sprawdzania poprawności temperatur
int check(double temp, char stopnie)
{
	if ((temp < 0 && stopnie == 'K') ||
		(temp < -273.15 && stopnie == 'C') ||
		(temp < -459.67 && stopnie == 'F'))
	{
		return -999;
	}
	return 0;
}

// Funkcje do historii
void zapiszDoHistorii(double staraTemp, char staraJednostka, double nowaTemp, char nowaJednostka)
{
	if (dataCounter < 100)
	{
		temperatury[dataCounter] = staraTemp;
		symbole[dataCounter] = staraJednostka;
		dataCounter++;

		temperatury[dataCounter] = nowaTemp;
		symbole[dataCounter] = nowaJednostka;
		dataCounter++;
	}
	else
	{
		cout << "Historia jest pełna! Nie można zapisać więcej danych." << endl;
	}
}
void pokazHistorie()
{
	system("cls");
	cout << "Wybierz co chcesz zobaczyc:" << endl;
	cout << "1. Tylko C -> inne" << endl;
	cout << "2. Tylko F -> inne" << endl;
	cout << "3. Tylko K -> inne" << endl;
	cout << "4. Cala historia" << endl;
	int wybor;
	cin >> wybor;
	cout << "Historia przeliczen:" << endl;
	int licznik = 0;

	for (int i = 0; i < dataCounter; i += 2)
	{
		if (wybor == 1 && symbole[i] == 'C')
		{
			cout << "<" << (i / 2) + 1 << "> " << temperatury[i] << symbole[i] << " = " << temperatury[i + 1] << symbole[i + 1] << endl;
			licznik++;
		}
		else if (wybor == 2 && symbole[i] == 'F')
		{
			cout << "<" << (i / 2) + 1 << "> " << temperatury[i] << symbole[i] << " = " << temperatury[i + 1] << symbole[i + 1] << endl;
			licznik++;
		}
		else if (wybor == 3 && symbole[i] == 'K')
		{
			cout << "<" << (i / 2) + 1 << "> " << temperatury[i] << symbole[i] << " = " << temperatury[i + 1] << symbole[i + 1] << endl;
			licznik++;
		}
		else if (wybor == 4)
		{
			cout << "<" << (i / 2) + 1 << "> " << temperatury[i] << symbole[i] << " = " << temperatury[i + 1] << symbole[i + 1] << endl;
			licznik++;
		}
	}

	if (licznik == 0)
	{
		cout << "Brak danych." << endl;
	}
}
void usunZHistorii()
{
	system("cls");

	cout << "Historia przeliczen:" << endl;

	for (int i = 0; i < dataCounter; i += 2)
	{
		cout << "<" << (i / 2) + 1 << "> "
			 << temperatury[i] << symbole[i]
			 << " = "
			 << temperatury[i + 1] << symbole[i + 1]
			 << endl;
	}

	cout << "Podaj numer wpisu do usuniecia: ";
	int numer = readInt();

	if (numer < 1 || numer > dataCounter / 2)
	{
		cout << "Niepoprawny numer!" << endl;
		return;
	}

	int index = (numer - 1) * 2;

	for (int i = index; i + 2 < dataCounter; i++)
	{
		temperatury[i] = temperatury[i + 2];
		symbole[i] = symbole[i + 2];
	}

	dataCounter -= 2;

	cout << "Usunieto wpis z historii." << endl;
}

void modyfikacja_wpisu()
{
	system("cls");
	cout << "Historia przeliczen: " << endl;
	for (int i = 0; i < dataCounter; i = i + 2)
	{
		cout << "<" << (i / 2) + 1 << ">" << temperatury[i] << symbole[i] << "=" << temperatury[i + 1] << symbole[i + 1] << endl;
	}
	cout << "Podaj numer wpisu do ususniecia: " << endl;
	int numer_do_usuniecia = 1;
	cin >> numer_do_usuniecia;
	if (numer_do_usuniecia < 1 || numer_do_usuniecia > dataCounter / 2)
	{
		cout << "Niepoprawny numer" << endl;
		return;
	}
	int index_modyfikacja = (numer_do_usuniecia - 1) * 2;
	double newTemp;
	char newSkala;

	cout << "Podaj nowa temperature i skale: ";
	cin >> newTemp >> newSkala;
	cout << "Podaj nowa skale docelowa: "; // na co przeliczamy
	char skala_docelowa;
	cin >> skala_docelowa;
	if (check(newTemp, newSkala) == -999)
	{
		cout << "Bledna temperatura." << endl;
		return;
	}
	double przeliczona_Temp = 0;
	if (newSkala == 'C' && skala_docelowa == 'F')
	{
		przeliczona_Temp = CtoF(newTemp);
	}
	else if (newSkala == 'C' && skala_docelowa == 'K')
	{
		przeliczona_Temp = CtoK(newTemp);
	}
	else if (newSkala == 'F' && skala_docelowa == 'C')
	{
		przeliczona_Temp = FtoC(newTemp);
	}
	else if (newSkala == 'F' && skala_docelowa == 'K')
	{
		przeliczona_Temp = FtoK(newTemp);
	}
	else if (newSkala == 'K' && skala_docelowa == 'C')
	{
		przeliczona_Temp = KtoC(newTemp);
	}
	else if (newSkala == 'K' && skala_docelowa == 'F')
	{
		przeliczona_Temp = KtoF(newTemp);
	}
	else
	{
		cout << "Niepoprawna konwersja. " << endl;
		return;
	}
	temperatury[index_modyfikacja] = newTemp;
	symbole[index_modyfikacja] = newSkala;
	temperatury[index_modyfikacja + 1] = przeliczona_Temp;
	symbole[index_modyfikacja + 1] = skala_docelowa;
	cout << "Wpis zmodyfikowany" << endl;
}

void losowe_wypelnienie_Historii()
{
	system("cls");
	srand(time(0));
	cout << "Ile losowych wpisow chcesz dodac?: ";
	int ile_Losowych;
	cin >> ile_Losowych;
	if (dataCounter + ile_Losowych > 100)
	{
		cout << "Za malo miejsca w historii! Mozna dodac tylko " << 100 - dataCounter << " nowych wpisow" << endl;
		return;
	}
	for (int i = 0; i < ile_Losowych; i++)
	{
		char skalaWejsciowa = "CFK"[rand() % 3];
		double tempWejsciowa = 0;
		double tempDocelowa = 0;
		char skalaDocelowa;

		if (skalaWejsciowa == 'C')
		{
			tempWejsciowa = (rand() % 1000) - 273.15;
			skalaDocelowa = "FK"[rand() % 2];
			tempDocelowa = (skalaDocelowa == 'F') ? CtoF(tempWejsciowa) : CtoK(tempWejsciowa);
		}
		else if (skalaWejsciowa == 'F')
		{
			tempWejsciowa = (rand() % 1000) + -469.67;
			skalaDocelowa = "CK"[rand() % 2];
			tempDocelowa = (skalaDocelowa == 'C') ? FtoC(tempWejsciowa) : FtoK(tempWejsciowa);
		}
		else if (skalaWejsciowa == 'K')
		{
			tempWejsciowa = (rand() % 1000) + 0;
			skalaDocelowa = "CF"[rand() % 2];
			tempDocelowa = (skalaDocelowa == 'C') ? KtoC(tempWejsciowa) : KtoF(tempWejsciowa);
		}
		zapiszDoHistorii(tempWejsciowa, skalaWejsciowa, tempDocelowa, skalaDocelowa);
		cout << "Dodano wpis: " << tempWejsciowa << skalaWejsciowa << "=" << tempDocelowa << skalaDocelowa << endl;
	}
}

void wyswietl_Menu()
{
	cout << "MENU KONWERTERA TEMPERATUR" << endl;
	cout << "1. Przelicz Fahr -> Celsius" << endl;
	cout << "2. Przelicz Fahr -> Kelwin" << endl;
	cout << "3. Przelicz Celsius->Fahr" << endl;
	cout << "4. Przelicz Celsius ->Kelwin" << endl;
	cout << "5. Przelicz Kelwin -> Celsius" << endl;
	cout << "6. Przelicz Kelwin -> Fahr" << endl;
	cout << "7. Pokaz historie" << endl;
	cout << "8. Usun wpis z historii" << endl;
	cout << "9. Modyfikuj wpis z historii" << endl;
	cout << "10. Dodaj losowe wypelnienie historii" << endl;
	cout << "-1. Zakoncz dzialanie programu" << endl;
}
int main()
{
	int wybor;
	double wynik;
	while (true)
	{
		system("cls");
		wyswietl_Menu();
		cout << "Wybierz opcje: ";
		wybor = readInt();
		switch (wybor)
		{
		case 1:
		{
			double fahrenheit = pobierz_F();
			if (check(fahrenheit, 'F') == -999)
			{
				cout << "Nie ma takiej temperatury w skali Fahrenheita!" << endl;
			}
			else
			{
				wynik = FtoC(fahrenheit);
				cout << "Temperatura w Celsjuszach: " << wynik << endl;
				zapiszDoHistorii(fahrenheit, 'F', wynik, 'C');
			}
			cout << "Nacisnij Enter zeby kontynuowac...";
			cin.ignore();
			cin.get();
			break;
		}
		case 2:
		{
			double fahr = pobierz_F();
			if (check(fahr, 'F') == -999)
			{
				cout << "Nie ma takiej temperatury w skali Fahrenheita!" << endl;
			}
			else
			{
				wynik = FtoK(fahr);
				cout << "Temperatura w Kelwinach: " << wynik << endl;
				zapiszDoHistorii(fahr, 'F', wynik, 'K');
			}
			cout << "Nacisnij Enter zeby kontynuowac...";
			cin.ignore();
			cin.get();
			break;
		}
		case 3:
		{
			double celsjusz = pobierz_C();
			if (check(celsjusz, 'C') == -999)
			{
				cout << "Nie ma takiej temperatury w skali Celsjusza!" << endl;
			}
			else
			{
				wynik = CtoF(celsjusz);
				cout << "Temperatura w Fahrenheitach: " << wynik << endl;
				zapiszDoHistorii(celsjusz, 'C', wynik, 'F');
			}
			cout << "Nacisnij Enter zeby kontynuowac...";
			cin.ignore();
			cin.get();
			break;
		}
		case 4:
		{
			double cels = pobierz_C();
			if (check(cels, 'C') == -999)
			{
				cout << "Nie ma takiej temperatury w skali Celsjusza!" << endl;
			}
			else
			{
				wynik = CtoK(cels);
				cout << "Temperatura w Kelwinach: " << wynik << endl;
				zapiszDoHistorii(cels, 'C', wynik, 'K');
			}
			cout << "Nacisnij Enter zeby kontynuowac...";
			cin.ignore();
			cin.get();
			break;
		}
		case 5:
		{
			double kelwin = pobierz_K();
			if (check(kelwin, 'K') == -999)
			{
				cout << "Nie ma takiej temperatury w skali Kelwina!" << endl;
			}
			else
			{
				wynik = KtoC(kelwin);
				cout << "Temperatura w Celsjuszach to: " << wynik << endl;
				zapiszDoHistorii(kelwin, 'K', wynik, 'C');
			}
			cout << "Nacisnij Enter zeby kontynuowac...";
			cin.ignore();
			cin.get();
			break;
		}
		case 6:
		{
			double kel = pobierz_K();
			if (check(kel, 'K') == -999)
			{
				cout << "Nie ma takiej temperatury w skali Kelwina! " << endl;
			}
			else
			{
				wynik = KtoF(kel);
				cout << "Temperatura w Fahrenheitach to: " << wynik << endl;
				zapiszDoHistorii(kel, 'K', wynik, 'F');
			}
			cout << "Nacisnij Enter zeby kontynuowac...";
			cin.ignore();
			cin.get();
			break;
		}
		case 7:
		{
			pokazHistorie();
			cout << "Nacisnij Enter zeby kontynuowac...";
			cin.ignore();
			cin.get();
			break;
		}
		case 8:
		{
			usunZHistorii();
			cout << "Nacisnij Enter zeby kontynuowac...";
			cin.ignore();
			cin.get();
			break;
		}
		case 9:
		{
			modyfikacja_wpisu();
			cout << "Nacisnij Enter zeby kontynuowac...";
			cin.ignore();
			cin.get();
			break;
		}
		case 10:
		{
			losowe_wypelnienie_Historii();
			cout << "Nacisnij Enter zeby kontynuowac...";
			cin.ignore();
			cin.get();
			break;
		}
		case -1:
			cout << "Koniec programu" << endl;
			return 0;
		default:
			cout << "Nieprawidlowy wybor.\nNacisnij Enter...";
			cin.ignore();
			cin.get();
			break;
		}
	}
}
