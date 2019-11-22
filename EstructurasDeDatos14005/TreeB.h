#pragma once
#include "NodoA.h"

template <class T>
class TreeB {
public:
	NodoA<T>* root;
	NodoA<T>* padre;
	NodoA<T>* last;					// es recomendable guardar un apuntador hacia el 'ultimo nodo insertado
	NodoA<T>* tmp;

	
	//bool isInserted;
	
	TreeB();
	~TreeB();

	void Insert(T val);				//30% debes colocar el nodo donde va, según las reglas antes definidas

	void DeleteT(T val);				//30% re-acomoda los nodos hijos del nodo eliminado, según su prioridad

	bool Find(T val);			//30% hay dos formas de encontrar nodos, por profundidad y por amplitud

	void Print();					//30% imprime los nodos de manera que se entienda el orden del árbol.
};

template <class T>
TreeB<T>::TreeB(){
	root = nullptr;
	padre = nullptr;
}

template <class T>
TreeB<T>::~TreeB() {
}

template <class T>
void TreeB<T>::Insert(T val) {
	if (root == nullptr) {
		root = new NodoA<T>(val);
	}
	else if (root != nullptr) {
		NodoA<T>* it = root;
		bool isInserted = false;
		if (val <= it->value) {
			if (it->izq == nullptr) {
				//NodoA<T>* tmp(val);				
				it->izq = new NodoA<T>(val);				
			}
			else {
				while (isInserted != true) {
					if (val <= it->value) {
						if (it->izq == nullptr) {
							it->izq = new NodoA<T>(val);
							isInserted = true;
						}
						else {
							it = it->izq;
						}
					}
					else if(val>it->value){
						if (it->der == nullptr) {
							it->der = new NodoA<T>(val);
							isInserted = true;
						}
						else {
							it = it->der;
						}						
					}
				}
			}
		}
		else if (val > it->value) {
			if (it->der == nullptr) {
				it->der = new NodoA<T>(val);
			}
			else {
				while (isInserted != true) {
					if (val <= it->value) {
						if (it->izq == nullptr) {
							it->izq = new NodoA<T>(val);
							isInserted = true;
						}
						else {
							it = it->izq;
						}
					}
					else if (val > it->value) {
						if (it->der == nullptr) {
							it->der = new NodoA<T>(val);
							isInserted = true;
						}
						else {
							it = it->der;
						}
					}
				}
			}
		}
	}
}


template <class T>
bool TreeB<T>::Find(T val) {
	NodoA<T>* it = root;
	bool encontrado = false;
	while (encontrado != true) {
		if (it->izq != nullptr) {
			if (val == it->value) {
				encontrado = true;
				return true;
			}
			else if (val < it->value) {
				it = it->izq;
			}
			else if (val > it->value) {
				it = it->der;
			}
		}
		else {
			return false;
		}
	}
	return false;
}

template <class T>
void TreeB<T>::Print() {

}

template <class T>
void TreeB<T>::DeleteT(T val) {

}






