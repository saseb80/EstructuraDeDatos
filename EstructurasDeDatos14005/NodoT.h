#pragma once
#include "pch.h"
#include <cstddef>
#include <iostream>
template<class T>
class NodoT
{
public:
	T value;
	NodoT<T>* next;
	NodoT<T>* prev;
	int index;
	NodoT(T v) : value(v) {
		next = NULL;
		index = -1;
	}
	NodoT() {}
	~NodoT() {}
};

