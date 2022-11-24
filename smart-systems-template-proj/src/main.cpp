#include "boost/date_time/posix_time/posix_time.hpp"
#include "boost/date_time/gregorian/gregorian.hpp"

#include "CLog.hpp"
#include "CLogListenerConsole.hpp"
#include "CLogListenerFile.hpp"
#include "CSingleton.hpp"
#include "CError.h"
#include <CRemolque.h>
#include <CAvion.h>
#include <CSensor.h>
#include <CLocalizacion.h>
#include <CRuta.h>
#include <CTipo.h>
#include <CValue.h>
#include <CPrediccion.h>
#include <CTime.h>

//DDBB
#include "CDatabase.hpp"
#include "CDatabaseLab4.hpp"

#define CONFIG_PATH "config"
#define LOGS_PROPERTIES_FILE "logs.ini"

#define SCHEMA_NAME "mydb"
#define HOST_NAME "127.0.0.1:3306"
#define USER_NAME "root"
#define PASSWORD_USER "mysql"

#define TIME_SCAN_CYCLE_S 900 //15 min

using namespace std;

int main(void){

	CDatabaseLab4 dbObject;
	int opcion;
	
	try {

		CError::ReservaPool();

		//  ---------------------------- INIT RESOURCES  ---------------------------- 

		//Configure logs
		CLog log("log");
		if (!log.initializeParametersFromIniFile(CONFIG_PATH, LOGS_PROPERTIES_FILE)) {
			std::cout << "ERROR reading database log in file: " << CONFIG_PATH << "/" << LOGS_PROPERTIES_FILE << std::endl;
			return 0;
		}
		log.println(boost::log::trivial::fatal, "Log initialized");

		CError::LiberaPool();

		uint64_t lastExecution = 0;

		//---------------------------------VARIABLES DE PRUEBA----------------------------
		//Listas
		list<CValue*> listValue;
		list<CValue*>::iterator ilistValue;
		CTime fec1 = CTime(2022, 11, 24, 15, 43, 00);


		CTipo Tip1 = CTipo(1, "bateria");
		CTipo Tip2 = CTipo(2, "localizacion");




		CValue Val1 = CValue(23.5, fec1.getDate());
		listValue.push_back(&Val1);
		ilistValue = listValue.begin();
		CPrediccion Pre1 = CPrediccion(7, fec1.getDate());
		CLocalizacion Loc1 = CLocalizacion(4, "Lib", "Const", 985, 589);
		CSensor Sen1 = CSensor(1, &Pre1, &Tip1, listValue, &Loc1);

		CRemolque Rem1 = CRemolque();
		CPrediccion Pre1 = CPrediccion(23.5, fec1.getDate());

		list<CSensor*> listSensor;
		list<CSensor*>::iterator ilistSensor;
		CAvion Avi1 = CAvion(390, "espera", &Loc1);

		vector<CLocalizacion*> VectorLoc1;
		VectorLoc1.push_back(&Loc1);
		CRuta Rut1 = CRuta(21, VectorLoc1);
		CRemolque Rem1 = CRemolque(200, "libre", listSensor, &Avi1, &Rut1, &Loc1);









		//  ---------------------------- START SCAN CYCLE ---------------------------- 
		while (1) {
			boost::posix_time::ptime execTime = boost::posix_time::second_clock::local_time();

			if ((helpers::CTimeUtils::seconds_from_epoch(execTime) - lastExecution) >= TIME_SCAN_CYCLE_S) {

				//The content of this if should go in a execute function of the object which will contain the intelligence module
				log.println(boost::log::trivial::trace, "Starting intelligence execution cycle");
				log.println(boost::log::trivial::trace, "Starting intelligence execution cycle");

				log.println(boost::log::trivial::trace, "Starting intelligence execution cycle");

				log.println(boost::log::trivial::trace, "Starting intelligence execution cycle");

				log.println(boost::log::trivial::trace, "Starting intelligence execution cycle");


				// ---------------------------- GET DATA FROM DB  ---------------------------- 

				//DDBB connection
				/*
				dbObject.Conectar(SCHEMA_NAME, HOST_NAME, USER_NAME, PASSWORD_USER);
				log.println(boost::log::trivial::trace, "Hemos conectado con la DB para hacer getters de info");

				//Do stuff with DB: GET DATA
				//EXAMPLE:
				std::string prosumer1MPAN;
				dbObject.getProsumerMPAN(1, prosumer1MPAN);


				dbObject.Desconectar();
				*/
				// ---------------------------- PROCESS OF DATA & INTELLIGENCE ---------------------------- 





				// ---------------------------- INSERT RESULTS IN db  ---------------------------- 

				//DDBB connection
				dbObject.Conectar(SCHEMA_NAME, HOST_NAME, USER_NAME, PASSWORD_USER);
				log.println(boost::log::trivial::trace, "Hemos conectado con la DB para hacer inserts de info");

				//Insert stuff in DB
				dbObject.ComienzaTransaccion();

				//Do insert of data 
//EXAMPLE:

//--------------------------------------Insert localizacion --------------------------------------------
				bool resultInsert = true;
				resultInsert = resultInsert && dbObject.insertLocalizacion(Loc1);

				if (resultInsert) {
					log.println(boost::log::trivial::trace, "Data insert OK");
					dbObject.ConfirmarTransaccion();
				}
				else {
					log.println(boost::log::trivial::trace, "Data insert ERROR");
					dbObject.DeshacerTransaccion();
				}

				//--------------------------------------Insert Remolque --------------------------------------------

				resultInsert = true;
				resultInsert = resultInsert && dbObject.insertRemolque(Rem1);
				if (resultInsert) {
					log.println(boost::log::trivial::trace, "Data insert OK Valores");
					dbObject.ConfirmarTransaccion();
				}
				else {
					log.println(boost::log::trivial::trace, "Data insert ERROR Valores");
					dbObject.DeshacerTransaccion();
				}

				// -------------------------------------- - Insert tipo----------------------------------------------

				resultInsert = true;
				resultInsert = resultInsert && dbObject.insertTipo(Tip1);
				if (resultInsert) {
					log.println(boost::log::trivial::trace, "Data insert OK Tipo");
					dbObject.ConfirmarTransaccion();
				}
				else {
					log.println(boost::log::trivial::trace, "Data insert ERROR Tipo");
					dbObject.DeshacerTransaccion();
				}

				//--------------------------------------Insert sensores --------------------------------------------

				resultInsert = true;
				resultInsert = resultInsert && dbObject.insertSensor(Sen1);

				if (resultInsert) {
					log.println(boost::log::trivial::trace, "Data insert OK Valores");
					dbObject.ConfirmarTransaccion();
				}
				else {
					log.println(boost::log::trivial::trace, "Data insert ERROR Valores");
					dbObject.DeshacerTransaccion();
				}
				//--------------------------------------Insert valores --------------------------------------------

				resultInsert = true;
				resultInsert = resultInsert && dbObject.insertValor(Val1, Sen1);

				if (resultInsert) {
					log.println(boost::log::trivial::trace, "Data insert OK Valores");
					dbObject.ConfirmarTransaccion();
				}
				else {
					log.println(boost::log::trivial::trace, "Data insert ERROR Valores");
					dbObject.DeshacerTransaccion();
				}


				//--------------------------------------Insert Sensor Localizaci�n y Bateria--------------------------------------------
				if (Sen1.getTipo()->getIdTipo() == 2) {
					resultInsert = true;
					resultInsert = resultInsert && dbObject.insertSensorLocalizacion(Sen1, Loc1);

					if (resultInsert) {
						log.println(boost::log::trivial::trace, "Data insert OK Valores");
						dbObject.ConfirmarTransaccion();
					}
					else {
						log.println(boost::log::trivial::trace, "Data insert ERROR Valores");
						dbObject.DeshacerTransaccion();
					}
				}
				else if (Sen1.getTipo()->getIdTipo() == 1) {
					resultInsert = true;
					resultInsert = resultInsert && dbObject.insertSensorBateria(Sen1, Rem1);

					if (resultInsert) {
						log.println(boost::log::trivial::trace, "Data insert OK Valores");
						dbObject.ConfirmarTransaccion();
					}
					else {
						log.println(boost::log::trivial::trace, "Data insert ERROR Valores");
						dbObject.DeshacerTransaccion();
					}
				}
				//--------------------------------------Insert predicion --------------------------------------------

				resultInsert = true;
				resultInsert = resultInsert && dbObject.insertPrediccion(Sen1, Pre1);

				if (resultInsert) {
					log.println(boost::log::trivial::trace, "Data insert OK Valores");
					dbObject.ConfirmarTransaccion();
				}
				else {
					log.println(boost::log::trivial::trace, "Data insert ERROR Valores");
					dbObject.DeshacerTransaccion();
				}

				//--------------------------------------Insert ruta --------------------------------------------

				resultInsert = true;
				resultInsert = resultInsert && dbObject.insertRuta(Rem1);

				if (resultInsert) {
					log.println(boost::log::trivial::trace, "Data insert OK Valores");
					dbObject.ConfirmarTransaccion();
				}
				else {
					log.println(boost::log::trivial::trace, "Data insert ERROR Valores");
					dbObject.DeshacerTransaccion();
				}

				//--------------------------------------Insert Avion --------------------------------------------

				resultInsert = true;
				resultInsert = resultInsert && dbObject.insertAvion(Avi1);
				if (resultInsert) {
					log.println(boost::log::trivial::trace, "Data insert OK Valores");
					dbObject.ConfirmarTransaccion();
				}
				else {
					log.println(boost::log::trivial::trace, "Data insert ERROR Valores");
					dbObject.DeshacerTransaccion();
				}
				//--------------------------------------Insert Localizacion - Ruta --------------------------------------------

				resultInsert = true;
				resultInsert = resultInsert && dbObject.insertLocalizacionRuta(Rut1);
				if (resultInsert) {
					log.println(boost::log::trivial::trace, "Data insert OK Valores");
					dbObject.ConfirmarTransaccion();
				}
				else {
					log.println(boost::log::trivial::trace, "Data insert ERROR Valores");
					//--------------------------------------Insert Remolque --------------------------------------------
					resultInsert = true;
					resultInsert = resultInsert && dbObject.insertSensorLocalizacion(Sen1, Loc1);

					if (resultInsert) {
						log.println(boost::log::trivial::trace, "Data insert OK Sensor-Localizacion");
						dbObject.ConfirmarTransaccion();
					}
					else {
						log.println(boost::log::trivial::trace, "Data insert ERROR Sensor-Localizacion");

						dbObject.DeshacerTransaccion();
					}

					dbObject.Desconectar();

					lastExecution = helpers::CTimeUtils::seconds_from_epoch(execTime);

				}









				//_____________________________________MENU__________________________________________

				printf("BIENVENIDO AL SISTEMA INTELIGENTE DE AEROPUERTOS\n\n");
				printf("Opci�n 1:\n");
				printf("Opci�n 2:\n");
				printf("Opci�n 3:\n");
				printf("Seleccione la opcion que desea:\n");
				scanf("%d", &opcion);

				switch (opcion) {
				case 1:
					opcion = 0; //Cambiar esto por lo que se quiera hacer en esta opcion
					break;

				case 2:
					opcion = 0;  //Cambiar esto por lo que se quiera hacer en esta opcion
					break;

				default:
					opcion = 0;  //Cambiar esto por lo que se quiera hacer en esta opcion
				}
			}

		}
	}
	catch (std::exception &e) {
		//Always close connections in case of error
		dbObject.Desconectar();

		CErrorEnFuncion ef("main(void)");
		std::ostringstream os; 
		os << "ERROR:" << e.what(); 
		std::cout << os.str() << std::endl;
		THROW_ERROR(e, ef);
		return (0);
	}
	return 0;
}

