#pragma once 
#include <iostream>
#include <memory>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Production.hh"

/* 
    Funkcje realizujące operacje na pliku źródłowym - .CSV zawierającym dane o produkcjach.
*/

/* Funkcja oczyszczająca plik CSV z uszkodzonych rekordów. */
void RepairCSV();

/* Funkcja wczytująca określoną ilość produkcji do wskazanej tablicy. */
void LoadCSV(int amount, Production *arr);