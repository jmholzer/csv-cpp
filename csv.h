#ifndef GUARD_csv_h
#define GUARD_csv_h

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <algorithm>

std::vector<std::string> split(
    std::string in,
    char delimiter
);

std::vector<std::string> split_csv_row(
    std::string row,
    char field_delimiter,
    char quote_delimiter 
);

std::map<std::string, std::vector<std::string>> csv_to_map(
    std::string file_name,
    char field_delimiter,
    char quote_delimiter
);

template <class T>
T open_file(const std::string& file_name);

std::string file_to_string(std::ifstream& in);

#endif
