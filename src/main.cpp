#include "datenSatzVerwaltung.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool weiter();

#define BUCHSTABEN_ZEICHEN_MUSTER "[A-Za-z!@#$%^&*()_+{}|:<>?\\-\\[\\]]"

int main() {
    vector<PersonalDaten> datenBank;
    while (weiter()) {
        PersonalDaten neuerEintrag;
        cout << "------ Neuer Eintrag ------" << endl;
        neuerEintrag.name = eingabeString("Name");
        neuerEintrag.vorname = eingabeString("Vorname");
        neuerEintrag.pNummer = eingabeInt("Personalnummer");
        neuerEintrag.gehalt = eingabeFloat("Gehalt");
        neuerEintrag.geburtsDatum = eingabeDatum("Geburtstag");
        datenBank.push_back(neuerEintrag);
    }
    ausgabeTabelle(datenBank);
    cout << "Ende" << endl;
    return 0;
}

bool weiter() {
    string sInput;
    cout << "Datensatz eingeben (J/N): " << endl;
    cout << "> ";
    getline(cin, sInput);
    if (sInput != "N" and sInput != "J") {
        return true;
    } else if (sInput == "J") {
        return true;
    } else {
        return false;
    }
}