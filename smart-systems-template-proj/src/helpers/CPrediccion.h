#pragma once
#include <time.h>
#include <iostream>


class CPrediccion {
private:
	float valor;
	time_t m_fecha;

public:
	//Defaut Constructor
	CPrediccion();
	//Constructor
	CPrediccion(float v, time_t m_f);
	//Constructor por copia
	CPrediccion(const CPrediccion& c);
	//Destructor
	~CPrediccion();

	//Access functions
	float getValor() const;
	time_t getFecha() const;

	//Operator= por referencia
	void operator=(const CPrediccion& c);

	//Operator<<
	friend std::ostream& operator<<(std::ostream& o, const CPrediccion& c);

	//Operator>>
	friend std::istream& operator>>(std::istream& is, CPrediccion& c);
};
