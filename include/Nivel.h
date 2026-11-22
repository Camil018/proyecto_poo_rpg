#ifndef NIVEL_H
#define NIVEL_H

#include <vector>
#include "Habitacion.h"
#include "Salas.h"
#include "Jugador.h"
using namespace std;

class Nivel {
private:
    int numero;
    vector<Habitacion*> habitaciones;
    Habitacion* salaInicial;
    SalaEnemigos* salaA;
    SalaEnemigos* salaB;
    SalaCofre* cofre;
    SalaTienda* tienda;
    SalaPortal* portal;
    SalaJefe* salaJefe;

    void conectar(Habitacion* a, Habitacion* b);

public:
    Nivel(int numero);
    ~Nivel();

    int getNumero();
    Habitacion* getSalaInicial();
    SalaEnemigos* getSalaA();
    SalaEnemigos* getSalaB();
    SalaCofre* getCofre();
    SalaTienda* getTienda();
    SalaPortal* getPortal();
    SalaJefe* getSalaJefe();

    int getIndiceSala(Habitacion* sala);
    Habitacion* getHabitacion(int indice);

    bool terminado();
    void empezar(Jugador* jugador);
    void moverse(Jugador* jugador);
    void avanzar(Jugador* jugador);
    void recorrer(Jugador* jugador);
    void reanudar(Jugador* jugador, int indiceSala);
};

#endif