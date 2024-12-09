#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void){

	srand(time(NULL));
	int	rand = (std::rand() % 3);
	switch (rand){
		
		case 0:
				std::cout << "new A" << std::endl;
				return new A;
		case 1:
				std::cout << "new B" << std::endl;
				return new B;
		case 2:
				std::cout << "new C" << std::endl;
				return new C;
	}
	return NULL;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;

}

void identify(Base& p)
{
	try {
        A& a = dynamic_cast< A& >( p );
        std::cout << "A" << std::endl;
        (void)a;
		return;
    } catch(const std::exception & e) {}
	try {
        B& b = dynamic_cast< B& >( p );
        std::cout << "B" << std::endl;
        (void)b;
		return;
    } catch(const std::exception & e) {}
	try {
        C& c = dynamic_cast< C& >( p );
        std::cout << "C" << std::endl;
        (void)c;
		return;
    } catch(const std::exception & e) {}
	std::cout << "Unknown" << std::endl;
}
