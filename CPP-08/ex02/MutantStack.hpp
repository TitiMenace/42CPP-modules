
#pragma once
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator	begin(void) {
			return (this->c.begin());
		}

		iterator	end(void) {
			return (this->c.end());
		}

		MutantStack() {};
		~MutantStack() {};
		MutantStack(const MutantStack &cpy) {
			*this = cpy;
		}
		MutantStack	&operator=(const MutantStack &to_assign) {
			this->c = to_assign.c;
			return (*this);
		}

};
