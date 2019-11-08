#pragma once
template <class T>
class NodoA {
public:
	NodoA<T>* padre;
	NodoA<T>* izq;
	NodoA<T>* der;
	T value;
	int prio; // prioridad
	T obj;
	int index;
	NodoA(T v) : value(v) {
		izq = nullptr;
		der = nullptr;
		//index = -1;
	}
	//void NodoA<T>::Insert(T val);
	NodoA() {}
	~NodoA() {}
};



//template <class T>
//void NodoA<T>::Insert(T val) {
//
//	if (izq == NULL) {
//		izq = new NodoT<T>(val);
//	}
//	else if (der == NULL) {
//		der = new NodoT<T>(val);
//	}
//	else {
//		izq->Insert(val);
//	}
//}