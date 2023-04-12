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
#include "../inc/personalM.h"

bool datumPruefung(std::string datum);
std::string eingabeString(const std::string&);
int eingabeInt(const std::string&);
int eingabeFlaot(const std::string&);
std::string datumVerarbeitung(const std::string&);
extern void ausgabeTabelle(const std::vector<personalDaten>&);
extern void ausgabe(const personalDaten&);

#endif //U_STRING_DATENSATZVERWALTUNG_H
