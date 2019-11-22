#pragma once
#include "NodoT.h"
#include <iostream>

template<class T>
class Lista
{
public:
	Lista();	
	NodoT<T>* first;
	NodoT<T>* last;
	NodoT<T>* tmp;
	NodoT<T>* tmp2;
	int size;
	void push_back(T val);
	void push_front(T val);
	void push_at(T val, int index);
	void updateIndex();
	void printG();
	//NodoG<T>* get_at(int index);
	void delete_at(int index);
	/*bool search(int val);*/
	void print();
	~Lista();
};

template<class T>
Lista<T>::Lista() {
	first = NULL;
	last = NULL;
	size = 0;
}

template<class T>
Lista<T>::~Lista() {
}

template<class T>
void Lista<T>::push_back(T val) {
	if (first == NULL) { // la lista está completamente vacía
			first = new NodoT<T>(val);
			last = first; // el primero y el último son el mismo
			first->index = 0;
			size++;
	}
	else {
		if (first == last) { // sólo hay un elemento en la lista
				last = new NodoT<T>(val); // last ahora es diferente
				first->next = last; // el siguiente de first ahora es el nuevo nodo
				first->index = 0;
				first->next->index = 1;
				size++;
		}
		else { // hay 2 o más elementos en la lista
				last->next = new NodoT<T>(val); // last->next era null, ahora es un nodo
				last->next->index = last->index + 1;
				last = last->next; // last ahora es el nodo nuevo
				size++;
		}
	}
	//Actualiza los index asi bien chulos
	updateIndex();
}

template<class T>
void Lista<T>::push_front(T val){
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
	//Actualiza los index asi bien chulos
	updateIndex();
}

template<class T>
void Lista<T>::push_at(T val, int index) {
	if (first == NULL) {
		first = new NodoT<T>(val);
		last = first;
		first->index = 0;
		size++;
	}
	else {
		if (index == 0 && first != NULL) {
			tmp = first;
			first = new NodoT<T>(val);
			first->next = tmp;
			size++;
		}
		if (index >= last->index && first != NULL) {
			last->next = new NodoT<T>(val);
			NodoT<T>* it = first; // se crea un "iterador"
			updateIndex();
			size++;
		}
		if (index != first->index && index != last->index) {
			int contador = 0;
			NodoT<T>* it = first; // se crea un "iterador"
			while (it != NULL) { // si el iterador no es nulo...	
				contador = contador + 1;
				if (contador == index) {
					tmp = it->next;
					it->next = new NodoT<T>(val);
					it->next->next = tmp;
				}
				it = it->next;
			}
			size++;
		}
	}
	updateIndex();
}

template<class T>
void Lista<T>::delete_at(int index) {
	if (first == NULL) {
		std::cout << "No puedes eliminar, porque la lista esta vacia" << std::endl;
	}
	else {
		if (index == 0 && first != NULL) {
			first = first->next;
			size--;
		}
		if (index >= last->index) {
			last = NULL;
		}

		if (index != first->index && index != last->index) {
			int contador = 0;
			NodoT<T>* it = first; // se crea un "iterador"
			while (it != NULL) { // si el iterador no es nulo...	
				contador = contador + 1;
				if (contador == index) {
					it->next = it->next->next;
				}
				it = it->next;
			}
		}
		updateIndex();
	}
}

template<class T>
void Lista<T>::updateIndex() {
	NodoT<T>* itr = first;
	int n = -1;
	while (itr != NULL) {
		n = n + 1;
		itr->index = n;
		itr = itr->next;
	}
}

template <class T>
void Lista<T>::print() {
	NodoT<T>* it = first;
	while (it != NULL) {
		std::cout << it->value << "----->" << it->index << std::endl;
		it = it->next;
	}
}


//template<class T>
//NodoG<T>* Lista<T>::get_at(int index){
//	NodoG<T>* it = first; // se crea un "iterador"
//	while (it != NULL) { // si el iterador no es nulo...
//		it = it->next;
//		if (it->index == index) {
//			return it;
//		}
//	}
//	return it;
//}