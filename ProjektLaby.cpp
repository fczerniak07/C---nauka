#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

// Krok 2: Wyświetlanie stanu populacji
void showPopulation(int day, int susceptible, int infected, int recovered) {
    int total = susceptible + infected + recovered;
    cout << "\nDay: " << day << "\n";
    cout << "Susceptible: " << susceptible << "\n";
    cout << "Infected: " << infected << "\n";
    cout << "Recovered: " << recovered << "\n";
    cout << "Total: " << total << "\n";
}

// Krok 5: Sprawdzenie poprawności populacji
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

    // Obliczenie wartości zaokrąglonych w dół na podstawie stanu początkowego dnia
    int newInfections = static_cast<int>(floor(currentInfected * infectionRate));
    int newRecoveries = static_cast<int>(floor(currentInfected * recoveryRate));

    // Ograniczenie do dostępnych osób w odpowiednich grupach
    newInfections = min(newInfections, susceptible);
    newRecoveries = min(newRecoveries, currentInfected);

    // Aktualizacja grup
    susceptible -= newInfections;
    infected = infected + newInfections - newRecoveries;
    recovered += newRecoveries;

    // Inkrementacja numeru dnia
    day++;
}

// Krok 7: Zmiana parametrów modelu z walidacją
void changeParameters(double &infectionRate, double &recoveryRate) {
    double tempInfectionRate, tempRecoveryRate;

    cout << "Enter infection rate (0-1): ";
    cin >> tempInfectionRate;
    cout << "Enter recovery rate (0-1): ";
    cin >> tempRecoveryRate;

    // Walidacja obu wartości przed wprowadzeniem zmian
    if (tempInfectionRate >= 0.0 && tempInfectionRate <= 1.0 &&
        tempRecoveryRate >= 0.0 && tempRecoveryRate <= 1.0) {
        infectionRate = tempInfectionRate;
        recoveryRate = tempRecoveryRate;
        cout << "Parameters updated.\n";
    } else {
        cout << "Error: Rates must be between 0 and 1. Parameters remain unchanged.\n";
    }
}

int main() {
    // Krok 1: Inicjalizacja stanu początkowego
    int susceptible = 80;
    int infected = 10;
    int recovered = 10;
    int day = 0;

    double infectionRate = 0.20;
    double recoveryRate = 0.10;

    bool running = true;

    // Krok 6: Główna pętla programu
    while (running) {
        showPopulation(day, susceptible, infected, recovered);

        cout << "\n=== Epidemic Simulator ===\n";
        cout << "1. Simulate next day\n";
        cout << "2. Change model parameters\n";
        cout << "3. Exit\n";
        cout << "Your choice: ";

        int choice;
        if (!(cin >> choice)) {
            cout << "Invalid input. Exiting.\n";
            break;
        }

        switch (choice) {
            case 1:
                simulateDay(day, susceptible, infected, recovered, infectionRate, recoveryRate);
                if (!checkPopulation(susceptible, infected, recovered)) {
                    cout << "\nCritical Error: Invalid population state detected!\n";
                    running = false;
                }
                break;

            case 2:
                changeParameters(infectionRate, recoveryRate);
                break;

            case 3:
                cout << "Exiting simulator. Goodbye!\n";
                running = false;
                break;

            default:
                cout << "Invalid choice. Please select an option from 1 to 3.\n";
                break;
        }
    }

    return 0;
}