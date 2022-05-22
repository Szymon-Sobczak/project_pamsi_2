#pragma once 
#include <iostream>
#include <memory>
#include <fstream>
#include <string>
#include <iomanip>
#include <bits/stdc++.h>

/*
    Klasa reprezentujaca pojedynczy wpis w tabeli filmów.
*/

class Production{
        int ID; /* Numer porzadkowy produkcji */
        double rating; /* Ocena krytyków z portalu IMDb */
        std::string name; /* Nazwa produkcji */
    public:
        Production(){;} /* Konstruktor domyślny */
        /* Konstruktor wraz z listą inicjalizacyjną */
        Production(int new_ID, std::string new_name, double new_rating) : ID(new_ID), rating(new_rating), name(new_name) {};
        double get_rating() {return rating;} /* Metoda pozwalaja na pobranie oceny produkcji */
        void print_production(); /* Metoda pozwalaja na wyswietlenie danych o produkcji */
        Production & operator = (const Production & new_elem); /* Przeciążenie operatora przypisania */
};