#pragma once
#include <string>
#include "Cancha.h"
using namespace std;

class Reserva{
private:
	int numeroReserva;
	//Cliente* clienteAsociado; //Queda en pendiente hasta hacer la clase cliente 
	Cancha* canchaAsociada;
	int franjaInicial;
	int franjaCantidadReservada;
	double montoReserva;
	bool estadoReserva;

public:

	//Getters
	int getNumeroReserva();
	//Cliente* getCanchaCliente();//Queda pendiente
	Cancha* getCanchaAsociada();
	int getFranjaInicial();
	int getFranjaCantidadReservada();
	double getMontoReserva();
	bool getEstadoReserva();

	//Setters
	void setEstadoReservado(bool estadoReserva);

	//Mostrar
	void mostrarInformacion();

	//Constructor
	Reserva(int numeroReserva,
		//Cliente* clienteAsociado,
		Cancha* canchaAsociada,
		int franjaInicial,
		int franjaCantidadReservada,
		double montoReserva);
	
	//Destructor
	~Reserva();
	
};

