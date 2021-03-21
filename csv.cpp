#include "csv.h"

std::vector<std::string> split_newline(std::string in)
{
    std::vector<std::string> out;

    size_t start = 0, end = 0;
    std::string token;

    while((end = in.find('\n', start)) != std::string::npos)
    {
        token = in.substr(start, end - start);
        start = end + 1;
        out.push_back(token);
    }
    
    // Add content after final \n, if it is not empty
    token = in.substr(start, end - start);
    if(!token.empty())
        out.push_back(token);

    return out;
}

std::vector<std::string> split_csv_row(
    std::string row,
    char field_delimiter,
    char quote_delimiter 
)
{
    std::vector<std::string> out;

    size_t start = 0, end = 0;
    size_t quote_start = 0, quote_end = 0;
    std::string token;
    size_t quote_num;

    while((end = row.find(field_delimiter, start)) != std::string::npos)
    {
        while(std::count(row.begin() + start, row.begin() + end, quote_delimiter) % 2 != 0
                && end != std::string::npos)
        {
            end = row.find(field_delimiter, end + 1);
        }
        token = row.substr(start, end - start);
        start = end + 1;
        out.push_back(token);
    }

    token = row.substr(start, end - start);
    out.push_back(token);

    return out;
}

std::map<std::string, std::vector<std::string>> csv_to_map(
    std::string file_name,
    char field_delimiter,
    char quote_delimiter
)
{
    std::map<std::string, std::vector<std::string>> out;

    std::ifstream in = open_file<std::ifstream>(file_name);
    std::string in_str = file_to_string(in);
    std::vector<std::string> in_rows = split_newline(in_str);
    
    std::vector<std::string> headers = split_csv_row(in_rows[0], field_delimiter, quote_delimiter);
    for(size_t i = 0; i != headers.size(); ++i)
        out.insert({headers[i], std::vector<std::string>()});

    for(size_t i = 0; i != in_rows.size(); ++i)
    {
        std::vector<std::string> row = split_csv_row(in_rows[i], field_delimiter, quote_delimiter);

        for(size_t j  = 0; j != headers.size(); ++j)
            out[headers[j]].push_back(row[j]);
    }

    return out;
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
    std::string out = buffer.str();
    return out; 
}

int main()
{
    std::string test_file_name = "test2.csv";

    std::map<std::string, std::vector<std::string>> out = csv_to_map(test_file_name, ',', '\"');

    for(size_t i = 0; i != out["col1"].size(); ++i)
    {
        std::cout << out["col1"][i] << " "
                  << out["col2"][i] << " " 
                  << out["col3"][i] << " " 
                  << out["col4"][i] << " " 
                  << out["col5"][i] << " " 
                  << std::endl;
    }

    return 0;
}
