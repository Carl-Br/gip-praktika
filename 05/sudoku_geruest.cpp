#include <iostream>
#include <string>
using namespace std;

const int sudoku_groesse = 9;
const int eingabe_groesse = 11;

bool pruefe_zeilen(int sudoku[][sudoku_groesse])
{   
    bool allesHatFunktioniert = true;
    bool zahlIstInReihe;
    //vergleich Indexe : 0 mit 1, 0 mit 2, 0 mit 3,..

    //für jede Reihe
    for(int k = 0;k<sudoku_groesse;k++){

        //jede Zahl in der Reihe
        for(int i = 0;i<sudoku_groesse;i++){

            //vergleiche mit allen anderen weiter "vorne" liegenden Zahlen
            for(int j =i+1;j<sudoku_groesse;j++){


                if((sudoku[k][i])==(sudoku[k][j]))
                {
                    cout<<"Zeile "<<k<<": Zahl "<<sudoku[k][i]<<" kommt mehrfach vor."<<endl;
                    allesHatFunktioniert=false;
                }

            }

            //immernoch für jede Zahl in der Reihe

            //wenn die Zahl i in der Sudoku Reihe ist.
            zahlIstInReihe = false;
            for(int j = 0;j<sudoku_groesse;j++){
                if(i+1==sudoku[k][j]){
                    // die Zahl i ist in der Reihe k
                    zahlIstInReihe = 1;
                }
            }
            if(!zahlIstInReihe){
                cout<<"Zeile "<<k<<": Zahl "<<i+1<<" kommt nicht vor."<<endl;
                allesHatFunktioniert=false;
            }
        }
    }

    return allesHatFunktioniert;
}

//quasi das selbe nur, dass i und j mit k vertauscht werden
bool pruefe_spalten(int sudoku[][sudoku_groesse])
{
    bool allesHatFunktioniert = true;
    bool zahlIstInZeile;
    //für jede Zeile
    for(int k = 0;k<sudoku_groesse;k++){

        //jede Zahl in der Zeile
        for(int i = 0;i<sudoku_groesse;i++){

            //vergleiche mit allen anderen weiter "vorne" liegenden Zahlen
            for(int j =i+1;j<sudoku_groesse;j++){


                if((sudoku[i][k])==(sudoku[j][k]))
                {
                    cout<<"Spalte "<<k<<": Zahl "<<sudoku[i][k]<<" kommt mehrfach vor."<<endl;
                    allesHatFunktioniert=false;
                }

            }

            //immernoch für jede Zahl in der Spalte
            //wenn die Zahl i in der Sudoku Reihe ist.
            zahlIstInZeile = false;
            for(int j = 0;j<sudoku_groesse;j++){
                if(i+1==sudoku[j][k]){
                    // die Zahl i ist in der Reihe k
                    zahlIstInZeile = true;
                }
            }
            if(!zahlIstInZeile){
                cout<<"Spalte "<<k<<": Zahl "<<i+1<<" kommt nicht vor."<<endl;
                allesHatFunktioniert=false;
            }
        }
    }
    return allesHatFunktioniert;
}

