#pragma once
#include"Lista.h"

template<class T>
class NodoG
{
public:
	NodoG() {};
	T nodoData; // Esto guarda el objeto deseado
	Lista<NodoG*> l; // esto guarda los apuntadores a los hijos
	NodoG<T>* papa;
	NodoG<T>(T dat);
	bool visited;
	~NodoG();
};

template<class T>
NodoG<T>::NodoG(T dat) {
	padre = nullptr;
	nodoData = dat;
	visited = false;
	Lista<NodoG<T>*> hijos;
}

template<class T>
NodoG<T>::~NodoG() {
}
