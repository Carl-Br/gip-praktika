#include <iostream>
using namespace std;

int main(){

    //zahl eingabe
    cout<<"Ihre Eingabe: ";
    double userZahl;
    cin>>userZahl;

    //wahl der umrechnung
    cout
    <<"\nIhre Auswahl der Umwandlung:\n"
    <<"1 - Celsius in Fahrenheit\n"
    <<"2 - Meter in Fuss\n"
    <<"3 - Euro in US Dollar\n";

    double auswahl;
    cin>>auswahl;


    double ausgabe =
     (userZahl*1.8+32)  *(            (2-auswahl)*(3-auswahl)*0.5) //(2-auswahl)*(3-ausgabe)) sind (bei auswahl 1) = 2. Um das wieder auf 1 zu bringen, müssen wir es mit 0.5 multiplizieren.
    +(userZahl* 3.2808) *((1-auswahl)            *(3-auswahl)*(-1))//(1-auswahl)*(3-auswahl) sind (bei auswahl 2) = -1. Um das wieder auf 1 zu bringen, müssen wir es mit -1 multiplizieren.
    +(userZahl*1.2957)  *((1-auswahl)*(2-auswahl)            *0.5)//(1-auswahl)*(2-auswahl) sind (bei auswahl 3) = 2. Um das wieder auf 1 zu bringen, müssen wir es mit 0.5 multiplizieren.
    ;

    cout<<"\nDas Ergebnis lautet: "<<ausgabe<<"\n\n";
    return 0;
}