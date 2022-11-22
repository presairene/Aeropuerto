// --------------------------------------------------------------------------
// ---------------------- CABECERA DE LA CLASE CDatabaseLab --------------------
// --------------------------------------------------------------------------
// ---------------------------------------------------------

#include <iostream>
#include <string.h>
#include "CDatabase.hpp"
#include "CLocalizacion.h"
#include "CSensor.h"
#include <CRemolque.h>
#include <CPrediccion.h>
#include <CTipo.h>
#include <CValue.h>

class CDatabaseLab4 : public CDatabase
{
public:

	CDatabaseLab4();
	~CDatabaseLab4();

	//INSERTS

	int insertLocalizacion(const CLocalizacion& c);

	int insertRemolque(const CRemolque& r);
	int insertAvion(const CAvion& a);
	int insertPrediccion(const CSensor& s, const CPrediccion& p);

	int insertSensor(const CSensor& s);
	int insertSensorBateria(const CSensor& s, const CRemolque& r);
	int insertSensorLocalizacion(const CSensor& s, const CLocalizacion& l);
	int insertTipo(const CTipo& t);
	int insertValor(const CValue& v, const CSensor& s);
	
	//OTHER
	int EnviarRemolquesCarga();
	int LeerSensorLocFINGER();
	int LeerSensorLocPISTA();
	int CambiarEstadoAvion(); 

private:

};