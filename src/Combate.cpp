#include "Combate.h"
#include "Utilidades.h"
#include <iostream>
using namespace std;

Combate::Combate(Jugador* jugador, Enemigo* enemigo) {
    this->jugador = jugador;
    this->enemigo = enemigo;
    this->turno = 0;
}

void Combate::mostrarSituacion() {
    cout << "\nTurno " << turno << "\n";
    cout << enemigo->getNombre() << " (nivel " << enemigo->getNivel() << "): "
         << enemigo->getVida() << "/" << enemigo->getVidaMaxima() << " de vida\n";
    jugador->mostrarEstado();
}

bool Combate::pelear() {
    cout << "\nAparece " << enemigo->getNombre() << "!\n";

    while (jugador->estaVivo() && enemigo->estaVivo()) {
        turno++;
        mostrarSituacion();
        turnoDelJugador();

        if (!enemigo->estaVivo()) {
            break;
        }

        turnoDelEnemigo();
    }

    jugador->quitarRaices();

    if (jugador->estaVivo()) {
        cout << "\nDerrotaste a " << enemigo->getNombre() << "\n";
        return true;
    }

    cout << "\n" << enemigo->getNombre() << " te dejo fuera de combate\n";
    return false;
}

void Combate::turnoDelJugador() {
    bool turnoGastado = false;

    while (!turnoGastado) {
        cout << "\nQue haces?\n";
        cout << "1) Atacar\n";
        cout << "2) Habilidad\n";
        cout << "3) Objeto\n";
        int opcion = leerOpcion("> ", 1, 3);

        if (opcion == 1) {
            menuAtacar();
            turnoGastado = true;
        } else if (opcion == 2) {
            if (jugador->puedeUsarHabilidad()) {
                jugador->usarHabilidad();
                turnoGastado = true;
            } else {
                cout << "Ya usaste la habilidad en esta sala\n";
            }
        } else {
            if (jugador->getCantidadObjetos() == 0) {
                cout << "No tienes objetos\n";
            } else if (menuObjeto()) {
                turnoGastado = true;
            }
        }
    }
}

void Combate::menuAtacar() {
    jugador->mostrarArmas();
    int opcion = leerOpcion("Con cual arma? ", 1, jugador->getCantidadArmas());
    jugador->elegirArma(opcion - 1);
    jugador->atacar(enemigo);
}

bool Combate::menuObjeto() {
    jugador->mostrarInventario();
    cout << "0) Volver\n";
    int opcion = leerOpcion("Cual usas? ", 0, jugador->getCantidadObjetos());
    if (opcion == 0) {
        return false;
    }

    Objeto* objeto = jugador->getObjeto(opcion - 1);
    if (!objeto->puedeUsar(jugador)) {
        return false;
    }

    objeto->usar(jugador);
    jugador->quitarObjeto(opcion - 1);
    return true;
}

void Combate::turnoDelEnemigo() {
    cout << "\nTurno de " << enemigo->getNombre() << "\n";

    if (jugador->raicesActivas()) {
        jugador->aplicarRaices(enemigo);
    } else {
        enemigo->atacar(jugador);
    }
}