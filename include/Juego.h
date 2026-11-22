#ifndef JUEGO_H
#define JUEGO_H

#include "Jugador.h"
#include "Nivel.h"
using namespace std;

class Juego {
private:
    Jugador* jugador;
    Nivel* nivel;
    int nivelActual;

    void nuevaPartida();
    void jugarDesde(int nivelInicial);
    void pantallaDerrota();
    void pantallaVictoria();

public:
    Juego();
    ~Juego();
    void iniciar();
};

#endif