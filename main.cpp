#include <iostream>
#include "Jugador.h"
#include "Pociones.h"
using namespace std;

void comprar(Pocion* pocion, Jugador* jugador) {
    if (pocion->puedeComprar(jugador)) {
        pocion->pagarCosto(jugador);
        jugador->agregarObjeto(pocion);
        cout << "Compraste " << pocion->getNombre() << "\n";
    } else {
        delete pocion;
    }
}

void usarObjeto(Jugador* jugador, int indice) {
    Objeto* objeto = jugador->getObjeto(indice);
    if (objeto->puedeUsar(jugador)) {
        objeto->usar(jugador);
        jugador->quitarObjeto(indice);
    }
}

int main() {
    Jugador roble;

    cout << "Prueba 1: comprar Pocion de Vida (cuesta escudo maximo)\n";
    roble.mostrarEstado();
    comprar(new PocionVida(), &roble);
    roble.mostrarEstado();
    roble.mostrarInventario();

    cout << "\nPrueba 2: usar Pocion de Vida (no pasa la vida maxima)\n";
    roble.recibirDanio(5);
    roble.mostrarEstado();
    usarObjeto(&roble, 0);
    roble.mostrarEstado();
    cout << "Objetos en el inventario: " << roble.getCantidadObjetos() << "\n";

    cout << "\nPrueba 3: comprar y usar Pocion de Escudo\n";
    comprar(new PocionEscudo(), &roble);
    roble.mostrarEstado();
    usarObjeto(&roble, 0);
    roble.mostrarEstado();

    cout << "\nPrueba 4: llegar al tope de escudo (6)\n";
    comprar(new PocionEscudo(), &roble);
    usarObjeto(&roble, 0);
    roble.mostrarEstado();
    comprar(new PocionEscudo(), &roble);
    roble.mostrarEstado();

    cout << "\nPrueba 5: minimos que bloquean la tienda\n";
    Jugador otro;
    otro.setVidaMaxima(1);
    otro.setEscudoMaximo(0);
    otro.mostrarEstado();
    comprar(new PocionEscudo(), &otro);
    comprar(new PocionVida(), &otro);
    cout << "Objetos de otro: " << otro.getCantidadObjetos() << "\n";

    cout << "\nPrueba 6: pocion de escudo que no se puede usar no se gasta\n";
    roble.agregarObjeto(new PocionEscudo());
    usarObjeto(&roble, 0);
    cout << "Objetos en el inventario: " << roble.getCantidadObjetos() << "\n";

    return 0;
}