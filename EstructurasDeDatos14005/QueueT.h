#pragma once
#include "NodoT.h"
#include <cstddef>
#include <iostream>

template<class T>
class QueueT {

public:
	NodoT<T>* first;
	NodoT<T>* last;
	NodoT<T>* tmp;
	int size;

	QueueT();
	void pop();
	T front();
	T back();
	void push(T val);
	void print();
	int sizeu();
	void swap(QueueT q);
	bool empty();
	void updateIndex();

	~QueueT();
};

template<class T>
QueueT<T>::QueueT() {
	first = NULL;
	last = NULL;
	size = 0;
}

template<class T>
QueueT<T>::~QueueT() {
}

template<class T>
void QueueT<T>::pop() {
	first = first->next;
	updateIndex();
}

template<class T>
void QueueT<T>::push(T val) {
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

template <class T>
T QueueT<T>::front() {
	return first->value;
}

template <class T>
T QueueT<T>::back() {
	return last->value;
}

template<class T>
bool QueueT<T>::empty() {
	if (first == NULL) {
		return true;
	}
	return false;
}

template <class T>
int QueueT<T>::sizeu() {
	return size;
	updateIndex();
}

template<class T>
void QueueT<T>::swap(QueueT<T> q) {
	NodoT<T>* it = first;
	while (it != NULL) {
		q.push(it->value);
		it = it->next;
	}
}

template <class T>
void QueueT<T>::print() {
	NodoT<T>* it = first;
	while (it != NULL) {
		std::cout << it->value << std::endl;
		it = it->next;
	}
}

template <class T>
void QueueT<T>::updateIndex() {
	NodoT<T>* itr = first;
	int n = -1;
	while (itr != NULL) {
		n = n + 1;
		itr->index = n;
		itr = itr->next;
	}
}
