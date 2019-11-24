#pragma once
#include "Lista.h"
template<class T>
class NodoG
{
public:
	NodoG();
	T nodoData; // Esto guarda el objeto deseado
	Lista<NodoG<T>*> l; // esto guarda los apuntadores a los hijos
	NodoG<T>* next;
	NodoG<T>* papa;
	NodoG<T>(T dat);
	bool visited;
	~NodoG();
};

template<class T>
NodoG<T>::NodoG() {
	l;
}

template<class T>
NodoG<T>::NodoG(T dat) {
	next = nullptr;
	papa = nullptr;
	nodoData = dat;
	visited = false;
}

template<class T>
NodoG<T>::~NodoG() {
}
