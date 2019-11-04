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

	NodoT<T>* right;
	NodoT<T>* left;
	NodoT<T>* papa;


	int index;
	NodoT(T v) : value(v) {
		next = NULL;
		index = -1;
	}
	void Insert(T val);
	NodoT() {}
	~NodoT() {}
};

template <class T>
void NodoT<T>::Insert(T val) {

	if (left == NULL) {
		left = new NodoT<T>(val);
	}
	else if (right == NULL) {
		right = new NodoT<T>(val);
	}
	else {
		left->Insert(val);
	}
}

