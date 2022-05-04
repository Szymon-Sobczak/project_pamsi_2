#include "Production.hh"

Production::Production(int new_ID, std::string new_name, double new_rating){
    ID = new_ID;
    name = new_name;
    rating = new_rating;
}

void Production::fill_production(int new_ID, std::string new_name, double new_rating){
    ID = new_ID;
    name = new_name;
    rating = new_rating;
}

void Production::print_production(){
    std::cout << ID << " " << name  << " " << std::fixed << std::setprecision(1) << rating << std::endl;
}

Production & Production::operator = (const Production & new_elem) {
    ID = new_elem.ID;
    name = new_elem.name;
    rating = new_elem.rating;
    return *this;
}

double Production::get_rating(){
    return rating;
}




