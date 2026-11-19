#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Jugador.h"
#include "Nivel.h"
using namespace std;

void mostrarEnemigos(SalaEnemigos* sala) {
    int cantidad = sala->getCantidadEnemigos();
    cout << sala->getNombre() << " (" << cantidad << " enemigos):\n";
    for (int i = 0; i < cantidad; i++) {
        Enemigo* enemigo = sala->getEnemigo(i);
        cout << "  " << enemigo->getNombre() << " (nivel " << enemigo->getNivel() << ")\n";
    }
}

void limpiarSala(SalaEnemigos* sala) {
    while (!sala->estaLimpia()) {
        sala->quitarEnemigo(0);
    }
    cout << sala->getNombre() << " limpia\n";
}

int main() {
    srand(time(0));

    cout << "Prueba 1: enemigos de cada nivel\n";
    for (int numero = 1; numero <= 3; numero++) {
        Nivel nivel(numero);
        cout << "\nNivel " << nivel.getNumero() << "\n";
        mostrarEnemigos(nivel.getSalaA());
        mostrarEnemigos(nivel.getSalaB());
        if (nivel.getTienda() != NULL) {
            cout << "Tienda: si\n";
        } else {
            cout << "Tienda: no\n";
        }
    }

    cout << "\nPrueba 2: el portal se abre al limpiar las dos salas\n";
    Nivel nivelPortal(1);
    SalaPortal* portal = nivelPortal.getPortal();
    bool abierto = portal->puedeEntrar();
    cout << "Portal abierto (1 = si, 0 = no): " << abierto << "\n";
    limpiarSala(nivelPortal.getSalaA());
    abierto = portal->puedeEntrar();
    cout << "Portal abierto (1 = si, 0 = no): " << abierto << "\n";
    limpiarSala(nivelPortal.getSalaB());
    abierto = portal->puedeEntrar();
    cout << "Portal abierto (1 = si, 0 = no): " << abierto << "\n";

    cout << "\nPrueba 3: recorrer el nivel 2 con el teclado\n";
    cout << "Elige en orden: 1, 1, 2, 2 (en la tienda 1 y luego 3), 1, 3\n";
    Jugador roble;
    Nivel nivelDos(2);
    roble.recibirDanio(4);
    roble.setMunicion(50);
    cout << "Antes de entrar: ";
    roble.mostrarEstado();
    nivelDos.empezar(&roble);
    cout << "Despues de entrar: ";
    roble.mostrarEstado();
    for (int paso = 1; paso <= 6; paso++) {
        nivelDos.moverse(&roble);
    }
    cout << "\nAl final: ";
    roble.mostrarEstado();
    roble.mostrarArmas();
    roble.mostrarInventario();

    cout << "\nPrueba 4: cofre con 2 armas, te pregunta cual reemplazar\n";
    cout << "Elige 1 para reemplazar la primera\n";
    SalaCofre otroCofre("Otro cofre", "Un cofre extra, solo para esta prueba.");
    otroCofre.entrar(&roble);
    roble.mostrarArmas();

    cout << "\nPrueba 5: recorrer el nivel 1 ya limpio hasta cruzar el portal\n";
    cout << "Elige en orden: 2 (Sala B), 2 (Portal), 1 (Cruzar)\n";
    Nivel nivelUno(1);
    limpiarSala(nivelUno.getSalaA());
    limpiarSala(nivelUno.getSalaB());
    nivelUno.recorrer(&roble);
    cout << "Nivel terminado (1 = si, 0 = no): " << nivelUno.terminado() << "\n";

    cout << "\nPrueba 6: nivel 4 (sala del jefe)\n";
    Nivel nivelCuatro(4);
    nivelCuatro.empezar(&roble);
    cout << "Nivel terminado (1 = si, 0 = no): " << nivelCuatro.terminado() << "\n";
    nivelCuatro.getSalaJefe()->getJefe()->setVida(0);
    cout << "Nivel terminado despues de vencer al jefe: " << nivelCuatro.terminado() << "\n";

    return 0;
}