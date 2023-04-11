//
// Created by azubi on 11.04.2023.
//
#ifndef U_STRING_DATENSATZVERWALTUNG_H
#define U_STRING_DATENSATZVERWALTUNG_H

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <sstream>
#include <regex>
#include <iomanip>

bool datumPruefung(std::string datum);
std::string stringVerarbeitung();
std::string intVerarbeitung();
std::string datumVerarbeitung();
extern void datenEingabe(std::vector<std::array<std::string, 5>>& datenBank);
extern void datenAusgabe(std::vector<std::array<std::string, 5>>& datenBank);

#endif //U_STRING_DATENSATZVERWALTUNG_H
