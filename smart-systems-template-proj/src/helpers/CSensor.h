#pragma once
#include <iostream>
#include <string.h>
#include <list>
#include <CPrediccion.h>
#include <CTipo.h>
#include <CValue.h>
#include <CLocalizacion.h>
using namespace std;

class CSensor
{
private:
	int m_idSensor;
	CPrediccion* m_p_prediccion;
	CTipo* m_p_tipo;
	list<CValue*> m_pl_value;
	CLocalizacion* m_p_localizacion;

public:
	//Defaut Constructor
	CSensor();
	//Constructor
	CSensor(int m_iS, CPrediccion* m_p_p, CTipo* m_p_t, list<CValue*> m_pl_v, CLocalizacion* m_p_l);
	//Constructor por copia
	CSensor(const CSensor& c);
	//Destructor
	~CSensor();

	//Access functions
	int getIdSensor() const;
	CTipo* getTipo() const;
	//Operator<<
	friend std::ostream& operator<<(std::ostream& o, const CSensor& c);
};

