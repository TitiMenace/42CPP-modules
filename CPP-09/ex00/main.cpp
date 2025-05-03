#include <iostream>
#include <fstream>

#include <sstream>
#include <map>
#define CSV_DB "data.csv"
std::string get_closest_date(std::string input_date, std::map<std::string,std::string>database)
{
    std::string closest_date ("no data for period");

    std::map<std::string, std::string>::iterator it = database.upper_bound(input_date);
    
    // Find the closest smaller date
    if (it != database.begin()) {
        --it;  // Move to the closest smaller date
        closest_date = it->first;
    }
    //Be careful to use the lower date and not the upper one dont forget dont forget dont forget
    return (closest_date);
}

void     populate_map(std::map<std::string,std::string>*database, std::ifstream &file, std::string delimiter){
    for (std::string line; std::getline(file, line);) {
        std::string data[2];
        size_t pos = line.find(delimiter);  // Find delimiter position

        if (pos != std::string::npos) {  
            data[0] = line.substr(0, pos);  // Extract key (before delimiter)
            data[1] = line.substr(pos + delimiter.length());  // Extract value (after delimiter)

            (*database)[data[0]] = data[1];  // Insert into map
        }
    }

}
    // populate_database(&database, infile);
double fromString(std::string src)
{
    std::istringstream double_stream (src);
    std::string double_floating_point;
    double dNbr = 0;
    double_stream >> dNbr;
    if (double_stream.fail())
        return -1; //since we work with only positive values, this is enough
    return dNbr;
}

std::string toString(double dNbr)
{
    std::string double_floating_point;
    std::ostringstream oss;
    oss << dNbr;
    double_floating_point = oss.str();
    return double_floating_point;
}

bool isNumber(const std::string& str) {
    size_t i = 0;
    if (str[0] == '-' || str[0] == '+') // Handle optional sign
        i = 1;

    bool dot = false;
    bool digits = false;

    while (i < str.size()) {
        if (std::isdigit(str[i])) {
            digits = true;
        } else if (str[i] == '.' && !dot) {
            dot = true;
            digits = false; // if there is a point then expect other numbers
        } else {
            return false;
        }
        i++;
    }
    return digits; // must have at least a digit
}

bool parseDate(struct tm *c_time, char **result, std::string data){
return (*result = strptime(data.c_str(), "%Y-%m-%d", c_time), 1);
}

bool isDate(std::string data) {
    struct tm c_time = {};
    char* result = NULL;
    return (1 
            && data.length() == 10 
            && data[4] == '-' 
            && data[7] == '-' 
            && parseDate(&c_time, &result, data) 
            && result != NULL 
            && *result == '\0' 
            && c_time.tm_year + 1900 >= 1000 
            && c_time.tm_year + 1900 <= 9999 
            && c_time.tm_mon >= 0 
            && c_time.tm_mon <= 11 
            && c_time.tm_mday >= 1 
            && c_time.tm_mday <= 31
    );
}


int main(int argc, char **argv){
    if (argc < 2){
        std::cout << "Not enough arguments" << std::endl;
        return __LINE__;
    }
    if (argc >= 3){
        std::cout << "Too many arguments" << std::endl;
        return __LINE__;
    }


    std::ifstream csv(CSV_DB);
    if (csv.fail()){
        std::cout << "The database file doesnt exist or isnt accesible" << std::endl;
        return __LINE__;
    }
    std::map<std::string, std::string> database;
    database["no data for period"] = "nan";
    populate_map(&database, csv, ",");

    std::ifstream infile(argv[1]);
    if (infile.fail()){
        std::cout << "This input file doesnt exist or isnt accesible" << std::endl;
        return __LINE__;
    }
    std::string delimiter = " | ";
    int line_n = 0;
    for (std::string line; std::getline(infile, line);) {
        std::string data[2];
        line_n++;
        size_t pos = line.find(delimiter);  // Find delimiter position

        if (pos != std::string::npos) {  
            data[0] = line.substr(0, pos);  // Extract key (before delimiter)
            data[1] = line.substr(pos + delimiter.length());  // Extract value (after delimiter)
            if (data[0].empty() || data[1].empty()){
                std::cout << "one of the values or both are empty in line "<< line_n << std::endl;
                continue;
            }
            if ((data[0] == "date" && data[1] == "value") && line_n == 1){
                continue;
            }
            if ((isNumber(data[1]) && (data[1][0] == '-'))){
                std::cout << "one of the values is negative on line " << line_n << std::endl;
                continue;
            }
            if (!isNumber(data[1])){
                std::cout << "the value isnt a correct numerical value on line " << line_n << std::endl;
                continue;
            }

            if (!isDate(data[0]))
            {
                std::cout << "the date is not in the right format on line " << line_n << std::endl;
                continue;
            }
            std::string database_date = get_closest_date(data[0], database);
            double rate = fromString(database[database_date]);
            if (rate < 0)
            {
                std::cout << "the rate is out of bounds for the " << database[database_date] <<"." << line_n << std::endl;
                continue;
            }
            double value = fromString(data[1]);
            if (value < 0)
            {
                std::cout << "the value is out of bounds on line " << line_n << std::endl;
                continue;
            }
            double result = 0;
            if (rate > 0 && value > 0 && rate > (INT_MAX / value)) 
            {
                std::cout << "multiplication overflow detected on line " << line_n << std::endl;
                continue;
            }
            else {
                result = rate * value;
            }
            std::cout << data[0] << " :: " << data[1] << " = "  <<result <<std::endl;
        }
        else
        {
            std::cout << "the input isnt formatted correctly on line " << line_n << std::endl;
            continue;
        }
    }
    //Be careful to use the lower date and not the upper one dont forget dont forget dont forget
    return 0;
}