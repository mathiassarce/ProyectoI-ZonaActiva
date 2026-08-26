#pragma once
#include "Cliente.h"
#include <string>
using namespace std;

const int MAX_CLIENTES = 100;


class ListaClientes {
private:
    Cliente** clientes[MAX_CLIENTES];   
    int cantidad;        

public:
   //Constructor
	ListaCliente();
 
	//Destructor
	~ListaCliente();
 
	//Metodos propios
	bool registrarCliente(int identificacion, string nombreCompleto, string numTelefono);
	void mostrarTodos();
	Cliente* buscarId(int identificacion);
	bool existeIdentificacion(int identificacion);
	int getCantidad();
};
 