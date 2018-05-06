/*
 * Arbol.h
 *
 *  Created on: 21/12/2014
 *      Author: pmartin
 */
#include <iostream>
using namespace std;

#ifndef NODOARBOL_H_
#define NODOARBOL_H_

class NodoArbol {
public:
	int clave;
	NodoArbol *iz, *de;

	NodoArbol () {
		clave = 0;
		iz = de = NULL;
	}
	NodoArbol (int elemento) {
		clave = elemento;
		iz = de = NULL;
	}
};

#endif /* NODOARBOL_H_ */


#ifndef ARBOL_H_
#define ARBOL_H_


typedef NodoArbol *pNodoArbol;

class Arbol {
	//Variables miembro
private:
	pNodoArbol raiz;
public:

	Arbol ();
	Arbol (int dato);
	~Arbol ();

	void preOrden ();
	void ordenCentral ();
	void postOrden ();
	void amplitud ();

	void insertar (int x);
	void eliminar (int x);

	void rellenarArbol (string f);
	int sumaClavesImparesDosHijos ();
	void mostrarClavesUnHijo ();
};

#endif /* ARBOL_H_ */
