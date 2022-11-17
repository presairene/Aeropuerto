#include "CTipo.h"
#include <iostream>
#include <string.h>
using namespace std;

//Constructors
CTipo::CTipo() {
	idTipo = 0;
	tipo = "NULL\0";
	cout << "Default creation" << endl;
}

CTipo::CTipo(int iT, string t) {
	idTipo = iT;
	tipo = t;
	cout << "I have been created with idVariable = " << idTipo
		<< " and description = " << tipo << endl;
}

CTipo::CTipo(const CTipo& c) {
	*this = c;
	cout << "I have been created with idVariable = " << c.idTipo
		<< " and type = " << c.tipo << endl;
}

//Destructor
CTipo::~CTipo() {
	cout << "I have been deleted with idVariable = " << idTipo
		<< " and type = " << tipo << endl;
}

//Operator<<
std::ostream& operator<<(std::ostream& o, const CTipo& c) {
	o << "idVariable: " << c.idTipo << ", with type: " << c.tipo << ".";
	return o;
}

//Access functions
int CTipo::getIdTipo() const {
	return idTipo;
}
string CTipo::getTipo() const {
	return tipo;
}