#include <iostream>
#include <list>
#include <sstream>
#include <limits>
#include <cctype>

int	main(int ac, char **av){
	if (ac < 2){
		std::cerr << "Error: Not enough arguments" << std::endl;
		return __LINE__;
	}
	if (ac >= 3){
		std::cerr << "Error: Too many arguments" << std::endl;
		return __LINE__;
	}

	std::string input(av[1]);
	std::list<int> numbers;

	for (size_t i = 0; i < input.length(); i++) {
		if (i % 2 == 0) {
			if (std::isdigit(input[i])) {
				numbers.push_front(input[i] - '0');
			} 
			else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
				if (numbers.size() < 2) {
					std::cerr << "Error: Not enough numbers for operation " << input[i] << std::endl;
					return __LINE__;
				}
				int b = numbers.front(); numbers.pop_front();
				int a = numbers.front(); numbers.pop_front();
				int result = 0;
				if (input[i] == '+') {
					if (a > 0 && b > 0 && a > (std::numeric_limits<int>::max() - b)) {
						std::cerr << "Error: Addition Overflow" << std::endl;
						return __LINE__;
					}
					result = a + b;
				} 
				else if (input[i] == '-') {
					if (a < 0 && b > 0 && a < (std::numeric_limits<int>::min() + b)) {
						std::cerr << "Error: Subtraction Underflow" << std::endl;
						return __LINE__;
					}
					result = a - b;
				} 
				else if (input[i] == '*') {
					if (a != 0 && b != 0 && (a > (std::numeric_limits<int>::max() / b))) {
						std::cerr << "Error: Multiplication Overflow" << std::endl;
						return __LINE__;
					}
					result = a * b;
				} 
				else if (input[i] == '/') {
					if (b == 0) {
						std::cerr << "Error: Division by zero" << std::endl;
						return __LINE__;
					}
					if (a == std::numeric_limits<int>::min() && b == -1) { 
						std::cerr << "Error: Division Overflow" << std::endl;
						return __LINE__;
					}
					result = a / b;
				}
				numbers.push_front(result);
			} 
			else {
				std::cerr << "Error: Invalid character at position " << i << ": " << input[i] << std::endl;
				return __LINE__;
			}
		} 
		else {
			if (input[i] != ' ') {
				std::cerr << "Error: Expected space at position " << i << " but found: " << input[i] << std::endl;
				return __LINE__;
			}
		}
	}

	if (input[input.length() - 1] == ' ') {
		std::cerr << "Error: Invalid format: input should not end with a space" << std::endl;
		return __LINE__;
	}
	if (numbers.size() != 1) {
		std::cerr << "Error: Too many numbers remaining" << std::endl;
		return __LINE__;
	}
	std::cout << "Result: " << numbers.front() << std::endl;
	return 0;
}
