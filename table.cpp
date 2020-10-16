#include "table.h"
#include <cctype>
#include <algorithm>
#include <fstream>
#include <exception>

Table::Table(const std::string &inputFileName) {
    std::ifstream inputFile(inputFileName);
    if (!inputFile) {
        throw std::runtime_error("File not found");
    }

    std::string s;
    size_t rowNumber = 0;
    while (getline(inputFile, s)) {
        size_t columnNumber = 0;
        std::istringstream ss(s);  //s is a stream now
        std::string str;
        int rowIndex = 0;
        while (getline(ss, str, ',')) {
            try {
                if (rowNumber == 0) {
                    this->header.push_back(str);
                    continue;
                }

                if (columnNumber == 0) {
                    rowIndex = std::atoi(str.c_str());
                    this->table.emplace(rowIndex, std::map<std::string, std::string>());
                } else {
                    this->table.at(rowIndex).emplace(header[columnNumber], str);
                }
                columnNumber++;
            }
            catch (const std::invalid_argument &e) {
                std::cout << "NaN found in file " << inputFileName << std::endl;
                e.what();
            }
        }
        rowNumber++;
    }
}

Table::Table(std::vector<std::string> &&header, std::map<int, std::map<std::string, std::string>> &&m)
    : header(std::move(header)), table(std::move(m)) {}

void Table::checkForExpressions(){
    std::string cell;
    for (auto const& x : this->table) {
        for (auto & y : x.second) {
            if (y.second[0] == '=') {
                this->table.at(x.first).at(y.first) = compute(y.second);
            }
        }
    }
}

std::string Table::compute(std::string expression){
    std::string firstAdress = "";
    std::string secondAdress = "";
    std::string result1;
    std::string result2;
    int result;
    char sign;
    for (auto ch : expression) {
        if (ch == '=' or ch == ' ')
            continue;
        else if (isalpha(ch))
            firstAdress += ch;

        else if (isdigit(ch))
            secondAdress += ch;

        else if (ch == '*' or ch == '+' or ch == '/' or ch == '-') {
                sign = ch;
                result1 = this->table.at(std::atoi(secondAdress.c_str())).at(firstAdress);
                firstAdress = "";
                secondAdress = "";
            }
        }
    result2 = this->table.at(std::atoi(secondAdress.c_str())).at(firstAdress);
    switch (sign) {
        case '*': result = std::atoi(result1.c_str()) * std::atoi(result2.c_str()); break;
        case '+': result = std::atoi(result1.c_str()) + std::atoi(result2.c_str()); break;
        case '-': result = std::atoi(result1.c_str()) - std::atoi(result2.c_str()); break;
        case '/': result = std::atoi(result1.c_str()) / std::atoi(result2.c_str()); break;
    }
    return std::to_string(result);
}

std::ostream &operator <<(std::ostream &os, const Table &t) {
    int length = t.header.size();
    for (int i = 0; i< length; i++) {
        if (i == length - 1)
            os << t.header[i] << std::endl;
        else
            os << t.header[i] << ", ";
    }

    for (auto const& x : t.table) {
        os << x.first << ", ";
        for (int i = 1; i < length; i++) {
            if (i == length - 1)
                os << x.second.at(t.header[i]) << std::endl;
            else
                os << x.second.at(t.header[i]) << ", ";
        }
    }
    return os;
}

bool operator== (Table const &table1, Table const &table2) {
    bool equal = true;

    for (auto it1 = table1.table.begin(), it2 = table2.table.begin(); it1 != table1.table.end() && it2 != table2.table.end(); it1++, it2++) {
        equal &= (it1->first == it2->first);
        if (!equal)
            break;
        for (auto it11 = it1->second.begin(), it22 = it2->second.begin(); it11 != it1->second.end() && it22 != it2->second.end(); it11++, it22++) {
            equal &= (it11->first == it22->first);
            equal &= (it11->second == it22->second);
            if (!equal)
                break;
        }
    }
    return equal;
}
