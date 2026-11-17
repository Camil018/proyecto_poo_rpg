#include "Pociones.h"
#include "Jugador.h"
#include <iostream>
using namespace std;

Pocion::Pocion(string nombre, string descripcion) : Objeto(nombre, descripcion) {
}

PocionVida::PocionVida()
    : Pocion("Pocion de Vida", "Cura 3 de vida, cuesta 1 de escudo maximo") {
}

bool PocionVida::puedeComprar(Jugador* jugador) {
    if (jugador->getEscudoMaximo() <= 0) {
        cout << "No se puede comprar la Pocion de Vida: el escudo maximo ya esta en 0\n";
        return false;
    }
    return true;
}

void PocionVida::pagarCosto(Jugador* jugador) {
    jugador->setEscudoMaximo(jugador->getEscudoMaximo() - 1);
}

void PocionVida::usar(Jugador* jugador) {
    jugador->setVida(jugador->getVida() + 3);
    cout << jugador->getNombre() << " usa Pocion de Vida. Vida: "
         << jugador->getVida() << "/" << jugador->getVidaMaxima() << "\n";
}

PocionEscudo::PocionEscudo()
    : Pocion("Pocion de Escudo", "Sube 1 el escudo maximo y el actual, cuesta 1 de vida maxima") {
}

bool PocionEscudo::puedeComprar(Jugador* jugador) {
    if (jugador->getVidaMaxima() <= 1) {
        cout << "No se puede comprar la Pocion de Escudo: la vida maxima no puede bajar de 1\n";
        return false;
    }
    if (jugador->getEscudoMaximo() >= 6) {
        cout << "No se puede comprar la Pocion de Escudo: el escudo maximo ya esta en 6\n";
        return false;
    }
    return true;
}

void PocionEscudo::pagarCosto(Jugador* jugador) {
    jugador->setVidaMaxima(jugador->getVidaMaxima() - 1);
}

bool PocionEscudo::puedeUsar(Jugador* jugador) {
    if (jugador->getEscudoMaximo() >= 6) {
        cout << "No puedes usar la Pocion de Escudo: el escudo maximo ya esta en 6\n";
        return false;
    }
    return true;
}

void PocionEscudo::usar(Jugador* jugador) {
    jugador->setEscudoMaximo(jugador->getEscudoMaximo() + 1);
    jugador->setEscudo(jugador->getEscudo() + 1);
    cout << jugador->getNombre() << " usa Pocion de Escudo. Escudo: "
         << jugador->getEscudo() << "/" << jugador->getEscudoMaximo() << "\n";
}