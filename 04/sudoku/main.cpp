#include <iostream>
#include <string>
using namespace std;


int main(){


    string eingabe[11];

    //sudoku eingabe
    cout<<"\n\nBitte geben Sie das Sudoku ein:\n"<<endl;
    for(int i =0;i<11;i++){
        cin>>eingabe[i];
    }

    //sudoku einscannen
    int sudoku[9][9] = {0};
    int zahlencodeStart = (int)'1';
    int zahlencodeEnde = (int)'9';
    char buchstabe;


    int anzahl_Sortierter_Zahlen_Der_Reihe; //gibt an, wie viele Zahlen aus der ... Reihe bereits eingescannt wurden.
    int anzahl_Sortierter_Reihen = 0;

    //geht jede Zeile des Sudokus durch (auch die, die nur aus Strichen besteht)
    for(int i = 0;i<11;i++){

        if(i==3 || i==7){
            //wenn so ein querstrich in der Mitte ist
            continue;
        }


        anzahl_Sortierter_Zahlen_Der_Reihe=0;

        for(int j = 0;j<eingabe[i].length();j++){
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

    //sudoku ausgabe
    
    cout<<"\n\nDas Sudoku lautet:\n"<<endl;

    int sudokureihe = 0;
    for(int i = 0;i<11;i++){
        if(i==3 || i==7)
        {
            cout<<"=======//=======//======="<<endl;
            continue;
        }

        cout<<";"
        <<sudoku[sudokureihe][0]
        <<";"
        <<sudoku[sudokureihe][1]
        <<";"
        <<sudoku[sudokureihe][2]
        <<";"

        <<"//"

        <<";"
        <<sudoku[sudokureihe][3]
        <<";"
        <<sudoku[sudokureihe][4]
        <<";"
        <<sudoku[sudokureihe][5]
        <<";"

        <<"//"

        <<";"
        <<sudoku[sudokureihe][6]
        <<";"
        <<sudoku[sudokureihe][7]
        <<";"
        <<sudoku[sudokureihe][8]
        <<endl;


        sudokureihe++;
    }

    return 0;
}
