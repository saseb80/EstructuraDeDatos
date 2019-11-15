#include "NodoG.h"

template <class T>
class Grafo {
public:
	
	Grafo();

	void InsertaNodo(T data, NodoG* padre); // 25% inserta un nodo agregando el apuntador a la lista de hijos del padre

	NodoG<T>* BuscaNodo(T data); // 25% busca un nodo por su data y regresa el apuntador al nodo si es que lo encuentra

	void EliminaNodo(T data); // 25% busca un nodo por su data, y lo elimina, asegurándose que sus hijos son agregados a otro nodo

	void ImprimeGrafo(); // 25% imprime el grafo de la siguiente manera: Padre1{hijo1, hijo2, hijo3,..., hijoN

	~Grafo();
};

template<class T>
Grafo<T>::Grafo() {
}

template<class T>
void Grafo<T>::InsertaNodo(T data, NodoG<T>* padre){
	NodoG<T>* n;
	if (padre == nullptr) {
		n = new NodoG<T>(data);
	}
	else if (padre != nullptr) {
		padre = n;
		n->l.push_back(new NodoG<T>(val));
	}

}

template<class T>
Grafo<T>::~Grafo() {

}


template<class T>
void Grafo<T>::InsertaNodo(T data, NodoG<T>* padre) {

}

template<class T>
NodoG<T>* Grafo<T>::BuscaNodo(T data) {

}

template<class T>
void Grafo<T>::EliminaNodo(T data) {

}

template<class T>
void Grafo<T>::ImprimeGrafo() {

}