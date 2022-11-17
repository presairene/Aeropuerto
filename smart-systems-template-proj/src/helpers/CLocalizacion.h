#pragma once
#include <iostream>
#include <string.h>

using namespace std;

class CLocalizacion
{
private:
	int m_idLocalizacion;
	std::string m_estado; /*'Ocupado' y Vacío'*/
	std::string m_tipo; /*'Finger', 'Pista' y 'Carretera'*/
	float m_coordenadasx;
	float m_coordenadasy;

public:
	//Constructors
	CLocalizacion();
	CLocalizacion(int id, string estado, string tipo, float coordenadasx, float coordenadasy);
	//CLocalizacion(const CLocalizacion& l); //Constructor copia. V se pasa por referencia. Si lo paso por copia se llamaría a si mismmo.
	//Destructor
	~CLocalizacion();
	//Access functions
	int getIdLocalizacion() const;
	string getEstado() const;
	string getTipo() const;
	float getCoordenadasX() const;
	float getCoordenadasY() const;

	//Operator<<
	friend std::ostream& operator<<(std::ostream& o, const CLocalizacion& c);



};