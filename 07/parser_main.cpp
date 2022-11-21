// Datei: parser_main.cpp

#include <iostream>
#include <string>

bool expect(char c, std::string &input, std::size_t pos)
{
    std::cout << "Teste auf das Zeichen " << c << std::endl;
    if ( pos >= input.length() )
    {
        std::cout << "Aber schon am Ende der "
                  << "Eingabe-Zeichenkette angelangt.\n";
        return false;
    }
    if ( input.at(pos) == c )
    {
        std::cout << "Zeichen " << c << " gefunden.\n";
        return true;
    }
    else
    {
        std::cout << "Test auf " << c << " nicht erfolgreich. "
                  << "Stattdessen " << input.at(pos) 
                  << " gesehen." << std::endl;
        return false;
    }
}

void match(char c, std::string &input, std::size_t &pos)
{
    std::cout << "Betrete match() fuer das Zeichen " << c << std::endl;
    if ( pos >= input.length() )
    {
        std::cout << "Error! Input-Zeichenkette zu kurz. "
                  << "Erwarte noch das Zeichen " << c << std::endl
                  << "Verlasse match()" << std::endl;
        return;
    }
    if ( input.at(pos) != c )
    {
        std::cout << "Error! An Position "
                  << pos << " erwarte "
                  << c << " und sehe " << input.at(pos) << std::endl;
        std::cout << "Verlasse match()" << std::endl;
        return;
    }
    pos++;
    std::cout << "Zeichen " << c << " konsumiert.\n"
              << "Verlasse match() fuer das Zeichen " 
              << c << std::endl;
}

// Die Funktions-Prototypen ...
void parse_gesamtausdruck(std::string &input, std::size_t &pos);
void parse_ausdruck(std::string &input, std::size_t &pos);
void parse_term(std::string &input, std::size_t &pos);
void parse_operand(std::string &input, std::size_t &pos);
void parse_number(std::string &input, std::size_t &pos);

/*Damit sieht unsere Grammatik für gültige Gesamtausdrücke wie folgt aus: 
Gesamtausdruck ::= Ausdruck '.' 
Ausdruck ::= Term { ( 'U' | 'O' ) Term } 
Term     ::= Operand { ( '>' | '<' ) Operand } 
Operand  ::= Number 
          |  '(' Ausdruck ')' 
Number   ::= '0'|'1'|'2'|'3'|'4'|'5'|'6'|'7'|'8'|'9'*/



/*Regel: Gesamtausdruck 
Ein Gesamtausdruck besteht aus einem Ausdruck, gefolgt von dem 
Zeichen '.'.  
Gesamtausdruck  ::=  Ausdruck '.'*/
void parse_gesamtausdruck(std::string &input, std::size_t &pos)
{
    std::cout << "Betrete parse_gesamtausdruck()" << std::endl;
    
    // ... (TODO)
    
    parse_ausdruck(input, pos);
    
    match('.',input,pos);
    
    std::cout << "Verlasse parse_gesamtausdruck()" << std::endl;
}

/*Regel: Ausdruck 
Ein Ausdruck besteht aus Termen, die mit dem Zeichen 'U' oder dem 
Zeichen 'O' verknüpft sind. Z.B. 4 > 3 > 2 U 5 > 4 O 2 < 3  
Ausdruck  ::=  Term { ( 'U' | 'O' ) Term } 
*/
void parse_ausdruck(std::string &input, std::size_t &pos)
{
    std::cout << "Betrete parse_ausdruck()" << std::endl;
    
    // ... (TODO)
    //hier muss ein Term sein
    parse_term(input,pos);
    
    while ( expect('U', input, pos) ||
            expect('O', input, pos) )
    {
        if (expect('U', input, pos))
        {
            std::cout << "Betrete parse_ausdruck(): U Fall" << std::endl;
            
            // ... (TODO)
            //hier muss ein Term sein
            match('U', input, pos);
            parse_term(input,pos);
            
            std::cout << "Verlasse parse_ausdruck(): U Fall" 
                 << std::endl;
        }
        else if ( expect('O', input, pos) )
        {
            std::cout << "Betrete parse_ausdruck(): O Fall" << std::endl;
            
            // ... (TODO)
            //hier muss ein Term sein
            match('O', input, pos);
            parse_term(input,pos);
            
            std::cout << "Verlasse parse_ausdruck(): O Fall" 
                      << std::endl;
        }
    }
    std::cout << "Verlasse parse_ausdruck()" << std::endl;
}

