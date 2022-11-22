#include "CRemolque.h"
#include <iostream>
#include <string.h>
#include <vector>
#include <list>

#include "CAvion.h"
#include "CLocalizacion.h"
#include "CRuta.h"

using namespace std;

//Constructors
CRemolque::CRemolque() {
	m_idRemolque = 0;
	m_estado = "libre";
	cout << "Default creation" << endl;

}

CRemolque::CRemolque(int id, string estado, list <CSensor*> sensores, CAvion* avion, CRuta* ruta, CLocalizacion* localizacion)
{
	m_idRemolque = id;
	m_estado = estado;
	m_pl_sensores = sensores;
	m_p_avion = avion;
	m_p_ruta = ruta;
	m_p_localizacion = localizacion;
	cout << "I have been created with id_remolque = " << id << " and stage = " << estado << endl;
}
//
//CRemolque::CRemolque(const CRemolque& r) {
//	*this = r;
//	
//	cout << "I have been created by copy of(" << *this << endl;
//}

//Destructor
CRemolque::~CRemolque(){
	cout << "I have been deleted id_remolque = " << m_idRemolque << " and stage= " << m_estado << endl;
}

//Functions for member access
int CRemolque::getIdRemolque() const {
	return m_idRemolque;
}

string CRemolque::getEstado() const{
	return m_estado;
}

list<CSensor*> CRemolque::getSensores() {
	return m_pl_sensores;
}
CAvion* CRemolque::getAvion() {
	return m_p_avion;

}
CRuta* CRemolque::getRuta() {
	return m_p_ruta;

}
CLocalizacion* CRemolque::getLocalizacion() const {
	return m_p_localizacion;
}
////Operator<<
//ostream& operator<<(ostream& o, const CRemolque& c) {
//	o << "idRemolque: " << c.m_idRemolque
//		<< ", estado: " << c.m_estado
//		<< ", sensores: " << for(i=0,size(c.m_pl_sensores), i++) c.si
//		<< ", avion: " << c.m_p_avion
//		<< ", ruta: " << c.m_pl_ruta
//		<< ", localizacion: " << c.m_p_localizacion
//		<< ".";
//	auto it = m_pl_sensores.begin();
//	for(int i = 0; i < )
//
//
//	return o;
//}
