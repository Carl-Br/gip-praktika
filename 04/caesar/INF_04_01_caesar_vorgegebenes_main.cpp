#include <iostream>
#include <string>
using namespace std;

// Hier die von Ihnen programmierte Funktion einfügen ...
string caesar(string original_text, unsigned int v)
{

    //kürze auf die richtige Nummer
    v = v % 26;

    int neuer_BuchstabeInt;
    string caesarText ="";

    //gehe jeden char im Originaltext durch
    for(int i =0;i<original_text.length();i++)
    {
        char original_buchstabe = original_text.at(i);
        //wenn Kleinbuchstabe
        if(int(original_buchstabe)>=97 & int(original_buchstabe)<=122){

            neuer_BuchstabeInt = ((int)original_buchstabe)+v;
            //wenn die Verschiebung aus den Kleinbuchstaben raus geht
            if(122<neuer_BuchstabeInt){
                //ziehe das Aplhabet einmal ab
                neuer_BuchstabeInt -=26;
            }
            
        }else if (int(original_buchstabe)>=65 & int(original_buchstabe)<=90)
        {
            neuer_BuchstabeInt = ((int)original_buchstabe)+v;
            //wenn die Verschiebung aus den Großbuchstaben raus geht
            if(90<neuer_BuchstabeInt){
                //ziehe das Aplhabet einmal ab
                neuer_BuchstabeInt -=26;
            }
        }
        else{
            neuer_BuchstabeInt = original_buchstabe;
        }

        //fügt den neuen Buchstaben zum ceasar Wort hinzu
        caesarText += char(neuer_BuchstabeInt);
        
    }
    

    return caesarText;
}

bool assert_equal(string original_text, unsigned int v, string erwarteter_verschluesselter_text)
{
    string berechneter_verschluesselter_text = caesar(original_text, v);

    if (berechneter_verschluesselter_text != erwarteter_verschluesselter_text)
    {
        cout << "Verschluesselungs-Test fehlgeschlagen (test case failed)!\n  Erwartet:  "
             << erwarteter_verschluesselter_text << endl
             << "  Berechnet: "
             << berechneter_verschluesselter_text << endl
             << "  Originaltext: " << original_text << endl
             << "  Anzahl Verschiebepositionen: " << v << endl;
        return false;
    }
    else
    {
        cout << "Verschluesselungs-Test erfolgreich (test case passed)! "
             << original_text
             << "  ==(" << v << ")==>  "
             << berechneter_verschluesselter_text << endl;
        return true;
    }
}

bool do_testcases()
{
    bool test_resultat = true;
    test_resultat = assert_equal("abc", 2, "cde") && test_resultat;
    test_resultat = assert_equal("ABC", 2, "CDE") && test_resultat;
    test_resultat = assert_equal("abc.,!?", 4, "efg.,!?") && test_resultat;
    test_resultat = assert_equal("apz", 2, "crb") && test_resultat;
    test_resultat = assert_equal("xYz. ABC", 5, "cDe. FGH") && test_resultat;
    test_resultat = assert_equal("., !?", 4, "., !?") && test_resultat;
    test_resultat = assert_equal("abcXYZ!", 0, "abcXYZ!") && test_resultat;
    test_resultat = assert_equal("", 7, "") && test_resultat;
    test_resultat = assert_equal("aBxYz!", 26, "aBxYz!") && test_resultat;
    test_resultat = assert_equal("aB!", 28, "cD!") && test_resultat;
    test_resultat = assert_equal("aBxYz!", 52, "aBxYz!") && test_resultat;
    test_resultat = assert_equal("aBxYz!", 78, "aBxYz!") && test_resultat;
    test_resultat = assert_equal("aBxYz!", 99, "vWsTu!") && test_resultat;
    test_resultat = assert_equal("abc def xyz!ABC XYZ?", 3, "def ghi abc!DEF ABC?") && test_resultat;
    test_resultat = assert_equal("Abc Zyx!", 55, "Def Cba!") && test_resultat;
    return test_resultat;
}

int main()
{
    if (do_testcases())
    {
        string text = "";
        unsigned int v = 0;
        cout << "Bitte geben Sie den zu verschluesselnden Text ein: ? ";
        getline(cin, text);
        cout << "Bitte geben Sie die Anzahl Verschiebepositionen "
             << "ein (als positive ganze Zahl): ? ";
        cin >> v;

        cout << "Verschluesselt: " << caesar(text, v) << endl;
    }

    return 0;
}
