#include "CDatabaseLab4.hpp"
#include "../helpers/CLocalizacion.h"
#include"../helpers/CRemolque.h"
#include "../helpers/CRuta.h"
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
int CDatabaseLab4::insertRemolque(CRemolque& r) {
	bool result = false;

	try {
		//This condition checks that there is a connection active
		if (m_p_con != NULL) {
			std::string query("INSERT INTO REMOLQUE (ID_REMOLQUE, ESTADO, ID_LOC)  VALUES (");
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
			std::string query("INSERT INTO AVION (ID_AVION, ESTADO, ID_REMOLQUE, ID_LOC)  VALUES (");
			std::ostringstream os;

			os << a.getIdAvion() << ", '" << a.getEstado() << "' , NULL," << a.getLocalizacion()->getIdLocalizacion() << ")";
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
			
			os << "FROM_UNIXTIME(" << p.getFecha() << " ), "  << p.getValor() << " , " << s.getIdSensor() << " )";
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
int CDatabaseLab4::insertSensorBateria(const CSensor& s, CRemolque& r) {
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


//------------------------------------------------------------------------------ OTHER FUNCTIONS ----------------------------

//Funciones del apartado PISTA
//LeerSensorLocPISTA()  funciona porque solo hay una pista, si se quieren leer varias pistas habría que modificarlo
int CDatabaseLab4::LeerSensorLocPISTA() {
	int loc = -1;
	sql::ResultSet* res = NULL; sql::Statement* p_stmt = NULL;

	try {

		//This condition checks that there is a connectioSn active
		if (m_p_con != NULL) {
			std::string query("SELECT ID_LOC FROM LOCALIZACION ");
			std::ostringstream os;
			os << "WHERE TIPO LIKE 'Pista' ";
			os << "AND ESTADO LIKE 'Ocupado' ";
			query += os.str();
			p_stmt = m_p_con->createStatement();
			res = p_stmt->executeQuery(query);
			if (res->next()) {
				loc = res->getInt(1);
			}
			delete res;
			delete p_stmt;
			p_stmt = NULL;
		}
		else {
			printf("ERROR m_p_con = NULL -> db is not connected ");
		}
	}
	catch (sql::SQLException& e) {
		if (res != NULL) delete res;
		if (p_stmt != NULL) delete p_stmt;
		std::ostringstream os;
		os << "ERROR:" << e.what();
		_log.println(boost::log::trivial::error, os.str());
		return -1;
	}
	return loc;
}
int CDatabaseLab4::LeerIdAvion(const int idLoc) {
	int id = -1;
	sql::ResultSet* res = NULL; sql::Statement* p_stmt = NULL;

	try {

		//This condition checks that there is a connection active
		if (m_p_con != NULL) {
			std::string query("SELECT ID_AVION FROM AVION ");
			std::ostringstream os;
			os << "WHERE ID_LOC = " << idLoc;
			query += os.str();
			p_stmt = m_p_con->createStatement();
			res = p_stmt->executeQuery(query);
			if (res->next()) {
				id = res->getInt(1);
			}
			delete res;
			delete p_stmt;
			p_stmt = NULL;
		}
		else {
			printf("ERROR m_p_con = NULL -> db is not connected ");
		}
	}
	catch (sql::SQLException& e) {
		if (res != NULL) delete res;
		if (p_stmt != NULL) delete p_stmt;
		std::ostringstream os;
		os << "ERROR:" << e.what();
		_log.println(boost::log::trivial::error, os.str());
		return -1;
	}
	return id;
}
int CDatabaseLab4::EliminarAvion(const int idAv) {
	bool result = false;
	try {

		//This condition checks that there is a connection active
		if (m_p_con != NULL) {
			std::string query("DELETE FROM AVION ");
			std::ostringstream os;
			os << "WHERE ID_AVION = " << idAv;
			query += os.str();
			result = EjecutaQuery(query);
			cout <<"He mandado la query"<<endl;
		}
		else {
		}
	}
	catch (sql::SQLException& e) {
		std::ostringstream os;
		os << "ERROR:" << e.what();
		_log.println(boost::log::trivial::error, os.str());
		result = false;

	}
	return result;
}
//Update estado de la localizacion
int CDatabaseLab4::UpdateLocalizacion(const int idLoc, string cadena) {
	bool result = false;
	try {

		//This condition checks that there is a connection active
		if (m_p_con != NULL) {
			std::string query("UPDATE LOCALIZACION ");
			std::ostringstream os;
			os << "SET ESTADO = '" << cadena << "' ";
			os << "WHERE ID_LOC = " << idLoc;
			query += os.str();
			result = EjecutaQuery(query);
		}
		else {
		}
	}
	catch (sql::SQLException& e) {
		std::ostringstream os;
		os << "ERROR:" << e.what();
		_log.println(boost::log::trivial::error, os.str());
		result = false;

	}
	return result;
}

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
int CDatabaseLab4::insertRuta( CRuta& Ru) {

	bool result = false;

	try {
		//This condition checks that there is a connection active
		if (m_p_con != NULL) {
			std::string query("INSERT INTO RUTA (ID_RUTA, ID_REMOLQUE)  VALUES (");
			std::ostringstream os;

			os << Ru.getIdRuta() << "," << (Ru.getRemolqueRuta())->getIdRemolque() << ")";
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
			for (i = 0; i < l; i++) {
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

//Funciones del apartado BATERIAS
//LeerSensorBateria()  funciona porque solo hay una pista, si se quieren leer varias pistas habría que modificarlo
int CDatabaseLab4::LeerSensorPredBateria() {
	int idRemolque = -1;
	sql::ResultSet* res = NULL; sql::Statement* p_stmt = NULL;

	try {

		//This condition checks that there is a connectioSn active
		if (m_p_con != NULL) {
			std::string query("Select T.id_remolque from (SELECT r.ID_REMOLQUE, p.valor_pred FROM prediccion as p, sensor_bateria as s, remolque as r WHERE p.ID_SENSOR = s.ID_SENSOR AND  r.ID_REMOLQUE = s.ID_REMOLQUE  AND r.ID_LOC = '0' ORDER BY P.FECHA_PRED ASC LIMIT 1) As T WHERE T.VALOR_PRED = '0'");
			std::ostringstream os;
			query += os.str();
			p_stmt = m_p_con->createStatement();
			res = p_stmt->executeQuery(query);
			if (res->next()) {
				idRemolque = res->getInt(1);
			}
			delete res;
			delete p_stmt;
			p_stmt = NULL;
		}
		else {
			printf("ERROR m_p_con = NULL -> db is not connected ");
		}
	}
	catch (sql::SQLException& e) {
		if (res != NULL) delete res;
		if (p_stmt != NULL) delete p_stmt;
		std::ostringstream os;
		os << "ERROR:" << e.what();
		_log.println(boost::log::trivial::error, os.str());
		return -1;
	}
	return idRemolque;
}
//Update la ruta que hace el remolque
int CDatabaseLab4::UpdateRutaRemolque(const int idRem, const int idRuta) {
	bool result = false;
	try {

		//This condition checks that there is a connection active
		if (m_p_con != NULL) {
			std::string query("update ruta set id_remolque = ");
			std::ostringstream os;
			os << idRem << " where id_ruta = " << idRuta << "";
			query += os.str();
			cout << query;
			result = EjecutaQuery(query);

		}
		else {
		}
	}
	catch (sql::SQLException& e) {
		std::ostringstream os;
		os << "ERROR:" << e.what();
		_log.println(boost::log::trivial::error, os.str());
		result = false;

	}
	return result;
}

//Update el estado del remolque
int CDatabaseLab4::UpdateEstadoRemolque(const int idRem) {
	bool result = false;
	try {

		//This condition checks that there is a connection active
		if (m_p_con != NULL) {
			std::string query("UPDATE remolque SET ESTADO = 'Ocupado' ");
			std::ostringstream os;

			os << "WHERE ID_REMOLQUE = " << idRem <<"";
			query += os.str();
			cout << query;
			result = EjecutaQuery(query);

		}
		else {
		}
	}
	catch (sql::SQLException& e) {
		std::ostringstream os;
		os << "ERROR:" << e.what();
		_log.println(boost::log::trivial::error, os.str());
		result = false;

	}
	return result;
}
//Update el localizacion del remolque
int CDatabaseLab4::UpdateLocRemolque(const int idRem, const int idLoc) {
	bool result = false;
	try {

		//This condition checks that there is a connection active
		if (m_p_con != NULL) {
			std::string query("UPDATE remolque SET ID_LOC = ");
			std::ostringstream os;

			os << idLoc;
			os << " WHERE ID_REMOLQUE = " << idRem;
			query += os.str();
			cout << query;
			result = EjecutaQuery(query);

		}
		else {
		}
	}
	catch (sql::SQLException& e) {
		std::ostringstream os;
		os << "ERROR:" << e.what();
		_log.println(boost::log::trivial::error, os.str());
		result = false;

	}
	return result;
}