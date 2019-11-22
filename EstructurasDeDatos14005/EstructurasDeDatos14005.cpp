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
	NodoG<int>* padre2 = new NodoG<int>(10);
	NodoG<int>* padre3 = new NodoG<int>(11);
	perro.padres.push_back(padre);
	perro.padres.push_back(padre2);
	perro.padres.push_back(padre3);
	//NodoG<int>* f = new NodoG<int>(5);
	//NodoG<int> padre2;
	perro.InsertaNodo(45,padre);
	perro.InsertaNodo(40,padre);
	perro.InsertaNodo(35,padre);
	perro.InsertaNodo(36,padre);
	perro.InsertaNodo(37,padre);
	perro.InsertaNodo(38,padre);
	perro.InsertaNodo(5, padre2);
	perro.InsertaNodo(4, padre2);
	perro.InsertaNodo(3, padre2);
	perro.ImprimeGrafo();
	std::cout << perro.padres.size<<std::endl;
	std::cout << padre->l.size<<std::endl;
	std::cout << padre2->l.size<<std::endl;
	padre->l.print();

	//padre->l.print();
	/*Lista<int> L;
	NodoG<int> n(3);
	NodoG<int> m(2876);
	n.l.listaData = &m;
	std::cout << n.nodoData << std::endl;
	std::cout << n.l.listaData->nodoData;*/
}