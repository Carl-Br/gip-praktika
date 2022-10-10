#include <iostream>
using namespace std;

int main(){

    cout<<"Bitte geben Sie den Buchstaben ein: ";
    char eingabe;
    cin>>eingabe;
    int nummer = (int)eingabe;
    cout<<"Der Buchstabe a hat die Position "<<nummer-96<<" im Alphabet."<<endl;
    return 0;
}