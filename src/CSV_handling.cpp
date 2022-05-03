#include "CSV_handling.hh"
#include<algorithm>

void read_record(int amount, Production arr[])
{
    int count = 0;
    std::fstream fin;
    fin.open("../datasets/film_list.csv", std::ios::in);
    std::vector<std::string> row;
    std::string line, word, temp;
    if(fin.is_open()){
        
        while (getline(fin, line) && count <= amount) {
            row.clear();

            int f_q_pos = line.find('"'), s_q_pos = line.rfind('"');
            
            if (f_q_pos != -1 && s_q_pos != -1){
                line.erase(std::remove(line.begin() + f_q_pos, line.begin() + s_q_pos + 1, ','), line.end()); 
            }


            std::stringstream str(line);
            while (std::getline(str, word, ',')){
                row.push_back(word);
            }
            if (count>0){
                arr[count-1] = Production(std::stoi(row[0]), row[1], std::stod(row[2]) ? std::stod(row[2]) : 0);
                arr[count-1].print_production();
            }
            count++;
        }
        fin.close();
    }
    else 
        std::cout<<"Could not open the file\n";
}