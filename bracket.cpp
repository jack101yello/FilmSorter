#include "bracket.h"

Bracket::Bracket(std::vector<std::string>& movielist_t) {
    movielist = movielist_t;
}

bool selectbetween(const std::string& movie1, const std::string& movie2) {
    std::cout << "Select between the following two movies:" << std::endl;
    std::cout << "[1] " << movie1 << std::endl;
    std::cout << "[2] " << movie2 << std::endl;
    int choice;
    std::cin >> choice;
    switch(choice) {
        case 1: return true; // The first movie is better
        case 2: return false; // The second movie is better
        default: return selectbetween(movie1, movie2); // Just ask again if they don't choose
    }
}

struct sortcomp {
    inline bool operator() (const std::string& movie1, const std::string& movie2) {
        return selectbetween(movie1, movie2);
    }
};

void Bracket::sort() {
    std::sort(movielist.begin(), movielist.end(), sortcomp());
}

void Bracket::print() {
    std::cout << "The sorted list of movies is:" << std::endl;
    int count = 1;
    for(std::vector<std::string>::iterator iter = movielist.begin();
    iter != movielist.end(); ++iter) {
        std::cout << count++ << ". " << *iter << std::endl;
    }
}

void Bracket::dump() {
    std::cout << "Dumping list to a file..." << std::endl;
    std::fstream outfile;
    std::string outfilename = "output.data";
    outfile.open(outfilename, std::ios::out);
    if(outfile.is_open()) {
        int count = 1;
        for(std::vector<std::string>::iterator iter = movielist.begin();
        iter != movielist.end(); ++iter) {
            outfile << count++ << ". " << *iter << std::endl;
        }
    }
}