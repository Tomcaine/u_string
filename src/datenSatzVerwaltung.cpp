//
// Created by azubi on 11.04.2023.
//
#include "../inc/datenSatzVerwaltung.h"

#define ZAHL_ZEICHEN_MUSTER "[0-9!@#$%^&*()_+{}|:<>?\\[\\]]"
#define BUCHSTABEN_ZEICHEN_MUSTER "[A-Za-z!@#$%^&*()_+{}|:<>?\\-\\[\\]]"
#define DATUMS_MUSTER "[0-9]{2}\\.[0-9]{2}\\.[0-9]{4}"
#define FLOAT_MUSTER ".*[.,].{2}"

void writePrompt();

void write(std::string const& s);

using namespace std;

bool datumPruefung(const string& datum) {
    uint16_t monate[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
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

    if (monat > 0 && monat <= 12) {
        if ((jahr % 4 == 0 && jahr % 100 != 0) || jahr % 400 == 0) {
            monate[2]++;
        }
        if (tag > 0 && tag <= monate[monat]) {
            return true;
        }
    }
    return false;
}

string eingabeString(const std::string &text) {
    write(text);
    writePrompt();

    string eingabe;
    regex muster(ZAHL_ZEICHEN_MUSTER);
    while (true) {
        getline(cin, eingabe);
        if (eingabe.empty()) {
            write("Feld darf nicht leer sein.");
            writePrompt();
        } else if (regex_search(eingabe, muster)) {
            write("Feld darf keine Zahlen oder Sonderzeichen enthalten.");
            writePrompt();
        } else {
            break;
        }
    }
    return eingabe;
}

void write(std::string const& s) { cout << s << endl; }

void writePrompt() { cout << "> "; }

int eingabeInt(const std::string &text) {
    write(text);
    writePrompt();

    string eingabe;
    istringstream temp;
    bool loop;
    int returnValue{};

    string tempMuster = BUCHSTABEN_ZEICHEN_MUSTER;
    tempMuster.replace(tempMuster.length() - 1, 1, ".,]");
    regex muster(tempMuster);
    do {
        loop = false;
        getline(cin, eingabe);
        if (eingabe.empty()) {
            loop = true;
            write("Feld darf nicht leer sein.");
            writePrompt();
        } else if (regex_search(eingabe, muster)) {
            loop = true;
            write("Feld darf keine Buchstaben oder sonderzeichen enthalten.");
            writePrompt();
        }
    } while (loop);
    temp.str(eingabe);
    temp >> returnValue;
    temp.clear();
    return returnValue;
}

int eingabeFloat(const std::string &text) {
    write(text);
    writePrompt();

    string eingabe;
    istringstream temp;
    bool loop;
    int returnValue{};

    regex muster(BUCHSTABEN_ZEICHEN_MUSTER);
    regex flaotMuster(FLOAT_MUSTER);
    do {
        loop = false;
        getline(cin, eingabe);
        if (eingabe.empty()) {
            loop = true;
            write("Feld darf nicht leer sein.");
            writePrompt();
        } else if (regex_search(eingabe, muster)) {
            loop = true;
            write("Feld darf keine Buchstaben oder sonderzeichen enthalten.");
            writePrompt();
        } else if (!regex_search(eingabe, flaotMuster)) {
            loop = true;
            write("Falsches Formart (0000.00)");
            writePrompt();
        }
    } while (loop);
    if (eingabe.find(',') == string::npos) {
        eingabe.erase(eingabe.find('.'), 1);
    } else {
        eingabe.erase(eingabe.find(','), 1);
    }
    temp.str(eingabe);
    temp >> returnValue;
    temp.clear();
    return returnValue;
}

std::string eingabeDatum(const std::string &text) {
    write(text);
    writePrompt();
    string eingabe;
    bool loop;
    regex muster(BUCHSTABEN_ZEICHEN_MUSTER);
    regex datumMuster(DATUMS_MUSTER);
    do {
        loop = false;
        getline(cin, eingabe);
        if (eingabe.empty()) {
            loop = true;
            write("Feld darf nicht leer sein.");
            writePrompt();
        } else if (regex_search(eingabe, muster)) {
            loop = true;
            write("Feld darf keine Buchstaben oder sonderzeichen enthalten.");
            writePrompt();
        } else if (!regex_match(eingabe, datumMuster)) {
            loop = true;
            write("Datumsformat falsch (TT.MM.JJJJ).");
            writePrompt();
        } else if (!datumPruefung(eingabe)) {
            loop = true;
            write("Datum existiert nicht.");
            writePrompt();
        }
    } while (loop);
    return eingabe;
}

void ausgabeTabelle(const std::vector<PersonalDaten> &datenBank) {
    if (!datenBank.empty()) {
        write("Name             Vorname          Personalnummer        Gehalt    "
                "Geburtstag");
        for (const PersonalDaten &person: datenBank) {
            ausgabe(person);
        }
    }
}

void ausgabe(const PersonalDaten &person) {
    cout << setfill(' ');
    cout << ausgabeString(person.name);
    cout << ausgabeString(person.vorname);
    cout << setw(14) << person.pNummer;
    cout << setw(14) << ausgabeFloat(person.gehalt);
    cout << setw(14) << person.geburtsDatum;
    cout << endl;
}

string ausgabeString(string text) {
    string returnValue;
    if (text.length() > 15) {
        text.erase(15, text.length() - 15);
        text.insert(16, ". ") += ". ";

    } else if (text.length() < 15) {
        text += string(17 - text.length(), ' ');
    } else {
        text += "  ";
    }
    return text;
}

string ausgabeFloat(int zahl) {
    string tempString = to_string(zahl);
    tempString.insert(tempString.length() - 2, ".");
    return tempString;
}