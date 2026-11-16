#ifndef ENTIDAD_H
#define ENTIDAD_H

#include <string>
using namespace std;

class Entidad {
private:
    string nombre;
    int vida;
    int vidaMaxima;

public:
    Entidad(string nombre, int vidaMaxima);
    virtual ~Entidad();

    string getNombre();
    int getVida();
    int getVidaMaxima();
    void setVida(int nuevaVida);
    void setVidaMaxima(int nuevaVidaMaxima);
    bool estaVivo();

    virtual void recibirDanio(int danio);
    virtual void atacar(Entidad* objetivo) = 0;
};

#endif