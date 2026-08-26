#include "ListaCliente.h"
#include <iostream>
using namespace std;

//Constructor
ListaCliente::ListaCliente() {
	cantidad = 0;
	clientes = new Cliente*[MAX_CLIENTES];
	for (int i = 0; i < MAX_CLIENTES; i++) {
		clientes[i] = nullptr;
	}
}

//Destructor
ListaCliente::~ListaCliente() {
	for (int i = 0; i < cantidad; i++) {
		delete clientes[i];
		clientes[i] = nullptr;
	}
	delete[] clientes;
}

//Metodos propios
bool ListaCliente::registrarCliente(int identificacion, string nombreCompleto, string telefono) {
	if (identificacion <= 0) {
		return false;
	}
	if (nombreCompleto == " " || nombreCompleto.empty() || telefono == " " || telefono.empty()) {
		return false;
	}
	if (cantidad >= MAX_CLIENTES) {
		return false;
	}
	if (existeIdentificacion(identificacion)) {
		return false;
	}
	clientes[cantidad] = new Cliente(identificacion, nombreCompleto, telefono);
	cantidad = cantidad + 1;
	return true;
}

void ListaCliente::mostrarTodos() {
	if (cantidad == 0) {
		cout << "No hay ningun cliente registrado" << endl;
	}
	else {
		for (int i = 0; i < cantidad; i++) {
			clientes[i]->mostrarInformacion();
			cout << "-----------------------------" << endl;
		}
	}
}

Cliente* ListaCliente::buscarPorIdentificacion(int identificacion) {
	for (int i = 0; i < cantidad; i++) {
		if (clientes[i]->getIdentificacion() == identificacion) {
			return clientes[i];
		}
	}
	return nullptr;
}

bool ListaCliente::existeIdentificacion(int identificacion) {
	for (int i = 0; i < cantidad; i++) {
		if (clientes[i]->getIdentificacion() == identificacion) {
			return true;
		}
	}
	return false;
}

int ListaCliente::getCantidad() {
	return cantidad;
}