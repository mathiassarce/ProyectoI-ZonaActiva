#include "ListaReserva.h"

bool ListaReserva::registrarReserva(Cliente* cliente, Cancha* cancha, int franjaInicial, int cantidadFranjas, double precioFranja){
    if (cliente == nullptr || cancha == nullptr) {
        cout << "Error: El cliente o la cancha no existen." << endl;
        return false;
    }
    for (int i = franjaInicial; i < franjaInicial + cantidadFranjas; i++) {
        if (!cancha->franjaLibre(i)) {
            cout << "Error: La franja " << i << " no esta disponible." << endl;
            return false;
        }
    }
    for (int i = franjaInicial; i < franjaInicial + cantidadFranjas; i++) {
        cancha->ocuparFranja(i);
    }

    double montoTotal = cantidadFranjas * precioFranja;
    Reserva* nuevaReserva = new Reserva(contadorConsecutivo, cliente, cancha, franjaInicial, cantidadFranjas, montoTotal);

    reservas[cantidad] = nuevaReserva;
    cantidad++;
    contadorConsecutivo++;

    cout << "Reserva #" << nuevaReserva->getNumeroReserva() << " registrada exitosamente." << endl;
    return true;
}

void ListaReserva::mostrarReservas(){
    if (cantidad == 0) {
        cout << "No hay reservas registradas en el sistema." << endl;
        return;
    }

    cout << "=== LISTA DE RESERVAS ===" << endl;
    for (int i = 0; i < cantidad; i++) {
        reservas[i]->mostrarInformacion();
        cout << "-----------------------------------" << endl;
    }
}


void ListaReserva::cambioDisponibilidad(Cancha* cancha, int franjaInicial, int cantidadFranjas, char nuevoEstado) {
    if (cancha == nullptr) return;

    for (int i = franjaInicial; i < franjaInicial + cantidadFranjas; i++) {
        if (nuevoEstado == 'O') {
            cancha->ocuparFranja(i);
        }
        else if (nuevoEstado == 'L') {
            cancha->liberarFranja(i);
        }
    }
}

Reserva* ListaReserva::buscarReserva(int numeroReserva){
    for (int i = 0; i < cantidad; i++) {
        if (reservas[i]->getNumeroReserva() == numeroReserva) {
            return reservas[i]; 
        }
    }
    return nullptr; 
}

void ListaReserva::mostarReservasCancha(int numeroCancha){
    bool encontrada = false;
    string codigoBuscado = to_string(numeroCancha);

    cout << "=== RESERVAS DE LA CANCHA " << numeroCancha << " ===" << endl;

    for (int i = 0; i < cantidad; i++) {
        if (reservas[i]->getCanchaAsociada()->getCodigo() == codigoBuscado) {
            reservas[i]->mostrarInformacion();
            cout << "-----------------------------------" << endl;
            encontrada = true;
        }
    }

    if (!encontrada) {
        cout << "No hay reservas asociadas a la cancha " << numeroCancha << "." << endl;
    }
}

void ListaReserva::cancelarReserva(int numeroReserva){
    Reserva* res = buscarReserva(numeroReserva);

    if (res == nullptr) {
        cout << "Error: La reserva #" << numeroReserva << " no existe." << endl;
        return;
    }

    if (!res->getEstadoReserva()) {
        cout << "Error: La reserva #" << numeroReserva << " ya se encuentra cancelada." << endl;
        return;
    }

    res->setEstadoReservado(false);

    Cancha* cancha = res->getCanchaAsociada();
    int inicio = res->getFranjaInicial();
    int cantFranjas = res->getFranjaCantidadReservada();

    for (int i = inicio; i < inicio + cantFranjas; i++) {
        cancha->liberarFranja(i);
    }

    cout << "Reserva #" << numeroReserva << " cancelada exitosamente y franjas liberadas." << endl;
}

ListaReserva::ListaReserva(){
    this->capacidad = 50;                     
    this->reservas = new Reserva * [capacidad]; 
    this->cantidad = 0;                      
    this->contadorConsecutivo = 1;
}

ListaReserva::~ListaReserva(){
    for (int i = 0; i < cantidad; i++) {
        delete reservas[i];
    }
    delete[] reservas;
}
