#include<fstream>
#include<string>
#include<sstream>
#include "Files.h"
#include "Container.h"


void read(const std:: string& filename, FloatArray& data){
    std::ifstream file(filename);

    std:: string line;

    while(std::getline(file, line) ){
        std::string token;
        std::stringstream parser(line);

        while (std::getline(parser, token, ',')){
            float num=stof(token);
            data.push_back(num);
        }
    }
file.close();
}