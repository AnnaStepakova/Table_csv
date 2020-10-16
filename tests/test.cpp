//
// Created by anna on 16.10.2020.
//
#include "../table.h"
#include <gtest/gtest.h>
#include <vector>

TEST(table1, positive) {
    Table table("tests/test1.csv");
    std::map<int, std::map<std::string, std::string>> m = {
            { 1, {
                    {"A", "2"},
                    {"B", "3"},
                    {"C", "15"}
                }
            }, { 2, {
                    {"A", "5"},
                    {"B", "7"},
                    {"C", "0"}
                }
            }, { 13, {
                    {"A", "-5"},
                    {"B", "4"},
                    {"C", "1"}
                }
            }
    };

    Table expected({ "", "A", "B", "C" }, std::move(m));
    table.checkForExpressions();

    ASSERT_EQ(table, expected);
}

TEST(table2, positive) {
    Table table("tests/test2.csv");
    std::map<int, std::map<std::string, std::string>> m = {
            {1, {
                        {"A", "2"},
                        {"B", "4"},
                        {"BB", "2"}
            }},
            {2, {
                        {"A", "3"},
                        {"B", "12"},
                        {"BB", "1"}
                }}
    };
    Table expected({ "", "A", "B", "BB" }, std::move(m));
    table.checkForExpressions();

    ASSERT_EQ(table, expected);
}

TEST(table3, positive) {
    Table table("tests/test3.csv");
    std::map<int, std::map<std::string, std::string>> m = {

            { 1, {
                    {"A", "1"},
                    {"B", "1"},
                    {"C", "2"}
            }
            }, { 2, {
                    {"A", "3"},
                    {"B", "5"},
                    {"C", "8"}
            }
            }, { 3, {
                    {"A", "13"},
                    {"B", "21"},
                    {"C", "34"}
            }}
    };
    Table expected({ "", "A", "B", "C" }, std::move(m));
    table.checkForExpressions();

    ASSERT_EQ(table, expected);
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}