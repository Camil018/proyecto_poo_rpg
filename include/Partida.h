#ifndef PARTIDA_H
#define PARTIDA_H

#include <vector>
using namespace std;

class Jugador;
class Nivel;

class Partida {
private:
    int nivel;
    int sala;
    int vida;
    int vidaMaxima;
    int escudoMaximo;
    vector<int> armas;
    int pocionesVida;
    int pocionesEscudo;
    int salaALimpia;
    int salaBLimpia;
    int cofreAbierto;

public:
    Partida();

    bool guardar(Jugador* jugador, Nivel* elNivel);
    bool leer();

    int getNivel();
    int getSala();
    void aplicarAlJugador(Jugador* jugador);
    void aplicarAlNivel(Nivel* elNivel);
};

#endif