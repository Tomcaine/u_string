#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>
#include "../inc/datenSatzVerwaltung.h"
#include "../inc/personalM.h"

using namespace std;

bool weiter();
#define BUCHSTABEN_ZEICHEN_MUSTER "[A-Za-z!@#$%^&*()_+{}|:<>?\\-\\[\\]]"
int main() {
    vector<personalDaten> datenBank;
    while (weiter()){
        personalDaten neuerEintrag;
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

bool weiter(){
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