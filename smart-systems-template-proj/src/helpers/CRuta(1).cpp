#include "CRuta.h"
#include "CLocalizacion.h"
#include <string.h>
#include <iostream>
#include "CLocalizacion.h"
#include <vector>

using namespace std;

//Defaut Constructor
CRuta::CRuta() {
	m_idRuta = 0;
	//m_pv_localizacion = NULL;
}
//Constructor
CRuta::CRuta(int idRuta, vector<CLocalizacion*> localizacion) {
	m_idRuta = idRuta;
	m_pv_localizacion = localizacion;
}
CRuta::CRuta(const CRuta& a) {
	m_idRuta = a.m_idRuta;
	m_pv_localizacion = a.m_pv_localizacion;
}
//Destructor
CRuta::~CRuta() {
	cout << "CRuta deleted with idRuta = " << m_idRuta << endl;
}
//Access functions
int CRuta::getIdRuta() {
	return m_idRuta;
}
//Operator<<
ostream& operator<<(ostream& o, const CRuta& c) {
	o << "idRuta: " << c.m_idRuta
		<< ", localizacion: " << c.m_pv_localizacion
		<< ".";
	return o;
}

