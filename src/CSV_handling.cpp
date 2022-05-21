#include "CSV_handling.hh"
#include <algorithm>

/* 
    Funkcja oczyszczająca plik CSV z uszkodzonych rekordów. 
*/
void fix_csv(){
    std::fstream file_in, file_out;
    std::string line;
    
    file_in.open("../datasets/film_list.csv", std::ios::in);
    file_out.open("../datasets/film_list_fixed.csv", std::ios::out);

    if(file_in.is_open()){
        while (getline(file_in, line)){
            if (line[line.length()-1] == '0'){
                int f_q_pos = line.find('"'), s_q_pos = line.rfind('"');
                if (f_q_pos != -1 && s_q_pos != -1)
                    std::remove(line.begin() + f_q_pos, line.begin() + s_q_pos  , ',');
                file_out << line << std::endl;
            }
        }
        file_in.close();
        file_out.close();
    }
    else 
        std::cerr<<"Could not open the file!!!\n";
}

/* 
    Funkcja wczytująca określoną ilość produkcji do wskazanej tablicy.
*/
void read_record(int amount, Production *arr){
    int count = 0;
    std::fstream file_in;
    std::vector<std::string> row;
    std::string line, word;
    
    file_in.open("../datasets/film_list_fixed.csv", std::ios::in);
    if(file_in.is_open()){
        while (getline(file_in, line) && count < amount){
            row.clear();
            std::stringstream str(line);
            while (std::getline(str, word, ','))
                row.push_back(word);
            arr[count] = Production(std::stoi(row[0]), row[1], std::stod(row[2]));
            count++;
        }
        file_in.close();
    }
    else 
        std::cerr<<"Could not open the file!!!\n";
}