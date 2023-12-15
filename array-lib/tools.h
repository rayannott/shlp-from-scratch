#include <iostream>
#include <vector>
#include <string>

#pragma once

template<typename T>
void pprint(const T& val, const std::string& end = "\n") {
    std::cout << val << end;
}


/*
Prints out the vector vec
*/
template<typename T>
void pprint(const std::vector<T>& vec, const std::string& end = "\n") {
    pprint("[", " ");
    for (auto& el : vec) {
        pprint(el, " ");
    }
    pprint("]", "");
    pprint(end, "");
}


/*
Prints out the matrix M
*/
template<typename T>
void pprint(const std::vector<std::vector<T>>& M, const std::string& end = "\n") {
    pprint("[", "\n");
    for (auto& row : M) {
        std::cout << "\t";
        pprint(row);
    }
    pprint("]", "");
    pprint(end, "");
}
