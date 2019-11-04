#pragma once
#include <iostream>
#include <cstddef>
#include "NodoT.h"

template<class T>
class TreeT 
{
public:
	NodoT<T>* root;
	NodoT<T>* left;
	NodoT<T>* right;
	NodoT<T>* son;
	NodoT<T>* papa;

	int size;

	TreeT();
	void insertn(T val); //15%
	void delet (T val);//20%
	void find(T val);/////15%
	~TreeT();
};

template <class T>
TreeT<T>::~TreeT() {
}

template <class T>
TreeT<T>::TreeT() {
	root = NULL;
	left = NULL;
	right = NULL;
	son = NULL;
	papa = NULL;
	size = 0;
}


template <class T>
void TreeT<T>::insertn(T val) {
	if (root == NULL){
		root = new NodoT<T>(val);
		size++;
	}
	else{
		root->Insert(val);
		size++;
	}
}

template <class T>
void TreeT<T>::delet(T val) {

}

template <class T>
void TreeT<T>::find(T val) {

}
