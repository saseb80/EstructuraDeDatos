#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <cstddef>
#include "Lista.h"
#include "NodoG.h"

int main(){
Lista<int> L;
NodoG<int> n(3);
NodoG<int> m(2876);
n.l.listaData = &m;
std::cout << n.nodoData << std::endl;
std::cout << n.l.listaData->nodoData;
}