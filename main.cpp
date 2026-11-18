#include <iostream>
#include "ProfesorRubrica.h"
#include "Jugador.h"
using namespace std;

class MunecoPrueba : public Entidad {
public:
    MunecoPrueba() : Entidad("Muneco", 100) {
    }

    void atacar(Entidad* objetivo) {
    }
};

int main() {
    cout << "Prueba 1: estado inicial del jefe\n";
    ProfesorRubrica* jefe = new ProfesorRubrica();
    cout << jefe->getNombre() << ": vida " << jefe->getVida() << "/"
         << jefe->getVidaMaxima() << ", fase " << jefe->getFase() << "\n";

    cout << "\nPrueba 2: ocho turnos de fase 1\n";
    MunecoPrueba muneco1;
    for (int turno = 1; turno <= 8; turno++) {
        cout << "Turno " << turno << ":\n";
        jefe->atacar(&muneco1);
    }
    cout << "Al muneco le quedan " << muneco1.getVida() << " de vida\n";
    delete jefe;

    cout << "\nPrueba 3: cambio a la fase 2 cuando le quedan 40 o menos\n";
    jefe = new ProfesorRubrica();
    MunecoPrueba muneco2;
    cout << "Turno 1:\n";
    jefe->atacar(&muneco2);
    jefe->setVida(41);
    cout << "Vida del jefe: " << jefe->getVida() << ", fase " << jefe->getFase() << "\n";
    cout << "Turno 2:\n";
    jefe->atacar(&muneco2);
    jefe->setVida(40);
    cout << "Vida del jefe: " << jefe->getVida() << ", fase " << jefe->getFase() << "\n";
    for (int turno = 3; turno <= 8; turno++) {
        cout << "Turno " << turno << ":\n";
        jefe->atacar(&muneco2);
    }
    cout << "Fase del jefe: " << jefe->getFase() << "\n";
    cout << "Al muneco le quedan " << muneco2.getVida() << " de vida\n";
    delete jefe;

    cout << "\nPrueba 4: un ciclo de fase 1 contra Roble sin que Roble haga nada\n";
    jefe = new ProfesorRubrica();
    Jugador roble;
    roble.mostrarEstado();
    for (int turno = 1; turno <= 4; turno++) {
        cout << "Turno " << turno << ":\n";
        jefe->atacar(&roble);
        roble.mostrarEstado();
    }
    cout << "Roble sigue vivo (1 = si, 0 = no): " << roble.estaVivo() << "\n";
    delete jefe;

    return 0;
}