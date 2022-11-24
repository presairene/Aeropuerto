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
		CLocalizacion LocPr1 = CLocalizacion(6, "Lib", "Const", 985, 589);
		
		
		

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

				//Do inserts of data
				bool resultInsert = true;

				//Do insert of data 
				//EXAMPLE:
				//Listas
				list<CValue*> listValue;
				list<CValue*>::iterator ilistValue;

				CTime fec1 = CTime();
				CLocalizacion Loc1 = CLocalizacion(3, "Lib", "Const", 985, 589);

				CTipo Tip1 = CTipo(2, "bateria");
				resultInsert = resultInsert && dbObject.insertTipo(Tip1);

				CValue Val1 = CValue(23.5, fec1.getDate());
				listValue.push_back(&Val1);
				ilistValue = listValue.begin();

				CPrediccion Pre1 = CPrediccion(7, fec1.getDate());
				CSensor Sen1 = CSensor(1,&Pre1, &Tip1, listValue, &Loc1);
				resultInsert = resultInsert && dbObject.insertValor(Val1, Sen1);
				
				
				
				resultInsert = resultInsert && dbObject.insertLocalizacion(LocPr1);

				if (resultInsert) {
					log.println(boost::log::trivial::trace, "Data insert OK");
					dbObject.ConfirmarTransaccion();
				}
				else {
					log.println(boost::log::trivial::trace, "Data insert ERROR");
					dbObject.DeshacerTransaccion();
				}

				dbObject.Desconectar();

				lastExecution = helpers::CTimeUtils::seconds_from_epoch(execTime);
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

