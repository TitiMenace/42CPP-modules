#include "includes.hpp"
#define DOUBLE_MAX 1.7976931348623157e+308

std::string get_closest_date(std::string input_date, std::map<std::string,std::string> datacsv)
{
    std::string closest_date ("no data for period");
    std::map<std::string, std::string>::iterator it = datacsv.upper_bound(input_date);
    
	if (it != datacsv.begin()) {
        --it;
        closest_date = it->first;
    }
    return (closest_date);
}

void	fillMap(std::string filebuf, std::map<std::string, std::string> &datacsv){

	std::string	key;
	std::string	value;
	std::stringstream	data(filebuf);

	size_t	pos = filebuf.find(",");
	if (pos != std::string::npos) {
		key = filebuf.substr(0, pos);
		value = filebuf.substr(pos + 1, filebuf.length() - 1);
		datacsv[key] = value;
	}
}

bool	parseMap(std::map<std::string, std::string> &datacsv, const char *inputfile){

	std::string		filebuf;
	std::ifstream	file(inputfile);

	if (!file.is_open()){

		std::cerr << "Can't open file" << std::endl;
		return false;
	}
	while (std::getline(file, filebuf, '\n')){
		if (filebuf == "date,exchange_rate")
			std::getline(file, filebuf);
		fillMap(inputfile, datacsv);
	}
	return true;
}

bool isNumber(const std::string& str) {
    size_t i = 0;
    if (str[0] == '-' || str[0] == '+')
        i = 1;

    bool dot = false;
    bool digits = false;

    while (i < str.size()) {
        if (std::isdigit(str[i])) {
            digits = true;
        } else if (str[i] == '.' && !dot) {
            dot = true;
            digits = false;
        } else {
            return false;
        }
        i++;
    }
    return digits;
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
	

bool	checkvalues(std::string (&data)[2], size_t n_line)
{
	if (data[0].empty() || data[1].empty()){
		std::cout << "Value empty in line "<< n_line << std::endl;
		return false;
	}
	if ((data[0] == "date" && data[1] == "value") && n_line == 1){
		return false;
	}
	if ((isNumber(data[1]) && (data[1][0] == '-'))){
		std::cout << "Negative value in line " << n_line << std::endl;
		return false;
	}
	if (!isNumber(data[1])){
		std::cout << "the value isnt a correct numerical value on line " << n_line << std::endl;
		return false;
	}

	if (!isDate(data[0]))
	{
		std::cout << "the date is not in the right format on line " << n_line << std::endl;
		return false;
	}
	return true;
}	

double	strtod(std::string src){
    
	std::istringstream double_stream (src);
    std::string double_floating_point;
    double dNbr = 0;
    double_stream >> dNbr;
    if (double_stream.fail())
        return -1;
    return dNbr;
}

bool	inputParsing(std::map<std::string, std::string> &datacsv, std::ifstream	&ifile){

	std::string delimiter  = " | ";
	std::string	line;
	std::string	data[2];
	std::string	datacsv_key;
	
	size_t		pos;	
	size_t		n_line = 0;
	double		rate = 0, value = 0, result = 0;

	
	while (std::getline(ifile, line)){
		n_line++;
		pos =  line.find(delimiter);

		if (pos != std::string::npos){
			data[0] = line.substr(0,pos);
			data[1] = line.substr(pos + delimiter.length());
			if(!checkvalues(data, n_line))
				continue;
			datacsv_key = get_closest_date(data[0], datacsv);
			rate = strtod(datacsv[datacsv_key]);
			if (rate < 0)
            {
                std::cout << "the rate is out of bounds for the " << datacsv[datacsv_key] <<"." << n_line << std::endl;
                continue;
            }
			value = strtod(data[1]);
			if (value < 0)
            {
                std::cout << "the value is out of bounds on line " << n_line << std::endl;
                continue;
            }
			if (rate > 0 && value > 0 && rate > (DOUBLE_MAX / value)) 
            {
                std::cout << "multiplication overflow detected on line " << n_line << std::endl;
                continue;
            }
            else {
                result = rate * value;
            }
			std::cout << data[0] << " :: " << data[1] << " = "  <<result <<std::endl;
		}
		else
        {
            std::cout << "the input isnt formatted correctly on line " << n_line << std::endl;
            continue;
        }
	}
	return true;
}

int	main(int ac, char **av){
	
	if (ac != 3){
		std::cerr << "First argument is input.txt, second is data.csv" << std::endl;
		return 1;
	}
	std::map<std::string, std::string>	datacsv;
	if (!parseMap(datacsv, av[2]))
		return 1;
	std::ifstream ifile(av[1]);
	if (ifile.fail()){
		
		std::cerr << "Cannot open " << (void *)av[1] << " it doesn't exist or you don't have permission" << std::endl;
		return 1;
	}
	if (!inputParsing(datacsv, ifile)){
		std::cerr << "Issue during exec" << std::endl;
		return 1;
	}
	return 0;
}
