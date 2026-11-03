#include <iostream>
#include <cmath>

using namespace std;

// Krok 2: Wyswietlanie stanu populacji
void showPopulation(int day, int susceptible, int infected, int recovered) {
    int total = susceptible + infected + recovered;
    cout << endl;
    cout << "Day: " << day << endl;
    cout << "Susceptible: " << susceptible << endl;
    cout << "Infected: " << infected << endl;
    cout << "Recovered: " << recovered << endl;
    cout << "Total: " << total << endl;
}

// Krok 5: Sprawdzenie poprawnosci populacji
bool checkPopulation(int susceptible, int infected, int recovered) {
    if (susceptible < 0 || infected < 0 || recovered < 0) {
        return false;
    }
    if (susceptible + infected + recovered != 100) {
        return false;
    }
    return true;
}

// Krok 4: Symulacja kolejnego dnia
void simulateDay(int &day, int &susceptible, int &infected, int &recovered, double infectionRate, double recoveryRate) {
    int currentInfected = infected;

    // Zaokraglanie w dol 
    int newInfections = (int)floor(currentInfected * infectionRate);
    int newRecoveries = (int)floor(currentInfected * recoveryRate);

    // Ograniczenie liczby za pomoca if
    if (newInfections > susceptible) {
        newInfections = susceptible;
    }
    if (newRecoveries > currentInfected) {
        newRecoveries = currentInfected;
    }

    // Aktualizacja
    susceptible = susceptible - newInfections;
    infected = infected + newInfections - newRecoveries;
    recovered = recovered + newRecoveries;

    // Kolejny dzien
    day++;
}

// Krok 7: Zmiana parametrow modelu
void changeParameters(double &infectionRate, double &recoveryRate) {
    double newInf, newRec;

    cout << "Enter infection rate (0-1): ";
    cin >> newInf;
    cout << "Enter recovery rate (0-1): ";
    cin >> newRec;

    // Sprawdzenie czy obie liczby mieszcza sie w przedziale [0, 1]
    if (newInf >= 0.0 && newInf <= 1.0 && newRec >= 0.0 && newRec <= 1.0) {
        infectionRate = newInf;
        recoveryRate = newRec;
        cout << "Parameters updated." << endl;
    } else {
        cout << "Blad: Wspolczynniki musza byc z przedzialu od 0 do 1!" << endl;
    }
}

int main() {
    // Krok 1: Stan poczatkowy
    int susceptible = 80;
    int infected = 10;
    int recovered = 10;
    int day = 0;

    double infectionRate = 0.20;
    double recoveryRate = 0.10;

    int choice = 0;

    // Krok 6: petla glowna na szyi
    while (choice != 3) {
        showPopulation(day, susceptible, infected, recovered);

        cout << endl;
        cout << "=== Epidemic Simulator ===" << endl;
        cout << "1. Simulate next day" << endl;
        cout << "2. Change model parameters" << endl;
        cout << "3. Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                simulateDay(day, susceptible, infected, recovered, infectionRate, recoveryRate);
                if (checkPopulation(susceptible, infected, recovered) == false) {
                    cout << "Blad krytyczny: Niepoprawny stan populacji!" << endl;
                    return 1;
                }
                break;

            case 2:
                changeParameters(infectionRate, recoveryRate);
                break;

            case 3:
                cout << "Koniec programu." << endl;
                break;

            default:
                cout << "Niepoprawna opcja! Wybierz 1, 2 lub 3." << endl;
                break;
        }
    }

    return 0;
}