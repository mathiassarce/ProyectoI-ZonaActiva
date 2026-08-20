#include "Reserva.h"
#include <iostream>

int Reserva::getNumeroReserva() {
    return numeroReserva;
}

//Cliente* getCanchaCliente();//Queda pendiente Cliente

Cancha* Reserva::getCanchaAsociada() {
    return canchaAsociada;
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

void Reserva::setEstadoReservado(bool estadoReserva) {
    this->estadoReserva = estadoReserva;
}

void Reserva::mostrarInformacion() {
    cout << "Reserva #" << numeroReserva
        << " | Franja inicio: " << franjaInicial
        << " | Cantidad: " << franjaCantidadReservada
        << " | Monto: $" << montoReserva
        << " | Estado: " << (estadoReserva ? "Activa" : "Cancelada") << endl;
}

Reserva::Reserva(int numeroReserva, /*Cliente* clienteAsociado ,*/ Cancha* canchaAsociada, int franjaInicial,
        int franjaCantidadReservada, double montoReserva) {
    this->numeroReserva = numeroReserva;
    //this->clienteAsociado = clienteAsociado //Queda pendiente 
    this->canchaAsociada = canchaAsociada;
    this->franjaInicial = franjaInicial;
    this->franjaCantidadReservada = franjaCantidadReservada;
    this->montoReserva = montoReserva;
    this->estadoReserva = true;
}

Reserva::~Reserva() {
}