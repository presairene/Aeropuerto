#pragma once
#include <iostream>
#include <string.h>
#include <list>
#include "CSensor.h"
#include "CAvion.h"
#include "CLocalizacion.h"
#include "CRuta.h"

using namespace std;


class CRemolque
{
private:
	int m_idRemolque;
	string m_estado; /*'Libre', 'Ocupado' y 'Cargando'*/
	list<CSensor*> m_pl_sensores;
	CAvion* m_p_avion;
	CLocalizacion* m_p_localizacion;
	

public:
	//Defaut Constructor
	CRemolque();
	//Constructor
	CRemolque(int id, string estado, list <CSensor*> sensores, CAvion* avion,  CLocalizacion* localizacion);
	//CRemolque(const CRemolque& r);
	//Destructor
	~CRemolque();
	//Access functions
	int getIdRemolque() const;
	string getEstado() const;
	list<CSensor*> getSensores() const;
	CAvion* getAvion() const;
	CLocalizacion* getLocalizacion() const;

	//Operator<<
	//friend std::ostream& operator<<(std::ostream& o, const CRemolque& c);
	
};

