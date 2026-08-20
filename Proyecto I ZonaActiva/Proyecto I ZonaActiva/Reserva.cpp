#include "Reserva.h"
#include "Cancha.h"
#include <string>
using namespace std;

int Reserva::getNumeroReserva() {
	return numeroReserva;
}
//Cliente* getCanchaCliente();//Queda pendiente
Cancha* Reserva::getCanchaAsociada() {

}
int Reserva::getFranjaInicial() {
	return franjaInicial;
}
int Reserva::getFranjaCantidadReservada() {
	return franjaCantidadReservada;
}
double Reserva::getMontoReserva() {
	return montoReserva;
}
bool Reserva::getEstadoReserva() {
	return estadoReserva;
}

//Setters
void Reserva::setEstadoReservado(bool estadoReserva) {
	this->estadoReserva = estadoReserva;
}

//Mostrar
void Reserva::mostrarInformacion();

//Constructor
Reserva(int numeroReserva,
	//Cliente* clienteAsociado,//
	Cancha* canchaAsociada,
	int franjaInicial,
	int franjaCantidadReservada,
	double montoReserva){
	this->numeroReserva = numeroReserva;
	this->franjaInicial = franjaInicial;
	this->franjaCantidadReservada = franjaCantidadReservada;
	this->montoReserva = montoReserva;
}

//Destructor
~Reserva();