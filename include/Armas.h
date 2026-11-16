#ifndef ARMAS_H
#define ARMAS_H

#include <string>
#include "Objeto.h"
using namespace std;

class Arma : public Objeto {
private:
    int disparos;
    int municionPorDisparo;
    int danio;
    int critico;
    int probCritico;

public:
    Arma(string nombre, string descripcion, int disparos, int municionPorDisparo,
         int danio, int critico, int probCritico);

    int getDisparos();
    int getMunicionPorDisparo();
    int getDanio();
    int getCritico();
    int getProbCritico();

    virtual int disparosEsteAtaque();
    int atacar(int& municion);
    void usar(Jugador* jugador);
};

class PistolaBasica : public Arma {
public:
    PistolaBasica();
};

class M4 : public Arma {
public:
    M4();
};

class Katana : public Arma {
private:
    bool golpeDoble;

public:
    Katana();
    int disparosEsteAtaque();
};

class CanonDeGrapas : public Arma {
public:
    CanonDeGrapas();
};

#endif