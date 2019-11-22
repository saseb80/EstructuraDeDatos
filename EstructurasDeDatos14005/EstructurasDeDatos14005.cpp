#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <cstddef>
#include "Lista.h"
#include "Grafo.h"
#include "NodoG.h"

int main(){

	Grafo<int> perro;
	NodoG<int>* padre = new NodoG<int>(9);
	perro.padres.push_back(padre);
	//NodoG<int>* f = new NodoG<int>(5);
	//NodoG<int> padre2;
	perro.InsertaNodo(45,padre);
	perro.InsertaNodo(40,padre);
	perro.InsertaNodo(35,padre);
	padre->l.print();
	/*Lista<int> L;
	NodoG<int> n(3);
	NodoG<int> m(2876);
	n.l.listaData = &m;
	std::cout << n.nodoData << std::endl;
	std::cout << n.l.listaData->nodoData;*/
}