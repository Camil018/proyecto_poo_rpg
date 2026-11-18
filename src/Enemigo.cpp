#include "Enemigo.h"

Enemigo::Enemigo(string nombre, int vidaBase, int danioBase, int nivel)
    : Entidad(nombre, vidaBase + 2 * (nivel - 1)) {
    this->nivel = nivel;
    this->danio = danioBase + (nivel - 1);
}

int Enemigo::getNivel() {
    return nivel;
}

int Enemigo::getDanio() {
    return danio;
}