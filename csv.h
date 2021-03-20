#ifndef GUARD_csv_h
#define GUARD_csv_h

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>

std::vector<std::string> split(
        std::string in,
        std::string delimiter
);

std::map<std::string, std::vector<std::string>> csv_to_map(
    std::fstream,
    char field_delimiter,
    char quote_delimitequote_delimiterr 
);

std::fstream open_file(const std::string& file_name);

std::string file_to_string(std::ifstream& in);

#endif
