#include <iostream>
using namespace std;

int main()
{
    int maxWert;
    int maxPos;

    int minWert;
    int minPos;

    cout<<"Bitte geben Sie die 1. Zahl ein: ? ";
    int ersteingabe;
    cin>>ersteingabe;

    maxWert = ersteingabe;
    minWert = ersteingabe;

    maxPos=1;
    minPos=1;


    int eingabe;

    for(int i = 0; i<4;i++){
        cout<<"Bitte geben Sie die "<<(i+2)<<". Zahl ein: ? ";
        cin>>eingabe;
        if(eingabe > maxWert){
            maxWert = eingabe;
            maxPos = i+2;
        }else if(eingabe < minWert){
            minWert = eingabe;
            minPos=i+2;
        }
    }

    cout<<"Die "<<minPos<<". Zahl war die kleinste der eingegebenen Zahlen und lautet: "<<minWert<<endl;
    cout<<"Die "<<maxPos<<". Zahl war die groesste der eingegebenen Zahlen und lautet: "<<maxWert<<endl;
    return 0;
}