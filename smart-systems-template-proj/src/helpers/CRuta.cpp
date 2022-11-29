#pragma once
#include "CRuta.h"
#include "CLocalizacion.h"
#include "CRemolque.h"
#include <string.h>
#include <iostream>
#include <vector>


using namespace std;

CRuta::CRuta() {
	m_idRuta = 0;
}

//Constructor
CRuta::CRuta(int idRuta, vector<CLocalizacion*> localizacion, CRemolque* remolque) {
	m_idRuta = idRuta;
	m_pv_localizacion = localizacion;
	m_p_remolque = remolque;
}
//CRuta::CRuta(int idRuta, vector<CLocalizacion*> localizacion) {
//	m_idRuta = idRuta;
//	m_pv_localizacion = localizacion;
//
//	m_p_remolque = new CRemolque();
//}

CRuta::CRuta(const CRuta& a) {
	m_idRuta = a.m_idRuta;
	m_pv_localizacion = a.m_pv_localizacion;
	m_p_remolque = a.m_p_remolque;
}
//Destructor
CRuta::~CRuta() {
	//cout << "CRuta deleted with idRuta = " << m_idRuta << endl;
}
//Access functions
int CRuta::getIdRuta() const{
	return m_idRuta;
}

vector <CLocalizacion*> CRuta::getLocalizacion() const {

	return m_pv_localizacion;
}

CRemolque* CRuta::getRemolqueRuta(){
	return m_p_remolque;
}

