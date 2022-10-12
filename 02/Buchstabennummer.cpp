#include <iostream>
using namespace std;

int main(){

    cout<<"Bitte geben Sie den Buchstaben ein: ";
    char eingabe;
    cin>>eingabe;
    int nummer = (int)eingabe;
    cout<<"Der Buchstabe "<<eingabe<<" hat die Position "<<(nummer-(int)'a'+1)<<" im Alphabet."<<endl;
    return 0;
}