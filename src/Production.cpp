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
    std::cout << ID << " " << name << " " << rating << std::endl;
}