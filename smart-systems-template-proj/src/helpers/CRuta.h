#include "CLocalizacion.h"
#include <string.h>
#include <iostream>
#include "CLocalizacion.h"
#include <vector>

using namespace std;
class CRuta{
private:
	int m_idRuta;
	vector<CLocalizacion*> m_pv_localizacion;

public:
	//Defaut Constructor
	CRuta();
	//Constructor
	CRuta(int idRuta, vector<CLocalizacion*> localizacion);
	CRuta(const CRuta& a); //Constructor copia. V se pasa por referencia. Si lo paso por copia se llamaría a si mismmo.
	//Destructor
	~CRuta();
	//Access functions
	int getIdRuta();

	//Operator<<
	friend std::ostream& operator<<(std::ostream& o, const CRuta& c);
};

