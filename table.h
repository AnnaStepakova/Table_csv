#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream> //istringstream
#include <fstream>

class Table {
private:
    std::vector<std::string> header;
    //std::map<int, std::map<std::string, std::string>> table;
public:
    std::map<int, std::map<std::string, std::string>> table;
    Table(const std::string &inputFile);
    Table(std::vector<std::string> &&header, std::map<int, std::map<std::string, std::string>> &&m);
    void checkForExpressions();
    std::string compute(std::string expression);
    friend bool operator== (Table const &table1, Table const &table2);
    friend std::ostream &operator <<(std::ostream &os, const Table &t);
};
