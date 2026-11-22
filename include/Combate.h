#ifndef COMBATE_H
#define COMBATE_H

#include "Jugador.h"
#include "Enemigo.h"
using namespace std;

class Combate {
private:
    Jugador* jugador;
    Enemigo* enemigo;
    int turno;

    void mostrarSituacion();
    void turnoDelJugador();
    void turnoDelEnemigo();
    void menuAtacar();
    bool menuObjeto();

public:
    Combate(Jugador* jugador, Enemigo* enemigo);
    bool pelear();
};

#endif