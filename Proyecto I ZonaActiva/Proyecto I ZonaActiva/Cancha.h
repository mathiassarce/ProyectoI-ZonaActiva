#pragma once
#include <string>
using namespace std;

const int NUM_FRANJAS = 12;

class Cancha {

private:

	string codigo;
	string tipoDeporte;
	double precioPorHora;
	char franjas[NUM_FRANJAS];

public:

	//Constructores
	Cancha();
	Cancha(string codigo, string tipoDeporte, double precioPorHora);

	//Getters
	string getCodigo();
	string getTipoDeporte();
	double getPrecioPorHora();
	char getEstadoFranja(int franja);

	//Setters
	void setCodigo(string codigo);
	void setTipoDeporte(string tipoDeporte);
	void setPrecioPorHora(double precioPorHora);
	void setEstadoFranja(int franja, char estado);

	//Metodos propios
	bool ocuparFranja(int posicion);
	bool liberarFranja(int posicion);
	bool ponerMantenimiento(int posicion);
	bool quitarMantenimiento(int posicion);
	bool franjaLibre(int posicion);

	//Metodos de mostrar
	void mostrarDisponibilidad();
	void mostrarInformacion();

};