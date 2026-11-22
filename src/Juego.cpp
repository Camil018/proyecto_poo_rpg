#include "Juego.h"
#include "Utilidades.h"
#include <iostream>
using namespace std;

Juego::Juego() {
    jugador = nullptr;
    nivel = nullptr;
    nivelActual = 1;
}

Juego::~Juego() {
    if (nivel != nullptr) {
        delete nivel;
    }
    if (jugador != nullptr) {
        delete jugador;
    }
}

void Juego::iniciar() {
    bool salir = false;

    while (!salir) {
        cout << "\nSOBREVIVE EL SEMESTRE\n";
        cout << "1) Nueva partida\n";
        cout << "2) Cargar partida\n";
        cout << "3) Salir\n";
        int opcion = leerOpcion("> ", 1, 3);

        if (opcion == 1) {
            nuevaPartida();
        } else if (opcion == 2) {
            cargarPartida();
        } else {
            salir = true;
        }
    }

    cout << "\nHasta la proxima\n";
}

void Juego::nuevaPartida() {
    if (jugador != nullptr) {
        delete jugador;
    }
    jugador = new Jugador();

    cout << "\nEres Roble y llevas toda la noche en el campus.\n";
    cout << "Para salir tienes que cruzar tres pisos llenos de bichos raros\n";
    cout << "y llegar al Salon del Examen Final, donde te espera el profesor Aurelio Rubrica.\n";
    pausar();

    jugarDesde(1, nullptr);
}

void Juego::cargarPartida() {
    Partida partida;
    if (!partida.leer()) {
        cout << "\nNo hay una partida guardada que se pueda cargar\n";
        return;
    }

    if (jugador != nullptr) {
        delete jugador;
    }
    jugador = new Jugador();
    partida.aplicarAlJugador(jugador);

    cout << "\nPartida cargada. Sigues en el nivel " << partida.getNivel() << "\n";
    jugarDesde(partida.getNivel(), &partida);
}

void Juego::jugarDesde(int nivelInicial, Partida* partida) {
    for (nivelActual = nivelInicial; nivelActual <= 4; nivelActual++) {
        nivel = new Nivel(nivelActual);

        if (partida != nullptr) {
            partida->aplicarAlNivel(nivel);
            nivel->reanudar(jugador, partida->getSala());
            partida = nullptr;
        } else {
            nivel->recorrer(jugador);
        }

        bool jefeVencido = false;
        if (nivelActual == 4 && jugador->estaVivo()) {
            jefeVencido = nivel->getSalaJefe()->getVencido();
        }

        jugador->setSalaActual(nullptr);
        delete nivel;
        nivel = nullptr;

        if (!jugador->estaVivo()) {
            pantallaDerrota();
            return;
        }

        if (jefeVencido) {
            pantallaVictoria();
            return;
        }
    }
}

void Juego::pantallaDerrota() {
    cout << "\nReprobaste el semestre\n";
    cout << "Llegaste hasta el nivel " << nivelActual << ". Toca volver a intentarlo.\n";
    pausar();
}

void Juego::pantallaVictoria() {
    cout << "\nEl profesor Rubrica se quedo sin tinta roja.\n";
    cout << "Pasaste el examen final y sobreviviste el semestre. Felicidades!\n";
    pausar();
}