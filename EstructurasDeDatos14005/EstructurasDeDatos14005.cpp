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
	std::cout << "--------B U R B U J A----E N----P R O C E S O--------" << std::endl;
	ordenar.burbuja();
	ordenar.print();

	/*colota.push(1);
	colota.push(2);
	colota.push(3);
	colota.push(4);
	colota.push(5);
	colota.push(6);
	colota.push(7);
	colota.push(8);
	colota.print();
	std::cout << "--------" << std::endl;
	colota.pop();
	colota.print();*/

	//colota.print();

	//platos.push('a');
	//platos.push('b');
	//platos.push('c');
	//platos.push('d');
	//platos.push('e');
	//platos.push('f');
	//platos.push('g');
	//platos.print();
	//std::cout << "--------"<<std::endl;
	//platos.pop();
	//platos.print();
	//std::cout << "--------" << std::endl;
	//platos.pop();
	//platos.print();
	//std::cout << "--------" << std::endl;
	//platos.pop();
	//platos.print();


	/*colota.push(1);
	colota.push(2);
	colota.push(3);
	colota.push(4);
	colota.push(5);
	colota.push(6);
	colota.print();
	colota.pop();
	colota.print();*/


	/*listota.push_back('a');
	listota.push_back('b');
	listota.push_back('c');
	listota.push_back('d');
	listota.push_back('e');
	listota.push_back('f');
	listota.push_back('g');
	listota.push_back('h');
	listota.push_at('r', 6);
	listota.delete_at(6);
	listota.get_at(5);
	listota.print();*/



	return 0;
}