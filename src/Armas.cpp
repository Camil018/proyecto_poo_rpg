#include "Armas.h"
#include "Utilidades.h"
#include <iostream>
using namespace std;

Arma::Arma(string nombre, string descripcion, int disparos, int municionPorDisparo,
           int danio, int critico, int probCritico) : Objeto(nombre, descripcion) {
    this->disparos = disparos;
    this->municionPorDisparo = municionPorDisparo;
    this->danio = danio;
    this->critico = critico;
    this->probCritico = probCritico;
}

int Arma::getDisparos() {
    return disparos;
}

int Arma::getMunicionPorDisparo() {
    return municionPorDisparo;
}

int Arma::getDanio() {
    return danio;
}

int Arma::getCritico() {
    return critico;
}

int Arma::getProbCritico() {
    return probCritico;
}

int Arma::disparosEsteAtaque() {
    return disparos;
}

int Arma::atacar(int& municion) {
    int total = 0;
    int cantidad = disparosEsteAtaque();

    for (int i = 0; i < cantidad; i++) {
        if (municion < municionPorDisparo) {
            cout << "  Te quedaste sin municion\n";
            break;
        }

        municion = municion - municionPorDisparo;

        int golpe = danio;
        if (probabilidad(probCritico)) {
            golpe = critico;
            cout << "  Critico! ";
        } else {
            cout << "  ";
        }
        cout << getNombre() << ": " << golpe << " de dano\n";
        total = total + golpe;
    }

    return total;
}

void Arma::usar(Jugador* jugador) {
    cout << "Esta arma se usa atacando en combate\n";
}

PistolaBasica::PistolaBasica()
    : Arma("Pistola Basica", "Arma inicial", 3, 1, 2, 3, 10) {
}

M4::M4()
    : Arma("M4", "Rifle de rafagas", 6, 2, 2, 3, 10) {
}

Katana::Katana()
    : Arma("Katana", "Cuerpo a cuerpo, no gasta municion", 1, 0, 6, 12, 20) {
    golpeDoble = false;
}

int Katana::disparosEsteAtaque() {
    golpeDoble = !golpeDoble;
    if (golpeDoble) {
        return 1;
    }
    return 2;
}

CanonDeGrapas::CanonDeGrapas()
    : Arma("Canon de Grapas", "Lenta con mucho Daño", 1, 4, 5, 7, 15) {
}