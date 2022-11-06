// Datei: suchen_rekursiv_main.cpp

#define CATCH_CONFIG_RUNNER
#include "catch.h"

#include <iostream>
#include <string>

using namespace std;

#include "suchen_rekursiv.h"

int main()
{
    Catch::Session().run();
	
    // Ihr Code ab hier ...
    cout<<"Bitte geben Sie den Text ein: ";
    string text;
    getline(cin,text);

    cout<<"Bitte geben Sie die zu suchende Zeichenkette ein: ";
    string zkette;
    getline(cin,zkette);

    int rueckgabe = zeichenkette_suchen_rekursiv(text,zkette);//alle anderen Werte sind default 0

    if(rueckgabe==-1){
        cout<<"Die Zeichenkette '"<<zkette<<"' ist NICHT in dem Text '"<<text<<"' enthalten."<<endl;
    }else{
        cout<<"Die Zeichenkette '"<<zkette<<"' ist NICHT in dem Text '"<<text<<"' enthalten."<<endl
        <<"Sie startet ab Zeichen "<<rueckgabe<<" (bei Zaehlung ab 0)."<<endl;
    }

    return 0;
}