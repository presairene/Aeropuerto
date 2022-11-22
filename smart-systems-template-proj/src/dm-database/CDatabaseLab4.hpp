// --------------------------------------------------------------------------
// ---------------------- CABECERA DE LA CLASE CDatabaseLab --------------------
// --------------------------------------------------------------------------
// ---------------------------------------------------------

#include "CDatabase.hpp"
#include "CLocalizacion.h"
#include "CSensor.h"
#include <CRemolque.h>
#include <CPrediccion.h>

class CDatabaseLab4 : public CDatabase
{
public:

	CDatabaseLab4();
	~CDatabaseLab4();

	int insertLocalizacion(const CLocalizacion& c);
	int insertRemolque(const CRemolque& r);
	int insertAvion(const CAvion& a);
	int insertSensor(const CSensor& s);
	int insertPrediccion(const CSensor& s, const CPrediccion& p);
private:

};