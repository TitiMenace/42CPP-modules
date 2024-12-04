

void	PseudoLiterals(size_t i){

	switch(i){
	
		case 1:
			std::cout << "char : Impossible" << std::endl;
			std::cout << "int : Impossible" << std::endl;
			std::cout << "float :-inff" << std::endl;
			std::cout << "double : -inf" << std::endl;
		case 2:
			std::cout << "char : Impossible" << std::endl;
			std::cout << "int : Impossible" << std::endl;
			std::cout << "float :+inff" << std::endl;
			std::cout << "double : +inf" << std::endl;
		case 3:
			std::cout << "char : Impossible" << std::endl;
			std::cout << "int : Impossible" << std::endl;
			std::cout << "float : nanf" << std::endl;
			std::cout << "double : nan" << std::endl;
	}
}

