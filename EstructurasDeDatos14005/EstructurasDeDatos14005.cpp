#include "pch.h"
#include <iostream>
#include <stdio.h>
#include "ListaT.h"
#include "QueueT.h"
#include "StackT.h"
#include "TreeT.h"
#include <cstddef>

int main() {
	ListaT<char> listota;
	QueueT<int> colota;
	StackT<char> platos;
	ListaT<int> desorden;

	ListaT<int> ordenar;

	TreeT<int> arboloide;

	arboloide.insertn(1);
	arboloide.insertn(2);
	arboloide.insertn(3);
	arboloide.insertn(4);
	arboloide.insertn(5);
	arboloide.insertn(6);

  /*ordenar.push_back(10);
	ordenar.push_back(1);
	ordenar.push_back(4);
	ordenar.push_back(8);
	ordenar.push_back(12);
	ordenar.push_back(15);
	ordenar.push_back(2);
	ordenar.push_back(7);
	
	ordenar.print();
	std::cout << "--------I N S E R T I O N--S O R T------" << std::endl;
	ordenar.insertion();
	ordenar.print();*/

	return 0;
}