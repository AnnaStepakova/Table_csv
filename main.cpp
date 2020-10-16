#include <gtest/gtest.h>
#include "table.h"

int main(int argc, char **argv){
    if (argc != 2) {
        std::cerr << "File name is required" << std::endl;
        return EXIT_FAILURE;
    }

    std::string filename = argv[1];
    Table table(filename);
    table.checkForExpressions();
    std::cout << table << std::endl;
    return 0;
}
