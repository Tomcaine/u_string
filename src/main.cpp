#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>
#include "../inc/datenSatzVerwaltung.h"
#include "../inc/personalM.h"

using namespace std;

bool weiter();

int main() {
    vector<personalDaten> datenBank;
    bool loop = false;
    string sInput;
    do {
        cout << "Datensatz eingeben (J/N): ";
        getline(cin, sInput);
        if (sInput != "N" and sInput != "J") {
            loop = true;
        } else if (sInput == "J") {
            datenEingabe(datenBank);
            loop = true;
        } else {
            datenAusgabe(datenBank);
            loop = false;
        }
    } while (loop);
    //cout << "Ende" << endl;
    return 0;
}

bool weiter(){
    cout << "Datensatz eingeben (J/N): ";
    cout << "> ";
}