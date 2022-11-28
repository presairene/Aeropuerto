#include "boost/date_time/posix_time/posix_time.hpp"
#include "boost/date_time/gregorian/gregorian.hpp"
#include <string.h>
#include <iostream>

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

#include <list>
#include <vector>

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



int main(void) {

	CDatabaseLab4 dbObject;
	int avion_en_pista;
	int id_avion_pista;
	int remolque_sin_bateria;
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
		/*
		list<CValue*> listValue;
		list<CValue*>::iterator ilistValue;
		CTime fec1 = CTime(2022, 11, 24, 15, 43, 00);
		CValue Val1 = CValue(23.5, fec1.getDate());
		listValue.push_back(&Val1);
		ilistValue = listValue.begin();
		CPrediccion Pre1 = CPrediccion(7, fec1.getDate());
		*/
	//CREACION DE OBJETOS DE CADA CLASE
	
	// LOCALIZACIONES 
		// Zona de recogida
	CLocalizacion P0 = CLocalizacion(0, "Libre", "Pista", 4, 1);

	//Sensor pista

	CLocalizacion SP12 = CLocalizacion(12, "Libre", "SenPista", 1, 0);

	//Zona de carga y mantenimiento remolques

	CLocalizacion M11 = CLocalizacion(11, "Libre", "ZnCarga", 1, 1);

	//Carreteras
	CLocalizacion C1 = CLocalizacion(1, "Libre", "Carretera", 4, 2);

	CLocalizacion C4 = CLocalizacion(4, "Libre", "Carretera", 2, 3);
	CLocalizacion C7 = CLocalizacion(7, "Libre", "Carretera", 1, 3);

	CLocalizacion C2 = CLocalizacion(2, "Libre", "Carretera", 3, 4);
	CLocalizacion C5 = CLocalizacion(5, "Libre", "Carretera", 2, 4);
	CLocalizacion C8 = CLocalizacion(8, "Libre", "Carretera", 1, 4);
	CLocalizacion C10 = CLocalizacion(10, "Libre", "Carretera", 1, 2);

	// Finges
	CLocalizacion F3 = CLocalizacion(3, "Libre", "Finger", 3, 5);
	CLocalizacion F6 = CLocalizacion(6, "Ocupado", "Finger", 2, 5);
	CLocalizacion F9 = CLocalizacion(9, "Ocupado", "Finger", 1, 5);

	// RUTAS
	// Pista a Finger 1
	vector<CLocalizacion*> VectorRut1;
	VectorRut1.push_back(&P0);
	VectorRut1.push_back(&C1);
	VectorRut1.push_back(&C2);
	VectorRut1.push_back(&F3);
	CRuta Rut1 = CRuta(1, VectorRut1);

	//Pista a Finger 2
	vector<CLocalizacion*> VectorRut2;
	VectorRut2.push_back(&P0);
	VectorRut2.push_back(&C1);
	VectorRut2.push_back(&C4);
	VectorRut2.push_back(&C5);
	VectorRut2.push_back(&F6);
	CRuta Rut2 = CRuta(2, VectorRut2);

	//Pista a Finger 3
	vector<CLocalizacion*> VectorRut3;
	VectorRut3.push_back(&P0);
	VectorRut3.push_back(&C1);
	VectorRut3.push_back(&C4);
	VectorRut3.push_back(&C7);
	VectorRut3.push_back(&C8);
	VectorRut3.push_back(&F6);
	CRuta Rut3 = CRuta(3, VectorRut3);

	//Finger 1 a Pista
	vector<CLocalizacion*> VectorRut4;
	VectorRut4.push_back(&F3);
	VectorRut4.push_back(&C2);
	VectorRut4.push_back(&C1);
	VectorRut4.push_back(&P0);
	CRuta Rut4 = CRuta(4, VectorRut4);

	//Finger 2 a Pista
	vector<CLocalizacion*> VectorRut5;
	VectorRut5.push_back(&F6);
	VectorRut5.push_back(&C5);
	VectorRut5.push_back(&C4);
	VectorRut5.push_back(&C1);
	VectorRut5.push_back(&P0);
	CRuta Rut5 = CRuta(5, VectorRut5);


	//Finger 3 a Pista
	vector<CLocalizacion*> VectorRut6;
	VectorRut6.push_back(&F9);
	VectorRut6.push_back(&C8);
	VectorRut6.push_back(&C7);
	VectorRut6.push_back(&C4);
	VectorRut6.push_back(&C1);
	VectorRut6.push_back(&P0);
	CRuta Rut6 = CRuta(6, VectorRut6);

	// Zona de matenimiento a zona de remolque (Pista)
	vector<CLocalizacion*> VectorRut7;
	VectorRut7.push_back(&M11);
	VectorRut7.push_back(&C10);
	VectorRut7.push_back(&C7);
	VectorRut7.push_back(&C4);
	VectorRut7.push_back(&C1);
	VectorRut7.push_back(&P0);
	CRuta Rut7 = CRuta(7, VectorRut7);

	// Zona de remolque (Pista) a zona de mantenimiento
	vector<CLocalizacion*> VectorRut8;
	VectorRut8.push_back(&P0);
	VectorRut8.push_back(&C1);
	VectorRut8.push_back(&C4);
	VectorRut8.push_back(&C7);
	VectorRut8.push_back(&C8);
	VectorRut8.push_back(&C10);
	VectorRut8.push_back(&M11);
	CRuta Rut8 = CRuta(8, VectorRut8);




	//VALORES BATERIAS

	list<CValue*> listValue0;
	list<CValue*>::iterator ilistValue0;
	CTime fec = CTime(2022, 11, 24, 15, 00, 00);
	CValue Value0 = CValue(23.5, fec.getDate());
	listValue0.push_back(&Value0);
	ilistValue0 = listValue0.begin();
	CPrediccion Pre0 = CPrediccion();
	if (Value0.getValor() <= 25) {
		CPrediccion Pre0 = CPrediccion(0, fec.getDate());
	}
	else if (Value0.getValor() <= 75) {
		CPrediccion Pre0 = CPrediccion(50, fec.getDate());
	}
	else if (Value0.getValor() > 75) {
		CPrediccion Pre0 = CPrediccion(100, fec.getDate());
	}

	list<CValue*> listValue1;
	list<CValue*>::iterator ilistValue1;
	//CTime fec = CTime(2022, 11, 24, 15, 00, 00);
	CValue Value1 = CValue(46, fec.getDate());
	listValue1.push_back(&Value1);
	ilistValue1 = listValue1.begin();
	CPrediccion Pre1 = CPrediccion();
	if (Value1.getValor() <= 25) {
		CPrediccion Pre1 = CPrediccion(0, fec.getDate());
	}
	else if (Value1.getValor() <= 75) {
		CPrediccion Pre1 = CPrediccion(50, fec.getDate());
	}
	else if (Value1.getValor() > 75) {
		CPrediccion Pre1 = CPrediccion(100, fec.getDate());
	}


	list<CValue*> listValue2;
	list<CValue*>::iterator ilistValue2;
	//CTime fec = CTime(2022, 11, 24, 15, 00, 00);
	CValue Value2 = CValue(65, fec.getDate());
	listValue2.push_back(&Value2);
	ilistValue2 = listValue2.begin();
	CPrediccion Pre2 = CPrediccion();
	if (Value2.getValor() <= 25) {
		CPrediccion Pre2 = CPrediccion(0, fec.getDate());
	}
	else if (Value2.getValor() <= 75) {
		CPrediccion Pre2 = CPrediccion(50, fec.getDate());
	}
	else if (Value2.getValor() > 75) {
		CPrediccion Pre2 = CPrediccion(100, fec.getDate());
	}

	list<CValue*> listValue3;
	list<CValue*>::iterator ilistValue3;
	//CTime fec = CTime(2022, 11, 24, 15, 00, 00);
	CValue Value3 = CValue(90, fec.getDate());
	listValue3.push_back(&Value3);
	ilistValue3 = listValue3.begin();
	CPrediccion Pre3 = CPrediccion();
	if (Value3.getValor() <= 25) {
		CPrediccion Pre3 = CPrediccion(0, fec.getDate());
	}
	else if (Value3.getValor() <= 75) {
		CPrediccion Pre3 = CPrediccion(50, fec.getDate());
	}
	else if (Value3.getValor() > 75) {
		CPrediccion Pre3 = CPrediccion(100, fec.getDate());
	}

	//VALORES LOCALIZACIONES 0 LIBRES 1 OCUPADAS

	list<CValue*> listValue4;
	list<CValue*>::iterator ilistValue4;
	//CTime fec = CTime(2022, 11, 24, 15, 00, 00);
	CValue Value4 = CValue(0, fec.getDate());
	listValue4.push_back(&Value4);
	ilistValue4 = listValue4.begin();

	list<CValue*> listValue5;
	list<CValue*>::iterator ilistValue5;
	//CTime fec = CTime(2022, 11, 24, 15, 00, 00);
	CValue Value5 = CValue(0, fec.getDate());
	listValue5.push_back(&Value5);
	ilistValue5 = listValue5.begin();

	list<CValue*> listValue6;
	list<CValue*>::iterator ilistValue6;
	//CTime fec = CTime(2022, 11, 24, 15, 00, 00);
	CValue Value6 = CValue(1, fec.getDate());
	listValue6.push_back(&Value6);
	ilistValue6 = listValue6.begin();

	list<CValue*> listValue7;
	list<CValue*>::iterator ilistValue7;
	//CTime fec = CTime(2022, 11, 24, 15, 00, 00);
	CValue Value7 = CValue(1, fec.getDate());
	listValue7.push_back(&Value7);
	ilistValue7 = listValue7.begin();

	//SENSORES REMOLQUES - BATERIA
	CTipo Tip1 = CTipo(1, "Bateria");
	CSensor S0R0 = CSensor(0, &Pre0, &Tip1, listValue0, NULL);
	CSensor S1R1 = CSensor(1, &Pre1, &Tip1, listValue1, NULL);
	CSensor S2R2 = CSensor(2, &Pre2, &Tip1, listValue2, NULL);
	CSensor S3R3 = CSensor(3, &Pre3, &Tip1, listValue3, NULL);


	// SENSORES LOCALIZACION
	CTipo Tip2 = CTipo(2, "Localizacion");
	CSensor S4L0 = CSensor(4, NULL, &Tip2, listValue4, &SP12);
	CSensor S5L1 = CSensor(5, NULL, &Tip2, listValue5, &F3);
	CSensor S6L2 = CSensor(6, NULL, &Tip2, listValue6, &F6);
	CSensor S7L3 = CSensor(7, NULL, &Tip2, listValue7, &F9);

	list<CSensor*> listSensor0;
	list<CSensor*>::iterator ilistSensor0;
	listSensor0.push_back(&S0R0);
	ilistSensor0 = listSensor0.begin();

	list<CSensor*> listSensor1;
	list<CSensor*>::iterator ilistSensor1;
	listSensor1.push_back(&S1R1);
	ilistSensor1 = listSensor1.begin();

	list<CSensor*> listSensor2;
	list<CSensor*>::iterator ilistSensor2;
	listSensor0.push_back(&S2R2);
	ilistSensor0 = listSensor2.begin();

	list<CSensor*> listSensor3;
	list<CSensor*>::iterator ilistSensor3;
	listSensor0.push_back(&S3R3);
	ilistSensor0 = listSensor3.begin();
	////----------Aviones------------------
	CAvion Avi0 = CAvion(0, "Aparcado", &F6);
	CAvion Avi1 = CAvion(1, "Aparcado", &F9);
	int indice_idAvion = 1;
	CAvion Avi2 = CAvion(indice_idAvion++, "Salida", &P0);
	CAvion Avi3 = CAvion(indice_idAvion++, "Aparcado", &F3);
	
	////----------Remolques------------------

	CRemolque Rem0 = CRemolque(0, "Libre", listSensor0, NULL, &M11);
	CRemolque Rem1 = CRemolque(1, "Libre", listSensor1, NULL, &P0);
	CRemolque Rem2 = CRemolque(2, "Libre", listSensor2, &Avi0, &F6);
	CRemolque Rem3 = CRemolque(3, "Libre", listSensor3, &Avi1, &F9);
	
	


	   
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

				//INSERTA OF DATA
				
				////--------------------------------------Insert localizacion --------------------------------------------
				//bool resultInsert = true;
				//resultInsert = resultInsert && dbObject.insertLocalizacion(P0);
				//resultInsert = resultInsert && dbObject.insertLocalizacion(SP12);
				//resultInsert = resultInsert && dbObject.insertLocalizacion(M11);
				//resultInsert = resultInsert && dbObject.insertLocalizacion(C1);
				//resultInsert = resultInsert && dbObject.insertLocalizacion(C4);
				//resultInsert = resultInsert && dbObject.insertLocalizacion(C7);
				//resultInsert = resultInsert && dbObject.insertLocalizacion(C2);
				//resultInsert = resultInsert && dbObject.insertLocalizacion(C5);
				//resultInsert = resultInsert && dbObject.insertLocalizacion(C8);
				//resultInsert = resultInsert && dbObject.insertLocalizacion(C10);
				//resultInsert = resultInsert && dbObject.insertLocalizacion(F3);
				//resultInsert = resultInsert && dbObject.insertLocalizacion(F6);
				//resultInsert = resultInsert && dbObject.insertLocalizacion(F9);

				//if (resultInsert) {
				//	log.println(boost::log::trivial::trace, "Data insert OK");
				//	dbObject.ConfirmarTransaccion();
				//}
				//else {
				//	log.println(boost::log::trivial::trace, "Data insert ERROR");
				//	dbObject.DeshacerTransaccion();
				//}

				////--------------------------------------Insert Remolque --------------------------------------------

				//resultInsert = true;
				//resultInsert = resultInsert && dbObject.insertRemolque(Rem0);
				//resultInsert = resultInsert && dbObject.insertRemolque(Rem1);
				//resultInsert = resultInsert && dbObject.insertRemolque(Rem2);
				//resultInsert = resultInsert && dbObject.insertRemolque(Rem3);

				//if (resultInsert) {
				//	log.println(boost::log::trivial::trace, "Data insert OK Valores");
				//	dbObject.ConfirmarTransaccion();
				//}
				//else {
				//	log.println(boost::log::trivial::trace, "Data insert ERROR Valores");
				//	dbObject.DeshacerTransaccion();
				//}

				//// -------------------------------------- - Insert Tipo----------------------------------------------

				//resultInsert = true;
				//resultInsert = resultInsert && dbObject.insertTipo(Tip1);
				//resultInsert = resultInsert && dbObject.insertTipo(Tip2);
				//if (resultInsert) {
				//	log.println(boost::log::trivial::trace, "Data insert OK Tipo");
				//	dbObject.ConfirmarTransaccion();
				//}
				//else {
				//	log.println(boost::log::trivial::trace, "Data insert ERROR Tipo");
				//	dbObject.DeshacerTransaccion();
				//}

				////--------------------------------------Insert sensores --------------------------------------------

				//resultInsert = true;
				//resultInsert = resultInsert && dbObject.insertSensor(S0R0);
				//resultInsert = resultInsert && dbObject.insertSensor(S1R1);
				//resultInsert = resultInsert && dbObject.insertSensor(S2R2);
				//resultInsert = resultInsert && dbObject.insertSensor(S3R3);
				//resultInsert = resultInsert && dbObject.insertSensor(S4L0);
				//resultInsert = resultInsert && dbObject.insertSensor(S5L1);
				//resultInsert = resultInsert && dbObject.insertSensor(S6L2);
				//resultInsert = resultInsert && dbObject.insertSensor(S7L3);

				//if (resultInsert) {
				//	log.println(boost::log::trivial::trace, "Data insert OK Valores");
				//	dbObject.ConfirmarTransaccion();
				//}
				//else {
				//	log.println(boost::log::trivial::trace, "Data insert ERROR Valores");
				//	dbObject.DeshacerTransaccion();
				//}
				////--------------------------------------Insert valores --------------------------------------------

				//resultInsert = true;
				//resultInsert = resultInsert && dbObject.insertValor(Value0, S0R0);
				//resultInsert = resultInsert && dbObject.insertValor(Value1, S1R1);
				//resultInsert = resultInsert && dbObject.insertValor(Value2, S2R2);
				//resultInsert = resultInsert && dbObject.insertValor(Value3, S3R3);
				//resultInsert = resultInsert && dbObject.insertValor(Value4, S4L0);
				//resultInsert = resultInsert && dbObject.insertValor(Value5, S5L1);
				//resultInsert = resultInsert && dbObject.insertValor(Value6, S6L2);
				//resultInsert = resultInsert && dbObject.insertValor(Value7, S7L3);

				//if (resultInsert) {
				//	log.println(boost::log::trivial::trace, "Data insert OK Valores");
				//	dbObject.ConfirmarTransaccion();
				//}
				//else {
				//	log.println(boost::log::trivial::trace, "Data insert ERROR Valores");
				//	dbObject.DeshacerTransaccion();
				//}


				//// --------------------------------------Insert Sensor Localización y Bateria--------------------------------------------

				//// ------------------------------------------Localizacion--------------------------------
				//resultInsert = true;
				//resultInsert = resultInsert && dbObject.insertSensorLocalizacion(S4L0, P0);
				//resultInsert = resultInsert && dbObject.insertSensorLocalizacion(S5L1, F3);
				//resultInsert = resultInsert && dbObject.insertSensorLocalizacion(S6L2, F6);
				//resultInsert = resultInsert && dbObject.insertSensorLocalizacion(S7L3, F9);

				//if (resultInsert) {
				//	log.println(boost::log::trivial::trace, "Data insert OK Valores");
				//	dbObject.ConfirmarTransaccion();
				//}
				//else {
				//	log.println(boost::log::trivial::trace, "Data insert ERROR Valores");
				//	dbObject.DeshacerTransaccion();
				//}
				//// -----------------------------------------Bateria ---------------------------------------------------------

				//resultInsert = true;
				//resultInsert = resultInsert && dbObject.insertSensorBateria(S0R0, Rem0);
				//resultInsert = resultInsert && dbObject.insertSensorBateria(S1R1, Rem1);
				//resultInsert = resultInsert && dbObject.insertSensorBateria(S2R2, Rem2);
				//resultInsert = resultInsert && dbObject.insertSensorBateria(S3R3, Rem3);

				//if (resultInsert) {
				//	log.println(boost::log::trivial::trace, "Data insert OK Valores");
				//	dbObject.ConfirmarTransaccion();
				//}
				//else {
				//	log.println(boost::log::trivial::trace, "Data insert ERROR Valores");
				//	dbObject.DeshacerTransaccion();


				//	//--------------------------------------Insert Predicion --------------------------------------------

				//	resultInsert = true;
				//	resultInsert = resultInsert && dbObject.insertPrediccion(S0R0, Pre0);
				//	resultInsert = resultInsert && dbObject.insertPrediccion(S1R1, Pre1);
				//	resultInsert = resultInsert && dbObject.insertPrediccion(S2R2, Pre2);
				//	resultInsert = resultInsert && dbObject.insertPrediccion(S3R3, Pre3);

				//	if (resultInsert) {
				//		log.println(boost::log::trivial::trace, "Data insert OK Valores");
				//		dbObject.ConfirmarTransaccion();
				//	}
				//	else {
				//		log.println(boost::log::trivial::trace, "Data insert ERROR Valores");
				//		dbObject.DeshacerTransaccion();
				//	}

				//	//--------------------------------------Insert ruta --------------------------------------------

				//	resultInsert = true;
				//	resultInsert = resultInsert && dbObject.insertRuta(Rut1);
				//	resultInsert = resultInsert && dbObject.insertRuta(Rut2);
				//	resultInsert = resultInsert && dbObject.insertRuta(Rut3);
				//	resultInsert = resultInsert && dbObject.insertRuta(Rut4);
				//	resultInsert = resultInsert && dbObject.insertRuta(Rut5);
				//	resultInsert = resultInsert && dbObject.insertRuta(Rut6);
				//	resultInsert = resultInsert && dbObject.insertRuta(Rut7);
				//	resultInsert = resultInsert && dbObject.insertRuta(Rut8);

				//	if (resultInsert) {
				//		log.println(boost::log::trivial::trace, "Data insert OK Valores");
				//		dbObject.ConfirmarTransaccion();
				//	}
				//	else {
				//		log.println(boost::log::trivial::trace, "Data insert ERROR Valores");
				//		dbObject.DeshacerTransaccion();
				//	}

				//	//--------------------------------------Insert Avion --------------------------------------------

				//	resultInsert = true;
				//	resultInsert = resultInsert && dbObject.insertAvion(Avi0);
				//	resultInsert = resultInsert && dbObject.insertAvion(Avi1);
				//	if (resultInsert) {
				//		log.println(boost::log::trivial::trace, "Data insert OK Valores");
				//		dbObject.ConfirmarTransaccion();
				//	}
				//	else {
				//		log.println(boost::log::trivial::trace, "Data insert ERROR Valores");
				//		dbObject.DeshacerTransaccion();
				//	}
				//	//--------------------------------------Insert Localizacion - Ruta --------------------------------------------

				//	resultInsert = true;
				//	resultInsert = resultInsert && dbObject.insertLocalizacionRuta(Rut1);
				//	resultInsert = resultInsert && dbObject.insertLocalizacionRuta(Rut2);
				//	resultInsert = resultInsert && dbObject.insertLocalizacionRuta(Rut3);
				//	resultInsert = resultInsert && dbObject.insertLocalizacionRuta(Rut4);
				//	resultInsert = resultInsert && dbObject.insertLocalizacionRuta(Rut5);
				//	resultInsert = resultInsert && dbObject.insertLocalizacionRuta(Rut6);
				//	resultInsert = resultInsert && dbObject.insertLocalizacionRuta(Rut7);
				//	resultInsert = resultInsert && dbObject.insertLocalizacionRuta(Rut8);

				//	if (resultInsert) {
				//		log.println(boost::log::trivial::trace, "Data insert OK Valores");
				//		dbObject.ConfirmarTransaccion();
				//	}
				//	else {
				//		log.println(boost::log::trivial::trace, "Data insert ERROR Valores");
				//		dbObject.DeshacerTransaccion();
				//	}

//______________________________________________PRUEBA ELIMINAR AVION______________________________________
								cout << "Ha comenzado la prueba de Eliminar Avion" << endl;
								bool resultInsert = true;
								resultInsert = true;
								resultInsert = resultInsert && dbObject.insertAvion(Avi2);
								resultInsert = resultInsert && dbObject.insertAvion(Avi3);
								if (resultInsert) {
									log.println(boost::log::trivial::trace, "Data insert OK Valores");
									dbObject.ConfirmarTransaccion();
								}
								else {
									log.println(boost::log::trivial::trace, "Data insert ERROR Valores");
									dbObject.DeshacerTransaccion();
								}
								dbObject.EliminarAvion(3);
								cout <<"Ha terminado la prueba de Eliminar Avion" << endl;


////____________________________________________________INTELIGENCIA_______________________________________________
					//1. Leer Sensor de Localizacion -> -1 si la pista esta libre; sino devuelve ID_LOC
						avion_en_pista = dbObject.LeerSensorLocPISTA();
						cout << "Avion en pista: "<< avion_en_pista << endl;
						
						if (avion_en_pista != -1) {
							//2. Comprobar si existe id Avion en esa localización-> si existe el avión va a despegar, si no el avión acaba de llegar
							id_avion_pista = dbObject.LeerIdAvion(2);
							cout << "El ID del avion es: "<< id_avion_pista << endl; //-1 si no existe el avion
							//3. Existe avion
							if (id_avion_pista != -1) {
								//3.1 Borrar avion de la base de datos
								dbObject.EliminarAvion(id_avion_pista);
								//3.2 Pista desocupada
								dbObject.UpdateLocalizacion(avion_en_pista, "Libre");
								dbObject.UpdateValorSensor(avion_en_pista, 0);
							}
							else{
							//4. No existe Id Avion ¿Hay que generar el avion aquí o lo introduce el usuario?
								//4.1 Insert Avion en base de datos
								CAvion Avi = CAvion(indice_idAvion++, "Aterrizado", &P0);
								resultInsert = resultInsert && dbObject.insertAvion(Avi);
								if (resultInsert) {
									log.println(boost::log::trivial::trace, "Data insert OK Valores");
									dbObject.ConfirmarTransaccion();
								}
								else {
									log.println(boost::log::trivial::trace, "Data insert ERROR Valores");
									dbObject.DeshacerTransaccion();
								}
								//4.2 Asignar remolque


								//4.3 Asignar finger

								//4.4 Asignar ruta

								//4.5 Cambiar pista a desocupada y valor del sensor a 0

								//4.6 Finger ocupado (se detecta en la interfaz cambiando el valor de sensor) 

								//4.7 Cambiar estado de avión a aparcado 
							}
						}
						////___________BATERIAS_______________________________________________
						//1. Leer Sensor de las Baterías -> -1 si no hay ningún remolque en la pista. 
							//Si no devuelve el ID_REMOLQUE
						remolque_sin_bateria = dbObject.LeerSensorPredBateria();
						cout << "Remolque cuya predicion es 0% de bateria:  " << remolque_sin_bateria << endl;



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













//---------------------------------VARIABLES DE PRUEBA----------------------------
//Listas
/*
list<CValue*> listValue;
list<CValue*>::iterator ilistValue;
CTime fec1 = CTime(2022, 11, 24, 15, 43, 00);
CValue Val1 = CValue(23.5, fec1.getDate());
listValue.push_back(&Val1);
ilistValue = listValue.begin();
CPrediccion Pre1 = CPrediccion(7, fec1.getDate());
*/