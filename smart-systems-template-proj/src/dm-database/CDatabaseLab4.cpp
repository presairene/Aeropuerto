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

<<<<<<< Updated upstream

=======
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
			std::string query("SELECT L.ID_LOC AS LOCALIZACION, L.ESTADO AS ESTADO ");
			std::ostringstream os;
			os << "FROM LOCALIZACION L ";
			os << "WHERE L.TIPO LIKE 'PISTA' AND ESTADO LIKE 'OCUPADO'";
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

int CDatabaseLab4::LeerIdAvion(const int idLoc) {
	int id = 0;
	sql::ResultSet* res = NULL; sql::Statement* p_stmt = NULL;

	try {
		//This condition checks that there is a connection active
		if (m_p_con != NULL) {
			std::string query("SELECT A.ID_AVION AS ID_AVION, A.ID_LOC AS ID_LOC ");
			std::ostringstream os;
			os << "FROM AVION A ";
			os << "WHERE ID_LOC = " << idLoc;
			query += os.str();
			p_stmt = m_p_con->createStatement();
			res = p_stmt->executeQuery(query);
			if (res->next()) {
				id = res->getInt(1);
				printf("COMPROBACION %d", id);
			}
			delete res;
			delete p_stmt;
			p_stmt = NULL;
			printf("VAMOS BIEN 1 ");
		}
		else {
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
	printf("VAMOS BIEN");
	return id;
}
>>>>>>> Stashed changes
