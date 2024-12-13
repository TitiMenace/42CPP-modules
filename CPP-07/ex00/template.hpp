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


