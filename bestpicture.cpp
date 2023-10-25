#include <iostream>
#include <vector>
#include <fstream>
#include "bracket.h"

// From a list of movies in a file, throw all of them into a vector
void getallmovies(std::string& filename, std::vector<std::string>& movielist) {
    std::fstream newfile;
    newfile.open(filename, std::ios::in);
    if(newfile.is_open()) {
        std::string line;
        while(getline(newfile, line)) {
            movielist.push_back(line);
        }
    }
    newfile.close();
    for(std::vector<std::string>::iterator iter = movielist.begin();
    iter != movielist.end(); ++iter) {
        std::cout << "// " << *iter << std::endl;
    }
}

int main() {
    std::string filename = "movielist.data";
    std::vector<std::string> movielist;

    std::cout << "Finding all of the movies from the list..." << std::endl;
    getallmovies(filename, movielist); // Put all of the movies into the vector
    Bracket bracket(movielist);

    bracket.sort(); // This will take a while. Brace yourself for all of the choices.

    bracket.print();
    bracket.dump();

    return 0;
}