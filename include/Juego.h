#ifndef JUEGO_H
#define JUEGO_H

#include "Jugador.h"
#include "Nivel.h"
#include "Partida.h"
using namespace std;

class Juego {
private:
    Jugador* jugador;
    Nivel* nivel;
    int nivelActual;

    void nuevaPartida();
    void cargarPartida();
    void jugarDesde(int nivelInicial, Partida* partida);
    void pantallaDerrota();
    void pantallaVictoria();

public:
    Juego();
    ~Juego();
    void iniciar();
};

#endif