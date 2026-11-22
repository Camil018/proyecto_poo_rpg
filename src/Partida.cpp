#include "Partida.h"
#include "Jugador.h"
#include "Nivel.h"
#include "Armas.h"
#include "Pociones.h"
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int codigoDeArma(Arma* arma) {
    string nombre = arma->getNombre();
    if (nombre == "M4") {
        return 2;
    }
    if (nombre == "Katana") {
        return 3;
    }
    if (nombre == "Canon de Grapas") {
        return 4;
    }
    return 1;
}

Arma* crearArma(int codigo) {
    if (codigo == 2) {
        return new M4();
    }
    if (codigo == 3) {
        return new Katana();
    }
    if (codigo == 4) {
        return new CanonDeGrapas();
    }
    return new PistolaBasica();
}

void vaciarSala(SalaEnemigos* sala) {
    if (sala == NULL) {
        return;
    }
    while (!sala->estaLimpia()) {
        sala->quitarEnemigo(0);
    }
}

Partida::Partida() {
    nivel = 0;
    sala = 0;
    vida = 0;
    vidaMaxima = 0;
    escudoMaximo = 0;
    pocionesVida = 0;
    pocionesEscudo = 0;
    salaALimpia = 0;
    salaBLimpia = 0;
    cofreAbierto = 0;
}

bool Partida::guardar(Jugador* jugador, Nivel* elNivel) {
    int indiceSala = elNivel->getIndiceSala(jugador->getSalaActual());
    if (indiceSala < 0) {
        return false;
    }

    int cuantasVida = 0;
    int cuantasEscudo = 0;
    int cantidadObjetos = jugador->getCantidadObjetos();
    for (int i = 0; i < cantidadObjetos; i++) {
        string nombre = jugador->getObjeto(i)->getNombre();
        if (nombre == "Pocion de Vida") {
            cuantasVida++;
        } else if (nombre == "Pocion de Escudo") {
            cuantasEscudo++;
        }
    }

    int aLimpia = 0;
    int bLimpia = 0;
    int abierto = 0;
    if (elNivel->getSalaA() != NULL && elNivel->getSalaA()->estaLimpia()) {
        aLimpia = 1;
    }
    if (elNivel->getSalaB() != NULL && elNivel->getSalaB()->estaLimpia()) {
        bLimpia = 1;
    }
    if (elNivel->getCofre() != NULL && elNivel->getCofre()->getAbierto()) {
        abierto = 1;
    }

    ofstream archivo("partida.txt");
    if (archivo.fail()) {
        return false;
    }

    archivo << elNivel->getNumero() << "\n";
    archivo << indiceSala << "\n";
    archivo << jugador->getVida() << " " << jugador->getVidaMaxima() << " "
            << jugador->getEscudoMaximo() << "\n";

    archivo << jugador->getCantidadArmas() << "\n";
    int cantidadArmas = jugador->getCantidadArmas();
    for (int i = 0; i < cantidadArmas; i++) {
        archivo << codigoDeArma(jugador->getArma(i)) << "\n";
    }

    archivo << cuantasVida << " " << cuantasEscudo << "\n";
    archivo << aLimpia << " " << bLimpia << " " << abierto << "\n";

    return true;
}

bool Partida::leer() {
    ifstream archivo("partida.txt");
    if (archivo.fail()) {
        return false;
    }

    int cantidadArmas = 0;
    archivo >> nivel >> sala;
    archivo >> vida >> vidaMaxima >> escudoMaximo;
    archivo >> cantidadArmas;

    if (archivo.fail() || cantidadArmas < 1 || cantidadArmas > 2) {
        return false;
    }

    armas.clear();
    for (int i = 0; i < cantidadArmas; i++) {
        int codigo = 0;
        archivo >> codigo;
        if (codigo < 1 || codigo > 4) {
            return false;
        }
        armas.push_back(codigo);
    }

    archivo >> pocionesVida >> pocionesEscudo;
    archivo >> salaALimpia >> salaBLimpia >> cofreAbierto;

    if (archivo.fail()) {
        return false;
    }
    if (nivel < 1 || nivel > 3 || sala < 0) {
        return false;
    }
    if (vidaMaxima < 1 || vidaMaxima > 6 || vida < 1 || vida > vidaMaxima) {
        return false;
    }
    if (escudoMaximo < 0 || escudoMaximo > 6) {
        return false;
    }
    if (pocionesVida < 0 || pocionesEscudo < 0) {
        return false;
    }

    return true;
}

int Partida::getNivel() {
    return nivel;
}

int Partida::getSala() {
    return sala;
}

void Partida::aplicarAlJugador(Jugador* jugador) {
    jugador->setVidaMaxima(vidaMaxima);
    jugador->setVida(vida);
    jugador->setEscudoMaximo(escudoMaximo);
    jugador->regenerar();

    jugador->reemplazarArma(0, crearArma(armas[0]));
    if (armas.size() == 2) {
        jugador->agregarArma(crearArma(armas[1]));
    }

    for (int i = 0; i < pocionesVida; i++) {
        jugador->agregarObjeto(new PocionVida());
    }
    for (int i = 0; i < pocionesEscudo; i++) {
        jugador->agregarObjeto(new PocionEscudo());
    }
}

void Partida::aplicarAlNivel(Nivel* elNivel) {
    if (salaALimpia == 1) {
        vaciarSala(elNivel->getSalaA());
    }
    if (salaBLimpia == 1) {
        vaciarSala(elNivel->getSalaB());
    }
    if (cofreAbierto == 1 && elNivel->getCofre() != NULL) {
        elNivel->getCofre()->setAbierto(true);
    }
}