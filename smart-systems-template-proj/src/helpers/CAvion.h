#pragma once
#include <string.h>
#include <iostream>
#include "CLocalizacion.h"

class CAvion
{
private:
	int m_idAvion;
	string m_estado; /*'Aterrizado', 'Aparcado' y 'Despegar*/
	CLocalizacion* m_p_localizacion;
	int m_idRemolque;
public:
	//Defaut Constructor
	CAvion();
	//Constructor
	CAvion(int idAvion, string estado, CLocalizacion* localizacion, int idRemolque);
	CAvion(const CAvion& a); //Constructor copia. V se pasa por referencia. Si lo paso por copia se llamaría a si mismmo.
	//Destructor
	~CAvion();
	//Access functions
	int getIdAvion() const;
	string getEstado() const;
	CLocalizacion* getLocalizacion() const;
	int getIdRemolque() const;

	//Operator<<
	friend std::ostream& operator<<(std::ostream& o, const CAvion& c);
};

