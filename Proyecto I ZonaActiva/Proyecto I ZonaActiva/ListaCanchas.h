#pragma once
#include "Cancha.h"
#include <string>
using namespace std;

const int MAX_CANCHAS = 10;

class ListaCanchas {

private:

	Cancha* canchas[MAX_CANCHAS];
	int cantidad;

public:

	//Constructor
	ListaCanchas();

	//Destructores
	~ListaCanchas();

	//Metodos propios
	bool registrarCancha(string codigo, string tipoDeporte, double precioPorHora);
	void mostrarTodas();
	Cancha* buscarPorCodigo(string codigo);
	bool modificarPrecio(string codigo, double nuevoPrecio);
	bool existeCodigo(string codigo);
	int getCantidad();
};