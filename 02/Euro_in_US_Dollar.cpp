#include <iostream>
using namespace std;

int main(){

    double euro;
    cout<<"Bitte geben Sie die Geldmenge in Euro ein: ";
    cin>>euro;
    cout<<"Die Geldmenge in US Dollar lautet: "<<(euro*1.2957)<<endl;
    return 0;
}