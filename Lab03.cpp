#include <iostream>
using namespace std;
int main() {
    //ZADANIE 1 i 2
    /*int a,b;
    cout << "Podaj pierwsza i druga liczbe calkowita:";
    cin >> a >> b;
    if (a==b) { 
        cout << "Liczby sa sobie rowne" << endl;
    } else  {if (a>b) 
       { cout << "Pierwsza liczba jest wieksza od drugiej liczby" << endl;
    }else {
        cout << "Druga liczba jest wieksza od pierwszej liczby" << endl;
    }
}
    return 0;
*/

//ZADANIE 3
double r;
cout << "Podaj wartosc wspolczynnika korelacji:" << endl;
cin >> r;
if (r<0 || r>1) {
    cout << "r jest poza wartosciami." << endl;
}
else if (r>= 0.7 && r<=1){
cout << "Bardzo silna korelacja dodatnia." << endl;}
else if (r>=0.5){
cout << "Silna korelacja dodatnia." << endl;}
else if (r>=0.3) {
    cout << "umiarkowana korelacja dodatnia." << endl;
}
else if (r>= 0.2) {
    cout << "slaba korelacja dodatnia." <<endl;
}
else if (r>=0) {
    cout << "brak korelacji." << endl;
}

}