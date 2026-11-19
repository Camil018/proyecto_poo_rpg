#ifndef HABITACION_H
#define HABITACION_H

#include <string>
#include <vector>
#include <map>
using namespace std;

class Jugador;

class Habitacion {
private:
    string nombre;
    string descripcion;
    map<string, Habitacion*> salidas;
    vector<string> nombresSalidas;

public:
    Habitacion(string nombre, string descripcion);
    virtual ~Habitacion();

    string getNombre();
    string getDescripcion();

    void agregarSalida(Habitacion* destino);
    int getCantidadSalidas();
    string getNombreSalida(int indice);
    Habitacion* getSalida(int indice);
    void mostrarSalidas();

    void llegar(Jugador* jugador);
    virtual bool puedeEntrar();
    virtual void entrar(Jugador* jugador) = 0;
};

#endif