#pragma once
#include "NodoT.h"
#include <cstddef>
#include <iostream>

template<class T>
class ListaT
{
public:
	NodoT<T>* first;
	NodoT<T>* last;
	NodoT<T>* tmp;
	NodoT<T>* tmp2;
	int size;
	ListaT();
	void push_back(T val);
	void push_front(T val);//10%
	void push_at(T val, int index); //10%
	NodoT<T>* get_at(int index);
	void delete_at(int index); //10%
	bool search(int val);//10%
	void burbuja();//10%
	void print();
	void updateIndex();
	~ListaT();
};

template<class T>
ListaT<T>::ListaT() {
	first = NULL;
	last = NULL;
	size = 0;
}

template<class T>
ListaT<T>::~ListaT() {
}

template<class T>
void ListaT<T>::push_back(T val) {
	if (first == NULL) { // la lista est� completamente vac�a
		first = new NodoT<T>(val);
		last = first; // el primero y el �ltimo son el mismo
		first->index = 0;
		size++;
	}
	else {
		if (first == last) { // s�lo hay un elemento en la lista
			last = new NodoT<T>(val); // last ahora es diferente
			first->next = last; // el siguiente de first ahora es el nuevo nodo
			first->index = 0;
			first->next->index = 1;
			size++;
		}
		else { // hay 2 o m�s elementos en la lista
			last->next = new NodoT<T>(val); // last->next era null, ahora es un nodo
			last->next->index = last->index + 1;
			last = last->next; // last ahora es el nodo nuevo
			size++;
		}
	}
	//Actualiza los index asi bien chulos
	NodoT<T>* itr = first;
	int n = -1;
	while (itr != NULL) {
		n = n + 1;
		itr->index = n;
		itr = itr->next;
	}
}

template<class T>
void ListaT<T>::push_front(T val) {
	if (first == NULL) { // la lista est� completamente vac�a
		first = new NodoT<T>(val);
		last = first; // el primero y el �ltimo son el mismo
		size++;
	}
	else {
		if (first == last) { // s�lo hay un elemento en la lista
			tmp = first;
			first = new NodoT<T>(val); // last ahora es diferente
			first->next = last; // el siguiente de first ahora es el nuevo nodo
			first->index = 0;
			last->index = 1;
			size++;
		}
		else { // hay 2 o m�s elementos en la lista
			tmp = first;
			first = new NodoT<T>(val); // last->next era null, ahora es un nodo
			first->next = tmp; // last ahora es el nodo nuevo					
			first->index = -1;
			NodoT<T>* it = first; // se crea un "iterador"
			while (it != NULL) { // si el iterador no es nulo...		
				it->index += 1;// se actualiza el iterador por el siguiente nodo en la lista
				it = it->next;
				// si it->next es null, entonces it ser� null, y se detendr� el While.
			}
			size++;
		}
	}
	//Actualiza los index asi bien chulos
	NodoT<T>* itr = first;
	int n = -1;
	while (itr != NULL) {
		n = n + 1;
		itr->index = n;
		itr = itr->next;
	}
}

template<class T>
void ListaT<T>::push_at(T val, int index) {
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
			//while (it != NULL) { // si el iterador no es nulo...		
			//	it->index += 1;// se actualiza el iterador por el siguiente nodo en la lista
			//	it = it->next;
			//	// si it->next es null, entonces it ser� null, y se detendr� el While.
			//}
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
	//Acomoda los indices asi bien chidos xd
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
void ListaT<T>::delete_at(int index) {
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
void ListaT<T>::burbuja() {

	if (size > 0) {
		NodoT<T> *behind = nullptr, *ahead, *it;
		bool swap = true;
		while (swap) {
			it = first;
			swap = false;
			while (it->next != NULL) {
				if (it == first) {
					if (it->value > it->next->value) {
						first = it->next;
						ahead = it->next->next;
						it->next->next = it;
						it->next = ahead;
						it = first;
						swap = true;
					}
					behind = it;
					it = it->next;
				}
				else if (it->value > it->next->value) {
					ahead = it->next->next;
					behind->next = it->next;
					it->next->next = it;
					it->next = ahead;
					behind = behind->next;
					swap = true;
				}
				else {
					behind = it;
					it = it->next;
				}
			}
		}
	}
	updateIndex();

	//NodoT<T> *it = first;
	//NodoT<T> *it2 = first->next;
	//while (it != NULL) {
	//	
	//	
	//	 if (it->next->value <= it->value) {
	//		tmp = it->next;
	//		it->next = it->next->next;
	//		tmp->next = it;		
	//		/*it->next = it2->next;
	//		it2->next = it;
	//		tmp = it->next;
	//		tmp2 = it2->next;
	//		it = tmp2;
	//		it2 = tmp;*/
	//	}
	//		it = it->next;
	//}
}

template<class T>
NodoT<T>* ListaT<T>::get_at(int index) {
	NodoT<T>* it = first; // se crea un "iterador"
	while (it != NULL) { // si el iterador no es nulo...
		it = it->next;
		if (it->index == index) {
			return it;
		}
	}
	return it;
}

template <class T>
void ListaT<T>::print() {
	NodoT<T>* it = first;
	while (it != NULL) {
		std::cout << it->value << "----->" << it->index << std::endl;
		it = it->next;
	}
}

template<class T>
bool ListaT<T>::search(int val) {
	NodoT<T>* it = first; // se crea un "iterador"
	while (it != NULL) { // si el iterador no es nulo...
		if (it->value == val) return true;
		it = it->next;
	}
	return false;
}

template<class T>
void ListaT<T>::updateIndex() {
	NodoT<T>* itr = first;
	int n = -1;
	while (itr != NULL) {
		n = n + 1;
		itr->index = n;
		itr = itr->next;
	}
}

