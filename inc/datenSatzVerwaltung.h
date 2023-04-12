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
int eingabeFloat(const std::string&);
std::string eingabeDatum(const std::string&);
void ausgabeTabelle(const std::vector<personalDaten>&);
void ausgabe(const personalDaten&);
std::string ausgabeString(std::string);
std::string ausgabeFloat(int);

#endif //U_STRING_DATENSATZVERWALTUNG_H
