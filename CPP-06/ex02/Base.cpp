#include "Base.hpp"


Base	*generate(void){

	srand(time(NULL));
	int	rand = std::rand() % 3;
	switch (rand){
		
		case 0:
				std::cout << "creating A" << std::endl;
				return new A;
		case 1:
				std::cout << "creating B" << std::endl;
				return new B;
		case 2:
				std::cout << "creating C" << std::endl;
				return new C;
	}
}
