#ifndef SALAS_H
#define SALAS_H

#include <string>
#include <vector>
#include "Habitacion.h"
#include "Enemigo.h"
#include "ProfesorRubrica.h"
using namespace std;

class SalaEnemigos : public Habitacion {
private:
    vector<Enemigo*> enemigos;

public:
    SalaEnemigos(string nombre, string descripcion);
    ~SalaEnemigos();

    void agregarEnemigo(Enemigo* enemigo);
    int getCantidadEnemigos();
    Enemigo* getEnemigo(int indice);
    void quitarEnemigo(int indice);
    bool estaLimpia();
    void entrar(Jugador* jugador);
};

class SalaCofre : public Habitacion {
private:
    bool abierto;

public:
    SalaCofre(string nombre, string descripcion);

    bool getAbierto() {
        return abierto;
    }

    void setAbierto(bool valor) {
        abierto = valor;
    }

    void entrar(Jugador* jugador);
};

class SalaTienda : public Habitacion {
public:
    SalaTienda(string nombre, string descripcion);
    void entrar(Jugador* jugador);
};

class SalaPortal : public Habitacion {
private:
    SalaEnemigos* salaA;
    SalaEnemigos* salaB;
    bool cruzado;

public:
    SalaPortal(string nombre, string descripcion, SalaEnemigos* salaA, SalaEnemigos* salaB);
    bool getCruzado();
    bool puedeEntrar();
    void entrar(Jugador* jugador);
};

class SalaJefe : public Habitacion {
private:
    ProfesorRubrica* jefe;

public:
    SalaJefe(string nombre, string descripcion);
    ~SalaJefe();
    ProfesorRubrica* getJefe();
    bool getVencido();
    void entrar(Jugador* jugador);
};

#endif