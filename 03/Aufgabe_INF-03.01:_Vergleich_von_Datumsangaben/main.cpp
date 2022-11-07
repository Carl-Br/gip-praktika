#include <iostream>
using namespace std;

int main()
{
    int tagEins;
    int tagZwei;
    
    int monatEins;
    int monatZwei;

    int jahrEins;
    int jahrZwei;


    //Datum 1
    cout<<"Bitte geben Sie den Tag des ersten Datums ein: ";
    cin>>tagEins;

    cout<<"Bitte geben Sie den Monat des ersten Datums ein: ";
    cin>>monatEins;

    cout<<"Bitte geben Sie das Jahr des ersten Datums ein: ";
    cin>>jahrEins;

     //Datum 2
    cout<<"Bitte geben Sie den Tag des zweiten Datums ein: ";
    cin>>tagZwei;

    cout<<"Bitte geben Sie den Monat des zweiten Datums ein: ";
    cin>>monatZwei;

    cout<<"Bitte geben Sie das Jahr des zweiten Datums ein: ";
    cin>>jahrZwei;

    if(jahrEins>jahrZwei)
    {
        cout<<"Das zweite Datum liegt vor dem ersten Datum.\n";
        return 0;
    }
    else if (jahrEins<jahrZwei){
        cout<<"Das erste Datum liegt vor dem zweiten Datum.\n";
        return 0;
    }

    //ab hier muss das Jahr gleich sein

    if(monatEins>monatZwei)
    {
        cout<<"Das zweite Datum liegt vor dem ersten Datum.\n";
        return 0;
    }
    else if (monatEins<monatZwei){
        cout<<"Das erste Datum liegt vor dem zweiten Datum.\n";
        return 0;
    }

    //ab hier ist auch noch der  Monat gleich

    if(tagEins>tagZwei)
    {
        cout<<"Das zweite Datum liegt vor dem ersten Datum.\n";
        return 0;
    }
    else if (tagEins<tagZwei){
        cout<<"Das erste Datum liegt vor dem zweiten Datum.\n";
        return 0;
    }

    // ab hier ist alles gleich

    cout<<"Beide Datumsangaben sind gleich."<<endl;

    return 0;
}
