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
void fix_csv();

/* Funkcja wczytująca określoną ilość produkcji do wskazanej tablicy. */
void read_record(int amount, Production *arr);