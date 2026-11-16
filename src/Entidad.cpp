#include "Entidad.h"

Entidad::Entidad(string nombre, int vidaMaxima) {
    this->nombre = nombre;
    this->vidaMaxima = vidaMaxima;
    this->vida = vidaMaxima;
}

Entidad::~Entidad() {
}

string Entidad::getNombre() {
    return nombre;
}

int Entidad::getVida() {
    return vida;
}

int Entidad::getVidaMaxima() {
    return vidaMaxima;
}

void Entidad::setVida(int nuevaVida) {
    vida = nuevaVida;
    if (vida > vidaMaxima) {
        vida = vidaMaxima;
    }
    if (vida < 0) {
        vida = 0;
    }
}

void Entidad::setVidaMaxima(int nuevaVidaMaxima) {
    vidaMaxima = nuevaVidaMaxima;
    if (vida > vidaMaxima) {
        vida = vidaMaxima;
    }
}

bool Entidad::estaVivo() {
    return vida > 0;
}

void Entidad::recibirDanio(int danio) {
    setVida(vida - danio);
}