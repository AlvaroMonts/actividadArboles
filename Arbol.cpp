/*
 * Arbol.cpp
 *
 *  Created on: 21/12/2014
 *      Author: pmartin
 */

#include "Arbol.h"
#include <fstream>
#include <queue>

Arbol::Arbol() {
	raiz = NULL;
}
Arbol::Arbol(int dato) {
	raiz = new NodoArbol(dato);
}
void destruir(pNodoArbol &nodo) {
	if (nodo != NULL) {
		destruir(nodo->iz);
		destruir(nodo->de);
		delete nodo;
		nodo = NULL;
	}
}
Arbol::~Arbol() {
	pNodoArbol nodo = raiz;
	destruir(nodo);
	raiz = NULL;
}

void auxPreOrden(pNodoArbol nodo) {
	if (nodo != NULL) {
		cout << nodo->clave << " "; 	// Nodo
		auxPreOrden(nodo->iz);	 		// Izquierda
		auxPreOrden(nodo->de);			// Derecha
	}
}

void Arbol::preOrden() {
	auxPreOrden(raiz);
	cout << "FIN" << endl;
}

void auxOrdenCentral(pNodoArbol nodo) {
	if (nodo != NULL) {
		auxOrdenCentral(nodo->iz);	 	// Izquierda
		cout << nodo->clave << " "; 	// Nodo
		auxOrdenCentral(nodo->de);		// Derecha
	}
}

void Arbol::ordenCentral() {
	auxOrdenCentral(raiz);
	cout << "FIN" << endl;
}

void auxPostOrden(pNodoArbol nodo) {
	if (nodo != NULL) {
		auxPostOrden(nodo->iz);	 	// Izquierda
		auxPostOrden(nodo->de);		// Derecha
		cout << nodo->clave << " "; 	// Nodo
	}
}

void Arbol::postOrden() {
	auxPostOrden(raiz);
	cout << "FIN" << endl;
}

void Arbol::amplitud() {
	pNodoArbol p;
	queue<pNodoArbol> c;

	p = raiz;
	if (p != NULL)
		c.push(p);
	while (!c.empty()) {
		p = c.front();
		c.pop();
		cout << p->clave << " ";
		if (p->iz != NULL)
			c.push(p->iz);
		if (p->de != NULL)
			c.push(p->de);
	}
	cout << "FIN" << endl;
}

void inserta(pNodoArbol &nodo, int valor) {

	if (nodo == NULL)
		nodo = new NodoArbol(valor);
	else if (valor != nodo->clave) {
		if (valor < nodo->clave)
			inserta(nodo->iz, valor);
		else
			inserta(nodo->de, valor);
	} else
		cout << "Error, la clave ya existe" << endl;
}

void Arbol::insertar(int x) {
	inserta(raiz, x);
}
void quitarSucesor(pNodoArbol nodoQuitar, pNodoArbol &sucesor) {
	pNodoArbol hijo;

	if (sucesor->de == NULL) {
		hijo = sucesor->iz;
		nodoQuitar->clave = sucesor->clave;
		delete sucesor;
		sucesor = hijo;
	} else
		quitarSucesor(nodoQuitar, sucesor->de);
}

void elimina(pNodoArbol &nodo, int valor) {
	pNodoArbol hijo;

	if (nodo != NULL) {
		if (valor == nodo->clave)
			if ((nodo->iz == NULL) || (nodo->de == NULL)) {
				if (nodo->iz == NULL)
					hijo = nodo->de;
				else
					hijo = nodo->iz;
				delete nodo;
				nodo = hijo;
			} else
				quitarSucesor(nodo, nodo->iz);
		else if (valor < nodo->clave)
			elimina(nodo->iz, valor);
		else
			elimina(nodo->de, valor);
	} else
		cout << "la clave buscada no existe" << endl;
}

void Arbol::eliminar(int x) {
	elimina(raiz, x);
}

void Arbol::rellenarArbol(string f) {
	// COMPLETAR
	ifstream fichero;
	int num;
	fichero.open(f.c_str());
	if (!fichero.is_open())
		cout << "No se ha podido abrir el fichero" << endl;
	else
		while (fichero >> num)
			insertar(num);
	fichero.close();
}

int Arbol::sumaClavesImparesDosHijos() {
	int resul = 0;
	// COMPLETAR
	/*
	 FUNCIONA PERO HACERLO SIN ELIMINAR NADA DE LA LISTA
	 pNodoArbol nodoRaiz = raiz;
	 while (nodoRaiz != NULL) {
	 if (nodoRaiz->clave % 2 == 1) {
	 resul += nodoRaiz->clave;
	 }

	 if ((nodoRaiz->iz == NULL) || (nodoRaiz->de == NULL)) {
	 if (nodoRaiz->iz == NULL)
	 nodoRaiz = nodoRaiz->de;
	 else
	 nodoRaiz = nodoRaiz->iz;
	 } else if (nodoRaiz->iz != NULL) {
	 quitarSucesor(nodoRaiz, nodoRaiz->iz);
	 } else if (nodoRaiz->de != NULL) {
	 quitarSucesor(nodoRaiz, nodoRaiz->de);
	 }
	 }
	 */
	return resul; // 307
}

void Arbol::mostrarClavesUnHijo() {
	// COMPLETAR
	string resul = "";
	pNodoArbol nodoRaiz = raiz;
	while (nodoRaiz != NULL) {

		if ((nodoRaiz->iz == NULL) || (nodoRaiz->de == NULL)) {
			if (nodoRaiz->iz == NULL)
				nodoRaiz = nodoRaiz->de;
			else
				nodoRaiz = nodoRaiz->iz;
		} else if (nodoRaiz->iz != NULL) {
			quitarSucesor(nodoRaiz, nodoRaiz->iz);
		} else if (nodoRaiz->de != NULL) {
			quitarSucesor(nodoRaiz, nodoRaiz->de);
		}
	}

	cout << resul << endl;
}

/*

 50
 25
 75
 15
 40
 60
 90
 13
 21
 32
 45
 58
 64
 11
 14
 43
 59
 10

 */
