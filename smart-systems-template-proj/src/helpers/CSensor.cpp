#include "CSensor.h"
#include <iostream>
#include <string.h>
#include <list>
using namespace std;

//Constructors
CSensor::CSensor() {
	m_idSensor = 0;
	m_p_prediccion = new CPrediccion();
	m_p_tipo = new CTipo();
	list<CValue*> list;
	m_pl_value = list;
	m_p_localizacion = new CLocalizacion();
	cout << "Default creation" << endl;
}

CSensor::CSensor(int m_iS, CPrediccion* m_p_p, CTipo* m_p_t, list<CValue*> m_pl_v, CLocalizacion* m_p_l) {
	m_idSensor = m_iS;
	m_p_prediccion = m_p_p;
	m_p_tipo = m_p_t;
	m_pl_value = m_pl_v;
	m_p_localizacion = m_p_l;
	cout << "I have been created with idSensor = " << m_idSensor
		<< ", predicion = " << m_p_prediccion
		<< ", tipo = " << m_p_tipo
		<< " and localización = " << m_p_localizacion << endl;
}

CSensor::CSensor(const CSensor& c) {
	*this = c;
	cout << "I have been created with idSensor = " << c.m_idSensor
		<< ", predicion = " << c.m_p_prediccion
		<< ", tipo = " << c.m_p_tipo
		<< " and localización = " << c.m_p_localizacion << endl;
}

//Destructor
CSensor::~CSensor() {
	cout << "I have been created with idSensor = " << m_idSensor
		<< ", predicion = " << m_p_prediccion
		<< ", tipo = " << m_p_tipo
		<< " and localización = " << m_p_localizacion << endl;
}

//Operator<<
std::ostream& operator<<(std::ostream& o, const CSensor& c) {
	o   << "I have been created with idSensor = " << c.m_idSensor
		<< ", predicion = " << c.m_p_prediccion
		<< ", tipo = " << c.m_p_tipo
		<< " and localización = " << c.m_p_localizacion << endl;
	return o;
}

//Access functions
int CSensor::getIdTipo() const {
	return m_idSensor;
}