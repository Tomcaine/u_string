#include <iostream>
#include "../inc/datenSatzVerwaltung.h"

using namespace std;

int main() {
    bool test = false;
    char cInput;
    do {
        cout << "Datensatz eingeben (J/N): ";
        cin >> cInput;
        if (cInput != 'N' and cInput != 'J') {
            test = true;
        } else if (cInput == 'J') {
            datenEingabe();
            test = true;
        } else {
            datenAusgabe();
            test = false;
        }
    } while (test);
    cout << "Ende" << endl;
    return 0;
}
