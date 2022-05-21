#include "Production.hh"

/*
    Metoda klasy Production, umożliwiająca wypisanie danych o produkcji na wyjście standardowe. 
*/
void Production::print_production(){
    std::cout << ID << " " << name  << " " << std::fixed << std::setprecision(1) << rating << std::endl;
}

/*
    Przeciązenie operatora przypisania dla klasy Production.
*/
Production & Production::operator = (const Production & new_elem) {
    ID = new_elem.ID;
    name = new_elem.name;
    rating = new_elem.rating;
    return *this;
}