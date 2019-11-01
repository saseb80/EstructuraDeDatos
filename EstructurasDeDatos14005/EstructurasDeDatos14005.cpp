#include "pch.h"
#include <iostream>
#include <stdio.h>
#include "ListaT.h"
#include "QueueT.h"
#include "StackT.h"
#include <cstddef>

int main() {
	ListaT<char> listota;
	QueueT<int> colota;
	StackT<char> platos;
	ListaT<int> desorden;


	ListaT<int> ordenar;

	ordenar.push_back(5);
	ordenar.push_back(4);
	ordenar.push_back(3);
	ordenar.push_back(2);
	ordenar.push_back(1);
	ordenar.push_back(0);
	ordenar.print();
	std::cout << "--------I N S E R T I O N--S O R T------" << std::endl;
	ordenar.insertion();
	ordenar.print();

	return 0;
}