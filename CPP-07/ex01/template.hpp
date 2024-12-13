#pragma once

#include <iostream>

template <typename T>
const T	& max(T const &A, T const &B){
	return (A>=B ? A : B);
}

template <typename T>
const T	& min(T const &A, T const &B){
	return (A<=B ? A : B);
}

template <typename T>
void	swap(T &A, T &B){

	T	C = B;

	B = A;
	A = C;
}

template <typename T>

void	iter(T *array, size_t len, void (*f)(const T&)){

	for(size_t	i = 0; i < len; i++)
		f(array[i]);
	return;
}


template <typename T>

void	print(T &printable)
{
	std::cout << printable << std::endl;
}
