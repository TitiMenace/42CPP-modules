#include "includes.hpp"

void	fillMap(std::string filebuf, std::map<std::string, double> &input){

	std::string	key;
	std::string	value;
	double		val;
	size_t		pos;
	std::stringstream	data(filebuf);
	

	pos = filebuf.find(",");
	key = filebuf.substr(0, pos);
	value = filebuf.substr(pos + 1, filebuf.length() - 1);
	std::stringstream convert(value);
	convert >> val;
	input[key] = val;
}

bool	parseMap(std::map<std::string, double> &input, const char *inputfile){

	std::string		filebuf;
	std::ifstream	file(inputfile);

	if (!file.is_open()){

		std::cerr << "Can't open file" << std::endl;
		return false;
	}
	while (std::getline(file, filebuf, '\n')){
		if (filebuf == "date,exchange_rate")
			std::getline(file, filebuf);
		fillMap(filebuf, input);
	}
	return true;
}

bool	calculateValue(std::map<std::string, double> &input, const char *inputfile){

	std::ifstream	file(inputfile);
	if (!file.is_open()){

		std::cerr << "Can't open file" << std::endl;
		return false;
	}
	while (std::getline(file, filebuf, '\n')){
		if (filebuf == "date | values")
			std::getline(file, filebuf);
		fillMap(filebuf, input);
	}

}

void	printResult(std::string	key, double value);

void printMap(std::map<std::string, double>& dataMap) {
    for (std::map<std::string, double >::iterator it = dataMap.begin(); it != dataMap.end(); ++it) {
        std::cout << it->first << " -> " << it->second << std::endl;
    }
}

int	main(int ac, char **av){
	
	if (ac != 3){
		std::cerr << "First argument is input.txt, second is data.csv" << std::endl;
		return 1;
	}
	std::map<std::string, double>	input;
	if (!parseMap(input, av[2]))
		return 1;
	if (!calculateValue(input, av[1]))
	printMap(input);

	return 0;
}
