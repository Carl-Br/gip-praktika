#include <iostream>
#include <fstream>

#include "main.h"


using namespace std;

int main(){

    string kurzeliste="",langeliste="";
    //lese datei
    string personString;

    fstream personendatenDatei("personendaten.txt",ios::in);
    while(true){

        personString = "";
        getline(personendatenDatei,personString);
        Person p = extrahiere_person(personString);

        //break wenn durchgelaufen
        if(bool(personendatenDatei.eof())){
            break;
        }
        
        kurzeliste+=("<b>"+p.nachname+"</b>, "+p.vorname+"</br>");
        langeliste+=("<b>"+p.vorname+" "+p.nachname+"</b>, "+p.geburtsdatum+"</br>");

    }
    personendatenDatei.close();

    //lese html datei aus
    string html ="";
    string htmlline;
    fstream webseitehtmltemp("webseitehtmltmpl.sec",ios::in);
    while(true){

        htmlline="";
        getline(webseitehtmltemp,htmlline);
        html+=htmlline;
        if(bool(webseitehtmltemp.eof())){
            break;
        }
    }

    webseitehtmltemp.close();

    //ersetzen
    string neuesHtml="";
    for(int i = 0; i<html.length();i++){
        if(html.at(i)=='%'){
            neuesHtml+=kurzeliste;
        }else if(html.at(i)=='$'){
            neuesHtml+=langeliste;
        }else{
            //ansonsten füge einfach das jetzige Zeichen hinzu
            neuesHtml+=html.at(i);
        }
    }
    cout<<neuesHtml<<endl;
    // in file schreiben
    fstream webseite("webseite.html",ios::out);
    webseite<<neuesHtml;
    webseite.close();
}


Person extrahiere_person(string eingabezeile){
    struct Person p = {"","",""};
    int variable = 0; //0: Nachname, 1: Vorname, 2: geburtsdatum
    for(int i = 0;i<eingabezeile.length();i++){

        if(eingabezeile.at(i)==','){
            i++;//überspringe leerzeichen
            variable++;
            continue;
        }

        else if(variable==0){
            //Nachname
            p.nachname+=eingabezeile.at(i);
        }
        else if(variable==1){
            //Vorname
            p.vorname+=eingabezeile.at(i);
        }else if(variable==2){
            //Geburtsdatum
            p.geburtsdatum+=eingabezeile.at(i);
        }

    }
    return p;
}
