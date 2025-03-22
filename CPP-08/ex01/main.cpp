#include "Span.hpp"


void bigSpanTest()
{
        std::vector<int>    v;
        for (int i = 0; i < 10000; i++)
        {
            v.push_back(i * 3);
        }
        
        Span span( v.size() );
        
        span.fillSpan( v.begin(), v.end() );

        std::cout << "Longest span: " << span.longestSpan() << std::endl;
        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
    
}


int main()
{

	try{Span	zazou(5);
		zazou.addNumber(1);
		zazou.addNumber(2);
		zazou.addNumber(3);
		zazou.addNumber(4);
		zazou.addNumber(5);
		zazou.print();
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	try{
		std::vector<int>	toFill;
		toFill.push_back(1);
		toFill.push_back(2);
		toFill.push_back(3);
		toFill.push_back(4);
		toFill.push_back(5);
		toFill.push_back(6);
		Span	zazou(6);
		zazou.fillSpan(toFill.begin(), toFill.end());
		zazou.print();

	} catch (std::exception &e){
	
		std::cerr << e.what() << std::endl;
	}

	try {
		bigSpanTest();
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}
