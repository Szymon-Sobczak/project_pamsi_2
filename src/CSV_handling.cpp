#include "CSV_handling.hh"
#include<algorithm>

void fix_csv(){
    std::fstream fin,fou;
    std::vector<std::string> row;
    std::string line, word, temp;
    
    fin.open("../datasets/film_list.csv", std::ios::in);
    
    fou.open("../datasets/film_list_fixed.csv", std::ios::out);

    if(fin.is_open()){
        while (getline(fin, line)){
            if (line[line.length()-1] == '0'){
                int f_q_pos = line.find('"'), s_q_pos = line.rfind('"');
                if (f_q_pos != -1 && s_q_pos != -1){
                    std::remove(line.begin() + f_q_pos, line.begin() + s_q_pos  , ',');
                }
                fou << line << std::endl;
            }
        }
        fin.close();
        fou.close();
    }
    else 
        std::cout<<"Could not open the file\n";
}

void read_record(int amount, Production arr[])
{
    int count = 0;
    std::fstream fin;
    std::vector<std::string> row;
    std::string line, word, temp;
    
    fin.open("../datasets/film_list_fixed.csv", std::ios::in);
    if(fin.is_open()){
        while (getline(fin, line) && count < amount) {
            row.clear();
            std::stringstream str(line);
            while (std::getline(str, word, ','))
                row.push_back(word);
            
            arr[count] = Production(std::stoi(row[0]), row[1], std::stod(row[2]));
            count++;
        }
        fin.close();
    }
    else 
        std::cout<<"Could not open the file\n";
}