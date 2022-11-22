#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class CTipo
{
private:
	int idTipo;
	string tipo;//solo puede ser: batería, localizacion.

public:
	//Defaut Constructor
	CTipo();
	//Constructor
	CTipo(int iT, string t);
	//Constructor por copia
	CTipo(const CTipo& c);
	//Destructor
	~CTipo();

	//Access functions
	int getIdTipo() const;
	string getTipo() const;

	//Operator<<
	friend std::ostream& operator<<(std::ostream& o, const CTipo& c);
};
