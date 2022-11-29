// --------------------------------------------------------------------------
// ---------------------- CABECERA DE LA CLASE CDatabaseLab --------------------
// --------------------------------------------------------------------------
// ---------------------------------------------------------

#include <iostream>
#include <string.h>
#include "CDatabase.hpp"
#include "CLocalizacion.h"
#include "CSensor.h"
#include <CRemolque.h>
#include <CPrediccion.h>
#include <CTipo.h>
#include <CValue.h>
#include <CRuta.h>

class CDatabaseLab4 : public CDatabase
{
public:

	CDatabaseLab4();
	~CDatabaseLab4();

	//INSERTS

	int insertLocalizacion(const CLocalizacion& c);
	int insertRuta( CRuta& Ru);
	int insertLocalizacionRuta(const CRuta& Ru);

	int insertRemolque(CRemolque& r);
	int insertAvion(const CAvion& a);
	int insertPrediccion(const CSensor& s, const CPrediccion& p);
	

	int insertSensor(const CSensor& s);
	int insertSensorBateria(const CSensor& s, CRemolque& r);
	int insertSensorLocalizacion(const CSensor& s, const CLocalizacion& l);
	int insertTipo(const CTipo& t);
	int insertValor(const CValue& v, const CSensor& s);
	
	
	//OTHER
	//Funciones del apartado PISTA
	int LeerSensorLocPISTA();
	int LeerIdAvion(const int idAvion);
	int EliminarAvion(const int idAv);
	int UpdateLocalizacion(const int idLoc, string cadena);//No funciona
	//int UpdateValorSensor(const int idLoc, const int val);

	int EnviarRemolquesCarga();
	int LeerSensorLocFINGER();

	

	int CambiarEstadoAvion();

	//Funciones del apartado BATERIA
	int LeerSensorPredBateria();
	int UpdateRutaRemolque(const int idRem, const int idRuta); // Funciona
	int UpdateEstadoRemolque(const int idRem, const int ocupadoLibre); // Funciona Mandarle un 0 cambiar a libre y un uno cambiar a ocupado
	int UpdateLocRemolque(const int idRem, const int idLoc);// FUNCIONA
	int remolquecargado();


	int UpdateEstadoAvion(string estado, int idAv);
	int AsignarFinger(); 
	int AsignarRemolque(int idAv);
	int LeerRemolquePista();

	int updateLocAvion(int avi,  int loc);



};