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

    while (weiter()){
        cout << "------ Neuer Eintrag ------" << endl;
    }
    //cout << "Ende" << endl;
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