bool pruefe_bloecke(int sudoku[][sudoku_groesse])
{
    bool allesHatFunktioniert = true;
    int spalte;
    int zeile;
    int folgendeSpalte;
    int folgendeZeile;


    for(int block = 0;block < sudoku_groesse;block++){
        for(int i = 0;i<3;i++){//zeile
            for(int j = 0;j<3;j++){//spalte



                //für jede Zahl in dem Block
                zeile = block/3*3+i;// Ursprungszeile von dem Block + die jetzige Zeile im Block
                spalte = block%3*3+j;// "

                bool spalteGesetzt = false;
                for(int k = i;k<3;k++){//zeile
                    for(int p = 0;p<3;p++){//spalte

                        if(k==i && spalteGesetzt==false){
                            /* 
                            Wenn die zu vergleichende Zahl in der selben
                            Zeile wie die original Zahl ist,
                            und dieser Codeblock HIER noch nicht aufgerufen wurde.
                            Also wenn die erste zu vergleichende Zahl gesucht wird.
                            */
                            p=j;
                            /*setzte die Spalte auf die Spalte von der Originalspalte und
                            danach kommt ein continue um p noch einmal zu erhöhen, damit die Zahl nicht mit sich selber verglichen wird
                            und um zzu überprüfen, ob p+1 immernoch kleiner als 3 ist.*/
                            spalteGesetzt=true;
                            continue;
                        }

                        //für jede darauf folgende Zahl in dem Block
                        folgendeZeile = block/3*3+k;
                        folgendeSpalte = block%3*3+p;

                        if(sudoku[zeile][spalte]==sudoku[folgendeZeile][folgendeSpalte]){
                            cout<<"Block "<<block<<": Zahl "<<sudoku[zeile][spalte]<<" kommt mehrfach vor."<<endl;
                            allesHatFunktioniert=false;
                        }
                    }

                }
                
            }
        }
    
        for(int i = 1;i<=sudoku_groesse;i++){//9 mal
            bool zahlIstImBlock = false;

            for(int k = 0;k<3;k++){//zeile
                for(int j = 0;j<3;j++){//spalte

                    //für jede Zahl in dem Block
                    zeile = block/3*3+k;
                    spalte = block%3*3+j;

                    if(sudoku[zeile][spalte]==i){
                        zahlIstImBlock=true;
                    }
                }
            }
            if(!zahlIstImBlock){
                cout<<"Block "<<block<<": Zahl "<<i<<" kommt nicht vor."<<endl;
                allesHatFunktioniert = false;
            }

        }
    }
    return allesHatFunktioniert;

}

void konvertiere(string eingabe[], int sudoku[][sudoku_groesse])
{
    int zahlencodeStart = (int)'1';
    int zahlencodeEnde = (int)'9';
    char buchstabe;


    int anzahl_Sortierter_Zahlen_Der_Reihe; //gibt an, wie viele Zahlen aus der ... Reihe bereits eingescannt wurden.
    int anzahl_Sortierter_Reihen = 0;

    //geht jede Zeile des Sudokus durch (auch die, die nur aus Strichen besteht)
    for(int i = 0;i<11;i++)
    {

        if(i==3 || i==7)
        {
            //wenn so ein querstrich in der Mitte ist
            continue;
        }


        anzahl_Sortierter_Zahlen_Der_Reihe=0;

        for(int j = 0;j<eingabe[i].length();j++)
        {
            buchstabe = eingabe[i].at(j);

            //wenn der Buchstabe eine Ziffer (ausgenommen 0 ist)
            if( ((int)buchstabe >= zahlencodeStart) & ((int)buchstabe <= zahlencodeEnde))
            {
                //sortiere die Ziffer ein
                sudoku[anzahl_Sortierter_Reihen][anzahl_Sortierter_Zahlen_Der_Reihe] = (((int)buchstabe) - zahlencodeStart+1);

                anzahl_Sortierter_Zahlen_Der_Reihe++;

            }
        }
        anzahl_Sortierter_Reihen++;
    }

}

int main() 
{

    int sudoku[sudoku_groesse][sudoku_groesse] = { 0 };
    string eingabe[eingabe_groesse];

    cout << "Bitte geben Sie das Sudoku ein:" << endl;
    for (int i = 0; i < eingabe_groesse; i++)
        getline(cin, eingabe[i]);

    konvertiere(eingabe, sudoku);

    
    cout<<"\n";
    bool ps = pruefe_spalten(sudoku);
    cout<<"\n";
    bool pz = pruefe_zeilen(sudoku);
    cout<<"\n";
    bool pb = pruefe_bloecke(sudoku); 
    cout<<"\n";

    if (ps && pz && pb)
        cout << "Das Sudoku ist gueltig." << endl;

    return 0;
}



