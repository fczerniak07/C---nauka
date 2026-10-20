//Zadanie 1 - rozne wariacje petli for 
#include <iostream>
 using namespace std ;
 int main(){ //kod 02_12
 /*for (int i = 10; i >= 0; i-=2) {
 cout << i << endl ;
 }
  return 0;
  */

  //Zadanie 3 
/*int fahr, celsius;
int start, limit, krok;
start = 0;
limit = 200;
krok = 20;
for (fahr = 0.0; fahr <= limit; fahr = fahr + krok){
    float celsius = (5.0 / 9.0) * (fahr - 32.0);
    cout << fahr << "\t" << celsius << endl;
}
*/

//Zadanie 8
/*for ( int i = 0; i <= 100; i+=2)
cout << i << endl;
return 0;
*/

//Zadanie 7
/*double liczba;
for (int i = 0; i < 10; i++) {
cout << "Podaj liczbe:" << endl;
cin >> liczba;
if (liczba > 0) {
    cout << "Liczba jest dodatnia" << endl;
}
 }
*/

//Zadanie 9
/*int n;
cout << "Podaj n" << endl;
    cin >> n;
    if (n == 0)
    {
        cout << "Nie mozna dzielic przez 0" << endl;
        return 0;
    }
for (int i=0; i<=100; i++) {
    if ( i % n == 0) {
        cout << i << endl;
    }
}
return 0;
*/

//Zadanie 10
/*int n;
int licznik=0;
cout << "Podaj liczbe n:" << endl;
cin >> n;
if (n==0) {
    cout << "Nie mozna dzielic przez zero" << endl;
    return 0;
}
for (int i=0; i<=100; i++) {
    if (i%n == 0) {
        licznik++;
    }
}
cout << "Liczb podzielnych przez " << n << " w zakresie od 0 do 100 jest: " << licznik << endl
;
return 0;
*/


}
