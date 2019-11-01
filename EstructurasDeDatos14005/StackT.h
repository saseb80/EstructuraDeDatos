#pragma once
#include "NodoT.h"
#include <cstddef>
#include <iostream>

template<class T>
class StackT {

public:
	NodoT<T>* first;
	NodoT<T>* last;
	NodoT<T>* tmp;
	int size;

	StackT();
	void pop();
	T top();
	void push(T val);
	void print();
	int sizeu();
	bool empty();
	void updateIndex();

	~StackT();
};

template<class T>
StackT<T>::StackT() {
	first = NULL;
	last = NULL;
	size = 0;
}

template<class T>
StackT<T>::~StackT() {
}

template<class T>
void StackT<T>::pop() {
	first = first->next;
}

template<class T>
void StackT<T>::push(T val) {
	if (first == NULL) { // la lista está completamente vacía
		first = new NodoT<T>(val);
		last = first; // el primero y el último son el mismo
		size++;
	}
	else {
		if (first == last) { // sólo hay un elemento en la lista
			tmp = first;
			first = new NodoT<T>(val); // last ahora es diferente
			first->next = last; // el siguiente de first ahora es el nuevo nodo
			first->index = 0;
			last->index = 1;
			size++;
		}
		else { // hay 2 o más elementos en la lista
			tmp = first;
			first = new NodoT<T>(val); // last->next era null, ahora es un nodo
			first->next = tmp; // last ahora es el nodo nuevo					
			first->index = -1;
			NodoT<T>* it = first; // se crea un "iterador"
			while (it != NULL) { // si el iterador no es nulo...		
				it->index += 1;// se actualiza el iterador por el siguiente nodo en la lista
				it = it->next;
				// si it->next es null, entonces it será null, y se detendrá el While.
			}
			size++;
		}
	}
	/*NodoT<T>* itr = first;
	int n = -1;
	while (itr != NULL) {
		n = n + 1;
		itr->index = n;
		itr = itr->next;
	}*/
	updateIndex();
}

template <class T>
T StackT<T>::top() {
	return last->value;
}

template<class T>
bool StackT<T>::empty() {
	if (first == NULL) {
		return true;
	}
	return false;
}

template <class T>
int StackT<T>::sizeu() {
	return size;
	updateIndex();
}

template <class T>
void StackT<T>::print() {
	NodoT<T>* it = first;
	while (it != NULL) {
		std::cout << it->value << std::endl;
		it = it->next;
	}
}

template <class T>
void StackT<T>::updateIndex() {
	NodoT<T>* itr = first;
	int n = -1;
	while (itr != NULL) {
		n = n + 1;
		itr->index = n;
		itr = itr->next;
	}
}

