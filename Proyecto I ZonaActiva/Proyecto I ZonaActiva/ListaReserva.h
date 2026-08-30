#pragma once
#include "Reserva.h"

class ListaReserva {
private:
	Reserva** reservas;
	int cantidad;               
	int capacidad;              
	int contadorConsecutivo;

public:
	bool registrarReserva(Cliente* cliente, Cancha* cancha, int franjaInicial, int cantidadFranjas, double precioFranja);
	void mostrarReservas();
	void cambioDisponibilidad(Cancha* cancha, int franjaInicial, int cantidadFranjas, char nuevoEstado);
	Reserva* buscarReserva(int numeroReserva);
	void mostarReservasCancha(int numeroCancha);
	void cancelarReserva(int numeroReserva);

	ListaReserva();
	~ListaReserva();
};