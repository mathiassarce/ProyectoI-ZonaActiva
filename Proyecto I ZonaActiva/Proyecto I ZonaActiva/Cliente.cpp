#include "Cliente.h"
#include <iostream>
using namespace std;

//Constructor sin parámetros
Cliente::Cliente() {
    identificacion = 0;
    nombreCompleto = "";
    numTelefono = "";
}

//Constructor con parámetros
Cliente::Cliente(int identificación, string nombreCompleto, string numTelefono) {
    this->identificacion = identificación;
    this->nombreCompleto = nombreCompleto;
    this->numTelefono = numTelefono;
}
 
//Getters
int Cliente::getIdentificacion() const {
    return identificacion;
}
 
string Cliente::getNombreCompleto() const {
    return nombreCompleto;
}
 
string Cliente::getNumTelefono() const {
    return numTelefono;
}

//Setters
void Cliente::setNombreCompleto(string nombreCompleto) {
    this->nombreCompleto = nombreCompleto;
}
 
void Cliente::setNumTelefono(string numTelefono) {
    this->numTelefono = numTelefono;
}

//Metodo mostrar
void Cliente::mostrar() const {
    cout << "Informacion del cliente: "<<endl;
    cout << "ID: " << identificacion<<endl;
    cout << "Nombre: " << nombreCompleto<<endl;
    cout << " Telefono: " << numTelefono << endl;
}