#include "CDatabaseLab4.hpp"
#include "../helpers/CLocalizacion.h"
#include"../helpers/CRemolque.h"
#include "../helpers/CSensor.h"


//Constructor and destructor of the object
CDatabaseLab4::CDatabaseLab4()
{

}

CDatabaseLab4::~CDatabaseLab4()
{

}

// ----------------- INSERTS -----------------

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
int CDatabaseLab4::insertRemolque(const CRemolque& r) {
	bool result = false;

	try {
		//This condition checks that there is a connection active
		if (m_p_con != NULL) {
			std::string query("INSERT INTO REMOLQUE (ID_REMOLQUE, ESTADO, LOCALIZACION_ID_LOC)  VALUES (");
			std::ostringstream os;

			os << r.getIdRemolque() << ", '" << r.getEstado() << "' ," << r.getLocalizacion()->getIdLocalizacion() <<")";
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
int CDatabaseLab4::insertAvion(const CAvion& a) {
	bool result = false;

	try {
		//This condition checks that there is a connection active
		if (m_p_con != NULL) {
			std::string query("INSERT INTO AVION (ID_AVION, ESTADO,ID_REMOLQUE, ID_LOC)  VALUES (");
			std::ostringstream os;

			os << a.getIdAvion() << ", '" << a.getEstado() << "' ," << a.getIdRemolque() << "," << a.getLocalizacion()->getIdLocalizacion() << ")";
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
int CDatabaseLab4::insertSensor(const CSensor& s) {
	bool result = false;

	try {
		//This condition checks that there is a connection active
		if (m_p_con != NULL) {
			std::string query("INSERT INTO SENSOR (ID_SENSOR, TIPO)  VALUES (");
			std::ostringstream os;

			os << s.getIdSensor() << ", '" << s.getTipo()  <<  "' )";
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
int CDatabaseLab4::insertPrediccion(const CSensor& s, const CPrediccion& p) {
	bool result = false;

	try {
		//This condition checks that there is a connection active
		if (m_p_con != NULL) {
			std::string query("INSERT INTO PREDICCION (FECHA_PRED, VALOR_PRED, ID_SENSOR)  VALUES (");
			std::ostringstream os;

			os << p.getFecha() << "," << p.getValor() << " , " << s.getIdSensor()<<" )";
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
