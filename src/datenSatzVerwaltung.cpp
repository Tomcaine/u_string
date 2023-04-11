//
// Created by azubi on 11.04.2023.
//
#include "../inc/datenSatzVerwaltung.h"
#include <regex>

using namespace std;
string stringVerarbeitung(){
    string eingabe;
    bool loop = false;
    regex muster("[0-9!@#$%^&*()_+{}|:<>?\\[\\]]");
    do{
        getline(cin, eingabe);
        if (eingabe.empty()){
            loop = true;
            cout << "Feld darf nicht leer sein." << endl;
            cout << "> ";
        } else if (regex_search(eingabe, muster)){
            loop = true;
            cout << "Feld darf keine Zahlen oder sonderzeichen enthalten." << endl;
            cout << "> ";
        }
    } while (loop);
    return eingabe;
}
string intVerarbeitung(){
    string eingabe;
    getline(cin, eingabe);
}
string datumVerarbeitung(){
    string eingabe;
    getline(cin, eingabe);
}
extern void datenEingabe(vector<array<string, 5>>& datenBank){
    array<string, 5> mitarbeiterDaten;
    cout << "------ Neuer Eintrag ------" << endl;
    cout << "Name: ";
    mitarbeiterDaten.at(0) = stringVerarbeitung();
    cout << "Vorname: ";
    mitarbeiterDaten.at(1) = stringVerarbeitung();
    cout << "Personalnummer: ";

    cout << "Gehalt: ";

    cout << "Geburtstag: ";

    datenBank.push_back(mitarbeiterDaten);
}
extern void datenAusgabe(vector<array<string, 5>>& datenBank){
    cout << "Daten Ausgabe" << endl;
}