#include "CDatabaseLab4.hpp"


//Constructor and destructor of the object
CDatabaseLab4::CDatabaseLab4()
{

}

CDatabaseLab4::~CDatabaseLab4()
{

}

// ----------------- INSERT EXAMPLE -----------------

int CDatabaseLab4::insertLocalizacion(const CLocalizacion& loc) {

	bool result = false;

	try {
		//This condition checks that there is a connection active
		if (m_p_con != NULL) {
			std::string query("INSERT INTO LOCALIZACION (ID_LOC, ESTADO, TIPO, COORDENADAS_X, COORDENADAS_Y)  VALUES (");
			std::ostringstream os;

			os << loc.getIdLocalizacion() << ", '" << loc.getEstado() << "' , '" << loc.getTipo() << "' ," << loc.getCoordenadasX() << "," << loc.getCoordenadasY() << ")";
			query += os.str();
			result = EjecutaQuery(query);

		}
		else {
		}
	}
	catch (sql::SQLException& e) {
		std::ostringstream os; os << "ERROR:" << e.what(); _log.println(boost::log::trivial::error, os.str());
		result = false;
	}

	return result;
}


