#ifndef bracket__H
#define bracket__H

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

class Bracket {
    public:
    Bracket(std::vector<std::string>& movielist_t);
    void sort();
    void print();
    void dump();

    private:
    std::vector<std::string> movielist;
};

#endif