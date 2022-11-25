#pragma once
#include "CLocalizacion.h"
#include <string.h>
#include <iostream>
#include "CLocalizacion.h"
#include <vector>
#include "CRemolque.h"



using namespace std;

class CRuta
{
private:
	int m_idRuta;
	vector<CLocalizacion*> m_pv_localizacion;
	CRemolque * m_p_remolque;

public:
	//Defaut Constructor

	//Constructor
	CRuta();
	CRuta(int idRuta, vector<CLocalizacion*> localizacion, CRemolque * remolque);
	CRuta(int idRuta, vector<CLocalizacion*> localizacion);
	CRuta(const CRuta& a); //Constructor copia. V se pasa por referencia. Si lo paso por copia se llamaría a si mismmo.
	//Destructor
	~CRuta();
	//Access functions
	int getIdRuta() const;
	vector <CLocalizacion*> getLocalizacion() const;
	CRemolque* getRemolqueRuta();
	friend CRemolque;
};