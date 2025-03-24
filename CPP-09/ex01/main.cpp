#include "includes.hpp"



bool	parseMap(std::map<Date, int> &input, std::string inputfile){

	std::ifstream	file(inputfile);



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