/*
Regel: Term 
Ein Term besteht aus Operanden, die mit dem Zeichen '>' oder dem 
Zeichen '<' verknüpft sind.  
Die ( ... ) Klammern im Regelwerk sind nötig, um zu klären, worauf sich 
die „oder“ Operation | des Regelwerks bezieht.  
Die geschweiften Klammern { ... } bedeuten „keine, eine oder mehrere 
Wiederholungen“ dessen, was in den Klammern enthalten ist, also z.B. 
4 > 3 > 2 < 8. 
Term  ::=  Operand { ( '>' | '<' ) Operand }
*/
void parse_term(std::string &input, std::size_t &pos)
{
    std::cout << "Betrete parse_term()" << std::endl;
    
    // ... (TODO)
    parse_operand(input,pos);

    if(expect('<',input,pos)){
        match('<',input,pos);
        parse_term(input,pos);//es muss ein Term oder zumindest ein Ausdruck folgen
    }else if(expect('>',input,pos)){
        match('>',input,pos);
        parse_term(input,pos);//es muss ein Term oder zumindest ein Ausdruck folgen
    }
    
    std::cout << "Verlasse parse_term()" << std::endl;
}

/*Regel: Operand 
Ein Operand besteht entweder aus einer Number, oder er besteht aus dem 
Zeichen ( gefolgt von einem Ausdruck (siehe Regel für Ausdruck weiter unten) 
gefolgt von dem Zeichen ), d.h. der runden schließenden Klammer.  
Operand  ::=  Number 
          |   '('  Ausdruck  ')'*/
void parse_operand(std::string &input, std::size_t &pos)
{
    std::cout << "Betrete parse_operand()" << std::endl;
    
    if ( expect('(', input, pos) )
    {
        std::cout << "Betrete parse_operand(): '(' Fall" << std::endl;
        
        match('(', input, pos);
        parse_ausdruck(input, pos);

        // ... (TODO)
        //klammer wiede zu machen 
        match(')', input, pos);

        std::cout << "Verlasse parse_operand(): '(' Fall" << std::endl;        
    }
    else {
        // ... (TODO)
        //es muss eine Nummer sein
        parse_number(input,pos);
    }
    
    std::cout << "Verlasse parse_operand()" << std::endl;
}

/*Regel: Number 
Eine Number besteht entweder aus der Ziffer '0' oder der Ziffer '1' oder 
... oder der Ziffer '9'. 
Number  ::=  '0'|'1'|'2'|'3'|'4'|'5'|'6'|'7'|'8'|'9' */
void parse_number(std::string &input, std::size_t &pos)
{
    std::cout << "Betrete parse_number()" << std::endl;
    
    // ... (TODO)
    //check ob es eine Nunmer ist
    if(expect('0',input,pos)){
        match('0',input,pos);
    }else if(expect('1',input,pos)){
        match('1',input,pos);
    }else if(expect('2',input,pos)){
        match('2',input,pos);
    }else if(expect('3',input,pos)){
        match('3',input,pos);
    }else if(expect('4',input,pos)){
        match('4',input,pos);
    }else if(expect('5',input,pos)){
        match('5',input,pos);
    }else if(expect('6',input,pos)){
        match('6',input,pos);
    }else if(expect('7',input,pos)){
        match('7',input,pos);
    }else if(expect('8',input,pos)){
        match('8',input,pos);
    }else if(expect('9',input,pos)){
        match('9',input,pos);
    }else{
        std::cout<<"Error! number an position "<<pos<<" erwartet"<<std::endl;
    }
         
    std::cout << "Verlasse parse_number()" << std::endl;
}

int main()
{    
    std::size_t pos = 0;

    std::cout << "Bitte geben Sie die Zeichenkette ein: " ;
    
    // Nur eine der folgenden Zeilen auskommentieren ...
    // Letzte Zeile: mit Benutzereingabe (für eigene Testläufe)
    // Zeilen davor: spezifische Testläufe (Eintippen nicht nötig)
    //
    //std::string input = "(3U4U7)>(5U2)."; // syntaktisch korrekt
    //std::string input = "(4>3)U2<7."; // syntaktisch korrekt
    //std::string input = "(4>3)U2<7"; // syntaktisch inkorrekt: finaler Punkt fehlt
    std::string input = "(9>1)U2<"; // syntaktisch inkorrekt
    //std::string input; std::getline(std::cin, input);

    parse_gesamtausdruck(input, pos);

    if ( pos != input.length() ) {
        std::cout << "Error! Noch Input-Zeichen uebrig.\n";
    }

    return 0;
}
