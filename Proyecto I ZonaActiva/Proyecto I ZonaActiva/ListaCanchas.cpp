#include "ListaCanchas.h"
#include <iostream>
using namespace std;

//Constructor
ListaCanchas::ListaCanchas() {
	cantidad = 0;
	for (int i = 0; i < MAX_CANCHAS; i++) {
		canchas[i] = nullptr;
	}
}

//Destructor
ListaCanchas :: ~ListaCanchas() {
	for (int i = 0; i < cantidad; i++) {
		delete canchas[i];
		canchas[i] = nullptr;
	}
}

//Metodos propios
bool ListaCanchas::registrarCancha(string codigo, string tipoDeporte, double precioPorHora) {
	if (cantidad >= MAX_CANCHAS) {
		return false;
	}
	if (existeCodigo(codigo)) {
		return false;
	}
	canchas[cantidad] = new Cancha(codigo, tipoDeporte, precioPorHora);
	cantidad = cantidad + 1;
	return true;
}

void ListaCanchas::mostrarTodas() {
	if (cantidad == 0) {
		cout << "No hay ninguna cancha registrada" << endl;
	}
	else {
		for (int i = 0; i < cantidad; i++) {
			canchas[i]->mostrarInformacion();
			cout << "-----------------------------" << endl;
		}
	}
}

Cancha* ListaCanchas::buscarPorCodigo(string codigo) {
	for (int i = 0; i < cantidad; i++) {
		if (canchas[i]->getCodigo() == codigo) {
			return canchas[i];
		}
	}
	return nullptr;
}

bool ListaCanchas::modificarPrecio(string codigo, double nuevoPrecio) {
	Cancha* c = buscarPorCodigo(codigo);
	if (c == nullptr) {
		return false;
	}
	c->setPrecioPorHora(nuevoPrecio);
	return true;
}

bool ListaCanchas::existeCodigo(string codigo) {
	for (int i = 0; i < cantidad; i++) {
		if (canchas[i]->getCodigo() == codigo) {
			return true;
		}
	}
	return false;
}

int ListaCanchas::getCantidad() {
	return cantidad;
}