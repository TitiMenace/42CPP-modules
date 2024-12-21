#pragma once

#include <iostream>

template<typename T>
class Array
{
	private:
		T*		_array;
		int		_size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& copy);
		~Array();
		Array& operator=(const Array& type);
		T& operator[](int index);
		int size() const;
	class OutOfLimitsException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Index out of limits");
			}
	};
};

template<typename T>
Array<T>::Array() : _array(new T[0]), _size(0) {}
template<typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {}
template<typename T>
Array<T>::Array(const Array& copy) : _array(new T[copy._size]), _size(copy._size)
{
	for (int i = 0; i < copy.size() && i < _size; i++)
		_array[i] = copy._array[i];
}
template<typename T>
Array<T>::~Array() { delete[] _array; }
template<typename T>
Array<T>& Array<T>::operator=(const Array& type)
{
	if (this == &type)
		return (*this);
	delete[] _array;
	_array = new T[type._size];
	_size = type._size;
	for (int i = 0; i < type.size(); i++)
		_array[i] = type._array[i];
	return (*this);
}
template<typename T>
T& Array<T>::operator[](int index)
{
	if (index < 0 || index >= _size)
		throw Array<T>::OutOfLimitsException();
	return (_array[index]);
}
template<typename T>
int Array<T>::size() const { return (_size); }




