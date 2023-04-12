//
// Created by azubi on 11.04.2023.
//
#include "../inc/datenSatzVerwaltung.h"

#define ZAHL_ZEICHEN_MUSTER "[0-9!@#$%^&*()_+{}|:<>?\\[\\]]"
#define BUCHSTABEN_ZEICHEN_MUSTER "[A-Za-z!@#$%^&*()_+{}|:<>?\\-\\[\\]]"
#define DATUMS_MUSTER "[0-9]{2}\\.[0-9]{2}\\.[0-9]{4}"
#define FLOAT_MUSTER ".*[.,].{2}"

using namespace std;

istringstream temp;

bool datumPruefung(string datum){
    uint16_t monate[13] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int tag{};
    int monat{};
    int jahr{};
    istringstream temp;

    temp.str(datum.substr(0, 2));
    temp >> tag;
    temp.clear();

    temp.str(datum.substr(3, 2));
    temp >> monat;
    temp.clear();

    temp.str(datum.substr(6, 4));
    temp >> jahr;
    temp.clear();

    if (monat > 0 && monat <= 12){
        if ((jahr % 4 == 0
             && jahr % 100 != 0)
            || jahr % 400 == 0){
            monate[2]++;
        }
        if (tag > 0 && tag <= monate[monat]){
            return true;
        }
    }
    return false;
}

string eingabeString(const std::string& text){
    cout << text << endl;
    cout << "> ";

    string eingabe;
    bool loop = false;
    regex muster(ZAHL_ZEICHEN_MUSTER);
    do{
        loop = false;
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

int eingabeInt(const std::string& text){
    cout << text << endl;
    cout << "> ";

    string eingabe;
    bool loop = false;
    int returnValue{};

    string tempMuster = BUCHSTABEN_ZEICHEN_MUSTER;
    tempMuster.replace(tempMuster.length() - 1, 1, ".,]");
    regex muster(tempMuster);
    do{
        loop = false;
        getline(cin, eingabe);
        if (eingabe.empty()){
            loop = true;
            cout << "Feld darf nicht leer sein." << endl;
            cout << "> ";
        } else if (regex_search(eingabe, muster)){
            loop = true;
            cout << "Feld darf keine Buchstaben oder sonderzeichen enthalten." << endl;
            cout << "> ";
        }
    } while (loop);
    temp.str(eingabe);
    temp >> returnValue;
    temp.clear();
    return returnValue;
}

int eingabeFlaot(const std::string& text){
    cout << text << endl;
    cout << "> ";

    string eingabe;
    bool loop = false;
    int returnValue{};

    regex muster(BUCHSTABEN_ZEICHEN_MUSTER);
    regex flaotMuster(FLOAT_MUSTER);
    do{
        loop = false;
        getline(cin, eingabe);
        if (eingabe.empty()){
            loop = true;
            cout << "Feld darf nicht leer sein." << endl;
            cout << "> ";
        } else if (regex_search(eingabe, muster)){
            loop = true;
            cout << "Feld darf keine Buchstaben oder sonderzeichen enthalten." << endl;
            cout << "> ";
        } else if (!regex_search(eingabe, flaotMuster)){
            loop = true;
            cout << "Falsches Formart (0000.00)" << endl;
            cout << "> ";
        }
    } while (loop);
    if (eingabe.find(',') == string::npos){
        eingabe.replace(eingabe.find('.'), 1, "");
    } else{
        eingabe.replace(eingabe.find(','), 1, "");
    }
    temp.str(eingabe);
    temp >> returnValue;
    temp.clear();
    return returnValue;
}

std::string datumVerarbeitung(const std::string& text){
    cout << text << endl;
    cout << "> ";
    string eingabe;
    bool loop = false;
    regex muster(BUCHSTABEN_ZEICHEN_MUSTER);
    regex datumMuster(DATUMS_MUSTER);
    do{
        loop = false;
        getline(cin, eingabe);
        if (eingabe.empty()){
            loop = true;
            cout << "Feld darf nicht leer sein." << endl;
            cout << "> ";
        } else if (regex_search(eingabe, muster)){
            loop = true;
            cout << "Feld darf keine Buchstaben oder sonderzeichen enthalten." << endl;
            cout << "> ";
        } else if (!regex_match(eingabe, datumMuster)){
            loop = true;
            cout << "Datumsformat falsch (TT.MM.JJJJ)." << endl;
            cout << "> ";
        } else if (!datumPruefung(eingabe)){
            loop = true;
            cout << "Datum existiert nicht." << endl;
            cout << "> ";
        }
    } while (loop);
    return eingabe;
}

extern void ausgabeTabelle(const std::vector<personalDaten>&){

}

extern void ausgabe(const personalDaten&){

}














/*
extern void datenEingabe(vector<personalDaten>& datenBank){
    personalDaten mitarbeiterDaten;
    cout << "------ Neuer Eintrag ------" << endl;
    cout << "Name:" << endl;
    cout << "> ";
    mitarbeiterDaten.name = stringVerarbeitung();
    cout << "Vorname:" << endl;
    cout << "> ";
    mitarbeiterDaten.vorname = stringVerarbeitung();
    cout << "Personalnummer:" << endl;
    cout << "> ";
    mitarbeiterDaten.pNummer = intVerarbeitung();
    cout << "Gehalt:" << endl;
    cout << "> ";
    mitarbeiterDaten.gehalt = intVerarbeitung();
    cout << "Geburtstag:" << endl;
    cout << "> ";
    mitarbeiterDaten.geburtsDatum = datumVerarbeitung();
    datenBank.push_back(mitarbeiterDaten);
}
extern void datenAusgabe(vector<personalDaten>& datenBank){
    if (!datenBank.empty()) {
        cout << "Name             Vorname          Personalnummer        Gehalt    Geburtstag" << endl;
        string temp;
        for (const array<string, 5> &person: datenBank) {
            for (int i{}; i < 5; i++) {
                temp = person.at(i);
                switch (i) {
                    case 0:
                    case 1:
                        if (temp.length() > 15) {
                            for (int x{}; x < 15; x++) {
                                cout << temp.at(x);
                            }
                            cout << ". ";
                        } else if (temp.length() < 15) {
                            cout << temp;
                            for (int z{}; z < 15 - temp.length(); z++) {
                                cout << " ";
                            }
                            cout << "  ";
                        } else {
                            cout << temp;
                            cout << "  ";
                        }
                        break;
                    default:
                        cout << setfill(' ');
                        cout << setw(14) << temp;
                }
            }
            cout << endl;
        }
    }
}
 */