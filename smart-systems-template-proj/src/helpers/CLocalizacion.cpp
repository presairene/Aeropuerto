#include "CLocalizacion.h"
#include <iostream>
#include <string.h>
using namespace std;

//Constructors
CLocalizacion::CLocalizacion() {
	m_idLocalizacion = 0;
	m_estado = "libre";
	m_tipo = "camino";
	m_coordenadasx = NULL;
	m_coordenadasy = NULL;
	//cout << "Default creation of CLocalizacion" << endl;
}
CLocalizacion::CLocalizacion(int id, std::string estado, std::string tipo, float coordenadasx, float coordenadasy) {
	m_idLocalizacion = id;
	m_estado = estado;
	m_tipo = tipo;
	m_coordenadasx = coordenadasx;
	m_coordenadasy = coordenadasy;
	//cout << "CLocalizacion creada con id_localizacion = " << m_idLocalizacion << ", estado = " << m_estado <<	", tipo = " << m_tipo << ", coordenadas = " << m_coordenadasx << "," << coordenadasy << endl;
}
/*CLocalizacion::CLocalizacion(const CLocalizacion& l) {
	m_idLocalizacion = l.m_idLocalizacion;
	m_estado = l.m_estado;
	m_tipo = l.m_tipo;
	m_coordenadasx = l.m_coordenadasx;
	m_coordenadasy = l.m_coordenadasy;
}*/
CLocalizacion::~CLocalizacion() {
	//cout << "CLocalizacion deleted with id = " << m_idLocalizacion << endl;
}
//Access functions
int CLocalizacion::getIdLocalizacion() const {
	return m_idLocalizacion;
}
string CLocalizacion::getEstado() const {
	return m_estado;
}
string CLocalizacion::getTipo() const {
	return m_tipo;
}
float CLocalizacion::getCoordenadasX() const {

	return m_coordenadasx;
}
float CLocalizacion::getCoordenadasY() const {

	return m_coordenadasy;
}



//Operator<<
ostream& operator<<(ostream& o, const CLocalizacion& c) {
	o << "idLocalizacion: " << c.m_idLocalizacion
		<< ", estado: " << c.m_estado
		<< ", tipo: " << c.m_tipo
		<< ", coordenada x: " << c.m_coordenadasx
		<< ", coordenada y: " << c.m_coordenadasy
		<< ".";
	return o;
}