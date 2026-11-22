#include "Nivel.h"
#include "Enemigos.h"
#include "Partida.h"
#include "Utilidades.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Nivel::Nivel(int numero) {
    this->numero = numero;
    salaInicial = NULL;
    salaA = NULL;
    salaB = NULL;
    cofre = NULL;
    tienda = NULL;
    portal = NULL;
    salaJefe = NULL;

    if (numero == 4) {
        salaJefe = new SalaJefe("Salon del Examen Final",
                                "Un salon enorme de ladrillo oscuro, con filas de pupitres vacios.");
        habitaciones.push_back(salaJefe);
        salaInicial = salaJefe;
        return;
    }

    salaA = new SalaEnemigos("Sala A",
                             "Un pasillo de ladrillo rojo con lockers oxidados y olor a cafe viejo.");
    salaB = new SalaEnemigos("Sala B",
                             "Un salon de clases abandonado, con pupitres volteados y un tablero lleno de formulas.");
    cofre = new SalaCofre("Cofre",
                          "Una bodega de la biblioteca, con estantes de ladrillo y un cofre de madera en el centro.");
    portal = new SalaPortal("Portal",
                            "Al fondo del edificio, un arco de ladrillo brilla con una luz extrana.",
                            salaA, salaB);

    habitaciones.push_back(salaA);
    habitaciones.push_back(salaB);
    habitaciones.push_back(cofre);
    habitaciones.push_back(portal);

    if (numero >= 2) {
        tienda = new SalaTienda("Tienda",
                                "La cafeteria del campus, cerrada hace meses. Sobre el mostrador alguien dejo unas pociones.");
        habitaciones.push_back(tienda);
    }

    if (numero == 1) {
        salaA->agregarEnemigo(new ZombiOjeras(numero));
        salaA->agregarEnemigo(new DronVigilante(numero));
        salaB->agregarEnemigo(new DronVigilante(numero));
        salaB->agregarEnemigo(new ZombiOjeras(numero));
        salaB->agregarEnemigo(new FotocopiadoraTanque(numero));
    } else if (numero == 2) {
        salaA->agregarEnemigo(new ZombiOjeras(numero));
        salaA->agregarEnemigo(new DronVigilante(numero));
        salaA->agregarEnemigo(new ZombiOjeras(numero));
        salaB->agregarEnemigo(new DronVigilante(numero));
        salaB->agregarEnemigo(new FotocopiadoraTanque(numero));
        salaB->agregarEnemigo(new ZombiOjeras(numero));
    } else {
        salaA->agregarEnemigo(new DronVigilante(numero));
        salaA->agregarEnemigo(new ZombiOjeras(numero));
        salaA->agregarEnemigo(new FotocopiadoraTanque(numero));
        salaB->agregarEnemigo(new ZombiOjeras(numero));
        salaB->agregarEnemigo(new FotocopiadoraTanque(numero));
        salaB->agregarEnemigo(new DronVigilante(numero));
    }

    conectar(salaA, cofre);
    conectar(salaA, salaB);
    if (tienda != NULL) {
        conectar(salaB, tienda);
    }
    conectar(salaB, portal);

    salaInicial = salaA;
}

Nivel::~Nivel() {
    int cantidad = habitaciones.size();
    for (int i = 0; i < cantidad; i++) {
        delete habitaciones[i];
    }
}

void Nivel::conectar(Habitacion* a, Habitacion* b) {
    a->agregarSalida(b);
    b->agregarSalida(a);
}

int Nivel::getNumero() {
    return numero;
}

Habitacion* Nivel::getSalaInicial() {
    return salaInicial;
}

SalaEnemigos* Nivel::getSalaA() {
    return salaA;
}

SalaEnemigos* Nivel::getSalaB() {
    return salaB;
}

SalaCofre* Nivel::getCofre() {
    return cofre;
}

SalaTienda* Nivel::getTienda() {
    return tienda;
}

SalaPortal* Nivel::getPortal() {
    return portal;
}

SalaJefe* Nivel::getSalaJefe() {
    return salaJefe;
}

int Nivel::getIndiceSala(Habitacion* sala) {
    int cantidad = habitaciones.size();
    for (int i = 0; i < cantidad; i++) {
        if (habitaciones[i] == sala) {
            return i;
        }
    }
    return -1;
}

Habitacion* Nivel::getHabitacion(int indice) {
    int cantidad = habitaciones.size();
    if (indice < 0 || indice >= cantidad) {
        return NULL;
    }
    return habitaciones[indice];
}

bool Nivel::terminado() {
    if (portal != NULL) {
        return portal->getCruzado();
    }
    if (salaJefe != NULL) {
        return salaJefe->getVencido();
    }
    return false;
}

void Nivel::empezar(Jugador* jugador) {
    cout << "\nNivel " << numero << "\n";
    salaInicial->entrar(jugador);
}

void Nivel::moverse(Jugador* jugador) {
    Habitacion* actual = jugador->getSalaActual();
    if (actual->getCantidadSalidas() == 0) {
        return;
    }

    cout << "\n";
    actual->mostrarSalidas();
    cout << "0) Guardar partida\n";
    int opcion = leerOpcion("A donde quieres ir? ", 0, actual->getCantidadSalidas());

    if (opcion == 0) {
        Partida partida;
        if (partida.guardar(jugador, this)) {
            cout << "Partida guardada\n";
        } else {
            cout << "No se pudo guardar la partida\n";
        }
        return;
    }

    Habitacion* destino = actual->getSalida(opcion - 1);
    if (destino->puedeEntrar()) {
        destino->entrar(jugador);
    }
}

void Nivel::avanzar(Jugador* jugador) {
    while (!terminado() && jugador->estaVivo()) {
        moverse(jugador);
    }
}

void Nivel::recorrer(Jugador* jugador) {
    empezar(jugador);
    avanzar(jugador);
}

void Nivel::reanudar(Jugador* jugador, int indiceSala) {
    Habitacion* sala = getHabitacion(indiceSala);

    if (sala == NULL) {
        empezar(jugador);
    } else if (sala == portal) {
        cout << "\nNivel " << numero << "\n";
        sala->entrar(jugador);
    } else {
        cout << "\nNivel " << numero << "\n";
        jugador->setSalaActual(sala);
        cout << "Estas en: " << sala->getNombre() << "\n";
        cout << sala->getDescripcion() << "\n";
    }

    avanzar(jugador);
}