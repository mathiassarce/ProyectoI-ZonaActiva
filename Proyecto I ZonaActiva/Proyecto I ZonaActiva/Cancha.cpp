#include "Cancha.h"
#include <iostream>
using namespace std;

//Constructor por defecto
Cancha::Cancha() {
	codigo = "";
	tipoDeporte = "";
	precioPorHora = 0.0;
	for (int i = 0; i < NUM_FRANJAS; i++) {
		franjas[i] = 'L'; // L para Libre
	}
}

//Constructor con parámetros
Cancha::Cancha(string codigo, string tipoDeporte, double precioPorHora) {
	this->codigo = codigo;
	this->tipoDeporte = tipoDeporte;
	this->precioPorHora = precioPorHora;
	for (int i = 0; i < NUM_FRANJAS; i++) {
		franjas[i] = 'L'; // L para Libre
	}
}

//Getters
string Cancha::getCodigo() {
	return codigo;
}
string Cancha::getTipoDeporte() {
	return tipoDeporte;
}
double Cancha::getPrecioPorHora() {
	return precioPorHora;
}
char Cancha::getEstadoFranja(int franja) {
	if (franja < 0 || franja >= NUM_FRANJAS) {
		return '?';
	}
	return franjas[franja];
}

//Setters
void Cancha::setCodigo(string codigo) {
	this->codigo = codigo;
}
void Cancha::setTipoDeporte(string tipoDeporte) {
	this->tipoDeporte = tipoDeporte;
}
void Cancha::setPrecioPorHora(double precioPorHora) {
	if (precioPorHora >= 0) {
		this->precioPorHora = precioPorHora;
	}
}
void Cancha::setEstadoFranja(int franja, char estado) {
	if (franja < 0 || franja >= NUM_FRANJAS) return; 
		if(estado == 'L' || estado == 'O' || estado == 'M'){
			this-> franjas[franja] = estado;
	}
}

//Metodos propios
bool Cancha::ocuparFranja(int posicion) {
	if (posicion < 0 || posicion >= NUM_FRANJAS) {
		return false;
	}
	if (this-> franjas[posicion] != 'L') {
		return false;
	}
	this-> franjas[posicion] = 'O';
	return true;
}

bool Cancha::liberarFranja(int posicion) {
	if (posicion < 0 || posicion >= NUM_FRANJAS) {
		return false;
	}
	if (this-> franjas[posicion] != 'O') {
		return false;
	}
	this->franjas[posicion] = 'L';
	return true;
}

bool Cancha::ponerMantenimiento(int posicion) {
	if (posicion < 0 || posicion >= NUM_FRANJAS) {
		return false;
	}
	if (this->franjas[posicion] == 'O') {
		return false;
	}
	this->franjas[posicion] = 'M';
	return true;
}

bool Cancha::quitarMantenimiento(int posicion) {
	if (posicion < 0 || posicion >= NUM_FRANJAS) {
		return false;
	}
	if (this->franjas[posicion] != 'M') {
		return false;
	}
	this->franjas[posicion] = 'L';
	return true;
}

bool Cancha::franjaLibre(int posicion) {
	if (posicion < 0 || posicion >= NUM_FRANJAS) {
		return false;
	}
	return this->franjas[posicion] == 'L';
}

//Metodos de mostrar
void Cancha::mostrarDisponibilidad() {
	cout << "Disponibilidad de la cancha " << codigo << endl;
	int horaInicio = 8;
	for (int i = 0; i < NUM_FRANJAS; i++) {
		cout << "[" << i << "]" << horaInicio << ":00 ->" << franjas[i] << endl;
		horaInicio++;
	}
}

void Cancha::mostrarInformacion() {
	cout << "Codigo: " << codigo << endl;
	cout << "Tipo de deporte: " << tipoDeporte << endl;
	cout << "Precio por hora: " << precioPorHora << endl;
}