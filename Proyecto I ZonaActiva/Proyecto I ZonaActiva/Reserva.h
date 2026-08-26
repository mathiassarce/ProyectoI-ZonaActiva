#pragma once
#include <string>
#include "Cancha.h"
#include "Cliente.h"
#include <iostream>
using namespace std;


class Reserva{
private:
	int numeroReserva;
	Cliente* clienteAsociado; 
	Cancha* canchaAsociada;
	int franjaInicial;
	int franjaCantidadReservada;
	double montoReserva;
	bool estadoReserva;

public:

	//Getters
	int getNumeroReserva();
	Cliente* getClienteAsociado();
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
			Cliente* clienteAsociado,
			Cancha* canchaAsociada,
			int franjaInicial,
			int franjaCantidadReservada,
			double montoReserva);
	
	//Destructor
	~Reserva();
	
};

