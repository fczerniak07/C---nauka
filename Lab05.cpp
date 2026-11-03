#include <iostream>

using namespace std;

int main() {

    //ZAD.1
    /*const int SIZE = 10;
    int tab[SIZE];

    cout << "Podaj 10 liczb calkowitych:\n";
    for (int i = 0; i < SIZE; i++) {
        cin >> tab[i];
    }

    cout << "Liczby w odwrotnej kolejnosci:\n";
    for (int i = SIZE - 1; i >= 0; i--) {
        cout << tab[i] << " ";
    }
    cout << "\n";

    return 0;
*/
   
//ZAD.2
/*int n;
cout << "Ile liczb ciagu Fibonacciego chcesz wyznaczyc? ";
cin >> n;

if (n<2) {
    cout << " Liczba elementow musi wynosic co njamniej 2" << endl;
    return 0;
}
long long tab[n];
tab [0] = 0;
tab [1] = 1;

for (int i=2; i<n; i++) {
    tab[i] = tab[i-1] + tab [i-2];
}

cout << "Wyznaczone liczby ciagu Fibonnaciego: " << endl;
for (int i=0; i<n; i++) {
    cout << "F[" << i << "] = " << tab[i] << endl;
}
return 0;
*/

//ZAD.3
const int SIZE = 10;
int tab[SIZE];
int suma = 0;

cout << "Wylosowane elemnty tablicy: " << endl;
for (int i=0; i<SIZE; i++) {
    tab[i] = rand() % 101 - 50;
    cout << tab[i] << " ";
    suma += tab[i];

}
cout << "\n";

double srednia = static_cast<double>(suma) / SIZE;
cout << "Srednia wartosc: " << srednia << endl;

int ponizejSredniej = 0;
int minimum = tab[0];
int maksimum = tab[0];

for (int i=0; i<SIZE; i++) {
    if (tab[i] < srednia) {
        ponizejSredniej++;
    }
    if (tab[i] < minimum) {
        minimum = tab[i];
    }
    if (tab[i] > maksimum) {
        maksimum = tab[i];
    }
}

cout << "Liczby ponizej sredniej: " << ponizejSredniej << endl;
cout << "Minimum: " << minimum << endl;
cout << "Maksimum: " << maksimum << endl;

return 0; 
}