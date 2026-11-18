#ifndef ENEMIGOS_H
#define ENEMIGOS_H

#include "Enemigo.h"
using namespace std;

class ZombiOjeras : public Enemigo {
private:
    bool golpeDoble;

public:
    ZombiOjeras(int nivel);
    void atacar(Entidad* objetivo);
};

class DronVigilante : public Enemigo {
public:
    DronVigilante(int nivel);
    void atacar(Entidad* objetivo);
};

class FotocopiadoraTanque : public Enemigo {
private:
    int turnosCarga;

public:
    FotocopiadoraTanque(int nivel);
    void atacar(Entidad* objetivo);
};

#endif