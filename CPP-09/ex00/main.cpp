#include "includes.hpp"
#include "Date.hpp"

void	getKeyval(std::string filebuf, std::map<Date, int> &input){

	Date	date;
	std::stringstream	data(filebuf);

	data >> data.year;
	data.ignore(1, '-');
	data >> date.month;
	data.ignore(1, '-');
	data >> date.day;
	data.ignore (1, ' ');
	data.ignore (1, '|');
	data.ignore (1, ' ');

	date >> input[date];
	date
}



bool	parseMap(std::map<Date, int> &input, std::string inputfile){

	std::string		filebuf;
	std::ifstream	file(inputfile);

	if (!file.is_open()){

		std::cerr << "Can't open file" << std::endl;
		return false;
	}
	std::getline(file, filebuf, "\n");
	if (filebuf == "date | value")
		std::getline(file, filebuf);
	getKeyval(filebuf);


}




int	main(int ac, char **av){
	
	if (ac != 3){
		std::cerr << "First argument is input.txt, second is data.csv" << std::endl;
		return 1;
	}
	std::map<Date, int>	input;
	std::string			inputfile = av[1];
	if (!parseMap(input, inputfile))
		return 1;

	return 0;
}
