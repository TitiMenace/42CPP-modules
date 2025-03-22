#include "easyfind.hpp"
#include <vector>

int main()
{

	try{
		std::vector<int>	list;
		list.push_back(1);
		list.push_back(2);
		list.push_back(3);
		list.push_back(4);
		list.push_back(5);
		list.push_back(6);
		list.push_back(7);
		list.push_back(8);
		list.push_back(9);
		std::vector<int>::iterator	it = easyfind(list, 2);
		std::cout << "Victory " << *it << " was found" << std::endl;
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	try{
		std::vector<int>	list;
		list.push_back(1);
		list.push_back(2);
		list.push_back(3);
		list.push_back(4);
		list.push_back(5);
		list.push_back(6);
		list.push_back(7);
		list.push_back(8);
		list.push_back(9);
		std::vector<int>::iterator	it = easyfind(list, -1);
		std::cout << "Victory " << *it << "was found" << std::endl;
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}
