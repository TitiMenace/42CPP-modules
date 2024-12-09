#include "Base.hpp"

int	main(void){

	Base *b = generate();
	identify(b);
	Base &c = *b;
	identify(c);
	delete b;
	return 0;
}
