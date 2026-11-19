#include "Jugador.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Jugador::Jugador() : Entidad("Roble", 6) {
    escudoMaximo = 5;
    escudo = escudoMaximo;
    municionMaxima = 120;
    municion = municionMaxima;
    armaElegida = 0;
    habilidadUsada = false;
    turnosRaices = 0;
    salaActual = NULL;
    armas.push_back(new PistolaBasica());
}

Jugador::~Jugador() {
    int cantidadArmas = armas.size();
    for (int i = 0; i < cantidadArmas; i++) {
        delete armas[i];
    }

    int cantidadObjetos = inventario.size();
    for (int i = 0; i < cantidadObjetos; i++) {
        delete inventario[i];
    }
}

int Jugador::getEscudo() {
    return escudo;
}

int Jugador::getEscudoMaximo() {
    return escudoMaximo;
}

int Jugador::getMunicion() {
    return municion;
}

int Jugador::getMunicionMaxima() {
    return municionMaxima;
}

void Jugador::setEscudo(int nuevoEscudo) {
    escudo = nuevoEscudo;
    if (escudo > escudoMaximo) {
        escudo = escudoMaximo;
    }
    if (escudo < 0) {
        escudo = 0;
    }
}

void Jugador::setEscudoMaximo(int nuevoEscudoMaximo) {
    escudoMaximo = nuevoEscudoMaximo;
    if (escudoMaximo > 6) {
        escudoMaximo = 6;
    }
    if (escudoMaximo < 0) {
        escudoMaximo = 0;
    }
    if (escudo > escudoMaximo) {
        escudo = escudoMaximo;
    }
}

void Jugador::setMunicion(int nuevaMunicion) {
    municion = nuevaMunicion;
    if (municion > municionMaxima) {
        municion = municionMaxima;
    }
    if (municion < 0) {
        municion = 0;
    }
}

void Jugador::recibirDanio(int danio) {
    if (danio <= escudo) {
        escudo = escudo - danio;
    } else {
        int sobrante = danio - escudo;
        escudo = 0;
        setVida(getVida() - sobrante);
    }
}

void Jugador::atacar(Entidad* objetivo) {
    Arma* arma = armas[armaElegida];
    cout << getNombre() << " ataca con " << arma->getNombre() << "\n";
    int total = arma->atacar(municion);
    objetivo->recibirDanio(total);
    cout << "Total: " << total << " de dano a " << objetivo->getNombre() << "\n";
}

void Jugador::regenerar() {
    escudo = escudoMaximo;
    municion = municionMaxima;
}

int Jugador::getCantidadArmas() {
    return armas.size();
}

Arma* Jugador::getArma(int indice) {
    return armas[indice];
}

void Jugador::elegirArma(int indice) {
    int cantidad = armas.size();
    if (indice >= 0 && indice < cantidad) {
        armaElegida = indice;
    }
}

bool Jugador::agregarArma(Arma* arma) {
    int cantidad = armas.size();
    if (cantidad < 2) {
        armas.push_back(arma);
        return true;
    }
    return false;
}

void Jugador::reemplazarArma(int indice, Arma* nuevaArma) {
    int cantidad = armas.size();
    if (indice >= 0 && indice < cantidad) {
        delete armas[indice];
        armas[indice] = nuevaArma;
    }
}

int Jugador::getCantidadObjetos() {
    return inventario.size();
}

Objeto* Jugador::getObjeto(int indice) {
    return inventario[indice];
}

void Jugador::agregarObjeto(Objeto* objeto) {
    inventario.push_back(objeto);
}

void Jugador::quitarObjeto(int indice) {
    int cantidad = inventario.size();
    if (indice < 0 || indice >= cantidad) {
        return;
    }

    delete inventario[indice];
    for (int i = indice; i < cantidad - 1; i++) {
        inventario[i] = inventario[i + 1];
    }
    inventario.pop_back();
}

bool Jugador::puedeUsarHabilidad() {
    return !habilidadUsada;
}

void Jugador::usarHabilidad() {
    habilidadUsada = true;
    turnosRaices = 5;
    cout << getNombre() << " usa Raices Salvajes, el enemigo queda inmovilizado 5 turnos\n";
}

bool Jugador::raicesActivas() {
    return turnosRaices > 0;
}

void Jugador::aplicarRaices(Entidad* enemigo) {
    enemigo->recibirDanio(1);
    turnosRaices = turnosRaices - 1;
    cout << "las raices sujetan a " << enemigo->getNombre()
         << " y le hacen 1 de dano (quedan " << turnosRaices << " turnos)\n";
}

void Jugador::recargarHabilidad() {
    habilidadUsada = false;
    turnosRaices = 0;
}

Habitacion* Jugador::getSalaActual() {
    return salaActual;
}

void Jugador::setSalaActual(Habitacion* sala) {
    salaActual = sala;
}

void Jugador::mostrarEstado() {
    cout << getNombre() << " - Vida: " << getVida() << "/" << getVidaMaxima()
         << ", Escudo: " << escudo << "/" << escudoMaximo
         << ", Municion: " << municion << "/" << municionMaxima << "\n";
}

void Jugador::mostrarArmas() {
    cout << "Armas:\n";
    int cantidad = armas.size();
    for (int i = 0; i < cantidad; i++) {
        cout << (i + 1) << ") " << armas[i]->getNombre()
             << " (" << armas[i]->getDescripcion() << ")\n";
    }
}

void Jugador::mostrarInventario() {
    int cantidad = inventario.size();
    if (cantidad == 0) {
        cout << "No tienes objetos\n";
        return;
    }

    cout << "Objetos:\n";
    for (int i = 0; i < cantidad; i++) {
        cout << (i + 1) << ") " << inventario[i]->getNombre()
             << " (" << inventario[i]->getDescripcion() << ")\n";
    }
}