#include "CValue.h"
#include <iostream>

using namespace std;

//Constructors
CValue::CValue() {
	valor = 0;
	fecha = time(0);
	cout << "Default creation" << endl;
}

CValue::CValue(float v, time_t f) {
	valor = v;
	fecha = f;
	cout << "I have been created with value = " << valor
		<< " and date = " << fecha << endl;
}

CValue::CValue(const CValue& c) {
	*this = c;
	cout << "I have been created with value = " << c.valor
		<< " and date = " << c.fecha << endl;
}

//Destructor
CValue::~CValue() {
	cout << "I have been deleted value = " << valor
		<< " and date = " << fecha << endl;
}

//Functions for member access
float CValue::getValor() const {
	return valor;
}

time_t CValue::getFecha() const{
	return fecha;
}

//Operator= por referencia
void CValue::operator=(const CValue& c) {
	valor = c.valor;
	fecha = c.fecha;
	cout << "Operator= por referencia" << endl;
}

//Operator<<
ostream& operator<<(ostream& o, const CValue& c) {
	o << "Value: " << c.valor << ",the day: " << c.fecha << ".";
	return o;
}

//Operator>>
istream& operator>>(istream& is, CValue& c) {
	is >> c.valor;
	is >> c.fecha;
	return is;
}

//Operator+=
void CValue::operator+=(const CValue& c) {
	valor = valor + c.valor;
	cout << "Operator+= por referencia" << endl;
}

//Operator+ un solo valor enviado
CValue CValue::operator+(const CValue& c) {
	CValue t = *this;
	t += c; //Guardamos la fecha del de la izq
	cout << "Operator+ por referencia" << endl;
	return t;
}

CValue operator+(const CValue& c1, const CValue& c2) {
	CValue t;
	t.valor = c1.valor + c2.valor;
	t.fecha = c1.fecha + c2.fecha;
	cout << "Operator+ friend" << endl;
	return t;
}