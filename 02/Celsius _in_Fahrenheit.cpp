#include <iostream>

using namespace std;

int main() {
    double temperaturCelsius;
    cout<<"Bitte geben Sie die Temperatur in Grad Celsius ein: ";
    cin >> temperaturCelsius;
    cout<<"Die Temperatur in Fahrenheit lautet: "<<(temperaturCelsius*1.8+32)<<endl;

    return 0;
}
