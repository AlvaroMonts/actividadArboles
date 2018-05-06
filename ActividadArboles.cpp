#include "Arbol.h"

int main () {
	cout << "----------" << endl;
	cout << "Ejercicio 1" << endl;
	Arbol a1;
	a1.rellenarArbol ("arbol.txt");
	cout << "Preorden:" << endl;
	a1.preOrden ();
	cout << "Orden central:" << endl;
	a1.ordenCentral ();
	cout << "Amplitud: " << endl;
	a1.amplitud();
	cout << "----------" << endl;
		cout << "Resultado del ejercicio 2: " << a1.sumaClavesImparesDosHijos() << endl;
	cout << "Orden central:" << endl;
	a1.ordenCentral ();
	cout << "----------" << endl;
	cout << "Ejercicio 3: " << endl;
	a1.mostrarClavesUnHijo();
	cout << "Orden central:" << endl;
	a1.ordenCentral ();
	cout << "----------" << endl;
	return 0;
}
