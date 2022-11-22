#include "CAvion.h"
#include <string.h>
#include <iostream>
#include "CLocalizacion.h"

using namespace std;

//Constructors
CAvion::CAvion() {
	m_idAvion = 0;
	m_estado = "libre";
	m_p_localizacion = NULL;
	m_idRemolque = 0;
	cout << "Default creation" << endl;
}

CAvion::CAvion(int idAvion, string estado, CLocalizacion* localizacion, int idRemolque) {
	m_idAvion = idAvion;
	m_estado = estado;
	m_p_localizacion = localizacion;
	m_idRemolque = idRemolque;
	cout << "I have been created with id_avion: "<<m_idAvion<< " stage = " << m_estado << " and loc: "<<m_p_localizacion->getIdLocalizacion()<< endl;
}

CAvion::CAvion(const CAvion& a) {
	m_idAvion = a.m_idAvion;
	m_estado = a.m_estado;
	m_p_localizacion = a.m_p_localizacion;
	m_idRemolque = a.m_idRemolque;
	cout << "I have been created by copy of(" << a.m_idAvion << "," << a.m_estado << "," << m_p_localizacion->getIdLocalizacion() << ")" << endl;
}

//Destructor
CAvion::~CAvion() {
	cout << "I have been deleted id_avion:"<< m_idAvion << "stage= "<< m_estado << "and id_loc:"<< m_p_localizacion->getIdLocalizacion() << endl;
}

//Functions for member access
int CAvion::getIdAvion() const {
	return m_idAvion;
}

string CAvion::getEstado() const{
	return m_estado;
}
CLocalizacion* CAvion::getLocalizacion() const{
	return m_p_localizacion;
}
int CAvion::getIdRemolque() const{
	return m_idRemolque;
}

//Operator<<
ostream& operator<<(ostream& o, const CAvion& c) {
	o << "idAvion: " << c.m_idAvion
		<< ", estado: " << c.m_estado
		<< ", localizacion: "<< c.m_p_localizacion 
		<< ", idRemolque: " << c.m_idRemolque
		<< ".";
	return o;
}
