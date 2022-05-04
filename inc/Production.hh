#pragma once 
#include <iostream>
#include <memory>
#include <fstream>
#include <string>
#include <iomanip>


class Production{
    private:
        int ID;
        double rating;
        std::string name;
    public:
        Production(){;}
        Production(int new_ID, std::string new_name, double new_rating);

        double get_rating();
        void print_production();

        void fill_production(int new_ID, std::string new_name, double new_rating);
        Production & operator = (const Production & new_elem);
};

