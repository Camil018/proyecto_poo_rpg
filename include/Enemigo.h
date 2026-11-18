#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <string>
#include "Entidad.h"
using namespace std;

class Enemigo : public Entidad {
private:
    int nivel;
    int danio;

public:
    Enemigo(string nombre, int vidaBase, int danioBase, int nivel);

    int getNivel();
    int getDanio();
};

#endif