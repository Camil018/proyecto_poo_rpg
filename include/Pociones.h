#ifndef POCIONES_H
#define POCIONES_H

#include <string>
#include "Objeto.h"
using namespace std;

class Pocion : public Objeto {
public:
    Pocion(string nombre, string descripcion);

    virtual bool puedeComprar(Jugador* jugador) = 0;
    virtual void pagarCosto(Jugador* jugador) = 0;
};

class PocionVida : public Pocion {
public:
    PocionVida();
    bool puedeComprar(Jugador* jugador);
    void pagarCosto(Jugador* jugador);
    void usar(Jugador* jugador);
};

class PocionEscudo : public Pocion {
public:
    PocionEscudo();
    bool puedeComprar(Jugador* jugador);
    void pagarCosto(Jugador* jugador);
    bool puedeUsar(Jugador* jugador);
    void usar(Jugador* jugador);
};

#endif