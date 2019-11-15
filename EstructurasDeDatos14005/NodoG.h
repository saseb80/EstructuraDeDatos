#pragma once
template<class T>
class NodoG
{
public:
	NodoG(){}
	T nodoData; // Esto guarda el objeto deseado
	Lista<NodoG*> l; // esto guarda los apuntadores a los hijos
	NodoG<T>(T dat) : nodoData(dat) {}
	~NodoG();
};

template<class T>
NodoG<T>::~NodoG() {
}
