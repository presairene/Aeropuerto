#include "CPrediccion.h"
#include <iostream>

using namespace std;

//Constructors
CPrediccion::CPrediccion() {
	valor = 0;
	m_fecha = time(0);
	//cout << "Default creation" << endl;
}

CPrediccion::CPrediccion(float v, time_t m_f) {
	valor = v;
	m_fecha = m_f;
	//cout << "I have been created with value = " << valor
		//<< " and date = " << m_fecha << endl;
}

CPrediccion::CPrediccion(const CPrediccion& c) {
	*this = c;
	cout << "I have been created with value = " << c.valor
		<< " and date = " << c.m_fecha << endl;
}

//Destructor
CPrediccion::~CPrediccion() {
	//cout << "I have been deleted value = " << valor << " and date = " << m_fecha << endl;
}

//Functions for member access
float CPrediccion::getValor() const {
	return valor;
}

time_t CPrediccion::getFecha() const {
	return m_fecha;
}

//Operator= por referencia
void CPrediccion::operator=(const CPrediccion& c) {
	valor = c.valor;
	m_fecha = c.m_fecha;
	//cout << "Operator= por referencia" << endl;
}

//Operator<<
ostream& operator<<(ostream& o, const CPrediccion& c) {
	o << "Value: " << c.valor << ",the day: " << c.m_fecha << ".";
	return o;
}

//Operator>>
istream& operator>>(istream& is, CPrediccion& c) {
	is >> c.valor;
	is >> c.m_fecha;
	return is;
}