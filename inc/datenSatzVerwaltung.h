//
// Created by azubi on 11.04.2023.
//
#ifndef U_STRING_DATENSATZVERWALTUNG_H
#define U_STRING_DATENSATZVERWALTUNG_H

#include "../inc/personalM.h"
#include <array>
#include <iomanip>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

bool datumPruefung(const std::string& datum);

std::string eingabeString(const std::string &);

int eingabeInt(const std::string &);

int eingabeFloat(const std::string &);

std::string eingabeDatum(const std::string &);

void ausgabeTabelle(const std::vector<PersonalDaten> &);

void ausgabe(const PersonalDaten &);

std::string ausgabeString(std::string);

std::string ausgabeFloat(int);

#endif // U_STRING_DATENSATZVERWALTUNG_H
