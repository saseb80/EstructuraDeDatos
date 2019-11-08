#include "pch.h"
#include <iostream>
#include <stdio.h>
#include "ListaT.h"
#include "QueueT.h"
#include "StackT.h"
#include "TreeB.h"
#include <cstddef>

int main() {
	TreeB<int> aB;

	aB.Insert(10);
	aB.Insert(12);
	aB.Insert(6);
	aB.Insert(3);
	aB.Insert(25);
	aB.Insert(3);
	aB.Insert(8);
	aB.Insert(22);
	aB.Insert(16);
	aB.Insert(30);
	aB.Insert(23);
	aB.Find(2);
	return 0;
}