#include <string>
using namespace std;
 
class Cliente {
private:
    int identificacion;
    string nombreCompleto;
    string numTelefono;
 
public:
    Cliente();
    Cliente(int identificacion, string nombreCompleto, string numTelefono);
 
    // Getters
    int getIdentificacion();
    string getNombreCompleto();
    string getNumTelefono();
 
    // Setters
    void setNombreCompleto(string nombreCompleto);
    void setNumTelefono(string numTelefono);
 
    // Muestra datos
    void mostrar();
};