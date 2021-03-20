#include "csv.h"

std::vector<std::string> split(
        std::string in,
        std::string delimiter
)
{
    std::vector<std::string> result;

    std::string::size_type start = 0, end = 0;
    std::string token;

    while((end = in.find(delimiter, start)) != std::string::npos)
    {
        token = in.substr(start, end - start);
        start = end + 1;
        result.push_back(token);
    }

    return result;
}

std::map<std::string, std::vector<std::string>> csv_to_map(
    std::fstream,
    char field_delimiter,
    char quote_delimitequote_delimiterr 
)
{
    std::map<std::string, std::vector<std::string>> result;

    return result;
}

template <class T>
T open_file(const std::string& file_name)
{
    T file;
    file.open(file_name);
    return file;
}

std::string file_to_string(std::ifstream& in)
{
    std::stringstream buffer;
    buffer << in.rdbuf();
    std::string result = buffer.str();
    return result; 
}

int main()
{
    std::ifstream in = open_file<std::ifstream>("test.csv");

    std::string fstr = file_to_string(in);

    std::cout << fstr << std::endl << "----" << std::endl;
    
    std::vector<std::string> fstr_split = split(fstr, "\n");

    for(size_t i = 0; i != fstr_split.size(); ++i)
        std::cout << fstr_split[i] << std::endl; 

    return 0;
}
