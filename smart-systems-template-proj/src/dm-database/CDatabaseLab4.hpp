// --------------------------------------------------------------------------
// ---------------------- CABECERA DE LA CLASE CDatabaseLab --------------------
// --------------------------------------------------------------------------
// ---------------------------------------------------------

#include "CDatabase.hpp"
#include "CLocalizacion.h"

class CDatabaseLab4 : public CDatabase
{
public:

	CDatabaseLab4();
	~CDatabaseLab4();

	int insertLocalizacion(const CLocalizacion& c);
	

private:

};
