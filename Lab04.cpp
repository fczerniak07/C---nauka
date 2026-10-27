/*#include <iostream>
using namespace std;
int dodawanie(int a, int b); //funkcja (zwracajaca wynik typu int)
void wyswietlanie(int a, int b); //funkcja bedaca procedura :)

int zmiennaGlobalna = 10;

int main() { //kod 04_05
   int a = 45, b = 25;
   int suma = dodawanie(a, b);
   cout << "Jesli dodam " << a << " do " << b << " to otrzymam " << suma << endl;
   a += 4;
   wyswietlanie(a, b);
   cout << "Zmienna globalna: " << zmiennaGlobalna << endl;
   cout << "Wartosci a oraz b: " << a << " i " << b << endl;
   return 0;
}

int dodawanie(int c, int b) {
   b = c + b;
   return b;
}

void wyswietlanie(int a, int b) {
   cout << "Wynik procedury / funkcji z void: " << a + b << endl;
   zmiennaGlobalna = 20;
   a = 111;
   b = 222;
   // wyjasnienie: a+=4 w main a rosnie do 49 
}
*/

//Zad.1 
#include <iostream>
#include <string>
using namespace std;

void powitanie(string imie) {
    cout << "Czesc, " << imie << endl;
}

void WyswietlWieksza(int a, int b);
/*void tabliczkaMnozenia();
*/
int main() {
    /*string ImieUzytkownika;
    cout << "Podaj swoje imie:";
    cin >> ImieUzytkownika;
    powitanie(ImieUzytkownika);
    return 0;
    */

    //Zad.2
   /*tabliczkaMnozenia(); 
   */
  //zad3
  int a, b;
  cout << "Podaj wartosc a i b:" << endl;
  cin >> a >> b;
  WyswietlWieksza(a, b);

}


void tabliczkaMnozenia() {
        for (int i=1; i<=10; ++i) {
            for (int j=1; j<=10; ++j) {
                cout << " " << i*j;
            }
            cout << "\n";
        } 
    }
        


    //Zad.3
    

    void WyswietlWieksza(int a, int b) {
        if (a>b) {
            cout << "Wieksza liczba to:" << a << endl;
        }else if (b>a) {
                cout << "Wieksza liczba to:" << b << endl;
            } else {
                cout << "Liczby sa sobie rowne" << endl;
            }
        }
        int ZwrocWieksza(int a, int b) {
            return (a>b) ? a:b;
        }
        