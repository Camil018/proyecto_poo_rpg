#ifndef OBJETO_H
#define OBJETO_H

#include <string>
using namespace std;

class Jugador;

class Objeto {
private:
    string nombre;
    string descripcion;

public:
    Objeto(string nombre, string descripcion) {
        this->nombre = nombre;
        this->descripcion = descripcion;
    }

    virtual ~Objeto() {
    }

    string getNombre() {
        return nombre;
    }

    string getDescripcion() {
        return descripcion;
    }

    virtual void usar(Jugador* jugador) = 0;
};

#endif