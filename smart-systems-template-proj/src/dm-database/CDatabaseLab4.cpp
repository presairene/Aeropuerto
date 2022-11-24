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

			os << a.getIdAvion() << ", '" << a.getEstado() << "' ," << NULL << "," << a.getLocalizacion()->getIdLocalizacion() << ")";
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
			std::string query("INSERT INTO SENSOR (ID_SENSOR, ID_TIPO)  VALUES (");
			std::ostringstream os;

			os << s.getIdSensor() << ", " << s.getTipo()->getIdTipo() <<  " )";
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
			
			os << " FROM_UNIXTIME(" << p.getFecha() << ", '%Y-%m-%d %H:%i:%s' ), " << "," << p.getValor() << " , " << s.getIdSensor()<<" )";
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
int CDatabaseLab4::insertSensorBateria(const CSensor& s, const CRemolque& r) {
	bool result = false;

	try {
		//This condition checks that there is a connection active
		if (m_p_con != NULL) {
			std::string query("INSERT INTO SENSOR_BATERIA (ID_SENSOR, ID_REMOLQUE)  VALUES (");
			std::ostringstream os;

			os << s.getIdSensor() << "," << r.getIdRemolque() << " )";
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
int CDatabaseLab4::insertSensorLocalizacion(const CSensor& s, const CLocalizacion& l) {
	bool result = false;

	try {
		//This condition checks that there is a connection active
		if (m_p_con != NULL) {
			std::string query("INSERT INTO SENSOR_LOCALIZACION (ID_SENSOR, ID_LOC)  VALUES (");
			std::ostringstream os;

			os << s.getIdSensor() << "," << l.getIdLocalizacion() << " )";
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
int CDatabaseLab4::insertTipo(const CTipo& t) {
	bool result = false;

	try {
		//This condition checks that there is a connection active
		if (m_p_con != NULL) {
			std::string query("INSERT INTO TIPO (ID_TIPO, DESC_TIPO)  VALUES (");
			std::ostringstream os;
			
			os << t.getIdTipo() << ", '" << t.getTipo() << "' )";
			query += os.str();
			result = EjecutaQuery(query);

		}
		else {
		}
	}
	catch (sql::SQLException& e) {
		std::ostringstream os; 
		os << "ERROR:" << e.what(); _log.println(boost::log::trivial::error, os.str());
		result = false;
	}

	return result;
}
int CDatabaseLab4::insertValor(const CValue& v, const CSensor& s) {
	bool result = false;

	try {
		//This condition checks that there is a connection active
		if (m_p_con != NULL) {
			std::string query("INSERT INTO VALOR (FECHA, VALOR, ID_SENSOR)  VALUES (");
			std::ostringstream os;

			os << "FROM_UNIXTIME(" << v.getFecha() << "), " << v.getValor() << " ," << s.getIdSensor() << " )";
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


//--------------- OTHER FUNCTIONS ----------------------------
int CDatabaseLab4::EnviarRemolquesCarga(){
	bool result = false;

	try {
		//This condition checks that there is a connection active
		if (m_p_con != NULL) {
			std::string query("SELECT S.ID_SENSOR AS SENSOR, P.VALOR AS PREDICION_BATERÍA, V.VALOR AS VALOR_BATERIA, S_L.ID_LOC AS LOCALIZACION");
			std::ostringstream os;
			os << "FROM PREDICCION P, SENSOR_BATERIA SB, SENSOR S, VALOR V, SENSOR_LOCALIZACION S_L";
			os << "WHERE P.ID_SENSOR = SB.ID_SENSOR";
			os << "AND SB.ID_SENSOR = S.ID_SENSOR";
			os << "AND S.ID_SENSOR = V.ID_SENSOR";
			os << "AND S.ID_SENSOR = S_L.ID_SENSOR";
			os << "AND P.FECHA = ''";
			os << "AND(P.VALOR < 0.10 OR V.VALOR < 0.10)";
			

		
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
int CDatabaseLab4::LeerSensorLocFINGER() {
	bool result = false;

	try {
		//This condition checks that there is a connection active
		if (m_p_con != NULL) {
			std::string query("SELECT L.ID_LOC AS LOCALIZACION, L.ESTADO AS ESTADO");
			std::ostringstream os;
			os << "FROM LOCALIZACION L";
			os << "WHERE L.TIPO LIKE 'FINGER'";

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
int CDatabaseLab4::LeerSensorLocPISTA() {
	bool result = false;

	try {
		//This condition checks that there is a connection active
		if (m_p_con != NULL) {
			std::string query("SELECT L.ID_LOC AS LOCALIZACION, L.ESTADO AS ESTADO");
			std::ostringstream os;
			os << "FROM LOCALIZACION L";
			os << "WHERE L.TIPO LIKE 'PISTA'";

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
int CDatabaseLab4::CambiarEstadoAvion() {
	bool result = false;

	try {
		//This condition checks that there is a connection active
		if (m_p_con != NULL) {
			std::string query("UPDATE AVION SET ESTADO = 'escribir aquí el estado'");
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

int CDatabaseLab4::insertRuta(const CRemolque& Re) {

	bool result = false;

	try {
		//This condition checks that there is a connection active
		if (m_p_con != NULL) {
			std::string query("INSERT INTO RUTA (ID_RUTA, ID_REMOLQUE)  VALUES (");
			std::ostringstream os;

			os << Re.getRuta()->getIdRuta() << "," << Re.getIdRemolque() << ")";
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
int CDatabaseLab4::insertLocalizacionRuta(const CRuta& Ru) {
	int l;
	int i;
	bool result = false;

	try {
		//This condition checks that there is a connection active
		if (m_p_con != NULL) {
			l = Ru.getLocalizacion().size();
			for (i = 0; i <= l; i++) {
				std::string query("INSERT INTO LOCALIZACION_RUTA (ID_RUTA, ORDEN, ID_LOC)  VALUES (");
				std::ostringstream os;

				os << Ru.getIdRuta() << "," << i << "," << Ru.getLocalizacion()[i]->getIdLocalizacion() << ")";
				query += os.str();
				result = EjecutaQuery(query);
			}

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